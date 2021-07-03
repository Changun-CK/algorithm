#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int arrymax(int *arry, int size)
{
	int i;
	int max = arry[0];
	for (i = 0; i < size; ++i)
	{
		if (arry[i] > max)
		{
			max = arry[i];
		}
	}

	return max;
}

// 1-冒泡排序, 具有稳定性, 效率O(n*n)
void sortbysoap(int *arry, const int size);

// 2-直接选择排序, 不具有稳定性, 效率O(n*n)
void sortbyselect(int *arry, const int size);

// 3-直接插入排序, 具有稳定性, 效率O(n*n)
void sortbyinsert(int *arry, const int size);

// 4-希尔排序, 不具有稳定性, 效率O(n^1.3 ~ n^2)
void sortbyshell(int *arry, const int size);

// 5-快速排序, 不具有稳定性, 效率O(n*log(2 n))
void sortbyquick(int *arry, const int size);

// 6-归并排序, 具有稳定性, 效率O(n*log(2 n))
void sortbymerger(int *arry, const int size);
//void _sortbymerger(int *arry, int *arrtmp, int start, int end);

// 7-堆排序, 不具有稳定性, 效率O(n*log(2 n))
void sortbyheap(int *arry, const int size);
void heapify(int *arry, int start, int end);

// 8-计数排序, 具有稳定性, 效率O(n+k)
void sortbycount(int *arry, const int size);

// 9-桶排序, 具有稳定性, 效率O(n+k)
void sortbybucket(int *arry, const int size);

// 10-基数排序, 具有稳定性, 效率O(d(n*k))
void sortbybase(int *arry, const int size);
void _sortbybase(int *arry, const int size, const int exp);


int main()
{
	int arr[] = { 133, 245, 851, 135, 665, 306, 199, 353, 603, 698, 851, 966, 270, 616, 36, 60, 39, 968, 274, 477, 696, 541, 118, 382, 654, 412, 129, 250, 367, 671, 559, 191, 917, 99, 326, 271, 95, 526, 624, 389, 914, 474, 44, 183, 89, 80, 935, 820, 48, 208, 296, 434, 749, 104, 506, 92, 516, 635, 32, 574, 996, 281, 455, 602, 381, 781, 873, 476, 997, 186, 555, 910, 660, 600, 93, 440, 680, 718, 950, 418, 926, 245, 852, 364, 349, 357, 146, 555, 682, 178, 819, 368, 149, 273, 660, 530, 745, 533, 697, 741, 719, 251, 651, 69, 851, 434, 199, 221, 151, 148, 639, 767, 83, 181, 821, 122, 228, 657, 677, 601, 525, 186, 969, 674, 149, 628, 204, 894, 851, 591, 325, 260, 842, 976, 19, 383, 99, 218, 294, 941, 56, 933, 397, 139, 804, 217, 952, 32, 874, 318, 633, 398, 504, 291, 762, 344, 609, 966, 928, 460, 556, 252, 720, 88, 918, 429, 161, 16, 647, 455, 647, 393, 77, 43, 222, 572, 951, 173, 604, 514, 491, 927, 602, 686, 217, 364, 29, 516, 329, 957, 976, 576, 209, 385, 354, 817, 814, 205, 834, 150 }; // 基本无序大数组
	//int arr[] = { 3, 6, 0, 1, 4, 9, 0, 5, 7, 2, 10, 0 }; // 基本无序
	//int arr[] = { 0, 2, 3, 1, 4, 5, 3 }; // 基本有序
	//int arr[] = { 5, 3, 4, 1, 2 };
	//int arr[] = { -1, 3, 6, 1, 4, 9, 0, 5, -7, 2, 10, 0 , -2 }; // 基本无序带负数
	//int arr[] = { 3, 6, 0, 1, 14, 29, 10, 35, 17, 12, 10, 30 }; // 基本无序桶排序适用
	int len = sizeof(arr) / sizeof(int);
	int ii = 0;

	//sortbysoap(arr, len);
	//sortbyselect(arr, len);
	sortbyinsert(arr, len);
	//sortbyshell(arr, len);
	//sortbyquick(arr, len);
	//sortbymerger(arr, len);
	//sortbyheap(arr, len);
	//sortbycount(arr, len);
	//sortbybucket(arr, len);
	//sortbybase(arr, len);

	printf("\n");
	for (ii = 0; ii < len; ii++)
	{
		printf("%d\t", arr[ii]);
	}
	printf("\n\n");

	return 0;
}

