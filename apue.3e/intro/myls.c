/**
 * @file myls.c
 * @author seed
 * @brief ls命令的简要实现
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "apue.h"
#include <dirent.h> 
int main(int argc, char **argv) {
    if (argc != 2) {
        err_quit("usage: myls <dirname>");
    }
    struct dirent * dirp;
    DIR * dp = opendir(argv[1]);
    if (dp == NULL) {
        err_sys("opendir error");
    } else {
        while ((dirp = readdir(dir)) != NULL) {
            printf("%s\n", dirp->d_name);
        }
    }
    closedir(dp);
    exit(0);
}