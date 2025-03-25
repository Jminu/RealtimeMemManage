void detect_memory_systemcall(int syscall_num)
{
	if(syscall_num == 214)
	{
		printf("[Detected]: brk\n");
	}
	else if(syscall_num == 222)
	{
		pitnf("[Detected]: mmap\n");
	}
	else if(syscall_num == 215)
	{
		printf("[Detected]: munmap\n");
	}
}


