/**
 * @file mycat.c
 * @author apue.3e
 * @brief 只使用read()和write()复制一个文件
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "apue.h"

#define	BUFFSIZE	4096

int
main(void)
{
	int		n;
	char	buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");

	if (n < 0)
		err_sys("read error");
	/**
	 * @brief 进程中止时，Unix系统内核会关闭进程的所有打开的文件描述符
	 * 所以此程序并不关闭输入和输出文件
	 */
	exit(0);
}
