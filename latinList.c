#include <stdio.h>
#include <stdlib.h>

#define NUM 9

typedef struct Node
{
	int data;
	struct Node *next;
}Node, *LinkList;

LinkList Create();
void printListByLatin(LinkList head);

int main()
{
	LinkList head;
	head = Create();
	printListByLatin(head);

	return 0;
}

LinkList Create()
{
	int i;
	LinkList head = NULL;
	LinkList s, r;

	r = head;

	for (i = 0; i < NUM; ++i)
	{
		s = (LinkList)malloc(sizeof(Node));
		if (!s)
		{
			exit(1);
		}
		s->data = i + 1;
		if (!head)
		{
			head = s;
		}
		else
		{
			r->next = s;
		}
		r = s;
	}

	s->next = head;
	return head;
}

void printListByLatin(LinkList head)
{
	//int i = 0;
	//for (i = 0; i < NUM; ++i)
	//{
	//	if (i == NUM-1)
	//	{
	//		printf("%d", head->data);
	//		break;
	//	}
	//	printf("%d->", head->data);
	//	head = head->next;
	//}
	//printf("\n");
	int i = 0;
	LinkList tmp = head;
	LinkList s = head;
	LinkList q = head;
	while (1)
	{
		++i;
		while (tmp->next != s)
		{
			printf("%d->", tmp->data);
			tmp = tmp->next;
		}
		printf("%d\n", tmp->data);

		tmp = tmp->next->next; //记录tmp的next指针, 下一次迭代起点
		s = s->next;           //记录s的next指针

		if (i == NUM)
		{
			break;
		}
	}
}
