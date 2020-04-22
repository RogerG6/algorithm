/*************************************************************
 Date       : 2020年 04月 22日 星期三 22:31:56 CST
 Author     : rogerg6
 File       : binary.c
 Description:
 	二分法查找
 		1. 排序好的数组
 		2. 取待查找数组中间值与目标值比较
 		3. = 则返回数组下标
 		   > 则在后面的子数组中查找
 		   < 则在前面的子数组中查找
 		4. 设置子数组为待查找的数组
*************************************************************/

/*
含头含尾
存在  ：返回下标
不存在：返回 -1
*/
int b_search_v1(int *a, int n, int target)
{
	int left = 0;
	int right = n - 1;
	int mid;

	while (left <= right) {
		mid = left + (right - left) / 2;
		if (a[mid] == target)
			return mid;
		else if (a[mid] < target)
			left = mid + 1;
		else if (a[mid] > target)
			right = mid - 1;
	}
	return -1;
}

// 含头不含尾
int b_search_v2(int *a, int n, int target)
{
	int left = 0;
	int right = n;		// 不同点
	int mid;

	while (left < right) {		// 不同点
		mid = left + (right - left) / 2;
		if (a[mid] == target)
			return mid;
		else if (a[mid] < target)
			left = mid + 1;
		else if (a[mid] > target)
			right = mid;		// 不同点
	}
	return -1;
}
