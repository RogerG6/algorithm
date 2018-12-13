//bubble sort
//2018年12月13日 16时51分

//对数组排序
for (int i = 0; i < n - 1; i++)
{
	for (int j = i; j < n - 1 - i; j++)
	{
		if (a[j] > a[j + 1])    //升序
		{
			tmp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = tmp;
		}
	}
}
	