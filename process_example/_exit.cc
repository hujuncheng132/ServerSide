#include<unistd.h>
#include<stdio.h>

int main()
{
    printf("使用_exit()退出\n");
    printf("_exit退出前刷新了数据流");
    _exit(0);
}