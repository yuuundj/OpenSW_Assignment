#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t mypid = getpid();
    printf("pid: %lu\n", (unsigned long)mypid);
    return 0;
}