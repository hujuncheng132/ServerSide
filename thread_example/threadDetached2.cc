/*
在创建线程之后，再将其进行分离
*/
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

void* tfun(void* arg)
{
    printf("在创建线程之后，再将线程设置成分离状态\n");
    return NULL;
}

int main()
{
    int iRet;
    pthread_t tid; //线程id

    iRet = pthread_create(&tid,NULL,tfun,NULL);
    if(iRet)
    {
         printf("线程create失败，错误代码iRet=%d\n",iRet);
        return iRet;
    }

    iRet = pthread_detach(tid); //在线程创建之后，将线程设置成分离状态
    if(iRet)
    {
         printf("线程分离失败，错误代码iRet=%d\n",iRet);
        return iRet;
    }

    iRet = pthread_join(tid,NULL); // 由于前面在线程创建之后，又将子线程的设置为分离状态，因此这里再调用join会失败
    if(iRet)
    {
         printf("子线程已经被分离，主线程join失败，错误代码iRet=%d\n",iRet);
        return iRet;
    }

    printf("主线程结束\n");

    return 0;
}