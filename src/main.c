#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include "../header/ptrace_process.h"
#include "../header/memory_tracker.h"


int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "argument error");
		exit(1);
	}

	pid_t target_pid = atoi(argv[1]); // get pid to trace
	
	if(target_pid < 0)
	{
		fprintf(stderr, "pid number error");
		exit(1);
	}

	ptrace_attach(target_pid); // attach tracer to target_pid
	ptrace_systemcall(target_pid); // watch target_pid process
	
	return 0;
}