// 冒泡排序
//void sortbysoap(int *arry, const int size)
//{
//	int i, j, temp, flag;
//	flag = 1;
//	// 控制次数size - 1次, flag确定是否需要比较, 此参数可加大查询效率
//	for (i = 0; (i < size - 1) && flag; i++)
//	{
//		flag = 0; // 若没有执行以下语句, 则说明排序已经完成, 无需比较
//		// 每次冒出最大数(第二次冒出第二大的数), 故每次只需比较size-1-size 次
//		for (j = 0; j < size - 1 - i; j++)
//		{
//			if (arry[j] > arry[j+1])
//			{
//				temp = arry[j+1];
//				arry[j+1] = arry[j];
//				arry[j] = temp;
//				flag = 1;
//			}
//		}
//	}
//}

//void sortbysoap(int *arry, const int size)
//{
//	if (size < 2) return;
//	int i, j, tmp, flag;
//	flag = 1;
//	for (i = size - 1; (i > 0) && flag; i--) // 控制循环次数
//	{
//		flag = 0;
//		//printf("iiiiiiiii==%d\n", i);
//		for (j = 0; j < i; j++) // 遍历比较大小
//		{
//			if (arry[j] > arry[j + 1])
//			{
//				tmp = arry[j];
//				arry[j] = arry[j + 1];
//				arry[j + 1] = tmp;
//				flag = 1;
//			}
//			printf("j==%d->", j);
//		}
//		//printf("\n", j);
//	}
//}

void sortbysoap(int *arry, const int size)
{
	if (size < 2) return;
	int i, tmp, tmpsize;
	for (i = 0; i < size - 1; i++) // 遍历比较大小
	{
		if (arry[i] > arry[i + 1])
		{
			tmp = arry[i];
			arry[i] = arry[i + 1];
			arry[i + 1] = tmp;
		}
	}

	tmpsize = size - 1;
	sortbysoap(arry, tmpsize); // 递归
}

//// 选择排序
//void sortbyselect(int *arry, const int size)
//{
//	int i, j, min, temp;
//	for(i = 0; i < size - 1; i++)
//	{
//		min = i; // 用来记录每次比较出的最小数的下标
//		for (j = i + 1; j < size; j++)
//		{
//			if (arry[j] < arry[min])
//			{
//				min = j;
//			}
//		}
//
//		if (min != i) // 若有更小的数, 则与arry[i]交换
//		{
//			temp = arry[i];
//			arry[i] = arry[min];
//			arry[min] = temp;
//		}
//	}
//}

// 选择排序
//void sortbyselect(int *arry, const int size)
//{
//	if (size < 2) return;
//	int i, min, max, temp;
//	int left = 0; // 左下标
//	int right = size - 1; // 右下标
//	while (left < right)
//	{
//		min = left;
//		max = right;
//		for (i = left; i < right + 1; ++i)
//		{
//			if (arry[i] < arry[min])
//			{
//				min = i;
//			}
//			if (arry[i] > arry[max])
//			{
//				max = i;
//			}
//		}
//
//		if (min != left)
//		{
//			temp = arry[left];
//			arry[left] = arry[min];
//			arry[min] = temp;
//		}
//		if (max == left)
//		{
//			max = min;
//		}
//		if (max != right)
//		{
//			temp = arry[right];
//			arry[right] = arry[max];
//			arry[max] = temp;
//		}
//		++left;
//		--right;
//	}
//}

