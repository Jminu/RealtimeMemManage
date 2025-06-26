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

void filter_memory_systemcall(int syscall_num);

SYSCALL_EVENT get_memory_snapshot(pid_t pid, int systemcall_num);
