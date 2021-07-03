#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//5个常量定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

//测试程序长度定义
#define LONGTH 5

//类型定义
typedef int Status;
typedef int ElemType;

//顺序栈的类型
typedef struct
{
	ElemType *elem; // 整个栈的空间
	int top;  // 栈顶指针
	int size; // 元素个数
	int increment; // size-top, 栈满时为1, 栈空时为size
} SqSrack;

//初始化顺序栈
Status InitStack_Sq(SqSrack &S, int size, int inc);

//销毁顺序栈
Status DestroyStack_Sq(SqSrack &S);

//判断S是否为空, 若为空则返回TRUE, 否则返回FALSE
Status StackEmpty_Sq(SqSrack S);

//清空栈S
void ClearStack_Sq(SqSrack &S);

//元素e压入栈S
Status Push_Sq(SqSrack &S, ElemType e);

//取栈S的栈顶元素, 并用e返回
Status GetTop_Sq(SqSrack S, ElemType &e);

//栈S的栈顶元素出栈, 并用e返回
Status Pop_Sq(SqSrack &S, ElemType &e);


int main(int argc, char *argv[])
{
	//定义栈
	SqSrack S;

	//定义测量值
	int size, increment, i;

	//初始化测试值
	size = LONGTH;
	increment = LONGTH;
	ElemType e, eArray[LONGTH] = { 1, 2, 3, 4, 5 };

	//显示测试值
	printf("---[顺序栈]---\n");
	printf("栈的size为: %d\n栈的increment为: %d\n", size, increment);
	printf("待测试元素为: \n");
	for (i = 0; i < LONGTH; ++i)
	{
		printf("%d\t", eArray[i]);
	}
	printf("\n");

	//初始化顺序栈
	if (!InitStack_Sq(S, size, increment))
	{
		printf("初始化顺序栈失败\n");
		exit(0);
	}
	printf("已初始化顺序栈\n");

	//入栈
	for (i = 0; i < S.size; ++i)
	{
		if (!Push_Sq(S, eArray[i]))
		{
			printf("%d入栈失败\n", eArray[i]);
			exit(1);
		}
	}
	printf("已入栈\n");

	//判断非空
	if (StackEmpty_Sq(S))
	{
		printf("S栈为空\n");
	}
	else
	{
		printf("S栈非空\n");
	}

	//取栈S的栈顶元素
	printf("栈S的栈顶元素为:\n\n%d\n", GetTop_Sq(S, e));

	//栈S元素出栈
	printf("栈S出栈为:\n");
	for (i = 0; i < S.size; ++i)
	{
		printf("%d\t", Pop_Sq(S, e));
	}
	printf("\n");

	//清空栈
	ClearStack_Sq(S);
	printf("已清空栈S\n");

	getchar();

	return 0;
}

Status InitStack_Sq(SqSrack &S, int size, int inc)
{
	S.elem = (ElemType *)malloc(size * sizeof(ElemType));
	if (NULL == S.elem)
	{
		return OVERFLOW;
	}
	S.top = 0;
	S.size = size;
	S.increment = inc;

	return OK;
}

Status DestroyStack_Sq(SqSrack &S)
{
	free(S.elem);
	S.elem = NULL;

	return OK;
}

Status StackEmpty_Sq(SqSrack S)
{
	if (0 == S.top)
	{
		return TRUE;
	}

	return FALSE;
}

void ClearStack_Sq(SqSrack &S)
{
	if (0 == S.top)
	{
		return;
	}
	S.size = 0;
	S.top = 0;
}

Status Push_Sq(SqSrack &S, ElemType e)
{
	ElemType *newbase;
	if (S.top >= S.size)
	{
		newbase = (ElemType *)realloc(S.elem, (S.size + S.increment) * sizeof(ElemType));
		if (NULL == newbase)
		{
			return OVERFLOW;
		}
		S.elem = newbase;
		S.size += S.increment;
	}
	S.elem[S.top++] = e;

	return OK;
}

Status GetTop_Sq(SqSrack S, ElemType &e)
{
	if (0 == S.top)
	{
		return ERROR;
	}
	e = S.elem[S.top - 1];

	return e;
}

Status Pop_Sq(SqSrack &S, ElemType &e)
{
	if (0 == S.top)
	{
		return ERROR;
	}
	e = S.elem[S.top - 1];
	S.top--;

	return e;
}
