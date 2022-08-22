#include "allhead.h"
/*showanybmp  -  在指定位置显示任意大小的bmp图片
	x         -  图片左上角的位置坐标
	y         -  图片左上角的位置坐标
	w		  -  图片实际的宽
	h 		  -  图片实际的高
	bmpfd 	  -  图片的文件描述符
*/
int showanybmp(int x, int y, int w, int h,int bmpfd)
{
	//int bmpfd = bmp_fd;
	int i;

	int w_change;
	w_change = w;
	while (w_change % 4 != 0)
	{
		w_change++;
	}

	//定义数组存放你读取到的bmp图片的颜色值
	char bmpbuf[w_change * h * 3];
	//定义数组存放转换得到的ARGB数据
	int lcdbuf[w_change * h]; // int类型数据占4个字节

	//跳过图片最前面的54字节的头信息
	lseek(bmpfd, 54, SEEK_SET);

	//从第55字节开始读取
	read(bmpfd, bmpbuf, w_change * h * 3);

	//把三个字节的BGR数据转换成四个字节ARGB
	for (i = 0; i < w_change * h; i++)
		lcdbuf[i] = 0x00 << 24 | bmpbuf[3 * i + 2] << 16 | bmpbuf[3 * i + 1] << 8 | bmpbuf[3 * i];

	//把图片每一行像素点拷贝到液晶屏对应的位置
	for (i = 0; i < h; i++)
		memcpy(lcdpoint + (y + h -1 - i) * 800 + x, &lcdbuf[i * w_change], w * 4);

	//关闭
	//close(bmpfd);
	//解除映射
	//munmap(lcdpoint, 800 * 480 * 4);
	return 0;
}