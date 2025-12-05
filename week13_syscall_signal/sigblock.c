#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

struct two_double {
    double a;
    double b;
} data;

void sigalrm_handler(int sig) {
    printf("%f, %f\n", data.a, data.b);
    alarm(1);
}

int main() {

    sigset_t block_mask;
    sigemptyset(&block_mask);
    sigaddset(&block_mask, SIGALRM);

    struct sigaction sa_alrm;

    struct two_double zeros = {0.0, 0.0}, ones = {1.0, 1.0};

    sa_alrm.sa_handler = sigalrm_handler;
    sigemptyset(&sa_alrm.sa_mask);
    sa_alrm.sa_flags = 0;

    if (sigaction(SIGALRM, &sa_alrm, NULL) == -1) {
        perror("sigaction error: ");
        exit(0);
    }
    
    alarm(1);

    while(1) {
        // block SIGALRM signal
        sigprocmask(SIG_BLOCK, &block_mask, NULL);
        data = ones;
        sigprocmask(SIG_UNBLOCK, &block_mask, NULL);
        // unblock SIGALRM signal

        // block SIGALRM signal
        sigprocmask(SIG_BLOCK, &block_mask, NULL);
        data = zeros;
        sigprocmask(SIG_UNBLOCK, &block_mask, NULL);
        // unblock SIGALRM signal
    }

    return 0;
}