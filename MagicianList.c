/*
 * 本程序利用循环单向链表实现魔术师发牌, 求魔术师应该摆放牌的顺序
 * 要求从第一张牌开始, 每次取完牌都从该位置抽出并从该位置继续取, 不可改变取牌的方向, 取到最后要循环取牌, 每次跳过取牌数量+1, 要求跳多少牌和取到牌要相等, 即每次取到的牌的顺序为1,2,3...
 * 例如:1, 8, 2, 5, 10, 3, 12, 11, 9, 4, 7, 6, 13
 */
#include <stdio.h>
#include <stdlib.h>

#define CardNumber 13

typedef struct Node
{
	int data;
	struct Node *next;
}Node, *LoopList;

LoopList CreateLoopList();
void Magician(LoopList head); // 摆牌的顺序计算
void DestoryList(LoopList *head);

int main()
{
	LoopList p;
	int i;

	p = CreateLoopList();
	Magician(p);

	for (i = 0; i < CardNumber; i++)
	{
		printf("黑桃%d ", p->data);
		p = p->next;
	}
	printf("\n");

	DestoryList(&p);

	return 0;
}

LoopList CreateLoopList()
{
	int i;
	LoopList s, r;
	LoopList head = NULL;
	r = head;

	for (i = 1; i <= CardNumber; ++i)
	{
		s = (LoopList)malloc(sizeof(Node));
		s->data = 0;

		if (head == NULL)
		{
			head = s;
		}
		else
		{
			r->next = s;
		}

		r = s; // 总是指向当前节点
	}

	r->next = head; // 循环链表

	return head;
}

void Magician(LoopList head)
{
	LoopList p;
	int j;
	int CountNumber= 2;

	p = head;
	p->data = 1; // 第一张牌放1

	while (1)
	{
		for (j = 0; j < CountNumber; j++)
		{
			p = p->next;
			if (p->data != 0) // 若该位置有牌的话则跳到下一个位置, 重点
			{
				p->next;
				--j;
			}
		}

		if (p->data == 0)
		{
			p->data = CountNumber;
			++CountNumber;
			if (CountNumber > CardNumber) // 超过了最大牌则退出
			{
				break;
			}
		}
	}
}

void DestoryList(LoopList *head)
{
	LoopList ptr = *head;
	LoopList buffer[CardNumber];
	int i = 0;

	while (i < CardNumber)
	{
		buffer[i++] = ptr;
		ptr = ptr->next;
	}

	for (i = 0; i < CardNumber; ++i)
	{
		free(buffer[i]);
	}

	*head = NULL;
}
