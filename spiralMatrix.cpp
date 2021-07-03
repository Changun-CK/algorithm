#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
private:
	const int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

public:
	std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
	{
		if (0 == matrix.size() || 0 == matrix[0].size())
		{
			return {};
		}

		int rows = matrix.size(), columns = matrix[0].size(); // 总行数, 总列数
		std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns)); // all false
		int total = rows * columns; // 总元素个数
		std::vector<int> order(total);

		int row = 0, column = 0; // 初始行和列
		int directionIndex = 0; // 初始方向矩阵的行数
		for (int i = 0; i < total; ++i)
		{
			order[i] = matrix[row][column]; // 赋值给order数组
			visited[row][column] = true; // 走过了就将该位置置为true
			int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1]; // 计算理论上下个行和列值
			// 若触碰到边界或者已经走过路径则转换方向
			if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn])
			{
				directionIndex = (1 + directionIndex) % 4;
			}
			// 计算实际下一个行值和列值
			row += directions[directionIndex][0];
			column += directions[directionIndex][1];
		}

		return order;
	}
};

int main(int argc, char *argv[])
{
	std::vector<std::vector<int>> raw = {{1,2,3},{4,5,6},{7,8,9}};
	std::vector<int> res;
	Solution s;
	res = s.spiralOrder(raw);

	for (auto it : res)
	{
		std::cout << it << ' ';
	}
	std::cout << '\n';

	return 0;
}
