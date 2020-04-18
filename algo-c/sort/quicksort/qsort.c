/*************************************************************
 Date: 2020年 04月 17日 星期五 20:38:28 CST
 Author: rogerg6
 File: qsort.c
 Description: 快速排序实现
 	思想：1. 数组中先中间项为base
 		 2. 设置i, j分别指向a[0], a[n-1]
 		 3. j--, 如果小于base, 则交换
 		 4. i++, 如果大于base，则交换
 		 5. 当i==j时，base左边 < base < base右边
 		 6. 对base两边的子数组递归处理
*************************************************************/
void swap(int *a, int *b);
int cmp(int a, int b);

void qsort(int *a, int left, int right)
{
	int i = left;
	int j = right;
	//int base = a[left];			// 基准值


	if (i >= j)
		return;

	swap(&a[i], &a[(i + j) / 2]);	// 取中间项为基准值

	while (i < j) {
		while (i < j && a[i] < a[j])	// i 指向基准值
			j--;
		swap(&a[i], &a[j]);

		while (i < j && a[i] < a[j])	// j 指向基准值
			i++;
		swap(&a[i], &a[j]);
	}

	qsort(a, left, i - 1);		// 递归处理左边
	qsort(a, j + 1, right);		// 递归处理右边
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
