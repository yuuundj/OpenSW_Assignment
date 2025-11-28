#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child = fork();

    if (child == 0) {
        sleep(1);
        printf("Child process PID: %lu\n", (unsigned long)getpid());
        printf("Child process PPID: %lu\n", (unsigned long)getppid());
        return 7;
    }
    else {
        printf("Parent process PID: %lu\n", (unsigned long)getpid());
        printf("Parent process PPID: %lu\n", (unsigned long)getppid());
        return 0;
    }
    return 0;
}