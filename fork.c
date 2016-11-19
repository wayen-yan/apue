/*
 fork被调用一个返回两次，子进程返回为0,父进程返回子进程的进程ID，
 子进程和父进程继续执行fork之后的指令，子进程是父进程的副本,子进程获得父进程数据
 空间、堆和栈的副本。但是子进程先执行还是父进程先执行是不确定的。
 write函数不带缓冲，printf函数属于标准I/O，带缓冲。
 当以交互式执行此程序时，printf输出一次;将输出重定向到文件时，输出两次
  
 
 */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int  glob = 6;
char buf[] = "a write to stdout\n";

int main(void)
{
	int var;
	pid_t pid;

	var =99;
	if(write( STDOUT_FILENO, buf , sizeof(buf) - 1) != sizeof(buf) - 1)
		printf("write error !\n");

	printf("before fork !\n");   //标准io，不会冲洗到标准输出

	if((pid = fork()) < 0 ){
		printf("fork error !\n");
	}else if(pid == 0){    //子进程，修改参数
		glob++;
		var++;
	}else{
		sleep(2);   //父进程
	}

	printf(" pid == %d, glob == %d, var == %d\n", getpid(), glob, var);

	exit(0);
		

}
