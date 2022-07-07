/**
 * @file access.c
 * @author apue.3e
 * @brief access()函数实例
 * @version 0.1
 * @date 2022-07-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "apue.h"
#include <fcntl.h>

int
main(int argc, char *argv[])
{
	if (argc != 2)
		err_quit("usage: a.out <pathname>");
	if (access(argv[1], R_OK) < 0) /* 测试读权限 */
		err_ret("access error for %s", argv[1]);
	else
		printf("read access OK\n");
	if (open(argv[1], O_RDONLY) < 0) /* 测试读权限 */
		err_ret("open error for %s", argv[1]);
	else
		printf("open for reading OK\n");
	exit(0);
}
