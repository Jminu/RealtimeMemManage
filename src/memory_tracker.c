#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "../header/memory_tracker.h"

int filter_memory_systemcall(int syscall_num)
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

SYSCALL_EVENT get_memory_snapshot(pid_t pid, int systemcall_num)
{
	SYSCALL_EVENT event;

		
	event.syscall_num = 0; // system call number
	event.syscall_name = "null\0"; // system call name
	event.cur_vmsize = 0; // virtual memory size
	event.cur_vmrss = 0; // real memory size
	event.cur_vmdata = 0; // heap area
	event.cur_mapped = 0; // mapped file area

	char status_path[64];
	char buffer[512];
	char *line = NULL;

	int fd;
	int read_bytes;
	
	snprintf(status_path, sizeof(path), "/proc/%d/status", pid); // generate path string
	
	fd = open(staus_path, O_RDONLY);
	if(fd == -1)
	{
		perror("file open error!");
		exit(1);
	}

	read_bytes = read(fd, buffer, sizeof(buffer) - 1);
	if(read_bytes <= 0)
	{
		perror("file read error!");
		exit(1);
	}

	buffer[read_bytes] = '\0' // add null at last
	
	line = strtok(buffer, '\n');
	while(line != NULL) // extract from str
	{
		if(sscanf(line, "VmSize: %zu kB", event.cur_vmsize) == 1)
		{}
		else if(sscanf(line, "VmRss: %zu kB", event.cur_vmrss) == 1)
		{}
		else if(sscanf(line, "VmData: %zu kB", event.cur_vmdata) == 1)
		{}
		else if(sscanf(line, "RssFile: %zu kB", event.cur_mapped) == 1)
		{}
		
		line = strtok(NULL, '\n');
	}
	event.syscall_num = systemcall_num;

	close(fd);

	return event;
}
