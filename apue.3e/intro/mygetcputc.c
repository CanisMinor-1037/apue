/**
 * @file mygetcputc.c
 * @author seed
 * @brief 用标准I/O将标准输入复制到标准输出
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "apue.h"
#define BUFFSIZE 4096
int main(void) {
    int ch;
    while ((ch = getc(stdin)) != EOF) {
        if (putc(ch, stdout) == EOF) {
            err_sys("putc error");
        }
    } 
    if (ferror(stdin)) {
        err_sys("input error");
    }
    exit(0);
}