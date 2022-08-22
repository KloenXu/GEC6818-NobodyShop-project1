#include "allhead.h"
/*showfullpicture  -  用于全屏显示图片 
  bmpfd            -  图像的文件描述符*/
int showfullpicture(int bmpfd)
{
    //int bmpfd = bmp_fd;
    int i;
    int x = 0, y = 0;//最终效果为从(0,0)开始打印图片,但是实际上是从最后一行479行开始往上打印图片
    char bmpbuf[800 * 480 * 3] = {0};
    int lcdbuf[800 * 480] = {0};

    //跳过图片最前面的54字节的头信息
    lseek(bmpfd, 54, SEEK_SET);

    //从第55字节开始读取
    read(bmpfd, bmpbuf, 800 * 480 * 3);

    //把三个字节的BGR数据转换成四个字节ARGB
    for (i = 0; i < 800 * 480; i++)
    {
        lcdbuf[i] = 0x00 << 24 | bmpbuf[3 * i + 2] << 16 | bmpbuf[3 * i + 1] << 8 | bmpbuf[3 * i];
    }

    //把图片每一行像素点拷贝到液晶屏对应的位置
    for (i = 0; i < 480; i++)
    {
        memcpy(lcdpoint + (y + 479 - i) * 800 + x, &lcdbuf[i * 800], 800 * 4); //最终效果为从(0,0)开始打
    }                                                                          //印图片,实际为从最后一行
                                                                               //开始向首行打印图片
    //close(bmpfd);
    return 0;
}