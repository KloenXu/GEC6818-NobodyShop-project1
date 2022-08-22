#include "allhead.h"

#define N 50
/*input_inf - 注册函数,将账号密码写入txt文件中,用"@"隔开
  txtpath   - txt文件的路径*/
int input_inf(char *txtpath)
{
    int x = 0, y = 0;
    char account[N] = {0};
    char passwd[N] = {0};
    char result[N] = {0};
    char *old_account;
    char *old_passwd;
    char old_result[N] = {0};

    FILE *txtfile;
    txtfile = fopen(txtpath, "a+");
    if (txtfile == NULL)
    {
        perror("open txt fail\n");
        return -1;
    }

    while (1)
    {
        Display_characterX(615, 115, "1", 0x00FF0000, 1); //显示字体
        touch_screen(&x, &y);
        if (x >= 245 && x <= 565 && y >= 105 && y <= 140)
        {
            printf("注册:请输入账号:");
            fflush(stdout);
            Display_characterX(620, 115, "1", 0x00FF0000, 1); //显示字体
            keyboard();
            strcpy(account, buf);
            break;
        }
    }

    while (1)
    {
        Display_characterX(615, 175, "1", 0x00FF0000, 1); //显示字体
        touch_screen(&x, &y);
        if (x >= 245 && x <= 565 && y >= 155 && y <= 190)
        {
            printf("注册:请输入密码:");
            fflush(stdout);
            Display_characterX(620, 175, "1", 0x00FF0000, 1); //显示字体
            keyboard();
            strcpy(passwd, buf);
            break;
        }
    }

    enter = 0; //让下一次回到账号密码处时从账号开始显示数据

    while (1)
    {
        fgets(old_result, sizeof(result), txtfile);
        if (feof(txtfile) == 1)
        {
            showanybmp(125, 90, 500, 120, bmpfd[9]);
            sleep(2);
            // return 0;
            break;
        }
        old_account = strtok(old_result, "@");
        old_passwd = strtok(NULL, "@");
        printf("%s\n", old_account);
        printf("%s\n", old_passwd);
        /*注册账户已存在时注册失败*/
        if (strncmp(account, old_account, strlen(account)) == 0 &&
            strlen(account) == strlen(old_account))
        {
            printf("该账号已经被注册\n");
            showanybmp(125, 90, 500, 120, bmpfd[5]);
            Display_characterX(620, 80, "This name", 0x00FF0000, 2);  //显示字体
            Display_characterX(620, 130, "has been", 0x00FF0000, 2);  //显示字体
            Display_characterX(620, 180, "signed up", 0x00FF0000, 2); //显示字体
            sleep(2);
            return 0;
            break;
        }
    }

    sprintf(result, "%s@%s\n", account, passwd);
    fputs(result, txtfile);
    fclose(txtfile);
    return 0;
}

/*enter_menu - 登录函数
  txtpath    - txt文件的路径*/
int enter_menu(char *txtpath)
{
    char account[N] = {0};
    char passwd[N] = {0};
    char result[N] = {0};
    char *now_account;
    char *now_passwd;
    int x = 0, y = 0;

    FILE *txtfile;
    txtfile = fopen(txtpath, "r+");
    if (txtfile == NULL)
    {
        perror("open txt fail\n");
        return -1;
    }

    rewind(txtfile); //将文件偏移值回到最开始的位置

    while (1)
    {
        Display_characterX(615, 115, "1", 0x00FF0000, 1); //显示字体
        touch_screen(&x, &y);
        if (x >= 240 && x <= 610 && y >= 100 && y <= 140)
        {
            printf("登录:请输入账号:");
            fflush(stdout);
            Display_characterX(620, 115, "1", 0x00FF0000, 1); //显示字体
            keyboard();
            strcpy(account, buf);
            break;
        }
    }

    while (1)
    {
        Display_characterX(615, 175, "1", 0x00FF0000, 1); //显示字体
        touch_screen(&x, &y);
        if (x >= 240 && x <= 610 && y >= 165 && y <= 200)
        {
            printf("登录:请输入密码:");
            fflush(stdout);
            Display_characterX(620, 175, "1", 0x00FF0000, 1); //显示字体
            keyboard();
            strcpy(passwd, buf);
            break;
        }
    }

    enter = 0; //让下一次回到账号密码处时从账号开始显示数据

    if (strlen(passwd) == 0 || strlen(account) == 0)
    {
        printf("账号或密码为空\n");
        return 2;
    }

    while (1)
    {
        fgets(result, sizeof(result), txtfile);
        if (feof(txtfile) == 1)
        {
            printf("账号或密码错误\n");
            return 2;
            break;
        }
        now_account = strtok(result, "@");
        now_passwd = strtok(NULL, "@");
        printf("%s\n", now_account);
        printf("%s\n", now_passwd);
        if ((strcmp(account, now_account) == 0) &&
            (strncmp(passwd, now_passwd, (strlen(now_passwd) - 1)) == 0) &&
            ((strlen(account)) == (strlen(now_account))) &&
            ((strlen(passwd)) == (strlen(now_passwd) - 1)))
        {
            if (strcmp(account, "A") != 0)
                return 1;
            if (strcmp(account, "A") == 0)
                return 3;
        }
    }

    fclose(txtfile);
    return 0;
}