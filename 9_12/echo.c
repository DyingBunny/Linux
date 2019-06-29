/*这是一个环境变量的演示程序，演示如何在代码最终获取环境变量并且还要演示一下环境变量的全局特性*/

#include <stdio.h>
#include <unistd.h>
/*
int main(int argc,char *argv[],char *env[])
{
    int i=0;
    for(i=0;env[i]!=NULL;i++)
    {
	printf("env:[%s]\n",env[i]);
    }
    return 0;
}
*/
//通过全局变量来获取环境变量
int main()
{
    extern char **environ;
    int i;
    for(i=0;environ[i]!=NULL;i++)
    {
	printf("env:[%s]\n",environ[i]);
    }
    return 0;
}

