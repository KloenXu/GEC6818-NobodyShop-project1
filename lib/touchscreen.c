#include "allhead.h"

int tsfd;//触摸屏的文件描述符

/*open_touchscreen  -  打开触摸屏的函数*/
int open_touchscreen()
{
	//打开触摸屏的驱动
	tsfd=open("/dev/input/event0",O_RDWR);
	if(tsfd==-1)
	{
		perror("打开触摸屏失败!\n");
		return -1;
	}
	return 0;
}

/*touch_screen  -  触发一次触摸屏的函数
  *xpoint       -  用于表示横坐标的指针
  *ypoint       -  用于表示纵坐标的指针*/
int touch_screen(int *xpoint,int *ypoint)
{
	int flag = 0;
	struct input_event myevent;

	while(1)
	{
		//读取触摸屏点击的坐标位置  阻塞
		read(tsfd,&myevent,sizeof(myevent));
		if(myevent.type==EV_ABS)  //说明确实是触摸屏的驱动
		{
			if(myevent.code==ABS_X) //说明是x坐标
			{
				*xpoint = myevent.value;
				flag=1;
			}
			if(flag == 1 && myevent.code==ABS_Y) //说明是y坐标
			{
				*ypoint = myevent.value;
				flag=2;
			}
			if(flag == 2)
			{
				flag = 0;
				break;
			}
		}
	}

	return 0;
}

/*close_touchscreen  -  关闭触摸屏的函数*/
int close_touchscreen()
{
	//关闭触摸屏
	close(tsfd);
	return 0;
}