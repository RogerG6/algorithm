/*************************************************************
 Date       : 2020年 05月 04日 星期一 12:12:53 CST
 Author     : rogerg6
 File       : full_permutitions.c
 Description:
 	用dfs深度优先搜索算法实现全排列
 	以下以1234全排列为例
*************************************************************/

#include <stdio.h>

int flg[100];		// 标记数组

void dfs(int dp, int n);

int main(void)
{
	int n;

	printf("Enter a num to full permutitions: ");
	scanf("%d", &n);

	dfs(1, n);

	return 0;
}

void dfs(int dp, int n)
{
	int i;
	static int buf[10] = {0};

	if (dp == n + 1) {
		for (i = 0; i < n; i++)
			printf("%d", buf[i]);
		putchar('\n');
		return;
	}

	for (i = 1; i <= n; i++) {
		if (flg[i] == 1)
			continue;
		//printf("%d", i);
		buf[dp - 1] = i;
		flg[i] = 1;
		dfs(dp + 1, n);
		flg[i] = 0;
	}
}