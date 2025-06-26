#include <sys/types.h>
#include "memory_tracker.h"

void ptrace_attach_process(pid_t pid);
void get_syscall(pid_t pid);
void ptrace_systemcall(pid_t pid);
void print_syscall_event(const SYSCALL_EVENT *event);
