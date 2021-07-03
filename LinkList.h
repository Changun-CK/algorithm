#ifndef _LINK_LIST_H
#define _LINK_LIST_H 1

#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0
/* 说明,本接口的所有位置元素都是1开始,而非0开始,不是具有头节点的链表 */

typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef Node *LinkList;

static LinkList CraeteNode(ElemType e);  // 生成一个节点
void InsertListHead(LinkList *L, ElemType e); // 头插法
void InsertListTail(LinkList *L, ElemType e); // 尾插法
//int  ListEmpty(LinkList *L); // 若线性表为空,返回TRUE,否则返回FALSE
void ClearList(LinkList *L); // 将线性表清空
int  GetElem(LinkList L, int i, ElemType *e); // 将线性表L中的第i个元素值返回给e,成功返回1,失败返回0
int  LocateElem(LinkList L, ElemType e); // 查找给定值e相等的元素,如果查找成功,返回该元素在表中的序号,否则返回0表示失败
int  ListInsert(LinkList *L, int i, ElemType e); // 在线性表L中的第i个位置插入新元素e
int  ListDelete(LinkList *L, int i, ElemType *e); // 删除线性表L中的第i个位置的元素,并用e返回其值
int  ListLength(LinkList L); // 线性表L的元素个数
void unionList(LinkList *La, LinkList Lb); // 线性表La和Lb的并集
void printList(LinkList L); // 打印线性表L

#endif /* _LINK_LIST_H */
