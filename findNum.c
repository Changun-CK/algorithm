#include <stdio.h>
#include <stdlib.h>

int bin_search(int Num[], int n, int key);

int main(int argc, char *argv[])
{
	int key = 55;
	int i;
	int n[11] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
	//int n[] = {1, 2, 33, 232, 12312};
	int count = sizeof(n)/sizeof(int);

	printf("start:key==%d, count==%d\n", key, count);
	for (i = 0; i < count; ++i)
	{
		printf("%d\t", n[i]);
	}
	printf("\n");

	int res = bin_search(n, count, 55);
	if (res < 0)
	{
		printf("not find this number.\n");
		return 0;
	}
	printf("search:n[%d]==%d\n", res, key);

	return 0;
}

int bin_search(int Num[], int n, int key)
{
	int low, mid, high;
	low = 0;
	high = n - 1;

	if (n <= 0)
	{
		return -1;
	}
	if ((high == 0) && (Num[0] != key))
	{
		return -1;
	}

	while (low <= high)
	{
		// 二分法
		//mid = (low + high) / 2;
		// 插值法, 适用于分布较均匀的数据
		mid = low + (key - Num[low]) * (high - low) / (Num[high] - Num[low]);
		if (Num[mid] == key)
		{
			return mid;
		}

		if (Num[mid] < key)
		{
			low = mid + 1;
		}

		if (Num[mid] > key)
		{
			high = mid - 1;
		}
	}

	return -1;
}
