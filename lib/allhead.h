#ifndef _ALLHEAD_H
#define _ALLHEAD_H

#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <dirent.h>

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <linux/input.h>

extern int showfullpicture(int bmpfd);
extern int open_touchscreen();
extern int touch_screen(int *xpoint, int *ypoint);
extern int close_touchscreen();
extern int input_inf(char *txtpath);
extern int showanybmp(int x, int y, int w, int h, int bmpfd);
extern int enter_menu(char *txtpath);
extern void keyboard();
extern void keyboard2();
extern void keyboard3();
extern load();
extern struct sell *sellInit();
extern int sell_insert(struct sell *head, char name[15], int num, int exp);
extern int selllist_Init(struct sell *head);
extern struct sell *search_point(struct sell *head, char name[15]);
extern int buy1(int x, int y, struct sell *head, struct sell *p);
extern int buy2(int x, int y, struct sell *head, struct sell *p);
extern int pay(struct sell *head, struct sell *p);
extern int show_num1(struct sell *head, struct sell *p);
extern int show_num2(struct sell *head, struct sell *p);
extern int show_final(struct sell *head, struct sell *p, int discount);
extern int wirte_final(struct sell *head, struct sell *p, char *vip);
extern int full_goods(struct sell *head, struct sell *p);
extern int empty_goods(struct sell *head, struct sell *p);
extern int change_price(struct sell *head, struct sell *p);
extern int exchange(struct sell *head, struct sell *p, struct sell *q);
extern int comput_pass(struct sell *head, struct sell *p);
extern int sellname_init();
extern int init_goodsbmp();
extern int list_all_del(struct sell *head);
extern int last_num_init(struct sell *head, struct sell *p);
extern int off_the_shelf(struct sell *head, struct sell *p, struct sell *q);
extern int exchange_use(struct sell *head, struct sell *p, struct sell *q);
extern int full_all_goods(struct sell *head,struct sell *p);
extern int del_account();

extern int enter;
extern char buf[50];
extern int *lcdpoint, lcdfd;
extern int bmpfd[30];
extern char *sellname[10];
extern char usetemp[10][50];

struct sell
{
    char name[15];
    int num;
    int exp;
    int pass_num;
    int last_num;
    struct sell *next;
};

#endif
