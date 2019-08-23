/*
创建一个子进程
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
        // sleep(1);
        printf("此时位于子进程内：子进程的pid为%u，父进程的pid为%u\n",getpid(),getppid());
    }
    else
    {
        printf("此时位于父进程内：父进程的pid为%u，父进程的pid为%u\n",getpid(),pid);
    }
    
    return 0;
}