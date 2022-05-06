#pragma warning(once:4996)
# include <stdio.h>
//                        一维数组，数组长度
void bubble_sort(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++) 
	{
		int j = 0;
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

//int main()
//{
//	int arr[10] = { 11,21,13,4,5,16,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	return 0;
//}