/**
 * @file mychangemod.c
 * @author seed 
 * @brief chmod函数实例
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "apue.h"
int main() {
    /* 对foo关闭S_ISGID，打开S_IXOTH */
    struct stat statbuf;
    if (stat("foo", &statbuf) < 0) {
        err_sys("stat error");
    }
    if (chmod("foo", (statbuf.st_mode & ~S_ISGID) | S_IXOTH) < 0) {
        err_sys("chmod error");
    }

    /* 对bar设置rw- r-- --- */
    if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP) < 0) {
        err_sys("chmod error");
    }
    return 0;
}