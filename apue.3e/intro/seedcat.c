/**
 * @file seedcat.c
 * @author seed
 * @brief 将标准输入复制到标准输出
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "apue.h"
#define BUFSIEZ 4096
int main() {
    char buffer[BUFSIEZ];
    ssize_t n;
    while ((n = read(STDIN_FILENO, buffer, BUFSIEZ)) > 0) {
        if (write(STDOUT_FILENO, buffer, n) != n) {
            err_sys("write error");
        }
    }
    if (n < 0) {
        err_sys("read_error");
    }
    exit(0);
}