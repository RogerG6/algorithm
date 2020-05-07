/*************************************************************
 Date       : 2020年 05月 04日 星期一 12:44:25 CST
 Author     : rogerg6
 File       : dlist.c
 Description:
*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List * init_list(void)
{
	List *list = (List *)malloc(sizeof(struct node));
	if (list == NULL) {
		fprintf(stderr, "ERROR: can't alloc memory for list\n");
		exit(1);
	}

	list->head = NULL;
	list->cnt = 0;
	return list;
}

static int is_empty(List *list)
{
	return list->cnt == 0 ? 1 : 0;
}

static int is_full(List *list)
{
	return list->cnt == MAXITEMS ? 1 : 0;
}

void num_items(List *list)
{
	printf("Total: %d item%c\n", list->cnt, list->cnt <= 1 ? ' ' : 's');
}

void delete_item(int val, List *list)
{
	Node *cur;

	// 链表为空
	if (is_empty(list)) {
		fprintf(stderr, "ERROR: list is empty, nothing to delete\n");
		exit(1);
	}

	for (cur = list->head; cur != NULL; cur = cur->next) {
		if (cur->val == val) {
			if (cur == list->head) {			// head of list
				list->head = cur->next;
				cur->next->pre = NULL;
				free(cur);
			} else if (cur->next == NULL) {		// tail of list
				cur->pre->next = NULL;
				free(cur);
			} else {							// middle of list
				cur->pre->next = cur->next;
				cur->next->pre = cur->pre;
				free(cur);
			}
			list->cnt--;
			printf("Item %d is deleted\n", val);
			return;
		}
	}

	// 未找到val
	printf("Item %d is not in list\n", val);
}

void add_item(int val, List *list)
{
	Node *cur;

	// 链表为满
	if (is_full(list)) {
		fprintf(stderr, "ERROR: list is full\n");
		exit(1);
	}

	Node *item = (Node *)malloc(sizeof(struct node));
	if (item == NULL) {
		fprintf(stderr, "ERROR: can't alloc memory for node\n");
		exit(1);
	}
	item->val = val;

	if (list->cnt == 0) {			// list is empty
		list->head = item;
		item->pre = NULL;
		item->next = NULL;
	} else {
		for (cur = list->head; cur != NULL; cur = cur->next) {
			if (cur->val > val) {	// find the place to insert
				if (cur == list->head) {		// head of list
					item->next = cur;
					item->pre = NULL;
					list->head = item;
					cur->pre = item;
				} else {						// middle of list
					item->next = cur;
					item->pre = cur->pre;
					cur->pre->next = item;
					cur->pre = item;
				}
				break;
			}

			if (cur->next == NULL) {			// tail of list
				item->pre = cur;
				item->next = NULL;
				cur->next = item;
				break;
			}
		}
	}

	list->cnt++;
	printf("Item %d is added\n", val);
}

void clear_list(List *list)
{
	Node *cur, *tmp;

	for (cur = list->head; cur != NULL; ) {
		tmp = cur->next;
		free(cur);
		list->cnt--;
		cur = tmp;
	}
	printf("List is cleared\n");
}

void display_list(List *list)
{
	Node *cur;

	if (is_empty(list)) {
		fprintf(stderr, "ERROR: list is empty\n");
		return;
	}

	printf("List:\n");
	for (cur = list->head; cur != NULL; cur = cur->next) 
		printf("%d ", cur->val);
}

