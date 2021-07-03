#include <queue>
#include <vector>
#include <iostream>
#include<functional>

class Solution
{
public:
	static std::vector<int> getLeastNumber(const std::vector<int>& arr, unsigned int k)
	{
		std::vector<int> res;
		if (0 == k)
		{
			return res;
		}

		//std::priority_queue<int> Q; // 大顶堆, 适合求最小k个数
		std::priority_queue<int, std::vector<int>, std::greater<int>> Q;
		for (unsigned int i = 0; i < k; ++i)
		{
			Q.push(arr[i]);
		}

		for (unsigned int i = k; i < arr.size(); ++i)
		{
			//if (Q.top() > arr[i])
			if (Q.top() < arr[i])
			{
				Q.pop();
				Q.push(arr[i]);
			}
		}

		while (!Q.empty())
		{
			res.push_back(Q.top());
			Q.pop();
		}

		return res;
	}
};

int main()
{
	std::vector<int> arr = { 4, 5, 1, 6, 2, 7, 3, 8 };
	std::vector<int> res;
	unsigned int k = 4;
	res = Solution::getLeastNumber(arr, k);
	for (auto element : res)
	{
		std::cout << element << ' ';
	}
	std::cout << '\n';

	return 0;
}
