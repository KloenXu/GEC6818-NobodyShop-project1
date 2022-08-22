#include "allhead.h"
#define N 50

/*char *sellname[10] = {"cokecola", "spirit", "Vinda", "Vitalenmon", "pesicola",
                      "sevenup", "Mirinda", "sunlenmon", "noodle", "ice"};*/
char *sellname[10];
char usetemp[10][50];

struct sell *sellInit()
{
    struct sell *head = malloc(sizeof(struct sell));
    head->next = NULL;
    strcpy(head->name, "商品信息");
    head->num = 0;
    head->exp = 0;
    head->pass_num = 0;
    head->last_num = 0;
    return head;
}

int printlinklist(struct sell *head)
{
    struct sell *p1 = head->next;
    while (p1 != NULL)
    {
        printf("%s\n", p1->name);
        p1 = p1->next;
    }
    return 0;
}

/*sell_insert  -  单个结点尾插
  head 头结点
  name[10] 商品名称
  num 商品数量
  exp 单价*/
int sell_insert(struct sell *head, char *name, int num, int exp)
{
    struct sell *newnode = malloc(sizeof(struct sell));
    newnode->next = NULL;
    strcpy(newnode->name, name);
    newnode->num = num;
    newnode->exp = exp;
    newnode->pass_num = 0;
    newnode->last_num = 20;

    struct sell *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newnode;
    return 0;
}

/*selllist_Init  -  将所有商品尾插至头结点后
  head           -  头结点*/
int selllist_Init(struct sell *head)
{
    char save[50];
    int num2;
    struct sell *p = head;
    char result[50] = {0};
    char *num;
    char *price;
    int num1, price1, sellname_num = 0;
    FILE *txtfile;
    txtfile = fopen("/project1/first.txt", "r+");
    if (txtfile == NULL)
    {
        perror("open txt fail\n");
        return -1;
    }
    /*for (i = 0; i <= 9; i++)
    {
        fgets(result, sizeof(result), txtfile);
        strtok(result, "@");
        num = strtok(NULL, "@");
        num1 = atoi(num);
        price = strtok(NULL, "@");
        price1 = atoi(price);
        printf("%s\n", sellname[i]);
        sell_insert(head, sellname[i], 0, price1);
    }*/
    while (1)
    {
        fgets(result, sizeof(result), txtfile);
        if (feof(txtfile) == 1)
            break;
        strcpy(save, result);
        strcpy(usetemp[sellname_num], strtok(save, "@"));
        sellname[sellname_num] = usetemp[sellname_num];
        strtok(NULL, "@");
        price = strtok(NULL, "@");
        price1 = atoi(price);
        sell_insert(head, sellname[sellname_num], 0, price1);
        sellname_num++;
    }
    fclose(txtfile);
    return 0;
}

/*search_point  -  以数据域中的name来搜索结点
  head          -  头结点
  name          -  数据域中的name*/
struct sell *search_point(struct sell *head, char name[15])
{
    struct sell *p = head->next;
    while (strcmp(p->name, name) != 0)
    {
        p = p->next;
    }
    return p;
}

/*buy1  -  商品页面第一页的按钮及其功能
  x     -  按钮横坐标
  y     -  按钮纵坐标
  head  -  链表的头结点
  p     -  结点,用于表示各个商品的属性*/
