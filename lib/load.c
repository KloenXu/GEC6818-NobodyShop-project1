#include "allhead.h"
int *lcdpoint, lcdfd;
int bmpfd[30] = {0};
/*load  -  将所有用到的文件打开
  如:所有bmp图片
     触摸屏驱动文件
     液晶屏驱动文件
     液晶屏映射*/
int load()
{
    //打开触摸屏
    open_touchscreen();

    //打开液晶屏的驱动
    lcdfd = open("/dev/fb0", O_RDWR);
    if (lcdfd == -1)
    {
        perror("打开lcd失败\n");
        return -1;
    }

    //映射得到lcd在内存中的首地址
    lcdpoint = mmap(NULL, 800 * 480 * 4, PROT_READ | PROT_WRITE, MAP_SHARED, lcdfd, 0);
    if (lcdpoint == NULL)
    {
        perror("映射lcd失败\n");
        return -1;
    }

    bmpfd[0] = open("/project1/bmp/false.bmp", O_RDWR);
    //bmpfd[1] = open("/project1/bmp/menu.bmp", O_RDWR);
    bmpfd[2] = open("/project1/bmp/sign.bmp", O_RDWR);
    bmpfd[3] = open("/project1/bmp/login.bmp", O_RDWR);
    bmpfd[4] = open("/project1/bmp/shop1.bmp", O_RDWR);
    bmpfd[5] = open("/project1/bmp/signfalse.bmp", O_RDWR);
    bmpfd[6] = open("/project1/bmp/pay.bmp", O_RDWR);
    bmpfd[7] = open("/project1/bmp/shop2.bmp", O_RDWR);
    bmpfd[8] = open("/project1/bmp/money.bmp", O_RDWR);
    bmpfd[9] = open("/project1/bmp/sign1.bmp", O_RDWR);
    bmpfd[10] = open("/project1/bmp/nokeyboard.bmp", O_RDWR);
    bmpfd[11] = open("/project1/bmp/finishpay.bmp", O_RDWR);
    bmpfd[22] = open("/project1/bmp/manage.bmp", O_RDWR);

    bmpfd[12] = open("/project1/bmp/cokecola.bmp", O_RDWR);
    bmpfd[13] = open("/project1/bmp/spirit.bmp", O_RDWR);
    bmpfd[14] = open("/project1/bmp/Vinda.bmp", O_RDWR);
    bmpfd[15] = open("/project1/bmp/Vitalenmon.bmp", O_RDWR);
    bmpfd[16] = open("/project1/bmp/pesicola.bmp", O_RDWR);
    bmpfd[17] = open("/project1/bmp/sevenup.bmp", O_RDWR);
    bmpfd[18] = open("/project1/bmp/Mirinda.bmp", O_RDWR);
    bmpfd[19] = open("/project1/bmp/sunlenmon.bmp", O_RDWR);
    bmpfd[20] = open("/project1/bmp/noodle.bmp", O_RDWR);
    bmpfd[21] = open("/project1/bmp/ice.bmp", O_RDWR);
    // bmpfd[22]在上面
    bmpfd[23] = open("/project1/bmp/add.bmp", O_RDWR);
    bmpfd[24] = open("/project1/bmp/cut.bmp", O_RDWR);
    bmpfd[25] = open("/project1/bmp/change.bmp", O_RDWR);
    bmpfd[26] = open("/project1/bmp/goback.bmp", O_RDWR);
    return 0;
}

/*
  init_goodsbmp  -  关闭所有商品的图片后再重新按照初始化的顺序打开
*/
int init_goodsbmp()
{
    int i;
    for (i = 0; i <= 9; i++)
        close(bmpfd[12 + i]);
    bmpfd[12] = open("/project1/bmp/cokecola.bmp", O_RDWR);
    bmpfd[13] = open("/project1/bmp/spirit.bmp", O_RDWR);
    bmpfd[14] = open("/project1/bmp/Vinda.bmp", O_RDWR);
    bmpfd[15] = open("/project1/bmp/Vitalenmon.bmp", O_RDWR);
    bmpfd[16] = open("/project1/bmp/pesicola.bmp", O_RDWR);
    bmpfd[17] = open("/project1/bmp/sevenup.bmp", O_RDWR);
    bmpfd[18] = open("/project1/bmp/Mirinda.bmp", O_RDWR);
    bmpfd[19] = open("/project1/bmp/sunlenmon.bmp", O_RDWR);
    bmpfd[20] = open("/project1/bmp/noodle.bmp", O_RDWR);
    bmpfd[21] = open("/project1/bmp/ice.bmp", O_RDWR);
    return 0;
}