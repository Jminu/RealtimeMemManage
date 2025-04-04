#include <time.h>

typedef struct syscall_event
{
	struct timespec timestamp;
	int syscall_num;
	char syscall_name[6];
	size_t cur_vmsize; //current virtual memory comsumed
	size_t cur_vmrss; //current real memory comsumed
	size_t cur_vmdata; //heap area
	size_t cur_mapped; //area that mapping by mmap
}SYSCALL_EVENT
	

void detect_memory_systemcall(int syscall_num, struct user_pt_regs *regs)
{
	if(syscall_num == 214)
	{
		printf("[Detected]: brk\n");
	}
	else if(syscall_num == 222)
	{
		printf("[Detected]: mmap\n");
	}
	else if(syscall_num == 215)
	{
		printf("[Detected]: munmap\n");
	}
}


