#include <stdio.h>
#include <string.h>

#define ROW 8
#define COL 8

int count = 0;

int notDanger(int row, int col, int (*q)[8])
{
	int i, j;
	//判断列方向
	for (i = 0; i < COL; ++i)
	{
		if (*(*(q + i) + col) == 1)
		{
			return 0;
		}
	}

	//判断斜对角方向左上
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (*(*(q + i) + j) == 1)
		{
			return 0;
		}
	}

	//判断斜对角方向右下
	for (i = row, j = col; i < ROW && j < COL; i++, j++)
	{
		if (*(*(q + i) + j) == 1)
		{
			return 0;
		}
	}

	//判断斜对角方向左下
	for (i = row, j = col; i < ROW && j >= 0; i++, j--)
	{
		if (*(*(q + i) + j) == 1)
		{
			return 0;
		}
	}

	//判断斜对角方向右上
	for (i = row, j = col; i >= 0 && j < COL; i--, j++)
	{
		if (*(*(q + i) + j) == 1)
		{
			return 0;
		}
	}

	return 1;
}

void EightQueen(int (*q)[8], int row, int col)
{
	int i, j;
	int p[ROW][COL];
	for (i = 0; i < ROW; ++i)
	{
		for (j = 0; j < COL; ++j)
		{
			p[i][j] = *(*(q + i) + j);
		}
	}

	if (ROW == row)
	{
		printf("第 %d 种\n", count+1);
		for (i = 0; i < row; ++i)
		{
			for (j = 0; j < col; ++j)
			{
				printf("%d ", *(*(p + i) + j));
			}
			printf("\n");
		}
		printf("\n");
		count++;
	}
	else
	{
		//遍历每行的列数据
		for (j = 0; j < col; j++)
		{
			//当没有危险时置为1,其他地方置为0,同时递归
			if (notDanger(row, j, q))
			{
				for (i = 0; i < col; ++i)
				{
					*(*(p + row) + i) = 0;
				}

				*(*(p + row) + j) = 1;

				EightQueen(p, row + 1, col);
			}
		}
	}
}

int main(int argc, char *argv[])
{
	int i, j;
	int chess[ROW][COL] = { 0 };
	for (i = 0; i < ROW; ++i)
	{
		for (j = 0; j < COL; ++j)
		{
			chess[i][j] = 0;
		}
	}

	EightQueen(chess, 0, COL);
	printf("一共有%d种方法\n\n", count);

	return 0;
}
