/**
 * @file umask.c
 * @author apue.3e
 * @brief 与每个进程相关联的文件模式创建屏蔽字
 * @version 0.1
 * @date 2022-07-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int
main(void)
{
	/**
	 * @brief umask()函数为进程设置文件模式创建屏蔽字，并返回之前的值
	 * @param cmask mode_t 0
	 * @return mode_t
	 */
	umask(0); 
	if (creat("foo", RWRWRW) < 0)
		err_sys("creat error for foo");
	/**
	 * @brief 
	 * 与每个文件相关联的9个访问权限位对应9个常量
	 * cmask由9个常量中的若干个按位或构成
	 */
	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (creat("bar", RWRWRW) < 0)
		err_sys("creat error for bar");
	exit(0);
}
