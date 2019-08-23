/*
在创建线程之前，就将它的状态设置为分离状态
*/
#include<pthread.h>
#include<stdio.h>

void* tfun(void* arg)
{
    printf("在创建线程之前，就将线程的属性设置为分离状态\n");
    return NULL;
}

int main()
{
    int iRet;
    pthread_t tid; //线程id
    pthread_attr_t attr; //线程属性
    iRet = pthread_attr_init(&attr); //线程属性初始化函数，必须在pthread_create函数之前调用
    if(iRet)
    {
         printf("线程属性初始化失败，错误代码iRet=%d\n",iRet);
        return iRet;
    }
    iRet = pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED); //将线程的属性设置成分离状态
    if(iRet)
    {
         printf("线程分离状态属性设置失败，错误代码iRet=%d\n",iRet);
        return iRet;
    }

    iRet = pthread_create(&tid,&attr,tfun,NULL);
    if(iRet)
    {
         printf("线程create失败，错误代码iRet=%d\n",iRet);
        return iRet;
    }

    iRet = pthread_join(tid,NULL); // 由于前面在线程创建之前，将子线程的设置为分离状态，因此这里再调用join会失败
    if(iRet)
    {
         printf("子线程已经被分离，主线程join失败，错误代码iRet=%d\n",iRet);
        return iRet;
    }

    return 0;
}