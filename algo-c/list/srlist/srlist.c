/*************************************************************
 Date       : 2020年 05月 04日 星期一 12:44:25 CST
 Author     : rogerg6
 File       : srlist.c
 Description:
 	单向循环链表
*************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


// 初始化链表
List * init_list(void)
{
	List *list = (List *)malloc(sizeof(struct list));
	if (list == NULL) {
		fprintf(stderr, "ERROR: Can't alloc memory for list\n");
		exit(1);
	}
	list->cnt = 0;
	list->head = NULL;
	list->tail = NULL;

	printf("List is inited\n");

	return list;
}

// 链表为空
int is_empty(List *list)
{
	return list->cnt == 0 ? 1 : 0;
}

// 链表为满
int is_full(List *list)
{
	return list->cnt == MAXITEMS ? 1 : 0;
}

void num_items(List *list)
{
	printf("Total: %d item%c\n", list->cnt, list->cnt <= 1 ? ' ' : 's');
}
#if 0

// 添加元素至末尾
void add_item(int val, List *list)
{
	Node *cur, *pre, *item;

	if (is_full(list)) {
		printf("List is full\n");
		exit(1);
	}	

	item = malloc(sizeof(struct node));
	if (item == NULL) {
		fprintf(stderr, "ERROR: Can't alloc memory for item\n");
		exit(1);
	}
	item->val = val;
	item->next = NULL;

	// 加入
	for (cur = list->head; cur != NULL; pre = cur, cur = cur->next)
		;
	if (cur == list->head)
		list->head = item;
	else
		pre->next = item;
	list->cnt++;
	printf("Item %d is added\n", val);
}
#endif

// 删除元素
int delete_item(int val, List *list)
{
	Node *cur, *pre;

	if (is_empty(list)) {
		printf("List is emtpy\n");
		return 0;
	}

	for (cur = list->head, pre = cur; cur != NULL; pre = cur, cur = cur->next) {
		if (cur->val == val) {
			if (cur == list->head) {		// 第一个item
				list->head = cur->next;
				free(cur);
				list->tail = list->head;
			} else {
				pre->next = cur->next;
				free(cur);
			}
			list->cnt--;
			printf("Item %d is deleted\n", val);
			return 1;
		}

		// 无此val项
		if (cur == list->tail) {
			printf("There is no %d val item\n", val);
			return 0;
		}
	}
}

// 插入元素
void insert_item(int val, List *list)
{
	Node *item, *pre, *cur;

	if (is_full(list)) {
		printf("List is full\n");
		exit(1);
	}

	item = malloc(sizeof(struct node));
	if (item == NULL) {
		fprintf(stderr, "ERROR: Can't alloc memory for item\n");
		exit(1);
	}
	item->val = val;

	// 第一个元素
	if (list->cnt == 0) {
		list->head = item;
		list->tail = item;
		item->next = item;
		list->cnt++;
		printf("Insert successfully\n");
	} else {
		for (cur = list->head, pre = cur; cur != NULL; pre = cur, cur = cur->next) {		
			if (cur->val > val) {
				if (cur == list->head){		// 插在第一个node前 
					list->head = item;
					item->next = cur;
					list->tail->next = item;
				} else {					// 插在链表中间
					pre->next = item;
					item->next = cur;
				}
				list->cnt++;
				printf("Insert successfully\n");
				break;
			}

			// 到达链表末尾
			// 添加在list末尾
			if (cur == list->tail) {
				item->next = list->head;
				cur->next = item;
				list->tail = item;
				list->cnt++;
				printf("Insert successfully\n");
				break;
			}
		}

	}

}

// 清空链表
void clear_list(List *list)
{
	Node *cur, *tmp;

	for (cur = list->head; list->cnt != 0; ) {
		tmp = cur->next;
		free(cur);
		list->cnt--;
		cur = tmp;
	}
	list->head = list->tail = NULL;
	printf("List is cleared\n");
}

// 打印链表
void display_list(List *list)
{
	Node *cur;

	if (is_empty(list)) {
		printf("List is empty\n");
		return;
	}

	printf("List:\n");
	for (cur = list->head; cur != NULL; cur = cur->next) {
		printf("%d ", cur->val);

		if (cur == list->tail)
			break;
	}
	putchar('\n');
}
