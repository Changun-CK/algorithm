#include <iostream>
#include <vector>

std::vector<int> topN(const std::vector<int>& arry, const unsigned int toplen);

void createheap(std::vector<int>& res);

void heapify(std::vector<int>& res, const int start, const int end);

void pushheap(std::vector<int>& res, const int val);

void sortbyheap(std::vector<int>& arry);

int main(int argc, char *argv[])
{
	std::vector<int> arry = {12, 34, 1, 67, 0, 32, 56, 34, 45, 23, 45, 56, 67, 23, 123, 345, 23, 121, 12312, 23, 231, 2, 21, 3, 7, 23, 2};
	std::vector<int> Arry = {12, 34, 1, 67, 0, 32, 56, 34, 45, 23, 45, 56, 67, 23, 123, 345, 23, 121, 12312, 23, 231, 2, 21, 3, 7, 23, 2};

	// sort
	sortbyheap(Arry);

	std::cout << "sort:" << '\n';
	for (size_t i = 0; i < Arry.size(); i++)
	{
		std::cout << Arry[i] << ", ";
	}
	std::cout << '\n';

	// topN
	std::vector<int> res = topN(arry, 8);

	std::cout << "topN:" << '\n';
	for (size_t i = 0; i < res.size(); i++)
	{
		std::cout << res[i] << ", ";
	}
	std::cout << '\n';

	return 0;
}

std::vector<int> topN(const std::vector<int>& arry, const unsigned int toplen)
{
	if (toplen >= arry.size())
	{
		return arry;
	}
	std::vector<int> res;

	// 创建小根堆
	for (unsigned int i = 0; i < toplen; ++i)
	{
		res.push_back(arry[i]);
	}
	createheap(res);
	//for (unsigned int i = 0; i < res.size(); ++i)
	//{
	//	std::cout << res[i] << "	";
	//}
	//std::cout << '\n';

	// 计算结果
	for (unsigned int i = toplen; i < arry.size(); ++i)
	{
		if (arry[i] > res[0])
		{
			pushheap(res, arry[i]);
		}
	}

	return res;
}

void createheap(std::vector<int>& res)
{
	int len = res.size();
	if (len < 2) return;

	for (int i = len / 2 - 1; i >= 0; i--)
	{
		heapify(res, i, len - 1);
	}
}

void heapify(std::vector<int>& res, const int start, const int end)
{
	int tmp;
	int dad = start;
	int son = 2 * start + 1;
	while (son <= end)
	{
		if (son + 1 <= end && res[son] > res[son + 1])
		{
			son++;
		}

		if (res[dad] < res[son])
		{
			return;
		}
		tmp = res[dad];
		res[dad] = res[son];
		res[son] = tmp;
		dad = son;
		son = 2 * dad + 1;
	}
}

void pushheap(std::vector<int>& res, const int val)
{
	res[0] = val;
	heapify(res, 0, res.size() - 1);
}

void sortbyheap(std::vector<int>& arry)
{
	createheap(arry);
	int tmp;
	int len = arry.size();

	for (unsigned int i = len - 1; i > 0; --i)
	{
		tmp = arry[0];
		arry[0] = arry[i];
		arry[i] = tmp;
		heapify(arry, 0, i - 1);
	}
}
