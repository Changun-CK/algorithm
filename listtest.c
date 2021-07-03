#include <stdio.h>
#include <stdlib.h>

typedef int dataType;

typedef struct LinkList
{
	dataType data;
	struct LinkList *next;
}LinkList;

/* 用快慢指针返回中间节点的数据域, 节点个数为偶数时结果为靠头指针(左边)的数据*/
dataType GetMidNode(LinkList *L);
LinkList *CreateNode();
void printList(LinkList *head);
void insertListByHead(LinkList **head, dataType data); // 头插法
void releaseList(LinkList **L);

int main(int argc, char *argv[])
{
	LinkList *head = NULL;
	insertListByHead(&head, 3);
	insertListByHead(&head, 4);
	insertListByHead(&head, 5);
	insertListByHead(&head, 6);
	insertListByHead(&head, 2);
	insertListByHead(&head, 8);
	printList(head);
	dataType tmp = GetMidNode(head);
	printf("mid == %d\n", tmp);

	releaseList(&head);

	return 0;
}

dataType GetMidNode(LinkList *L)
{
	LinkList *search, *mid;
	mid = search = L;

	while (search->next != NULL)
	{
		//tmp 的移动速度是mid的2倍
		if (search->next->next != NULL)
		{
			search = search->next->next;
			mid = mid->next;
		}
		else
		{
			search = search->next;
		}
	}
	return (mid->data);
}

LinkList *CreateNode(dataType data)
{
	LinkList *tmp = (LinkList *)malloc(sizeof(LinkList));
	if (tmp == NULL)
	{
		exit(1);
	}
	tmp->data = data;
	tmp->next = NULL;
	return tmp;
}

void printList(LinkList *head)
{
	LinkList *tmp;
	tmp = head;
	printf("head->");
	while (tmp)
	{
		printf("%d->", tmp->data);
		tmp = tmp->next;
	}
	printf("end\n");
}

void insertListByHead(LinkList **head, dataType data)
{
	LinkList *Node = CreateNode(data);
	LinkList *tmp;
	if (*head)
	{
		tmp = *head;
		*head = Node;
		Node->next = tmp;
	}
	else
	{
		*head = Node;
		Node->next = NULL;
	}
}

void releaseList(LinkList **L)
{
	LinkList *tmp = NULL;
	while (*L)
	{
		tmp = *L;
		*L = (*L)->next;
		free(tmp);
	}
}
