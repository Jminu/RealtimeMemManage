void filter_memory_systemcall(int syscall_num, struct user_pt_regs *regs)
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


