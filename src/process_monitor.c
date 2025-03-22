#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

void monitor_all_process()
{
	DIR *dir = opendir("/proc");
	if(dir == NULL)
	{
		perror("opendir error");
		exit(1);
	}

	struct dirent *all_process;
	
	while((all_process = readdir(dir)) != NULL)
	{
		if(all_process->d_type == DT_DIR)
		{
			pid_t pid = atoi(all_process->d_name);
			if(pid > 0)
			{
				printf("[Monitor] PID : %d\n", pid);
			}
		}
	}
	closedir(dir);
}

int main()
{
	while(1)
	{
		system("clear");
		monitor_all_process();
		sleep(1);
	}

	return 0;
}
