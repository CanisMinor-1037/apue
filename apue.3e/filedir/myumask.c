/**
 * @file myumask.c
 * @author seed 
 * @brief umask函数实例
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "apue.h"
#include <fcntl.h>
mode_t RWRWRW = S_IRUSR | S_IWUSR | 
                S_IRGRP | S_IWGRP |
                S_IROTH | S_IWOTH;
mode_t __RWRW = S_IRGRP | S_IWGRP |
                S_IROTH | S_IWOTH;
int main(void) {
    umask(0);
    if (creat("foo", RWRWRW) < 0) {
        err_sys("creat error");
    }
    umask(__RWRW);
    if (creat("bar", RWRWRW) < 0) {
        err_sys("creat error");
    }
    return 0;
} 