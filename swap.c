#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b);

int main()
{
	int a = -1;
	int b = 0;
	printf("a==%d, b==%d\n", a, b);
	//swap(&a, &b);
	printf("swap(a, b):\na==%d, b==%d\n", a, b);

	return 0;
}

//void swap(int *a, int *b)
//{
//	*a = *a + *b;
//	*b = *a - *b;
//	*a = *a - *b;
//}

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
