/**
 * @file myuidgid.c
 * @author seed
 * @brief 打印用户id和组id
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "apue.h"
int main(void) {
    printf("uid:%d gid:%d\n", getuid(), getgid());
    return 0;
}