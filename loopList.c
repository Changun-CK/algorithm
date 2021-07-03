/* 
 * 本程序用于解决约瑟夫问题
 * 1到41人围成一圈, 从第一个人开始报数, 每数到3的人自杀, 然后下一个人接着数数, 求死亡顺序
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

typedef struct Node *LoopList;

LoopList createList(int n); // n为人数
void deleteAndPrintList(LoopList head, int m); // m为第多少个人要自杀

int main(int argc, char *argv[])
{
	int n = 41;
	int m = 3;
	m = m % n; // 3, 这里考虑m>n的情况, 所以取余

	LoopList head = createList(n);

	deleteAndPrintList(head, m);

	return 0;
}

LoopList createList(const int n)
{
	int i = 1;
	LoopList head;
	LoopList p;// 指向当前节点的指针
	LoopList s = NULL;
	head = (LoopList)malloc(sizeof(Node));
	if (!head)
	{
		exit(1);
	}

	p = head;
	if (n > 0)
	{
		while (i <= n)
		{
			s = (LoopList)malloc(sizeof(Node));
			if (!s)
			{
				exit(1);
			}
			s->data = i++; // 1, 2, 3, ... , 41
			p->next = s;
			p = s;
		}
		s->next = head->next; // 循环链表
	}

	free(head);

	return s->next;
}

void deleteAndPrintList(LoopList head, int m)
{
	int i = 0;
	LoopList tmp = NULL;
	while (head != head->next)
	{
		for (i = 1; i < m - 1; ++i)
		{
			head = head->next;
		}

		printf("%d->", head->next->data);

		tmp = head->next;
		head->next = tmp->next;
		free(tmp);

		head = head->next;
	}

	printf("%d\n", head->data);

	free(head);
}
