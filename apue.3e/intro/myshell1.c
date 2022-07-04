/**
 * @file myshell1.c
 * @author seed
 * @brief 从标准输入读入命令并执行
 * @version 0.2
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "apue.h"
#include <sys/wait.h>

static void sig_int(int);

int main(void) {
    char buffer[MAXLINE];
    int status;
    pid_t pid;
    
    if (signal(SIGINT, sig_int) == SIG_ERR) {
        err_sys("signal error");
    }
    printf("%% ");
    
    /* 用标准I/O函数fgets从标准输入一次读取一行 */
    while (fgets(buffer, MAXLINE, stdin) != NULL) {
        /* 用'\0'替换'\n' */
        buffer[strlen(buffer) - 1] = '\0';
        /* 调用fork()创建一个新进程 */
        pid = fork();
        if (pid < 0) {
            err_sys("fork error");
        } else if (pid == 0) {
            /* 子进程 */
            execlp(buffer, buffer, NULL);
            err_sys("execlp error");
            exit(127);
        }
        /* 父进程 */
        if ((pid = waitpid(pid, &status, 0)) < 0) {
            err_sys("waitpid error");
        }
        printf("%% ");
    }
    exit(0);
}

/**
 * @brief 产生SIGINT信号时要调用的函数
 * 
 * @param signo 
 */
void sig_int(int signo) {
    printf("interrupt\n%% ");
}