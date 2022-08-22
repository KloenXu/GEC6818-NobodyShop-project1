#include "allhead.h"

/*
  full_goods  -  将货物补充为20个
  head          -  头结点
  p             -  用于操作的结点
*/
int full_goods(struct sell *head, struct sell *p)
{
    int x = 0, y = 0;
    touch_screen(&x, &y);
    if (x >= 380 && x <= 430 && y >= 25 && y <= 135)
    {
        printf("cokecola补货\n");
        p = search_point(head, "cokecola");
        p->last_num = 20;
    }
    else if (x >= 480 && x <= 530 && y >= 25 && y <= 135)
    {
        printf("spirit补货\n");
        p = search_point(head, "spirit");
        p->last_num = 20;
    }
    else if (x >= 580 && x <= 630 && y >= 25 && y <= 135)
    {
        printf("Vinda补货\n");
        p = search_point(head, "Vinda");
        p->last_num = 20;
    }
    else if (x >= 680 && x <= 730 && y >= 25 && y <= 135)
    {
        printf("Vitalenmon补货\n");
        p = search_point(head, "Vitalenmon");
        p->last_num = 20;
    }

    else if (x >= 380 && x <= 430 && y >= 175 && y <= 285)
    {
        printf("pesicola补货\n");
        p = search_point(head, "pesicola");
        p->last_num = 20;
    }
    else if (x >= 480 && x <= 530 && y >= 175 && y <= 285)
    {
        printf("sevenup补货\n");
        p = search_point(head, "sevenup");
        p->last_num = 20;
    }
    else if (x >= 580 && x <= 630 && y >= 175 && y <= 285)
    {
        printf("Mirinda补货\n");
        p = search_point(head, "Mirinda");
        p->last_num = 20;
    }
    else if (x >= 680 && x <= 730 && y >= 175 && y <= 285)
    {
        printf("sunlenmon补货\n");
        p = search_point(head, "sunlenmon");
        p->last_num = 20;
    }

    else if (x >= 380 && x <= 430 && y >= 325 && y <= 435)
    {
        printf("noodle补货\n");
        p = search_point(head, "noodle");
        p->last_num = 20;
    }
    else if (x >= 480 && x <= 530 && y >= 325 && y <= 435)
    {
        printf("ice补货\n");
        p = search_point(head, "ice");
        p->last_num = 20;
    }
    return 0;
}

/*
  full_goods  -  将货物补充为20个
  head          -  头结点
  p             -  用于操作的结点
*/
int full_all_goods(struct sell *head, struct sell *p)
{
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
        p->last_num = 20;
    }
    return 0;
}

/*
  empty_goods  -  将货物清空为0个
  head          -  头结点
  p             -  用于操作的结点
*/
int empty_goods(struct sell *head, struct sell *p)
{
    int x = 0, y = 0;
    touch_screen(&x, &y);
    if (x >= 380 && x <= 430 && y >= 25 && y <= 135)
    {
        printf("cokecola清货\n");
        p = search_point(head, "cokecola");
        p->last_num = 0;
    }
    else if (x >= 480 && x <= 530 && y >= 25 && y <= 135)
    {
        printf("spirit清货\n");
        p = search_point(head, "spirit");
        p->last_num = 0;
    }
    else if (x >= 580 && x <= 630 && y >= 25 && y <= 135)
    {
        printf("Vinda清货\n");
        p = search_point(head, "Vinda");
        p->last_num = 0;
    }
    else if (x >= 680 && x <= 730 && y >= 25 && y <= 135)
    {
        printf("Vitalenmon清货\n");
        p = search_point(head, "Vitalenmon");
        p->last_num = 0;
    }

    else if (x >= 380 && x <= 430 && y >= 175 && y <= 285)
    {
        printf("pesicola清货\n");
        p = search_point(head, "pesicola");
        p->last_num = 0;
    }
    else if (x >= 480 && x <= 530 && y >= 175 && y <= 285)
    {
        printf("sevenup清货\n");
        p = search_point(head, "sevenup");
        p->last_num = 0;
    }
    else if (x >= 580 && x <= 630 && y >= 175 && y <= 285)
    {
        printf("Mirinda清货\n");
        p = search_point(head, "Mirinda");
        p->last_num = 0;
    }
    else if (x >= 680 && x <= 730 && y >= 175 && y <= 285)
    {
        printf("sunlenmon清货\n");
        p = search_point(head, "sunlenmon");
        p->last_num = 0;
    }

    else if (x >= 380 && x <= 430 && y >= 325 && y <= 435)
    {
        printf("noodle清货\n");
        p = search_point(head, "noodle");
        p->last_num = 0;
    }
    else if (x >= 480 && x <= 530 && y >= 325 && y <= 435)
    {
        printf("ice清货\n");
        p = search_point(head, "ice");
        p->last_num = 0;
    }
    return 0;
}

