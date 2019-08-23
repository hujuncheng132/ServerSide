/*
父子进程共享资源：代码段共享，子进程会复制一份父进程的数据段和堆栈段，独立进行操作
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int global = 1; //全局变量，存储在数据段

int main()
{
    int stack = 2; //局部变量，存储在栈中
    int *heap; //指针变量存储在栈中
    heap = (int*)malloc(sizeof(int)); //指针变量指向一个堆变量
    *heap = 3; //通过指针将堆变量的值设为3
    pid_t pid;
    pid = fork();
    if(pid < 0)
    {
        perror("创建子进程错误\n");
        exit(-1);
    }
    else if(pid == 0)
    {
        //在子进程中改变这些变量
        ++global;
        ++stack;
        ++(*heap);
        printf("在子进程中，这边变量改变后的值为global=%d，stack=%d,heap=%d\n",global,stack,*heap);
    }
    else
    {
        sleep(2); //休眠2秒，确保子进程先执行完
        printf("在父进程中，这边变量的值为global=%d，stack=%d,heap=%d\n",global,stack,*heap);
    }
    
}