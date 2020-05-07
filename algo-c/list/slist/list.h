/*************************************************************
 Date: 2020年 05月 04日 星期一 14:02:30 CST
 Author: rogerg6
 File: list.h
 Description:
*************************************************************/
#define MAXITEMS 100	// 链表最大项个数

// 结点
typedef struct node {
	int val;			// 值
	struct node *next;	// 指向下一个结点的指针
}Node;

typedef struct list {
	struct node *head;	// 指向链表的头指针
	int cnt;			// 链表中元素的个数
}List;


List * init_list(void);
void add_item(int val, List *list);
int delete_item(int val, List *list);
void insert_item(int val, List *list);
void clear_list(List *list);
void display_list(List *list);

