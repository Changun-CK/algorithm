#define MAX_TREE_SIZE 100

typedef char ElemType;

//child
typedef struct CTNode
{
	int child;
	struct CTNode *next;
} *ChildPtr;

//table top
typedef stuct
{
	ElemType data;
	int parent;
	ChildPtr firstchild;
} CTBox;

//tree
typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int r, n;
};
