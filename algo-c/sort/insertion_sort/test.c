/*************************************************************
 Date       : 2020年 04月 22日 星期三 20:37:43 CST
 Author     : rogerg6
 File       : test.c
 Description:
 	test file for insertion sort
*************************************************************/

#include <stdio.h>

#define NUM 6

void insertsort(int *a, int n);
void printarray(int *a, int n);

int main()
{
	int a[NUM] = {6, 5, 4, 3, 2, 1};
	int i;


	printf("unsorted array:\n");
	printarray(a, NUM);

	insertsort(a, NUM);

	printf("sorted array:\n");
	printarray(a, NUM);

	return 0;
}
