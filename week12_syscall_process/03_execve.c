#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./03_execve <program path> [OPTION] ...\n");
        exit(0);
    }

    pid_t child = fork();
    if (child == 0) {
        execve(argv[1], &argv[1], NULL);
        return 1;
    }
    else {
        int wstatus;
        waitpid(child, &wstatus, 0);
        if (WIFEXITED(wstatus)) {
            printf("Child exited with status %d\n", WEXITSTATUS(wstatus));
        }
    }
    return 0;
}