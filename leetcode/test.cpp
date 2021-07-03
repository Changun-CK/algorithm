#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
	void backtrack(std::vector<std::vector<int>>& res, std::vector<int>& output, unsigned int first, unsigned int len)
	{
		// 所有的数都填完了
		if (first == len)
		{
			res.emplace_back(output);
			std::cout << "over" << std::endl;
			return;
		}
		for (unsigned int i = first; i < len; ++i)
		{
			std::cout << "1i==" << i << "  first==" << first << std::endl;
			// 维护动态数组
			std::swap(output[i], output[first]);
			// 继续递归填下一个数
			backtrack(res, output, first + 1, len);
			// 撤销操作
			std::cout << "2i==" << i << "  first==" << first << std::endl;
			std::swap(output[i], output[first]);
		}
	}

	std::vector<std::vector<int>> permute(std::vector<int>& nums)
	{
		std::vector<std::vector<int> > res;
		backtrack(res, nums, 0, nums.size());
		return res;
	}

};

int main()
{
	Solution a;
	//std::vector<int> c = { 1, 2 };
	//std::vector<int> c = { 1, 2, 3 };
	std::vector<int> c = { 1, 2, 3, 4 };
	std::vector<std::vector<int>> b = a.permute(c);
	for (unsigned int i = 0; i < b.size(); ++i)
	{
		std::cout << "[";
		for (unsigned int j = 0; j < b[i].size(); ++j)
		{
			std::cout << b[i][j];
			if (j != b[i].size() - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << "]" << std::endl;
	}

	return 0;
}
