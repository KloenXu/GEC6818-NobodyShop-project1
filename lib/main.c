#include "allhead.h"
#include "font.h"
// struct sell *head; //设为全局变量

/*  编译命令(带上字库)
    arm-linux-gcc *.c -o main -L ./ -lfont
*/
int main(int argc, char *argv[])
{
    int x, y, page = 1, time = 0, flag = 0, discount = 0, ret = 0;
    // int x, y, page = 5, time = 2, flag = 0, discount = 0, ret = 0;
    char vip[10] = {0};
    Init_Font(); //初始化字库

    load(); //打开各种文件驱动

    struct sell *head = sellInit();
    selllist_Init(head);
    struct sell *p;
    struct sell *q;

    while (1)
    {
        comput_pass(head, p);
        if (page == 1) //登录页面
        {
            while (1)
            {
                showfullpicture(bmpfd[10]);
                if (time > 0)
                {
                    showanybmp(738, 1, 60, 130, bmpfd[26]);
                }
                usleep(100000);
                touch_screen(&x, &y);
                if (x >= 450 && x <= 600 && y >= 350 && y <= 415) //进入注册,往记事本写入账号密码
                {
                    showfullpicture(bmpfd[3]);
                    showanybmp(125, 90, 500, 120, bmpfd[2]);
                    Display_characterX(395, 210, "please touch account", 0x00FF0000, 2);  //显示字体
                    Display_characterX(395, 260, "and password to input", 0x00FF0000, 2); //显示字体
                    input_inf("/project1/inf.txt");
                    sleep(1);
                    showfullpicture(bmpfd[10]);
                }
                else if (x >= 625 && x <= 775 && y >= 350 && y <= 415) //登陆键
                {
                    showfullpicture(bmpfd[3]);
                    Display_characterX(395, 210, "please touch account", 0x00FF0000, 2);  //显示字体
                    Display_characterX(395, 260, "and password to input", 0x00FF0000, 2); //显示字体
                    flag = enter_menu("/project1/inf.txt");
                    if (flag == 1)
                    {
                        printf("VIP登录\n");
                        strcpy(vip, "vip");
                        discount = 1;
                        time++;
                        page = 2;
                        flag = 0;
                        break; //账号密码正确打断该循环进入下一个页面
                    }
                    else if (flag == 2)
                    {
                        flag = 0;
                        showanybmp(125, 90, 500, 120, bmpfd[0]);
                        sleep(1);
                    }
                    else if (flag == 3)
                    {
                        printf("管理员登录\n");
                        if (time == 0)
                        {
                            strcpy(vip, "manager");
                            time++;
                            page = 2;
                            flag = 0;
                            break;
                        }
                        time++;
                        page = 5;
                        flag = 0;
                        break;
                    }
                }
                else if (x >= 738 && x <= 798 && y >= 1 && y <= 130 && time > 0)
                {
                    page = 2;
                    break;
                }
            }
        }

        else if (page == 2) //点单页面1,第二个页面(点单)
        {
            while (1)
            {
                showfullpicture(bmpfd[4]);
                if (strcmp(vip, "vip") == 0)
                    Display_characterX(720, 0, vip, 0x00FFD700, 2); //显示字体 720 680 685
                else if (strcmp(vip, "manager") == 0)
                    Display_characterX(680, 0, vip, 0x00FFD700, 2);
                else
                    Display_characterX(685, 0, "no vip", 0x00FFD700, 2);
                show_num1(head, p);
                usleep(100000);
                touch_screen(&x, &y);
                if (x >= 1 && x <= 135 && y >= 1 && y <= 75)
                {
                    page = 1; //回到第一页
                    break;
                }
                else if (x >= 1 && x <= 135 && y >= 400 && y <= 478)
                {
                    page = 4; //进入结账页面
                    break;
                }
                else if (x >= 690 && x <= 798 && y >= 430 && y <= 478)
                {
                    page = 3; //进入点单页面2
                    break;
                }
                else if (x >= 1 && x <= 130 && y >= 195 && y <= 260) //数量清零键
                {
                    clear_num(head, p);
                }
                buy1(x, y, head, p);
            }
        }

        else if (page == 3) //点单页面2,第三个页面(点单)
        {
            while (1)
            {
                showfullpicture(bmpfd[7]);
                if (strcmp(vip, "vip") == 0)
                    Display_characterX(720, 0, vip, 0x00FFD700, 2); //显示字体 720 680 685
                else if (strcmp(vip, "no vip") == 0)
                    Display_characterX(685, 0, vip, 0x00FFD700, 2);
                else if (strcmp(vip, "manager") == 0)
                    Display_characterX(680, 0, vip, 0x00FFD700, 2);
                show_num2(head, p);
                touch_screen(&x, &y);
                if (x >= 1 && x <= 135 && y >= 1 && y <= 75)
                {
                    page = 1; //回到登录页面
                    break;
                }
                else if (x >= 1 && x <= 135 && y >= 400 && y <= 478)
                {
                    page = 4; //进入结账页面
                    break;
                }
                else if (x >= 690 && x <= 799 && y >= 430 && y <= 478)
                {
                    page = 2; //进入点单页面2
                    break;
                }
                else if (x >= 1 && x <= 130 && y >= 195 && y <= 260) //数量清零键
                {
                    clear_num(head, p);
                }
                buy2(x, y, head, p);
            }
        }

        else if (page == 4) //第四个页面(结账)
        {
            showfullpicture(bmpfd[6]);
            usleep(100000);
            printf("\n");
            pay(head, p);
            while (1)
            {
                if (strcmp(vip, "vip") == 0)
                {
                    Display_characterX(665, 10, "you are", 0x00FFD700, 2);
                    Display_characterX(665, 60, "vip!!!!", 0x00FFD700, 2);
                    Display_characterX(665, 110, "have 20%", 0x00FFD700, 2);
                    Display_characterX(665, 160, "discount", 0x00FFD700, 2);
                    Display_characterX(665, 210, "Price is", 0x00FFD700, 2);
                    Display_characterX(665, 260, "integer", 0x00FFD700, 2);
                }
                show_final(head, p, discount);
                touch_screen(&x, &y);
                if (x >= 1 && x <= 135 && y >= 1 && y <= 75)
                {
                    page = 2; //进入点单页面2
                    break;
                }
                else if (x >= 1 && x <= 135 && y >= 305 && y <= 390)
                {
                    while (1)
                    {
                        showanybmp(135, 75, 400, 400, bmpfd[8]); //付款二维码
                        showanybmp(660, 0, 140, 75, bmpfd[11]);  //完成支付,将数量清零
                        touch_screen(&x, &y);
                        if (x >= 1 && x <= 135 && y >= 391 && y <= 478) //关闭付款二维码,再次回到结账
                        {
                            page = 4;
                            break;
                        }
                        else if (x >= 660 && x <= 799 && y >= 1 && y <= 75) //完成支付
                        {
                            ret = wirte_final(head, p, vip);
                            clear_num(head, p);
                            page = 2;
                            discount = 0;
                            if (ret == 0)
                                strcpy(vip, "no vip");
                            break;
                        }
                        break;
                    }
                    break;
                }
            }
        }

        else if (page == 5) //管理页面
        {
            while (1)
            {
                showfullpicture(bmpfd[22]);
                touch_screen(&x, &y);
                if (x >= 600 && x <= 799 && y >= 385 && y <= 479) //回到点单
                {
                    page = 2;
                    break;
                }
                else if (x >= 25 && x <= 85 && y >= 20 && y <= 75)
                {
                    printf("点击了单个补货\n");
                    Display_characterX(60, 60, "1", 0x00FF0000, 1); //显示字体
                    full_goods(head, p);
                    wirte_final(head, p, vip);
                    showanybmp(125, 90, 500, 120, bmpfd[23]);
                    sleep(1);
                    break;
                }
                else if (x >= 90 && x <= 150 && y >= 20 && y <= 75)
                {
                    printf("点击了全部补货\n");
                    Display_characterX(130, 60, "1", 0x00FF0000, 1); //显示字体
                    full_all_goods(head, p);
                    wirte_final(head, p, vip);
                    showanybmp(125, 90, 500, 120, bmpfd[23]);
                    sleep(1);
                    break;
                }
                else if (x >= 25 && x <= 150 && y >= 85 && y <= 145)
                {
                    printf("点击了清货\n");
                    Display_characterX(110, 105, "1", 0x00FF0000, 1); //显示字体
                    empty_goods(head, p);
                    wirte_final(head, p, vip);
                    showanybmp(125, 90, 500, 120, bmpfd[24]);
                    sleep(1);
                    break;
                }
                else if (x >= 170 && x <= 230 && y >= 20 && y <= 75)
                {
                    printf("点击了修改价格\n");
                    Display_characterX(215, 60, "1", 0x00FF0000, 1); //显示字体
                    change_price(head, p);
                    wirte_final(head, p, vip);
                    showanybmp(125, 90, 500, 120, bmpfd[25]);
                    sleep(1);
                    break;
                }
                else if (x >= 170 && x <= 300 && y >= 85 && y <= 145)
                {
                    printf("点击了交换货品\n");
                    Display_characterX(280, 105, "1", 0x00FF0000, 1); //显示字体
                    exchange(head, p, q);
                    wirte_final(head, p, vip);
                    break;
                }
                else if (x >= 775 && x <= 798 && y >= 1 && y <= 85)
                {
                    printf("点击了初始化\n");
                    last_num_init(head, p);
                    sellname_init();
                    clear_num(head, p);
                    init_goodsbmp();
                    system("cp 1.txt first.txt");
                    list_all_del(head);
                    selllist_Init(head);
                    page = 2;
                    break;
                }
                else if (x >= 170 && x <= 300 && y >= 150 && y <= 200)
                {
                    printf("点击了删除货品\n");
                    Display_characterX(280, 170, "1", 0x00FF0000, 1); //显示字体
                    off_the_shelf(head, p, q);
                    wirte_final(head, p, vip);
                    break;
                }
                else if (x >= 235 && x <= 300 && y >= 20 && y <= 75)
                {
                    printf("点击了删除账号\n");
                    Display_characterX(280, 60, "1", 0x00FF0000, 1);             //显示字体
                    Display_characterX(530, 320, "del account:", 0x00FF0000, 2); //显示字体
                    del_account();
                    break;
                }
            }
        }
    }

    close_touchscreen();

    //解除字库
    UnInit_Font();

    munmap(lcdpoint, 800 * 480 * 4);
    return 0;
}