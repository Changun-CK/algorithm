#include <stdio.h>
#include <string.h>

#define MaxSize 9

void Getnext(int next[], const char *t);

int KMP(const char *s, const char *t);

int main(int argc, char *argv[])
{
	char s[] = "1213ababaaaba12312312312";
	char t[] = "ababaaaba";

	int res = KMP(s, t);
	if (res == -1)
	{
		printf("not found ipos\n");
		return -1;
	}

	printf("ipos==%d\n", res);
	return 0;
}

void Getnext(int next[], const char *t)
{
	size_t j = 0;
	int k = -1; //j-后缀最后一个位置, k-前缀最后一个位置
	next[0] = -1;

	while (j < strlen(t) - 1)
	{
		if (k == -1 || t[j] == t[k])
		{
			j++;
			k++;
			if (t[j] == t[k]) //当两个字符相同时,就跳过
			{
				next[j] = next[k];
				continue;
			}
			next[j] = k;
			continue;
		}

		k = next[k]; //回退
	}
}

int KMP(const char *s, const char *t)
{
	int next[MaxSize];
	int i, j;

	Getnext(next, t);
	for (i = 0; i < MaxSize; ++i)
	{
		printf("%d ", next[i]);
	}
	printf("\n");

	i = 0; j = 0;
	int p =strlen(s);
	int q =strlen(t);

	while ( (i < p) && (j < q) )
	{//开始时i为s的起始位置, j为t的起始位置
		if ( (-1 == j) || (s[i] == t[j]) )
		{
			++i;
			++j;
		}
		else
		{
			j = next[j]; // j回退 
		}
	}
	printf("i=%d j=%d\n", i, j);

	if (j >= q) // 找到i为匹配s的最后位置, j为t的最后位置
	{
		return (i - q);
	}

	return -1;
}
