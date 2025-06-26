#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "../header/ptrace_process.h"

void run_tracker(pid_t pid)
{
	// attach to the target process
	ptrace_attach_process(pid);

	// begin trace target system call
	printf("[START] : tracking memory related system calls for PID : %d\n", pid);
	ptrace_systemcall(pid);

	printf("[FINISH] : tracking for PID : %d\n", pid);
}
