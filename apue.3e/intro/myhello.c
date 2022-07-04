/**
 * @file myhello.c
 * @author seed
 * @brief 打印进程ID
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "apue.h"
int main(void) {
    // 使用长整型用于提高可移植性 
    printf("Hello world from process id %ld\n", (long)getpid());
    return 0;
}