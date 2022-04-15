#include <stdio.h>

int bin_search(int arr[], int left, int right, int key)
{
	int mid = 0;
	while (left <= right)
	{
		mid = (left + right)/2;
		if (arr[mid] > key)
		{ 
			right = mid - 1;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
			return mid;//找到了,返回下标
	}
	return -1;//找不到
}