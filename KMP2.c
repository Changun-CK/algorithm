#include <stdio.h>
#include <string.h>

#define MaxSize 9

void Getnext(int next[], const char *t);

int KMP(const char *s, const char *t);

int main(int argc, char *argv[])
{
	char s[] = "ababababaaababaaabaaba";
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
	//r-后缀最后一个位置, l-前缀最后一个位置
	int l = -1;
	int r = 0;
	int tlen = strlen(t);
	next[0] = -1;

	while (r < tlen - 1)
	{
		if (l == -1 || t[l] == t[r])
		{
			l++;
			r++;
			if (t[l] == t[r])
			{
				next[r] = next[l];
			}
			else
			{
				next[r] = l;
			}
		}
		else
		{
			l = next[l];
		}
	}
}

int KMP(const char *s, const char *t)
{
	int next[MaxSize];
	Getnext(next, t);
	int p = strlen(s);
	int q = strlen(t);
	//printf("p = %d, q = %d\n", p, q);
	//for (i = 0; i < MaxSize; ++i)
	//{
	//	printf("%d ", next[i]);
	//}
	//printf("\n");

	int i = 0, j = 0;
	while ((i < p) && (j < q))
	{
		if ( -1 == j || s[i] == t[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j]; // j回退
		}
		printf("i = %d, j = %d\n", i, j);
	}
	//printf("i = %d, j = %d\n", i, j);

	if (j == q) // 找到i为匹配s的最后位置, j为t的最后位置
	{
		return i - q;
	}

	return -1;
}
