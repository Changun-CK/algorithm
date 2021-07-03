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

		int rows = matrix.size(), columns = matrix[0].size();
		std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns)); // all false
		int total = rows * columns;
		std::vector<int> order(total);

		int row = 0, column = 0;
		int directionIndex = 0;
		for (int i = 0; i < total; ++i)
		{
			order[i] = matrix[row][column];
			visited[row][column] = true;
			int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
			if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn])
			{
				directionIndex = (1 + directionIndex) % 4;
			}
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
