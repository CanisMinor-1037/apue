/**
 * @file seedhole.c
 * @author seed
 * @brief 
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "apue.h"
#include <fcntl.h>
int main(void) {
    char buf1[] = "abcdefghij";
    char buf2[] = "ABCDEFGHIJ";
    int fd;
    if ((fd = creat("file.hole", FILE_MODE)) < 0) {
        err_sys("creat error");
    }
    if (write(fd, buf1, 10) != 10) {
        err_sys("write error");
    }
    if (lseek(fd, 16384, SEEK_SET) == -1) {
        err_sys("lseek error");
    }
    if (write(fd, buf2, 10) != 10) {
        err_sys("write error");
    }
    return 0;
}