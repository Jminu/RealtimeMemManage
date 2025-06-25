int filter_memory_systemcall(int syscall_num, struct user_pt_regs *regs)
{
	if(syscall_num == 214)
	{
		printf("[Detected]: brk\n");
		return 1;
	}
	else if(syscall_num == 222)
	{
		printf("[Detected]: mmap\n");
		return 1;
	}
	else if(syscall_num == 215)
	{
		printf("[Detected]: munmap\n");
		return 1;
	}
	else{
		return 0; // not SystemCall return false;
	}
}


