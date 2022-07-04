/**
 * @file mytesterror.c
 * @author seed
 * @brief 使用strerror 和 perror
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "apue.h"
#include <errno.h>
int main(int argc, char *argv[]) {
    fprintf(stderr, "%s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    return 0;
}