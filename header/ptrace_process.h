#include <sys/types.h>

void ptrace_attach_process(pid_t pid);
void get_syscall(pid_t pid);
void ptrace_systemcall(pid_t pid);
