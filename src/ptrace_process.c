#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/user.h>
#include <linux/elf.h> //basic binary format in Linux
#include <string.h>
#include <sys/uio.h> //for - ptrace(PTRACE_GETREGSET) call, iovec definition
#include <asm/ptrace.h> //for - struct user_pt_regs

int status; //process status

void ptrace_attach_process(pid_t pid)
{
	ptrace(PTRACE_ATTACH, pid, NULL, NULL); //chage this pid to trace mode
	waitpid(pid, &status, 0); //wait till child process stop
	printf("Attach to PID: %d\n", pid);
}

void get_syscall(pid_t pid)
{
	struct user_pt_regs regs; //structure that register status when SystemCall ocurred
	//basically SystemCall number stored to Reg[8] in arm64 Linux
	
	struct iovec io = { //from "sys/uio.h"
	        .iov_base = &regs, //register pointer
	        .iov_len = sizeof(regs) //register size
	};

	ptrace(PTRACE_GETREGSET, pid, (void *)NT_PRSTATUS, &io); //NT_PRSTATUS: select register set
	//copy process's register set to io
	
	printf("Current system call number: %llu x0: %llu, x1: %llu\n", regs.regs[8], regs.regs[0], regs.regs[1]); //based on aarch64(arm64)
}	

void ptrace_systemcall(pid_t pid)
{
        while(WIFSTOPPED(status))  //if this process stopped because of ptrace,  WIFSTOPPED(status) returns TRUE
        {
                ptrace(PTRACE_SYSCALL, pid, NULL, NULL); //stop when enter the SystemCall
                waitpid(pid, &status, 0); //
                
                if(WIFEXITED(status))
                        break;
                        
                get_syscall(pid);
                
                ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
                waitpid(pid, &status, 0);
                if(WIFEXITED(status))
                        break;
        }
}

int main()
{
	pid_t pid = fork();
	
	if(pid == 0)
	{
		int *p = (int *)malloc(sizeof(int));
		*p = 32;
		printf("child\n");
	}
	else
	{
		ptrace_attach_process(pid);
		ptrace_systemcall(pid);
		printf("parent\n");
	}

	return 0;
}

