//bubble sort
//2018年12月13日 16时51分

//对数组排序
for (int i = n - 1; i >= 0; i--)
{
	for (int j = 0; j < i; j++)
	{
		if (a[j] > a[j + 1])    //升序
		{
			tmp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = tmp;
		}
	}
}
	