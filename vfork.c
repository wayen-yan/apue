
/*
 vfork创建一个新进程，此新进程用于exec一个新程序。
 子进程在调用exec或者exit之前，在父进程空间运行。
 vfork保证子进程先运行，在它调用exec或者exit后父进程才可能被调度运行。如果子进程
 在调用这两个函数之前，依赖于父进程的进一步动作，则会导致死锁。
 
 */



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int  glob = 6;

int main(void)
{
	int var;
	pid_t pid;

	var =99;

	printf("before fork !\n");   //标准io，不会冲洗到标准输出

	if((pid = vfork()) < 0 ){
		printf("fork error !\n");
	}else if(pid == 0){    //子进程，修改参数
		glob++;
		var++;
		_exit(0);
	}

	printf(" pid == %d, glob == %d, var == %d\n", getpid(), glob, var);

	exit(0);
		

}
