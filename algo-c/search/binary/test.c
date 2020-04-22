/*************************************************************
 Date       : 2020年 04月 22日 星期三 22:19:45 CST
 Author     : rogerg6
 File       : test.c
 Description:
 	test file for binary search
*************************************************************/

#include <stdio.h>

#define N 7

int b_search_v1(int *a, int n, int target);
int b_search_v2(int *a, int n, int target);

int main()
{
	int a[N] = {3, 4, 5, 6, 7, 8, 9};
	int target, index;

	printf("enter target number:\n");
	scanf("%d", &target);

	if ((index = b_search_v2(a, N, target)) != -1) 
		printf("%d is in a[N]\nindex = %d\n", target, index);
	else
		printf("%d is not in a[N]\n", target);

	return 0;
}