// 选择排序
void sortbyselect(int *arry, const int size)
{
	if (size < 2) return;
	int i, min, max, temp;
	int left = 0; // 左下标
	int right = size - 1; // 右下标
	min = left;
	max = right;

	for (i = left; i < right + 1; ++i)
	{
		if (arry[i] < arry[min])
		{
			min = i;
		}
		if (arry[i] > arry[max])
		{
			max = i;
		}
	}

	if (min != left)
	{
		temp = arry[left];
		arry[left] = arry[min];
		arry[min] = temp;
	}
	if (max == left)
	{
		max = min;
	}
	if (max != right)
	{
		temp = arry[right];
		arry[right] = arry[max];
		arry[max] = temp;
	}

	temp = size - 2;
	sortbyselect(++arry, temp); // 递归
}

// 直接插入排序
void sortbyinsert(int *arry, const int size)
{
	if (size < 2) return;

	int i, j, temp;
	for (i = 1; i < size; i++)
	{
		if (arry[i] < arry[i - 1])
		{
			temp = arry[i]; // 待排序的元素值
			// 因为这里的前i-1个元素有序, 所以也这里可以采用二分查找插入位置
			for (j = i - 1; arry[j] > temp && j >= 0; j--)
			{
				arry[j + 1] = arry[j];
			}

			arry[j + 1] = temp;
		}
	}
}

// 希尔排序, 插入排序的一种, 是对直接插入排序的优化
void sortbyshell(int arry[], const int size)
{
	if (size < 2) return;

	int i, j, temp, gap;
	for (gap = size / 2; gap > 0; gap = gap / 2)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i - gap; j >= 0 && arry[j] > arry[j + gap]; j = j - gap)
			{
				temp = arry[j];
				arry[j] = arry[j + gap];
				arry[j + gap] = temp;
			}
		}
	}
}

// 希尔排序, 插入排序的一种, 是对直接插入排序的优化
//void sortbyshell(int arry[], const int size)
//{
//	if (size < 2) return;
//
//	int i, j, temp;
//	int gap = size;
//	do
//	{
//		gap = gap / 2;
//		for (i = gap; i < size; i += gap)
//		{
//			if (arry[i] < arry[i - gap])
//			{
//				temp = arry[i]; // 待排序的元素值
//				// 因为这里的前i-1个元素有序, 所以也这里可以采用二分查找插入位置
//				for (j = i - gap; arry[j] > temp && j >= 0; j -= gap)
//				{
//					arry[j + gap] = arry[j];
//				}
//
//				arry[j + gap] = temp;
//			}
//		}
//	} while (gap > 1) ;
//}

// 5-快速排序(属于交换排序), 不具有稳定性, 效率O(n*log(2 n))
void sortbyquick(int *arry, const int size)
{
	// 挖坑法排序, 配合递归
	if (size < 2) return;

	int left, right, tmp, space;
	left = 0;
	right = size - 1;
	space = 0;     // 空位
	tmp = arry[0]; // 需要比较的基准元素

	while (right > left)
	{
		// 先右游标往左移动
		while (arry[right] > tmp)
		{
			--right;
		}
		if (right > left)
		{
			++left;
			arry[space] = arry[right];
			space = right;
		}

		// 再左游标往右移动
		while (arry[left] <= tmp && right > left)
		{
			++left;
		}
		if (right > left)
		{
			--right;
			arry[space] = arry[left];
			space = left;
		}
	}

	arry[space] = tmp; //此时left == right == space, 要将基准元素tmp填进去

	sortbyquick(arry, left);
	sortbyquick(arry + left + 1, size - left -1);
}

