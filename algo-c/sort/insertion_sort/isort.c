/*************************************************************
 Date       : 2020年 04月 22日 星期三 20:37:43 CST
 Author     : rogerg6
 File       : isort.c
 Description:
 	插入排序：
 		1. 对a[n]，从1开始到n-1
 		2. 插入到由第一个元素组成的子数组中
 		3. 重复2步，直到数组有序
*************************************************************/
#include <stdio.h>

void printarray(int *a, int n);

void insertsort(int *a, int n)
{
	int i, j, tmp;

	printf("\nInsertion sort steps:\n");
	for(i = 1; i < n; i++) {
		for (tmp = a[i], j = i; j > 0 && a[j - 1] > tmp; j--)
			a[j] = a[j - 1];
		a[j] = tmp;
		printarray(a, n);
	}
}

void printarray(int *a, int n)
{
	int j;
	for (j = 0; j < n; j++)
		printf("%d ", a[j]);
	putchar('\n');	
}
