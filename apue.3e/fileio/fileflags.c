/**
 * @file fileflags.c
 * @author apue.3e
 * @brief 对于指定的描述符打印文件标志
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "apue.h"
#include <fcntl.h>

int
main(int argc, char *argv[])
{
	int		val;

	if (argc != 2)
		err_quit("usage: a.out <descriptor#>");
	/**
	 * @brief 对于于fd的文件状态标志作为函数值返回
	 * 
	 */
	if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
		err_sys("fcntl error for fd %d", atoi(argv[1]));
	
	switch (val & O_ACCMODE) {
	/**
	 * @brief 
	 * O_RDONLY: 0
	 */
	case O_RDONLY:
		printf("read only");
		break;
	/**
	 * @brief 
	 * O_WRONLY: 1
	 */
	case O_WRONLY:
		printf("write only");
		break;
	/**
	 * @brief 
	 * O_RDWR: 2
	 */
	case O_RDWR:
		printf("read write");
		break;
	/**
	 * @brief 
	 * others
	 */
	default:
		err_dump("unknown access mode");
	}
	/**
	 * @brief 
	 * O_APPEND: 追加写
	 */
	if (val & O_APPEND)
		printf(", append");
	/**
	 * @brief 
	 * O_NONBLOCK: 非阻塞模式
	 */
	if (val & O_NONBLOCK)
		printf(", nonblocking");
	/**
	 * @brief 
	 * O_SYNC: 等待写完成(数据和属性)
	 */
	if (val & O_SYNC)
		printf(", synchronous writes");

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
	/**
	 * @brief 
	 * O_FSYNC: 等待写完成(仅FreeBSD和Mac OS X)
	 */
	if (val & O_FSYNC)
		printf(", synchronous writes");
#endif

	putchar('\n');
	exit(0);
}
