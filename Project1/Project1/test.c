#include <stdio.h>

#include "bin_search.h"
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int key = 5;
	
	int mid =  bin_search(arr, left, right,key);
	if (mid == -1)
	{
		printf("找不到！！！");
	}
	else
		printf("找到了，下标为：%d", mid);

	return 0;
}