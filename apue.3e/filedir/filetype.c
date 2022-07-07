/**
 * @file filetype.c
 * @author apue.3e
 * @brief 对每个命令行参数打印文件类型
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "apue.h"

int
main(int argc, char *argv[])
{
	int			i;
	struct stat	buf;
	char		*ptr;

	for (i = 1; i < argc; i++) {
		printf("%s: ", argv[i]);
		/**
		 * @brief lstat()
		 * 类似于stat(), 当命名的文件是一个符号链接时
		 * lstat()返回该符号链接的有关信息， 
		 * 而不是由该符号链接引用的文件的信息
		 * @param pathname: const char *restrict: argv[i]
		 * @param buf: struct stat *restrict: &buf
		 * @return int: 若成功,返回0; 若出错,返回1 
		 */
		if (lstat(argv[i], &buf) < 0) {
			err_ret("lstat error");
			continue;
		}
		if (S_ISREG(buf.st_mode)) /* 普通文件 */
			ptr = "regular";
		else if (S_ISDIR(buf.st_mode)) /* 目录文件 */
			ptr = "directory";
		else if (S_ISCHR(buf.st_mode)) /* 字符特殊文件 */
			ptr = "character special";
		else if (S_ISBLK(buf.st_mode)) /* 块特殊文件 */
			ptr = "block special";
		else if (S_ISFIFO(buf.st_mode)) /* 管道或FIFO */
			ptr = "fifo";
		else if (S_ISLNK(buf.st_mode)) /* 符号链接 */
			ptr = "symbolic link";
		else if (S_ISSOCK(buf.st_mode)) /* 套接字 */
			ptr = "socket";
		else
			ptr = "** unknown mode **";
		printf("%s\n", ptr);
	}
	exit(0);
}
