/**
 * @file myaccess.c
 * @author seed
 * @brief access()函数实例
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "apue.h"
#include <fcntl.h>
int main(int argc, char * argv[]) {
    if (argc != 2) {
        err_quit("usage: ./myaccess <filename>");
    }    
    if (access(argv[1], R_OK) < 0) {
        err_ret("access error");
    } else {
        printf("access read ok\n");
    }
    if (open(argv[1], O_RDONLY) < 0) {
        err_ret("open error");
    } else {
        printf("open read ok\n");
    }
    exit(0);
}