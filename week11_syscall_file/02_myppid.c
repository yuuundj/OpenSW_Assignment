#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t mypid = getpid();
    pid_t ptpid = getppid();
    printf("pid: %lu\n", (unsigned long)mypid);
    printf("ppid: %lu\n", (unsigned long)ptpid);
    return 0;
}