// 6-归并排序, 具有稳定性, 效率O(n*log(2 n)), 递归
//void sortbymerger(int *arry, const int size)
//{
//	if (size < 2) return;
//	int arrtmp[size];
//	_sortbymerger(arry, arrtmp, 0, size - 1);
//}
//
//void _sortbymerger(int *arry, int *arrtmp, int start, int end)
//{
//	// 如果start>=end, 表示该区间的元素少于两个, 递归终止
//	if (start >= end) return;
//	
//	int mid = start + (end - start) / 2; // 计算区间中间的位置
//
//	int istart1 = start;
//	int iend1 = mid;
//	int istart2 = mid + 1;
//	int iend2 = end;
//	
//	_sortbymerger(arry, arrtmp, istart1, iend1);
//	_sortbymerger(arry, arrtmp, istart2, iend2);
//	
//	int i = start; // 已排序数组arrtmp的计数器
//
//	// 把区间左右两边数列合并到已排序数组arrtmp中
//	while (istart1 <= iend1 && istart2 <= iend2)
//	{
//		if (arry[istart1] < arry[istart2])
//		{
//			arrtmp[i] = arry[istart1];
//			++i;
//			++istart1;
//		}
//		else
//		{
//			arrtmp[i] = arry[istart2];
//			++i;
//			++istart2;
//		}
//	}
//
//	// 把左边数列其它的元素追加到已排序数组
//	while (istart1 <= iend1)
//	{
//		arrtmp[i] = arry[istart1];
//		++i;
//		++istart1;
//	}
//	// 把右边数列其它的元素追加到已排序数组
//	while (istart2 <= iend2)
//	{
//		arrtmp[i] = arry[istart2];
//		++i;
//		++istart2;
//	}
//
//	// 把已排序数组arrtmp中的元素复制到arry中
//	memcpy(arry + start, arrtmp + start, (end - start + 1) * sizeof(int));
//}

// 6-归并排序, 具有稳定性, 效率O(n*log(2 n)), 循环
void sortbymerger(int *arry, const int size)
{
	if (size < 2) return;
	int *arr = arry;                                 // 指向待排序的数组
	int *arrtmp = (int *)malloc(size * sizeof(int)); // 指向已排序的数组

	int iseg;   // 区间分段的计数器, 1, 2, 4, 8...
	int istart; // 区间起始位置的计数器
	for (iseg = 1; iseg < size; iseg *= 2)
	{
		// 每趟排序选取区间的循环
		for (istart = 0; istart < size; istart = istart + iseg * 2)
		{
			// 把每个区间分成两部分, ilow是起始位置, imid是中间位置, imax是结束位置
			int ilow = istart;
			int imid = MIN(istart + iseg, size); // 考虑分段不均匀的情况, imid 不能超出size
			int imax = MIN(istart + iseg * 2, size); // 考虑分段不均匀的情况, imax 不能超出size

			int i = ilow; // 已经排序数组的计数器
			int istart1 = ilow; // 左起始位置
			int iend1 = imid;   // 左结束位置
			int istart2 = imid; // 右起始位置
			int iend2 = imax;   // 右结束位置

			// 把待排序左右两边数列合并到已排序数组
			while ((istart1 < iend1) && (istart2 < iend2))
			{
				if (arr[istart1] < arr[istart2])
				{
					arrtmp[i] = arr[istart1];
					++i;
					++istart1;
				}
				else
				{
					arrtmp[i] = arr[istart2];
					++i;
					++istart2;
				}
			}

			// 把左边剩余元素追加到已排序数组
			while (istart1 < iend1)
			{
				arrtmp[i] = arr[istart1];
				++i;
				++istart1;
			}

			// 把右边剩余元素追加到已排序数组
			while (istart2 < iend2)
			{
				arrtmp[i] = arr[istart2];
				++i;
				++istart2;
			}
		}
		// 交换两个数组的指针, 准备下一趟的排序
		int *ptmp = arr;
		arr = arrtmp;
		arrtmp = ptmp;
	}

	// 如果arr指向的不是原始数组的指针, 把arr中的内容复制到arry中
	if (arr != arry)
	{
		memcpy(arry, arr, size * sizeof(int));
		arrtmp = arr;
	}

	free(arrtmp);
}

// 7-堆排序(属于选择排序), 不具有稳定性, 效率O(n*log(2 n))
void sortbyheap(int *arry, const int size)
{
	if (size < 2) return;
	int i;
	// 初始化堆, 从最后一个父节点开始调整
	for (i = (size - 1) / 2; i >= 0; --i)
	{
		heapify(arry, i, size - 1);
	}

	// 把第一个元素和堆最后一个元素交换, 然后重新调整, 直到排序完毕
	for (i = size - 1; i > 0; --i)
	{
		swap(&arry[0], &arry[i]);
		heapify(arry, 0, i - 1);
	}
}

