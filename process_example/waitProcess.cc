/*
使用wait回收子进程并且利用WEXITSTATUS获得子进程的返回码
*/

#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("创建子进程错误\n");
        exit(-1);        
    }
    else if(pid > 0)
    {
        printf("此时位于父进程内：父进程的pid为%u，子进程的pid为%u\n",getpid(),pid);
        int status=-1; //子进程的状态返回码
        pid_t subpid = wait(&status); //调用wait函数获取子进程的状态返回码
        if(WIFEXITED(status)) //WIFEXITED(status)宏用于指出子进程是否为正常退出，当返回非零时表示正常退出
        {
            printf("子进程 pid=%d 正常退出！\n",subpid);
            printf("子进程的状态返回码为 %d\n",WEXITSTATUS(status)); // 可用WEXITSTATUS(status)获得子进程的返回码
        }
        else
        {
            printf("子进程 pid=%d 异常退出！\n",subpid);
        }
    }
    else
    {
        printf("此时位于子进程内：子进程的pid为%u，父进程的pid为%u\n",getpid(),getppid());
        sleep(3);
        exit(3);
    }
    
    return 0;
}