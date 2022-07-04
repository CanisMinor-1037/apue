/**
 * @file myseek.c
 * @author seed
 * @brief 测试对其标准输入是否能设置偏移量
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "apue.h"
int main(void) {
    /**
     * @brief 因为偏移量可能是负值，
     * 所以在比较lseek()返回值时应该谨慎
     * 不要测试它是否小于0，而要测试它是否等于-1
     */
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) {
        printf("Cannot seek\n");
    } else {
        printf("Seek OK\n");
    }
    return 0;
}