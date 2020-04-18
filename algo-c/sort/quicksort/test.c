/*************************************************************
 Date: 2020年 04月 17日 星期五 20:38:28 CST
 Author: rogerg6
 File: test.c
 Description: test file for qsort
*************************************************************/

#include <stdio.h>

#define NUM 6
void qsort(int *a, int left, int right);

int main()
{
	int n[NUM] = {6, 5, 4, 3, 2, 1};
	int i;


	printf("unsorted array:\n");
	for (i = 0; i < NUM; i++)
		printf("%d ", n[i]);
	putchar('\n');

	qsort(n, 0, NUM - 1);

	printf("sorted array:\n");
	for (i = 0; i < NUM; i++)
		printf("%d ", n[i]);
	putchar('\n');

	return 0;
}
