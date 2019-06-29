/*这是一个回顾标准c库文件中IO的demo
 * fopen f close fseek fwrite fread fprintf
 */

#include <stdio.h>
#include <string.h>
/*int main()
{
    FILE *fp=NULL;

    fp=fopen("./test.txt","w+");
    if(fp==NULL)
    {
	printf("fopen error\n");
	return -1;
    }
    char *ptr="apple!\n";
    fwrite(ptr,strlen(ptr),1,fp);
    fseek(fp,-10,SEEK_CUR);

    char buff[1024]={0};
    fread(buff,1024,1,fp);
    printf("buff:[%s]\n",buff);
    
    fclose(fp);
    return 0;
}
*/

/*int main(const char *pathname,int flags,mode_t mode)
pathname 要打开的文件名
flags: 选项标志
0_RDONLY只读
0_WRONLY只写
0_RDWR读写

0_CREAT 文件不存在则创建，否则就打开
0_EXCL与0_CREAT同用，若文件存在则报错
0_TRUNC 打开文件的同时，清空文件原有内容
0_APPEND追加
mode 文件权限，用于创建文件的时候
*/
int fd=-1;
fd=open("./tmp.txt",0_RDWR|0_CREAT,0777)
if(fd<0)
{
    perror("open error");
    return -1;
}
//sszie_t_write(int fd,const void *buf,size_t count);
//fd:文件描述符
//buf要写如的数据
//count要写入的数据长度
//返回值 实际写入的数据长度
char *ptr="an apple\n";
ssize_t wlen=write(fd,ptr,strlen(ptr));
if(wlen<0)
{
    perror("write error");
    return -1;
}

//off_t lseek(int fd,off_t offset,int whence);
//fd:文件描述符
//offset 偏移值
//










