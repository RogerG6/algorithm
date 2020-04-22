/*************************************************************
 Date       : 2020年 04月 22日 星期三 22:19:45 CST
 Author     : rogerg6
 File       : trvrs.c
 Description:
 	遍历查找
*************************************************************/

/*
存在  ：返回下标
不存在： 返回-1
*/
int traverse(int *a, int n, int target)
{
	int i;
	for (i = 0; i < n; i++)
		if (a[i] == target)
			return i;
	return -1;
}