int buy1(int x, int y, struct sell *head, struct sell *p)
{
    if (x >= 145 && x <= 195 && y >= 290 && y <= 340) //第一个的减少键
    {
        printf("1\n");
        printf("%s\n", sellname[0]);
        p = search_point(head, sellname[0]);
        p->num--;
        if (p->num < 0)
            p->num = 0;
        printf("%s的数量:%d\n", p->name, p->num);
    }
    else if (x >= 295 && x <= 345 && y >= 290 && y <= 340) //第二个的减少键
    {
        p = search_point(head, sellname[1]);
        p->num--;
        if (p->num < 0)
            p->num = 0;
        printf("%s的数量:%d\n", p->name, p->num);
    }
    else if (x >= 445 && x <= 495 && y >= 290 && y <= 340) //第三个的减少键
    {
        p = search_point(head, sellname[2]);
        p->num--;
        if (p->num < 0)
            p->num = 0;
        printf("%s的数量:%d\n", p->name, p->num);
    }
    else if (x >= 595 && x <= 645 && y >= 290 && y <= 340) //第四个的减少键
    {
        p = search_point(head, sellname[3]);
        p->num--;
        if (p->num < 0)
            p->num = 0;
        printf("%s的数量:%d\n", p->name, p->num);
    }

    else if (x >= 210 && x <= 260 && y >= 290 && y <= 340) //第一个的增加键
    {
        p = search_point(head, sellname[0]);
        p->num++;
        if (p->last_num - p->num < 0)
            p->num--;
        printf("%s的数量:%d\n", p->name, p->num);
    }
    else if (x >= 360 && x <= 410 && y >= 290 && y <= 340) //第二个的增加键
    {
        p = search_point(head, sellname[1]);
        p->num++;
        if (p->last_num - p->num < 0)
            p->num--;
        printf("%s的数量:%d\n", p->name, p->num);
    }
    else if (x >= 510 && x <= 560 && y >= 290 && y <= 340) //第三个的增加键
    {
        p = search_point(head, sellname[2]);
        p->num++;
        if (p->last_num - p->num < 0)
            p->num--;
        printf("%s的数量:%d\n", p->name, p->num);
    }
    else if (x >= 660 && x <= 710 && y >= 290 && y <= 340) //第四个的增加键
    {
        p = search_point(head, sellname[3]);
        p->num++;
        if (p->last_num - p->num < 0)
            p->num--;
        printf("%s的数量:%d\n", p->name, p->num);
    }
    return 0;
}

/*buy2  -  商品页面第二页的按钮及其功能
  x     -  按钮横坐标
  y     -  按钮纵坐标
  head  -  链表的头结点
  p     -  结点,用于表示各个商品的属性*/
int buy2(int x, int y, struct sell *head, struct sell *p)
{
    if (x >= 145 && x <= 195 && y >= 290 && y <= 370) //百事可乐的减少键
    {
        p = search_point(head, sellname[4]);
        p->num--;
        if (p->num < 0)
            p->num = 0;
        printf("%s的数量:%d\n", p->name, p->num);
    }
    else if (x >= 295 && x <= 345 && y >= 290 && y <= 370) //七喜的减少键
    {
        p = search_point(head, sellname[5]);
        p->num--;
        if (p->num < 0)
            p->num = 0;
        printf("%s的数量:%d\n", p->name, p->num);
    }
    else if (x >= 445 && x <= 495 && y >= 290 && y <= 370) //美年达的减少键
    {
        p = search_point(head, sellname[6]);
        p->num--;
        if (p->num < 0)
            p->num = 0;
        printf("%s的数量:%d\n", p->name, p->num);
    }
    else if (x >= 595 && x <= 645 && y >= 290 && y <= 370) //阳光的减少键
    {
        p = search_point(head, sellname[7]);
        p->num--;
        if (p->num < 0)
            p->num = 0;
        printf("%s的数量:%d\n", p->name, p->num);
    }

    else if (x >= 210 && x <= 260 && y >= 290 && y <= 370) //百事可乐的增加键
    {
        p = search_point(head, sellname[4]);
        p->num++;
        if (p->last_num - p->num < 0)
            p->num--;
        printf("%s的数量:%d\n", p->name, p->num);
    }
    else if (x >= 360 && x <= 410 && y >= 290 && y <= 370) //七喜的增加键
    {
        p = search_point(head, sellname[5]);
        p->num++;
        if (p->last_num - p->num < 0)
            p->num--;
        printf("%s的数量:%d\n", p->name, p->num);
    }
    else if (x >= 510 && x <= 560 && y >= 290 && y <= 370) //美年达的增加键
    {
        p = search_point(head, sellname[6]);
        p->num++;
        if (p->last_num - p->num < 0)
            p->num--;
        printf("%s的数量:%d\n", p->name, p->num);
    }
    else if (x >= 660 && x <= 710 && y >= 290 && y <= 370) //阳光的增加键
    {
        p = search_point(head, sellname[7]);
        p->num++;
        if (p->last_num - p->num < 0)
            p->num--;
        printf("%s的数量:%d\n", p->name, p->num);
    }
    return 0;
}

