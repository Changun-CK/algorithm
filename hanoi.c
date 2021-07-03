#include <stdio.h>
#include <string.h>

void hanoi(int n, char x, char y, char z)
{
	if (n == 1)
	{
		printf("%c-->%c\n", x, z);
	}
	else
	{
		hanoi(n - 1, x, z, y);     //将 n-1 个从 x 借助z移到 y 上
		printf("%c-->%c\n", x, z); //将第 n 个从 x 移到 z 上
		hanoi(n - 1, y, x, z);     //将 n-1 个从 y 借助z移到 z 上
	}
}

int main(int argc, char *argv[])
{
	char x = 'X';
	char y = 'Y';
	char z = 'Z';
	hanoi(9, x, y, z);

	return 0;
}
