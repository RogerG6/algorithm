/* time: 2018/12/27 16:22
   function: Selection sort
   author: rogerg6
  */

void select_sort(int * s, int n)  
{
	int tmp;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (s[i] > s[j])            //ascending order, '<': decending order
			{
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
}
