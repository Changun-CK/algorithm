#include "LinkList.h"

LinkList CraeteNode(ElemType e)
{
	LinkList L = (LinkList)malloc(sizeof(Node));
	if (L == NULL)
	{
		exit(1);
	}

	L->data = e;
	L->next = NULL;

	return L;
}

int GetElem(LinkList L, int i, ElemType *e)
{
	int j = 1;
	LinkList p;
	p = L->next; // 链表的第一个节点

	while (p && (j < i))
	{
		p = p->next; // p指向下一个节点
		++j;
	}
	if (!p || (j > i))
	{
		return 0;
	}

	*e = p->data;

	return 1;
}

int ListInsert(LinkList *L, int i, ElemType e)
{
	int j = 1;
	LinkList p, s;
	p = *L;

	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || (j > i))
	{
		return 0;
	}

	s = (LinkList)malloc(sizeof(Node));
	if (s == NULL)
	{
		exit(1);
	}
	s->data = e;
	s->next = p->next;
	p->next = s;

	return 1;
}

int ListDelete(LinkList *L, int i, ElemType *e)
{
	int j = 1;
	LinkList p, q;
	p = *L;

	while (p->next && (j < i))
	while (p && (j < i))
	{
		p = p->next; // 寻找第i-1个节点
		++j;
	}
	if ((!(p->next)) || (j > i))
	if (!p || (j > i))
	{
		return 0;
	}

	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);

	return 1;
}

void InsertListHead(LinkList *L, ElemType e)
{
	LinkList q = NULL;
	LinkList Ltmp = CraeteNode(e);
	if (*L == NULL)
	{
		*L = Ltmp;
		Ltmp->next = NULL;
		return;
	}

	q = *L;
	*L = Ltmp;
	Ltmp->next = q;
}

void InsertListTail(LinkList *L, ElemType e)
{
	LinkList Ltmp = CraeteNode(e);
	if (*L == NULL)
	{
		*L = Ltmp;
		Ltmp->next = NULL;
		return;
	}

	LinkList Ltail = *L;
	while (Ltail->next != NULL)
	{
		Ltail = Ltail->next;
	}

	Ltail->next = Ltmp;
	Ltmp->next = NULL;
}

void ClearList(LinkList *L)
{
	LinkList p = NULL;
	while (*L)
	{
		p = *L;
		*L = (*L)->next;
		free(p);
	}
}

int LocateElem(LinkList L, ElemType e)
{
	int Len = 0;
	LinkList Ltmp = L->next;

	while (Ltmp->next)
	{
		Len++;
		if (Ltmp->data == e)
		{
			return Len;
		}
		Ltmp = Ltmp->next;
	}

	return Len;
}

int ListLength(LinkList L)
{
	LinkList Ltmp = L;
	int Len = 0;
	while (Ltmp)
	{
		Ltmp = Ltmp->next;
		Len++;
	}

	return Len;
}

void unionList(LinkList *La, LinkList Lb)
{
	int La_len, Lb_len, i;
	ElemType e;
	La_len = ListLength(*La);
	Lb_len = ListLength(Lb);
	for (i = 1; i <= Lb_len; ++i)
	{
		GetElem(Lb, i, &e);
		if (!LocateElem(*La, e)) // 若La不存在e,则插入
		{
			ListInsert(La, ++La_len, e);
		}
	}
}

void printList(LinkList L)
{
	LinkList Ltmp = L;
	printf("head->");
	while (Ltmp)
	{
		printf("%d->", Ltmp->data);
		Ltmp = Ltmp->next;
	}
	printf("end\n");
}
