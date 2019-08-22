/*
线程的创建与结束
*/
#include<stdio.h>
#include<pthread.h>
#include<string>

// say_hello1函数是线程的运行函数，返回值和参数都是void*,即返回通用指针，输入通用指针
void* say_hello1(void* args)
{
    printf("你好，线程\n");
    pthread_exit((void*)1); // 线程函数的返回代码是1（在线程函数中调用pthread_exit,以便返回值能被主线程接收）
}

// 如果线程调用的函数是在一个类中，应该把该函数写成静态成员函数
class Hello
{
    static void* say_hello(void* args)
    {
        printf("你好，线程\n");
        pthread_exit((void*)1); // 线程函数的返回代码是1（在线程函数中调用pthread_exit,以便返回值能被主线程接收）
    }
};

// say_hello2函数用来展现如何在线程调用函数时传递一个int参数
void* say_hello2(void* args)
{
    int i = *(int*)args; //将参数的通用指针转为int指针并解引用该指针得到线程传递给函数的int参数
    printf("你好，线程,传递进入函数的参数是%d\n",i);
    pthread_exit((void*)1); // 线程函数的返回代码是1（在线程函数中调用pthread_exit,以便返回值能被主线程接收）
}

struct arg_type
{
    int a;
    std::string s;
};

// say_hello3函数用来展现如何在线程调用函数时传递一个结构体
void* say_hello3(void* args)
{
    arg_type arg_temp = *(arg_type*)args; //将参数的通用指针转为arg_type指针并解引用该指针得到线程传递给函数的arg_type结构体参数
    printf("你好，线程,传递进入函数的参数是一个结构体：arg_temp.a=%d,arg_temp.s=%s\n",arg_temp.a,(arg_temp.s).c_str());
    pthread_exit((void*)1); // 线程函数的返回代码是1（在线程函数中调用pthread_exit,以便返回值能被主线程接收）
}


// say_hello4函数是线程的运行函数，返回值和参数都是void*,即返回通用指针，输入通用指针
void* say_hello4(void* args)
{
    printf("你好，线程,第四个线程的线程id是%lu\n",pthread_self()); //pthread_self()用来获得线程id
    pthread_exit((void*)1); // 线程函数的返回代码是1（在线程函数中调用pthread_exit,以便返回值能被主线程接收）
}

int main()
{
    /*
    创建子线程1
    */
    pthread_t tid1;
    // 创建线程函数传入的参数依次是创建的线程id,线程参数，调用函数名，传入的函数参数
    int iRet = pthread_create(&tid1,NULL,say_hello1,NULL);
    if(iRet)
    {
        printf("线程create失败，错误代码iRet=%d\n",iRet);
        return iRet;
    }

   /*
    创建子线程2（用于展示如何在线程调用函数时传入参数）
    */
    pthread_t tid2;
    int para = 10;
    // 创建线程函数传入的参数依次是创建的线程id,线程参数，调用函数名，传入的函数参数
    iRet = pthread_create(&tid2,NULL,say_hello2,&para);
    if(iRet)
    {
        printf("线程create失败，错误代码iRet=%d\n",iRet);
        return iRet;
    }

    /*
    创建子线程3（用于展示如何在线程调用函数时传入结构体参数）
    */
    pthread_t tid3;
    arg_type arg_temp;
    arg_temp.a = 10;
    arg_temp.s = "结构体参数";
    // 创建线程函数传入的参数依次是创建的线程id,线程参数，调用函数名，传入的函数参数
    iRet = pthread_create(&tid3,NULL,say_hello3,&arg_temp);
    if(iRet)
    {
        printf("线程create失败，错误代码iRet=%d\n",iRet);
        return iRet;
    }

    /*
    创建子线程4（用于获取线程id）
    */
    pthread_t tid4;
    // 创建线程函数传入的参数依次是创建的线程id,线程参数，调用函数名，传入的函数参数
    iRet = pthread_create(&tid4,NULL,say_hello4,NULL);
    if(iRet)
    {
        printf("线程create失败，错误代码iRet=%d\n",iRet);
        return iRet;
    }
    
    /*
    主线程等待子线程
    */
    void* retval1;//用于存储被等待线程的返回值，在这里是指线程运行函数say_hello函数的返回值，也就是线程函数退出时返回的1
    iRet = pthread_join(tid1,&retval1); // 主线程等待子线程退出，主线程处于阻塞状态（调用pthread_join函数，获取线程的返回值）
    if(iRet)
    {
        printf("线程join失败，错误代码iRet=%d\n",iRet);
        return iRet;
    }
    printf("被等待的子线程结束之后，返回给主线程的值retval1是:%ld\n",(long)retval1);

    void* retval2;//用于存储被等待线程的返回值，在这里是指线程运行函数say_hello函数的返回值，也就是线程函数退出时返回的1
    iRet = pthread_join(tid2,&retval2); // 主线程等待子线程退出，主线程处于阻塞状态（调用pthread_join函数，获取线程的返回值）
    if(iRet)
    {
        printf("线程join失败，错误代码iRet=%d\n",iRet);
        return iRet;
    }
    printf("被等待的子线程结束之后，返回给主线程的值retval2是:%ld\n",(long)retval2);

    void* retval3;//用于存储被等待线程的返回值，在这里是指线程运行函数say_hello函数的返回值，也就是线程函数退出时返回的1
    iRet = pthread_join(tid3,&retval3); // 主线程等待子线程退出，主线程处于阻塞状态（调用pthread_join函数，获取线程的返回值）
    if(iRet)
    {
        printf("线程join失败，错误代码iRet=%d\n",iRet);
        return iRet;
    }
    printf("被等待的子线程结束之后，返回给主线程的值retval3是:%ld\n",(long)retval3);

    printf("第四个线程的线程id是%lu\n",tid4);
    void* retval4;//用于存储被等待线程的返回值，在这里是指线程运行函数say_hello函数的返回值，也就是线程函数退出时返回的1
    iRet = pthread_join(tid4,&retval4); // 主线程等待子线程退出，主线程处于阻塞状态（调用pthread_join函数，获取线程的返回值）
    if(iRet)
    {
        printf("线程join失败，错误代码iRet=%d\n",iRet);
        return iRet;
    }
    printf("被等待的子线程结束之后，返回给主线程的值retval1是:%ld\n",(long)retval1);
   
    return 0;

}