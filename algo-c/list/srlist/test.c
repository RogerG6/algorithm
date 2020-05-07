/*************************************************************
 Date       : 2020年 05月 04日 星期一 13:49:27 CST
 Author     : rogerg6
 File       : test.c
 Description:
 	测试list
*************************************************************/

#include <stdio.h>
#include <ctype.h>
#include "list.h"

void menu(void);

int main(void)
{
	char c;
	int val;
	List *listp;

	do {
		menu();
		printf("Enter your choice: ");
		while (isspace(c = getchar()))
			;

		switch (c) {
			case 'n': listp = init_list(); break;
			case 'h': 
				num_items(listp);
				break;
			case 'i': 
				printf("Enter a val to insert:");
				scanf("%d", &val);
				insert_item(val, listp);
				break;
			case 'd': 
				printf("Enter a val to delete:");
				scanf("%d", &val);
				delete_item(val, listp);
				break;
			case 'e': clear_list(listp); break;
			case 'p': display_list(listp); break;
			default : printf("There is no %c option\n", c); break;
		} 
	} while (c != 'q');

	return 0;
}

void menu(void)
{
	printf("\n-------------------------\n");
	printf("List operations:\n");
	printf("n : init a list\n");
	printf("h : how many items in list\n");
	printf("i : inset a item to list\n");
	printf("d : delete a item in list\n");
	printf("e : empty a list\n");
	printf("p : print the list\n");
	printf("-------------------------\n");
}