/*clear_num  -  商品页面左边的数量清零键,用于将商品的数量清零
  x          -  按钮横坐标
  y          -  按钮纵坐标
  head       -  链表的头结点
  p          -  结点,用于表示各个商品的属性*/
int clear_num(struct sell *head, struct sell *p)
{
    p = head->next;
    while (p != NULL)
    {
        p->num = 0;
        p = p->next;
    }
    printf("已清零\n");
    return 0;
}

/*pay  -  显示总共购买的商品以及价格
  head -  链表的头结点
  p    -  结点,用于表示商品的属性*/
int pay(struct sell *head, struct sell *p)
{
    int allpay = 0;
    p = head->next;
    while (p != NULL)
    {
        if (p->num != 0)
        {
            printf("%s单价为%d,该商品数量为%d,总价为%d\n", p->name, p->exp, p->num, (p->num) * (p->exp));
            allpay = allpay + (p->num) * (p->exp);
            p->last_num = p->last_num - p->num;
        }
        p = p->next;
    }
    printf("全部商品总价为:%d\n", allpay);
    return 0;
}

/*
  show_num1  -  下单页面1的显示
  head       -  头结点
  p          -  用于操作的结点
*/
int show_num1(struct sell *head, struct sell *p)
{
    p = head;
    int i;
    char str[10] = {0};
    for (i = 0; i <= 3; i++)
    {
        p = p->next;
        showanybmp(170 + i * 150, 140, 60, 130, bmpfd[12 + i]);
        sprintf(str, "num:%d", p->num);
        Display_characterX(145 + i * 150, 340, str, 0x00FF0000, 2); //显示字体
        sprintf(str, "price:%d", p->exp);
        Display_characterX(145 + i * 150, 390, str, 0x00FF0000, 2); //显示字体
        sprintf(str, "last:%d", p->last_num - p->num);
        Display_characterX(145 + i * 150, 100, str, 0x00FF0000, 2); //显示字体
        sprintf(str, "pass:%d", p->pass_num);
        Display_characterX(145 + i * 150, 50, str, 0x00FF0000, 2); //显示字体
    }
    return 0;
}

/*
  show_num2  -  下单页面2的显示
  head       -  头结点
  p          -  用于操作的结点
*/
int show_num2(struct sell *head, struct sell *p)
{
    p = head;
    while (strcmp(p->name, sellname[4]) != 0)
    {
        p = p->next;
    }
    int i;
    char str[10] = {0};

    for (i = 4; i <= 7; i++)
    {
        if (i != 4)
            p = p->next;
        showanybmp(170 + (i - 4) * 150, 140, 60, 130, bmpfd[12 + i]);
        sprintf(str, "num:%d", p->num);
        Display_characterX(145 + (i - 4) * 150, 340, str, 0x00FF0000, 2); //显示字体
        sprintf(str, "price:%d", p->exp);
        Display_characterX(145 + (i - 4) * 150, 390, str, 0x00FF0000, 2); //显示字体
        sprintf(str, "last:%d", p->last_num - p->num);
        Display_characterX(145 + (i - 4) * 150, 100, str, 0x00FF0000, 2); //显示字体
        sprintf(str, "pass:%d", p->pass_num);
        Display_characterX(145 + (i - 4) * 150, 50, str, 0x00FF0000, 2); //显示字体
    }
    return 0;
}

/*
  show_final  -  结账页面的显示
  head        -  头结点
  p           -  用于操作的结点
*/
int show_final(struct sell *head, struct sell *p, int discount)
{
    int i = 0, allpay = 0;
    char pay[5] = {0};
    char str[5] = {0};
    char result[50] = {0};
    p = head->next;
    while (p != NULL)
    {
        if (p->num != 0)
        {
            Display_characterX(135, 135 + (32 * i), p->name, 0x00FF0000, 3); //显示字体
            sprintf(str, "%d", p->exp);
            Display_characterX(460, 135 + (32 * i), str, 0x00FF0000, 3); //显示字体
            sprintf(str, "%d", p->num);
            Display_characterX(550, 135 + (32 * i), str, 0x00FF0000, 3); //显示字体
            i++;
            sprintf(result, "%s@%d@%d\n", p->name, p->exp, p->num);
        }
        allpay = allpay + p->exp * p->num;
        p = p->next;
    }
    if (discount == 1)
    {
        allpay = allpay * 0.8;
    }
    sprintf(pay, "%d", allpay);
    Display_characterX(660, 395, pay, 0x00FF0000, 5); //显示字体

    return 0;
}

