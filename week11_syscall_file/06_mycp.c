#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 32

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("Usage: %s [src] [dst1] [dst2] ... \n", argv[0]);
        exit(0);
    }

    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror(argv[1]);
        exit(0);
    }

    int num_files = argc -2;
    int* dst_fd_list = (int*)malloc(sizeof(int) * num_files);
    for (int i = 0; i < num_files; i++) {
        dst_fd_list[i] = open(argv[i + 2], O_WRONLY | O_CREAT, 0644);
    }

    char* readStr = (char*)malloc(sizeof(char) * BUF_SIZE);
    int read_result;
    while (1) {
        read_result = read(src_fd, readStr, BUF_SIZE);
        if (read_result == 0) {
            break;
        }
        write(1, readStr, read_result);
        for (int i = 0; i < num_files; i++) {
            write(dst_fd_list[i], readStr, read_result);
        }
    }

    close(src_fd);
    for (int i = 0; i < num_files; i++) {
        close(dst_fd_list[i]);
    }

    free(readStr);
    free(dst_fd_list);

    return 0;
}