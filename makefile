CC=gcc
CXX=g++
FLAG=-g -O2 -W

all: listtest sort libLinkList.a mainList loopList MagicianList latinList swap RedBlackTree BSTree findNum hanoi KMP queen BinaryTree findFibonacci HashTable LinkList LinkList_with_head SqList SqStack spiralMatrix topN threadControl

listtest:listtest.c
	$(CC) $(FLAG) -o listtest listtest.c
	cp listtest bin/.

sort:sort.c
	$(CC) $(FLAG) -o sort sort.c
	cp sort bin/.

libLinkList.a:LinkList.c LinkList.h
	$(CC) -c -o libLinkList.a LinkList.c
	cp libLinkList.a bin/.

mainList:mainList.c
	$(CC) $(FLAG) -o mainList mainList.c libLinkList.a
	cp mainList bin/.

loopList:loopList.c
	$(CC) $(FLAG) -o loopList loopList.c
	cp loopList bin/.

MagicianList:MagicianList.c
	$(CC) $(FLAG) -o MagicianList MagicianList.c
	cp MagicianList bin/.

latinList:latinList.c
	$(CC) $(FLAG) -o latinList latinList.c
	cp latinList bin/.

swap:swap.c
	$(CC) $(FLAG) -o swap swap.c
	cp swap bin/.

RedBlackTree:RedBlackTree.cpp
	$(CXX) $(FLAG) -o RedBlackTree RedBlackTree.cpp
	cp RedBlackTree bin/.

BSTree:BSTree.c
	$(CC) $(FLAG) -o BSTree BSTree.c
	cp BSTree bin/.

findNum:findNum.c
	$(CC) $(FLAG) -o findNum findNum.c
	cp findNum bin/.

hanoi:hanoi.c
	$(CC) $(FLAG) -o hanoi hanoi.c
	cp hanoi bin/.

KMP:KMP.c
	$(CC) $(FLAG) -o KMP KMP.c
	cp KMP bin/.

queen:queen.c
	$(CC) $(FLAG) -o queen queen.c
	cp queen bin/.

BinaryTree:BinaryTree.cpp
	$(CXX) $(FLAG) -o BinaryTree BinaryTree.cpp
	cp BinaryTree bin/.

findFibonacci:findFibonacci.cpp
	$(CXX) $(FLAG) -o findFibonacci findFibonacci.cpp
	cp findFibonacci bin/.

HashTable:HashTable.cpp
	$(CXX) $(FLAG) -o HashTable HashTable.cpp
	cp HashTable bin/.

LinkList:LinkList.cpp
	$(CXX) $(FLAG) -o LinkList LinkList.cpp
	cp LinkList bin/.

LinkList_with_head:LinkList_with_head.cpp
	$(CXX) $(FLAG) -o LinkList_with_head LinkList_with_head.cpp
	cp LinkList_with_head bin/.

SqList:SqList.cpp
	$(CXX) $(FLAG) -o SqList SqList.cpp
	cp SqList bin/.

SqStack:SqStack.cpp
	$(CXX) $(FLAG) -o SqStack SqStack.cpp
	cp SqStack bin/.

spiralMatrix:spiralMatrix.cpp
	$(CXX) $(FLAG) -o spiralMatrix spiralMatrix.cpp
	cp spiralMatrix bin/.

topN:topN.cpp
	$(CXX) $(FLAG) -o topN topN.cpp
	cp topN bin/.

threadControl:threadControl.cpp
	$(CXX) $(FLAG) -o threadControl threadControl.cpp -lpthread
	cp threadControl bin/.

clean:
	rm -f bin/* listtest sort libLinkList.a mainList loopList MagicianList latinList swap RedBlackTree BSTree findNum hanoi KMP queen BinaryTree findFibonacci HashTable LinkList LinkList_with_head SqList SqStack spiralMatrix topN threadControl
