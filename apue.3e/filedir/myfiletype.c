/**
 * @file myfiletype.c
 * @author seed
 * @brief 对每个命令行参数打印文件类型
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "apue.h"
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: ./myfiletype arg1 ...\n");
        exit(-1);
    }
    int i;
    struct stat buf;
    char * str;

    for (i = 1; i < argc; i++) {
        if (lstat(argv[i], &buf) < 0) {
            err_ret("lstat error");
            continue;
        }
        if (S_ISREG(buf.st_mode)) {
            str = "普通文件 regular";
        } else if (S_ISDIR(buf.st_mode)) {
            str = "目录文件 directory";
        } else if (S_ISCHR(buf.st_mode)) {
            str = "字符特殊文件 character special";
        } else if (S_ISBLK(buf.st_mode)) {
            str = "块特殊文件 block special";
        } else if (S_ISFIFO(buf.st_mode)) {
            str = "管道 fifo";
        } else if (S_ISLNK(buf.st_mode)) {
            str = "符号链接 symbolic link";
        } else if (S_ISSOCK(buf.st_mode)) {
            str = "套接字 socket";
        } else {
            str = "未知 unknown";
        }
        printf("%s: %s\n", argv[i], str);
    }
    exit(0);
}