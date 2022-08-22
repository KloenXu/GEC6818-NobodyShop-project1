#include "allhead.h"
char buf[50] = {0};
int enter = 0;
/*keyboard  -  键盘函数
  用于注册与登录时的键盘*/
void keyboard()
{
    bzero(buf, sizeof(buf));
    char show;
    int len = 0, flag = 0, x = 0, y = 0;
    while (1)
    {
        x = 0;
        y = 0;
        flag = 0;
        usleep(100000);
        touch_screen(&x, &y);
        if (len <= 5)
        {
            if (x >= 15 && x <= 70 && y >= 220 && y <= 275)
                buf[len] = '1';
            else if (x >= 80 && x <= 135 && y >= 220 && y <= 275)
                buf[len] = '2';
            else if (x >= 145 && x <= 200 && y >= 220 && y <= 275)
                buf[len] = '3';
            else if (x >= 210 && x <= 265 && y >= 220 && y <= 275)
                buf[len] = '4';

            else if (x >= 15 && x <= 70 && y >= 285 && y <= 340)
                buf[len] = '5';
            else if (x >= 80 && x <= 135 && y >= 285 && y <= 340)
                buf[len] = '6';
            else if (x >= 145 && x <= 200 && y >= 285 && y <= 340)
                buf[len] = '7';
            else if (x >= 210 && x <= 265 && y >= 285 && y <= 340)
                buf[len] = '8';

            else if (x >= 15 && x <= 70 && y >= 350 && y <= 405)
                buf[len] = '9';
            else if (x >= 80 && x <= 135 && y >= 350 && y <= 405)
                buf[len] = '0';
            else if (x >= 145 && x <= 200 && y >= 350 && y <= 405)
                buf[len] = 'A';
            else if (x >= 210 && x <= 265 && y >= 350 && y <= 405)
                buf[len] = 'B';

            else if (x >= 15 && x <= 70 && y >= 415 && y <= 470)
                buf[len] = 'C';
            else if (x >= 80 && x <= 135 && y >= 415 && y <= 470)
                buf[len] = 'D';
            else if (x >= 145 && x <= 200 && y >= 415 && y <= 470)
                buf[len] = 'E';
            else if (x >= 210 && x <= 265 && y >= 415 && y <= 470)
                buf[len] = 'F';

            else if (x >= 300 && x <= 390 && y >= 400 && y <= 445)
            {
                printf("\n你按了退格键\n");
                flag = 1;
                buf[len] = '\0';
                len--;
                x = 0;
                y = 0;
                if (len < 0)
                {
                    len = 0;
                }
            }
            else if (x >= 310 && x <= 365 && y >= 255 && y <= 365)
            {
                enter = 1;
                printf("\n你按了回车键");
                break; //右边的回车键
            }
            else
                continue;
        }
        if (x >= 300 && x <= 390 && y >= 400 && y <= 445)
        {
            printf("\n你按了退格键\n");
            flag = 1;
            buf[len] = '\0';
            len--;
            x = 0;
            y = 0;
            if (len < 0)
            {
                len = 0;
            }
        }
        else if (x >= 310 && x <= 365 && y >= 255 && y <= 365)
        {
            enter = 1;
            printf("\n你按了回车键");
            break; //右边的回车键
        }
        // enter为0时是在输入账号栏的字符,为1时在输入密码栏的字符,在account.c中会给enter做置0
        if (flag == 0 && enter == 0)
        {
            printf("%c", buf[len]); //到时候可能需要改成字符串%s
            fflush(stdout);
            Clean_Area(245, 107, 300, 27, 0xFFFFFFFF);        //清除区域
            Display_characterX(240, 105, buf, 0x00FF0000, 2); //显示字体
            len++;
        }
        else if (flag == 1 && enter == 0)
        {
            printf("%c", buf[len]); //到时候可能需要改成字符串%s
            fflush(stdout);
            Clean_Area(245, 107, 300, 27, 0xFFFFFFFF);        //清除区域
            Display_characterX(240, 105, buf, 0x00FF0000, 2); //显示字体
            flag = 0;
        }
        else if (flag == 0 && enter == 1)
        {
            printf("%c", buf[len]); //到时候可能需要改成字符串%s
            fflush(stdout);
            Clean_Area(245, 169, 300, 23, 0xFFFFFFFF);        //清除区域
            Display_characterX(240, 165, buf, 0x00FF0000, 2); //显示字体
            len++;
        }
        else if (flag == 1 && enter == 1)
        {
            printf("%c", buf[len]); //到时候可能需要改成字符串%s
            fflush(stdout);
            Clean_Area(245, 169, 300, 23, 0xFFFFFFFF);        //清除区域
            Display_characterX(240, 165, buf, 0x00FF0000, 2); //显示字体
            flag = 0;
        }
    }
    printf("\n");
}

