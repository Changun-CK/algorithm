#include "LinkList.h"

int main(int argc, char *argv[])
{
	LinkList head = NULL;
	InsertListHead(&head, 1);
	InsertListHead(&head, 2);
	InsertListHead(&head, 3);
	InsertListHead(&head, 4); // 4, 3, 2, 1
	InsertListTail(&head, 1);
	InsertListTail(&head, 2);
	InsertListTail(&head, 3);
	InsertListTail(&head, 4); // 4, 3, 2, 1, 1, 2, 3, 4

	printList(head);

	LinkList headtmp = NULL;
	InsertListHead(&headtmp, 0);
	InsertListHead(&headtmp, 6);
	InsertListHead(&headtmp, 0);
	InsertListHead(&headtmp, 4);
	InsertListTail(&headtmp, 1);
	InsertListTail(&headtmp, 5);

	printList(headtmp);

	int e;
	ListDelete(&head, 3, &e);
	printf("e = %d\n", e);
	printList(head);
	ListInsert(&head, 4, 19);
	printList(head);
	printf("is==%d\n", LocateElem(head, 19));
	InsertListHead(&head, 0);
	printList(head);
	GetElem(head, 4, &e);
	printf("e = %d\n", e);
	ClearList(&headtmp);
	printList(headtmp);
	ClearList(&head);

	//e = ListEmpty(&headtmp);
	//printf("e = %d\n", e);

	return 0;
}
