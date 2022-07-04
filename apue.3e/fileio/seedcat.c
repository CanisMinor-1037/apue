/**
 * @file seedcat.c
 * @author seed
 * @brief 使用read()和write()复制一个文件
 * usage: ./seedcat 0<infile 1>outfile
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "apue.h"
#define BUFFSIZE 4096
int main() {
    int n;
    char buffer[BUFFSIZE];
    while ((n = read(STDIN_FILENO, buffer, BUFFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buffer, n) != n) {
            err_sys("write error");
        }
    }
    if (n < 0) {
        err_sys("read error");    
    }
    exit(0);
}