/*
  change_price  -  改变商品的价格
  head          -  头结点
  p             -  用于操作的结点
*/
int change_price(struct sell *head, struct sell *p)
{
    p = head->next;
    int x = 0, y = 0, new_price = 0;
    touch_screen(&x, &y);
    if (x >= 380 && x <= 430 && y >= 25 && y <= 135)
    {
        p = search_point(head, "cokecola");
        Display_characterX(400, 140, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 480 && x <= 530 && y >= 25 && y <= 135)
    {
        p = search_point(head, "spirit");
        Display_characterX(500, 140, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 580 && x <= 630 && y >= 25 && y <= 135)
    {
        p = search_point(head, "Vinda");
        Display_characterX(600, 140, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 680 && x <= 730 && y >= 25 && y <= 135)
    {
        p = search_point(head, "Vitalenmon");
        Display_characterX(700, 140, "1", 0x00FF0000, 1); //显示字体
    }

    else if (x >= 380 && x <= 430 && y >= 175 && y <= 285)
    {
        p = search_point(head, "pesicola");
        Display_characterX(400, 290, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 480 && x <= 530 && y >= 175 && y <= 285)
    {
        p = search_point(head, "sevenup");
        Display_characterX(500, 290, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 580 && x <= 630 && y >= 175 && y <= 285)
    {
        p = search_point(head, "Mirinda");
        Display_characterX(600, 290, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 680 && x <= 730 && y >= 175 && y <= 285)
    {
        p = search_point(head, "sunlenmon");
        Display_characterX(700, 290, "1", 0x00FF0000, 1); //显示字体
    }

    else if (x >= 380 && x <= 430 && y >= 325 && y <= 435)
    {
        p = search_point(head, "noodle");
        Display_characterX(400, 430, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 480 && x <= 530 && y >= 325 && y <= 435)
    {
        p = search_point(head, "icd");
        Display_characterX(500, 430, "1", 0x00FF0000, 1); //显示字体
    }

    keyboard2();

    new_price = atoi(buf);
    p->exp = new_price;

    return 0;
}

/*
  exchange  -  将两个商品交换位置
  head      -  头结点
  p         -  用于操作的结点
  q         -  用于操作的结点
*/
int exchange(struct sell *head, struct sell *p, struct sell *q)
{
    clear_num(head, p);
    p = head->next;
    q = head->next;
    struct sell *r = head->next;
    int x = 0, y = 0, i, j = 0, k = 0;
    int temp_num = 0, temp_exp = 0, temp_fd = 0, temp_allnum = 0;
    char temp_name[15] = {0};
    char *temp_sellname;

    touch_screen(&x, &y);
    if (x >= 380 && x <= 430 && y >= 25 && y <= 135)
    {
        p = search_point(head, "cokecola");
        Display_characterX(400, 140, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 480 && x <= 530 && y >= 25 && y <= 135)
    {
        p = search_point(head, "spirit");
        Display_characterX(500, 140, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 580 && x <= 630 && y >= 25 && y <= 135)
    {
        p = search_point(head, "Vinda");
        Display_characterX(600, 140, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 680 && x <= 730 && y >= 25 && y <= 135)
    {
        p = search_point(head, "Vitalenmon");
        Display_characterX(700, 140, "1", 0x00FF0000, 1); //显示字体
    }

    else if (x >= 380 && x <= 430 && y >= 175 && y <= 285)
    {
        p = search_point(head, "pesicola");
        Display_characterX(400, 290, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 480 && x <= 530 && y >= 175 && y <= 285)
    {
        p = search_point(head, "sevenup");
        Display_characterX(500, 290, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 580 && x <= 630 && y >= 175 && y <= 285)
    {
        p = search_point(head, "Mirinda");
        Display_characterX(600, 290, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 680 && x <= 730 && y >= 175 && y <= 285)
    {
        p = search_point(head, "sunlenmon");
        Display_characterX(700, 290, "1", 0x00FF0000, 1); //显示字体
    }

    else if (x >= 380 && x <= 430 && y >= 325 && y <= 435)
    {
        p = search_point(head, "noodle");
        Display_characterX(400, 430, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 480 && x <= 530 && y >= 325 && y <= 435)
    {
        p = search_point(head, "ice");
        Display_characterX(500, 430, "1", 0x00FF0000, 1); //显示字体
    }

    touch_screen(&x, &y);
    if (x >= 380 && x <= 430 && y >= 25 && y <= 135)
    {
        q = search_point(head, "cokecola");
        Display_characterX(400, 140, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 480 && x <= 530 && y >= 25 && y <= 135)
    {
        q = search_point(head, "spirit");
        Display_characterX(500, 140, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 580 && x <= 630 && y >= 25 && y <= 135)
    {
        q = search_point(head, "Vinda");
        Display_characterX(600, 140, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 680 && x <= 730 && y >= 25 && y <= 135)
    {
        q = search_point(head, "Vitalenmon");
        Display_characterX(700, 140, "1", 0x00FF0000, 1); //显示字体
    }

    else if (x >= 380 && x <= 430 && y >= 175 && y <= 285)
    {
        q = search_point(head, "pesicola");
        Display_characterX(400, 290, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 480 && x <= 530 && y >= 175 && y <= 285)
    {
        q = search_point(head, "sevenup");
        Display_characterX(500, 290, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 580 && x <= 630 && y >= 175 && y <= 285)
    {
        q = search_point(head, "Mirinda");
        Display_characterX(600, 290, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 680 && x <= 730 && y >= 175 && y <= 285)
    {
        q = search_point(head, "sunlenmon");
        Display_characterX(700, 290, "1", 0x00FF0000, 1); //显示字体
    }

    else if (x >= 380 && x <= 430 && y >= 325 && y <= 435)
    {
        q = search_point(head, "noodle");
        Display_characterX(400, 430, "1", 0x00FF0000, 1); //显示字体
    }
    else if (x >= 480 && x <= 530 && y >= 325 && y <= 435)
    {
        q = search_point(head, "ice");
        Display_characterX(500, 430, "1", 0x00FF0000, 1); //显示字体
    }

    while (strcmp(r->name, p->name) != 0)
    {
        r = r->next;
        j++;
    }
    printf("%d\n", j);
    r = head->next;
    while (strcmp(r->name, q->name) != 0)
    {
        r = r->next;
        k++;
    }
    printf("%d\n", k);

    temp_exp = p->exp;
    p->exp = q->exp;
    q->exp = temp_exp;

    temp_num = p->num;
    p->num = q->num;
    q->num = temp_num;

    strcpy(temp_name, p->name);
    strcpy(p->name, q->name);
    strcpy(q->name, temp_name);

    temp_fd = bmpfd[12 + j];
    bmpfd[12 + j] = bmpfd[12 + k];
    bmpfd[12 + k] = temp_fd;

    temp_sellname = sellname[j];
    sellname[j] = sellname[k];
    sellname[k] = temp_sellname;

    temp_allnum = p->last_num;
    p->last_num = q->last_num;
    q->last_num = temp_allnum;

    return 0;
}

/*
  exchange  -  将两个商品交换位置
  head      -  头结点
  p         -  用于操作的结点
  q         -  用于操作的结点
*/
int exchange_use(struct sell *head, struct sell *p, struct sell *q)
{
    struct sell *p1;
    clear_num(head, p1);
    struct sell *r = head->next;
    int x = 0, y = 0, j = 0, k = 0;
    int temp_num = 0, temp_exp = 0, temp_fd = 0, temp_allnum = 0;
    char temp_name[15] = {0};
    char *temp_sellname;

    while (strcmp(r->name, p->name) != 0)
    {
        r = r->next;
        j++;
    }
    printf("%d\n", j);
    r = head->next;
    while (strcmp(r->name, q->name) != 0)
    {
        r = r->next;
        k++;
    }
    printf("%d\n", k);

    temp_exp = p->exp;
    p->exp = q->exp;
    q->exp = temp_exp;

    temp_num = p->num;
    p->num = q->num;
    q->num = temp_num;

    strcpy(temp_name, p->name);
    strcpy(p->name, q->name);
    strcpy(q->name, temp_name);

    temp_fd = bmpfd[12 + j];
    bmpfd[12 + j] = bmpfd[12 + k];
    bmpfd[12 + k] = temp_fd;

    temp_sellname = sellname[j];
    sellname[j] = sellname[k];
    sellname[k] = temp_sellname;

    temp_allnum = p->last_num;
    p->last_num = q->last_num;
    q->last_num = temp_allnum;

    return 0;
}

/*
  off_the_shelf  -  下架商品,实际作用是把该商品对应的结点放到链表最后位置
  head           -  头结点
  p              -  用于操作的结点
  q              -  用于操作的结点
*/
int off_the_shelf(struct sell *head, struct sell *p, struct sell *q)
{
    int x = 0, y = 0;
    p = head;
    q = head;
    touch_screen(&x, &y);
    if (x >= 380 && x <= 430 && y >= 25 && y <= 135)
        p = search_point(head, "cokecola");
    else if (x >= 480 && x <= 530 && y >= 25 && y <= 135)
        p = search_point(head, "spirit");
    else if (x >= 580 && x <= 630 && y >= 25 && y <= 135)
        p = search_point(head, "Vinda");
    else if (x >= 680 && x <= 730 && y >= 25 && y <= 135)
        p = search_point(head, "Vitalenmon");

    else if (x >= 380 && x <= 430 && y >= 175 && y <= 285)
        p = search_point(head, "pesicola");
    else if (x >= 480 && x <= 530 && y >= 175 && y <= 285)
        p = search_point(head, "sevenup");
    else if (x >= 580 && x <= 630 && y >= 175 && y <= 285)
        p = search_point(head, "Mirinda");
    else if (x >= 680 && x <= 730 && y >= 175 && y <= 285)
        p = search_point(head, "sunlenmon");

    else if (x >= 380 && x <= 430 && y >= 325 && y <= 435)
        p = search_point(head, "noodle");
    else if (x >= 480 && x <= 530 && y >= 325 && y <= 435)
        p = search_point(head, "ice");

    if (p->next == NULL)
        q = p;
    else
        q = p->next;
    while (q != NULL)
    {
        exchange_use(head, p, q);
        p = p->next;
        q = q->next;
    }
    return 0;
}

/*
  del_account  -  删除账号
*/
int del_account()
{
    char del_account[50] = {0};
    char del_taget[10] = {0};
    char save[50] = {0};
    int del_len, line = 0, line_temp;
    int i;
    system("touch temp.txt");
    chmod("temp.txt", 0777);
    FILE *txtfile1;
    txtfile1 = fopen("inf.txt", "r+");
    if (txtfile1 == NULL)
    {
        perror("open txt fail\n");
        return -1;
    }

    FILE *txtfile2;
    txtfile2 = fopen("temp.txt", "r+");
    if (txtfile2 == NULL)
    {
        perror("open txt fail\n");
        return -1;
    }

    keyboard3();

    while (1)
    {
        fgets(del_account, sizeof(del_account), txtfile1);
        strcpy(save, del_account);
        line++;
        del_len = strlen(del_account);
        if (feof(txtfile1) == 1)
        {
            break;
        }
        strcpy(del_taget, strtok(del_account, "@"));
        if (strcmp(buf, del_taget) == 0)
            continue;
        fputs(save, txtfile2);
    }

    fclose(txtfile1);

    rewind(txtfile2);

    FILE *txtfile3;
    txtfile3 = fopen("inf.txt", "w+");
    if (txtfile3 == NULL)
    {
        perror("open txt fail\n");
        return -1;
    }
    while (1)
    {
        fgets(del_account, sizeof(del_account), txtfile2);
        strcpy(save, del_account);
        if (feof(txtfile2) == 1)
        {
            break;
        }
        fputs(save, txtfile3);
    }

    fclose(txtfile2);
    fclose(txtfile3);
    system("rm temp.txt");
    return 0;
}