#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main() {

    sigset_t block_mask, pending_mask;

    sigemptyset(&block_mask);
    sigaddset(&block_mask, SIGINT);

    sigprocmask(SIG_BLOCK, &block_mask, NULL);
   
    printf("SIGINT blocked. Sleeping for 5 seconds...\n");
    printf("Try Ctrl + C during sleep.\n");

    sleep(5);

    sigpending(&pending_mask);

    if (sigismember(&pending_mask, SIGINT) == 1) {
        printf("SIGINT is pending\n");
    }
    else if (sigismember(&pending_mask, SIGINT) == 0) {
        printf("SIGINT is not pending\n");
    }

    sigprocmask(SIG_BLOCK, &block_mask, NULL);

    return 0;
}