void keyboard2()
{
    bzero(buf, sizeof(buf));
    char show;
    int len = 0, x = 0, y = 0;
    while (1)
    {
        x = 0;
        y = 0;
        usleep(100000);
        touch_screen(&x, &y);
        if (x >= 15 && x <= 70 && y >= 220 && y <= 275)
            buf[len] = '1';
        else if (x >= 80 && x <= 135 && y >= 220 && y <= 275)
            buf[len] = '2';
        else if (x >= 145 && x <= 200 && y >= 220 && y <= 275)
            buf[len] = '3';
        else if (x >= 210 && x <= 265 && y >= 220 && y <= 275)
            buf[len] = '4';

        else if (x >= 15 && x <= 70 && y >= 285 && y <= 340)
            buf[len] = '5';
        else if (x >= 80 && x <= 135 && y >= 285 && y <= 340)
            buf[len] = '6';
        else if (x >= 145 && x <= 200 && y >= 285 && y <= 340)
            buf[len] = '7';
        else if (x >= 210 && x <= 265 && y >= 285 && y <= 340)
            buf[len] = '8';

        else if (x >= 15 && x <= 70 && y >= 350 && y <= 405)
            buf[len] = '9';
        else if (x >= 80 && x <= 135 && y >= 350 && y <= 405)
            buf[len] = '0';

        else if (x >= 275 && x <= 365 && y >= 420 && y <= 470)
        {
            printf("\n你按了退格键\n");
            buf[len] = '\0';
            len--;
            x = 0;
            y = 0;
            if (len < 0)
            {
                len = 0;
            }
        }
        else if (x >= 280 && x <= 335 && y >= 275 && y <= 385)
        {
            printf("\n你按了回车键");
            break; //右边的回车键
        }
        else
            continue;
        Clean_Area(125, 160, 45, 40, 0xFFFFFFFF);
        Display_characterX(125, 160, buf, 0x00FF0000, 3); //显示字体
    }
    printf("\n");
}

void keyboard3()
{
    bzero(buf, sizeof(buf));
    char show;
    int len = 0, x = 0, y = 0, flag = 0;
    while (1)
    {
        flag = 0;
        x = 0;
        y = 0;
        usleep(100000);
        touch_screen(&x, &y);
        if (x >= 15 && x <= 70 && y >= 220 && y <= 275)
            buf[len] = '1';
        else if (x >= 80 && x <= 135 && y >= 220 && y <= 275)
            buf[len] = '2';
        else if (x >= 145 && x <= 200 && y >= 220 && y <= 275)
            buf[len] = '3';
        else if (x >= 210 && x <= 265 && y >= 220 && y <= 275)
            buf[len] = '4';

        else if (x >= 15 && x <= 70 && y >= 285 && y <= 340)
            buf[len] = '5';
        else if (x >= 80 && x <= 135 && y >= 285 && y <= 340)
            buf[len] = '6';
        else if (x >= 145 && x <= 200 && y >= 285 && y <= 340)
            buf[len] = '7';
        else if (x >= 210 && x <= 265 && y >= 285 && y <= 340)
            buf[len] = '8';

        else if (x >= 15 && x <= 70 && y >= 350 && y <= 405)
            buf[len] = '9';
        else if (x >= 80 && x <= 135 && y >= 350 && y <= 405)
            buf[len] = '0';
        else if (x >= 145 && x <= 200 && y >= 350 && y <= 405)
            buf[len] = 'A';
        else if (x >= 210 && x <= 265 && y >= 350 && y <= 405)
            buf[len] = 'B';

        else if (x >= 15 && x <= 70 && y >= 415 && y <= 470)
            buf[len] = 'C';
        else if (x >= 80 && x <= 135 && y >= 415 && y <= 470)
            buf[len] = 'D';
        else if (x >= 145 && x <= 200 && y >= 415 && y <= 470)
            buf[len] = 'E';
        else if (x >= 210 && x <= 265 && y >= 415 && y <= 470)
            buf[len] = 'F';
        else if (x >= 275 && x <= 365 && y >= 420 && y <= 470)
        {
            printf("\n你按了退格键\n");
            buf[len] = '\0';
            len--;
            x = 0;
            y = 0;
            if (len < 0)
            {
                len = 0;
            }
            flag = 1;
        }
        else if (x >= 280 && x <= 335 && y >= 275 && y <= 385)
        {
            printf("\n你按了回车键");
            break; //右边的回车键
        }
        else
            continue;
        if (flag == 0)
            len++;
        Clean_Area(720, 320, 78, 65, 0xFFFFFFFF);
        Display_characterX(718, 320, buf, 0x00FF0000, 2); //显示字体
    }
    printf("\n");
}