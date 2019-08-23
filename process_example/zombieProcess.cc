/*
僵尸进程
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    pid_t pid; //进程标识符，本质上就是一个无符号整型的类型别名
    pid = fork(); //创建一个子进程,并返回子进程的PID
    if(pid < 0)
    {
        perror("创建子进程错误\n");
        exit(-1);        
    }
    else if(pid == 0)
    {
        printf("在父进程中随眠3秒，等待子进程先退出\n");
        sleep(10); 
        printf("父进程退出\n");
    }
    else
    {
        printf("子进程通过exit()退出\n");
        exit(0);
    }
    
    return 0;
}