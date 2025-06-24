#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "argument error");
		exit(1);
	}

	pid_t target_pid = atoi(argv[1]);
	
	if(pid < 0)
	{
		fprintf(stderr, "pid number error");
		exit(1);
	}

	return 0;
}
