#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int mysystem(const char* command) {
    if (command == NULL) {
        return 1;
    }
    pid_t child = fork();
    if (child == 0) {
        execl("/bin/sh", "sh", "-c", command, (char*)NULL);
        _exit(127);
    }
    else if (child == -1) {
        return -1;
    }
    else {
        int wstatus;
        waitpid(child, &wstatus, 0);
    }
    return 0;
}

int main() {

    mysystem("ls -l | wc -l");
    mysystem("find . -name '*.c'");

    printf("Good bye\n");

    return 0;
}