/*
  wirte_final  -  确认付款后更改文件中记录的库存以及将购买记录写入文件
  head         -  头结点
  p            -  用于操作的结点
*/
int wirte_final(struct sell *head, struct sell *p, char *vip)
{
    int i = 0, record = 0;
    FILE *txtfile1;
    txtfile1 = fopen("/project1/record.txt", "a+");
    if (txtfile1 == NULL)
    {
        perror("open txt fail\n");
        return -1;
    }

    FILE *txtfile2;
    txtfile2 = fopen("/project1/first.txt", "r+");
    if (txtfile2 == NULL)
    {
        perror("open txt fail\n");
        return -1;
    }

    char result[50] = {0};
    p = head->next;
    while (p != NULL)
    {
        if (p->num != 0)
        {
            sprintf(result, "%s@%d@%d\n", p->name, p->num, p->exp);
            fputs(result, txtfile1);
            record = record + p->num * p->exp;
        }
        p = p->next;
    }

    if (record == 0)
    {
        fclose(txtfile1);
        fclose(txtfile2);
        return 1;
    }

    if (strcmp(vip, "vip") == 0)
    {
        record = 0.8 * record;
        sprintf(result, "vip:%d\n\n", record);
        fputs(result, txtfile1);
    }
    else
    {
        sprintf(result, "no vip:%d\n\n", record);
        fputs(result, txtfile1);
    }

    p = head->next;
    while (p != NULL)
    {
        sprintf(result, "%s@%d@%d\n", p->name, p->last_num, p->exp);
        fputs(result, txtfile2);
        i++;
        p = p->next;
    }

    fclose(txtfile1);
    fclose(txtfile2);
    return 0;
}

/*
  comput_pass  -  打开消费记录文本并计算各商品销量
  head         -  头结点
  p            -  用于操作的结点
*/
int comput_pass(struct sell *head, struct sell *p)
{
    char pass_result[N] = {0};
    char pass_result1[N] = {0};
    char *pass_name;
    char *pass_num;
    int pass_num1 = 0;
    FILE *txtfile;
    txtfile = fopen("/project1/record.txt", "r+");
    if (txtfile == NULL)
    {
        perror("open txt fail\n");
        return -1;
    }

    p = head;
    while (p->next != NULL)
    {
        p = p->next;
        p->pass_num = 0;
    }

    while (1)
    {
        fgets(pass_result, sizeof(pass_result), txtfile);
        strcpy(pass_result1, pass_result);
        if (feof(txtfile) == 1)
            break;
        pass_name = strtok(pass_result, "@");
        if (strcmp(pass_name, pass_result1) == 0 && strlen(pass_name) == strlen(pass_result1))
            continue;
        pass_num = strtok(NULL, "@");
        pass_num1 = atoi(pass_num);
        p = search_point(head, pass_name);
        p->pass_num = p->pass_num + pass_num1;
    }
    fclose(txtfile);
    return 0;
}

/*
  sellname_init  -  初始化商品名对应的数组位置
*/
int sellname_init()
{
    sellname[0] = "cokecola";
    sellname[1] = "spirit";
    sellname[2] = "Vinda";
    sellname[3] = "Vitalenmon";
    sellname[4] = "pesicola";
    sellname[5] = "sevenup";
    sellname[6] = "Mirinda";
    sellname[7] = "sunlenmon";
    sellname[8] = "noodle";
    sellname[9] = "ice";
    return 0;
}

/*
  list_all_del  -  将链表中除了头结点外所有结点全部删除
  head          -  头结点
*/
int list_all_del(struct sell *head)
{
    struct sell *p, *q;
    p = head;
    q = head->next;
    while (q->next != NULL)
    {
        p = head;
        q = head->next;
        while (q->next != NULL)
        {
            q = q->next;
            p = p->next;
        }
        p->next = NULL;
        free(q);
        q = head;
    }
    return 0;
}

/*
  last_num_init  -  初始化商品的剩余量,赋为20
  head           -  头结点
  p              -  用于操作的结点
*/
int last_num_init(struct sell *head, struct sell *p)
{
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
        p->last_num = 20;
    }
    return 0;
}