void heapify(int *arry, int start, int end)
{
	// 确定父节点和左子节点的数组下标
	int dad = start;
	int son = dad * 2 + 1;
	
	// 如果子节点的下标没有超出范围, 循环继续
	while (son <= end)
	{
		// 先比较两个子节点大小, 选择最大的
		if ((son < end) && (arry[son] < arry[son + 1]))
		{
			++son;
		}

		// 如果父节点大于子节点代表调整完毕, 直接return
		if (arry[dad] > arry[son])
		{
			return;
		}

		// 否则交换父子内容再继续子节点和孙节点比较
		swap(&arry[dad], &arry[son]);
		dad = son;
		son = dad * 2 + 1;
	}
}

// 8-计数排序, 具有稳定性, 效率O(n+k)
void sortbycount(int *arry, const int size)
{
	if (size < 2) return;
	int max = arrymax(arry, size); // 获取最大值
	int arrtmp[max + 1];

	memset(arrtmp, 0, sizeof(arrtmp));

	int i, j, k;
	// 构建临时计数的数组
	for (i = 0; i < size; ++i)
	{
		arrtmp[arry[i]]++;
	}

	// 将临时数组计数内容填充到arry中
	i = 0;
	for (j = 0; j < max + 1; ++j)
	{
		for (k = 0; k < arrtmp[j]; ++k)
		{
			arry[i++] = j;
		}
	}
}

// 9-桶排序, 具有稳定性, 效率O(n+k)
void sortbybucket(int *arry, const int size)
{
	int bucket[5][5];  // 桶
	int bucketsize[5]; // 记录每个桶元素个数

	memset(bucket, 0, sizeof(bucket));
	memset(bucketsize, 0, sizeof(bucketsize));

	// 把数组arry的数据加入到桶中
	// 0-9 , 10-19, ...
	// 同时更新桶和桶的元素个数
	int i = 0;
	for (i = 0; i < size; ++i)
	{
		bucket[arry[i] / 10][bucketsize[arry[i] / 10]++] = arry[i];
	}

	// 对每个桶进行排序
	for (i = 0; i < 5; ++i)
	{
		sortbyheap(bucket[i], bucketsize[i]);
	}

	// 将每个桶中的数据填充到数组arry中
	int j = 0, k = 0;
	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < bucketsize[i]; ++j)
		{
			arry[k++] = bucket[i][j];
		}
	}
}

// 10-基数排序, 具有稳定性, 效率O(d(n*k))
void sortbybase(int *arry, const int size)
{
	if (size < 2) return;
	int i = 0;
	int j;
	//int count = 0; // 位数
	//int flag = 1;
	//int tmp = 1;
	//while (flag)
	//{
	//	flag = 0;
	//	tmp = tmp * 10;
	//	for (i = 0; i < size; ++i)
	//	{
	//		if (0 != arry[i] / tmp)
	//		{
	//			flag = 1;
	//			break;
	//		}
	//	}
	//	count++;
	//}

	int max = arrymax(arry, size);
	int exp = 1;
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		_sortbybase(arry, size, exp);
		//printf("exp=%-5d ", exp);
		//for (j = 0; j < size; ++j)
		//{
		//	printf("%d ", arry[j]);
		//}
		//printf("\n");
	}
}

void _sortbybase(int *arry, const int size, const int exp)
{
	int i;
	int result[size];
	int buckets[10] = {0};

	// 遍历arry, 将数据出现的次数存储在buckets中
	for (i = 0; i < size; ++i)
	{
		buckets[(arry[i] / exp) % 10]++;
	}

	// 调整buckets各元素的值, 调整后的值就是arry中元素在result中的位置
	for (i = 1; i < 10; ++i)
	{
		buckets[i] = buckets[i] + buckets[i - 1];
	}

	// 将arry中的元素加入到result中
	for (i = size - 1; i >= 0; --i)
	{
		int iexp = (arry[i] / exp) % 10; // 个位数决定在哪个容器中
		result[buckets[iexp] - 1] = arry[i]; // 容器中的值-1即为位置
		buckets[iexp]--;                     // buckets对应的值要-1，因为下次很可能还要在该桶中取元素
	}

	// 将排序好的数组result复制到数组arry中
	memcpy(arry, result, size * sizeof(int));
}
