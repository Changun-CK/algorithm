#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef int Type;
typedef struct BSTreeNode
{
	Type              key;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
	struct BSTreeNode *parent;
}Node, *BSTree;

/* 创建节点 */
static Node *create_bstree_node(Type key, Node *parent, Node *left, Node *right);
/* 插入节点 */
static Node *bstree_insert(BSTree tree, Node *z);
Node *insert_bstree(BSTree tree, Type key);
/* 删除节点 */
static Node *bstree_delete(BSTree tree, Node *z);
Node *delete_bstree(BSTree tree, Type key);
/* 前序遍历 */
void preorder_bstree(BSTree tree);
/* 递归查找 */
Node *bstree_search(BSTree x, Type key);
/* 查找最大值 */
Node *bstree_maximum(BSTree tree);
/* 查找最小值 */
Node *bstree_minimum(BSTree tree);
/* 查找前驱节点 */
Node *bstree_predecessor(Node *x);
/* 查找后继节点 */
Node *bstree_successor(Node *x);
/* 打印二叉树 */
void print_bstree(BSTree tree, Type key, int direction);
/* 销毁二叉树 */
void destroy_bstree(BSTree tree);

int main(int argc, char *argv[])
{
	BSTree tree = NULL;
	tree = insert_bstree(tree, 5);
	tree = insert_bstree(tree, 6);
	tree = insert_bstree(tree, 6);
	tree = insert_bstree(tree, 11);
	tree = insert_bstree(tree, 21);
	tree = insert_bstree(tree, 0);
	tree = insert_bstree(tree, 3);
	tree = insert_bstree(tree, 3);
	tree = insert_bstree(tree, 9);
	tree = insert_bstree(tree, 7);
	tree = insert_bstree(tree, 8);
	tree = insert_bstree(tree, 1);

	printf("printf bstree\n");
	print_bstree(tree, 0, 0);

	printf("delete 6 and 8\n");
	tree = delete_bstree(tree, 6);
	tree = delete_bstree(tree, 8);

	printf("printf bstree\n");
	print_bstree(tree, 0, 0);

	Type max = bstree_maximum(tree)->key;
	printf("max is %d\n", max);

	Type min = bstree_minimum(tree)->key;
	printf("min is %d\n", min);

	printf("insert 4 to bstree\n");
	tree = insert_bstree(tree, 4);
	printf("printf bstree\n");
	print_bstree(tree, 0, 0);
	//destroy_bstree(tree);

	return 0;
}

static Node *create_bstree_node(Type key, Node *parent, Node *left, Node *right)
{
	Node *p = (Node *)malloc(sizeof(Node));
	if (!p)
	{
		return NULL;
	}

	p->key = key;
	p->left = left;
	p->right = right;
	p->parent = parent;

	return p;
}

static Node *bstree_insert(BSTree tree, Node *z)
{
	Node *y = NULL; // 记录插入位置
	Node *x = tree;

	// 查找z的插入位置
	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}

	z->parent = y;
	if (y == NULL)
	{
		tree = z;
	}
	else if (z->key < y->key)
	{
		y->left = z;
	}
	else
	{
		y->right = z;
	}

	return tree;
}

Node *insert_bstree(BSTree tree, Type key)
{
	// 查找是否有相同节点, 若存在相同节点, 不插入
	if (NULL != bstree_search(tree, key))
	{
		//printf("NODE %d NOT NULL\n", key);
		return tree;
	}

	Node *z = NULL; // 新建节点

	// 如果新建节点失败, 则返回
	if ((z = create_bstree_node(key, NULL, NULL, NULL)) == NULL)
	{
		return tree;
	}

	return bstree_insert(tree, z);
}

static Node *bstree_delete(BSTree tree, Node *z)
{
	Node *x = NULL; // 待替换的节点
	Node *y = NULL; // 待删除的节点

	// 左孩子或者右孩子为空的情况,就是只有一个孩子或者两个孩子都没有的情况
	// 直接将z赋值给y
	if ((z->left == NULL) || (z->right == NULL))
	{
		y = z;
	}
	else // 两个孩子都存在的情况下, 直接找z的后继
	{
		y = bstree_successor(z);
	}

	// 那个后继节点的左子树不为空, 将左子树给x
	if (y->left != NULL)
	{
		x = y->left;
	}
	else // 那个后继节点的左子树为空, 那x就是y的右子树
	{
		x = y->right;
	}

	// x节点不为空的情况, 将y的父节点赋值给x的父亲, 标准的删除操作, 这是为了删除后继节点y
	// 因为删除的思路就是用后继节点来替换删除的那个节点
	if (x != NULL)
	{
		x->parent = y->parent;
	}

	// 如果y没有父亲了, y是比较靠近树根的点
	if (y->parent == NULL)
	{
		tree = x;
	}
	else if (y == y->parent->left)
	{
		y->parent->left = x;
	}
	else
	{
		y->parent->right = x;
	}

	if (y != z)
	{
		z->key = y->key;
	}

	if (y != NULL)
	{
		free(y);
	}

	return tree;
}

Node *delete_bstree(BSTree tree, Type key)
{
	Node *z, *node;

	if ((z = bstree_search(tree, key)) != NULL)
	{
		tree = bstree_delete(tree, z);
	}

	return tree;
}

void preorder_bstree(BSTree tree)
{
	if (tree)
	{
		printf("%d ", tree->key);
		preorder_bstree(tree->left);
		preorder_bstree(tree->right);
	}
}

Node *bstree_search(BSTree x, Type key)
{
	if (!x || x->key == key)
	{
		return x;
	}

	if (key < x->key)
	{
		return bstree_search(x->left, key);
	}

	if (key > x->key)
	{
		return bstree_search(x->right, key);
	}
}

Node *bstree_maximum(BSTree tree)
{
	if (!tree)
	{
		return NULL;
	}

	while (tree->right)
	{
		tree = tree->right;
	}

	return tree;
}

Node *bstree_minimum(BSTree tree)
{
	if (!tree)
	{
		return NULL;
	}

	while (tree->left)
	{
		tree = tree->left;
	}

	return tree;
}

Node *bstree_predecessor(Node *x)
{
	// 即是该节点的左子树的最大节点
	// 如果x存在左孩子, 则 "x的前驱节点" 为 "以其左孩子为根的子树的最大节点"
	if (x->left)
	{
		return bstree_maximum(x->left);
	}

	// 如果x没有左孩子, 则x有以下两种可能:
	// x是"一个右孩子", 则x的前驱节点为 "它的父节点"
	// x是"一个左孩子", 则查找 "x的最低的父节点, 并且该父节点要具有右孩子", 找到的这个 "最低父节点" 就是 "x的前驱节点"
	Node *y = x->parent;
	while ((y != NULL) && (x == y->left))
	{
		x = y;
		y = y->parent;
	}

	return y;
}

Node *bstree_successor(Node *x)
{
	// 即是该节点的右子树中最小节点
	// 如果x存在右孩子, 则 "x的后继节点" 为 "以其右孩子为根的子树的最小节点"
	if (x->right != NULL)
	{
		return bstree_minimum(x->right);
	}

	// 如果x没有右孩子, 则x有以下两种可能
	// x 是 "一个左孩子", 则 "x的后继节点" 为 "它的父节点"
	// x 是 "一个右孩子", 则查找 "x的最低的父节点, 并且该父节点要具有左孩子", 找到这个 "最低父节点" 就是 "x的后继节点"
	Node *y = x->parent;
	while ((y != NULL) && (x == y->right))
	{
		x = y;
		y = y->parent;
	}

	return y;
}

void print_bstree(BSTree tree, Type key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0) // tree为根节点, direction==0代表是根节点,direction==-1代表是左节点, direction==1代表是右节点
		{
			printf("%2d is root\n", tree->key);
		}
		else
		{
			printf("%2d is %2d's %6s child\n", tree->key, key, direction == 1 ? "right" : "left");
		}

		print_bstree(tree->left, tree->key, -1);
		print_bstree(tree->right, tree->key, 1);
	}
}

void destroy_bstree(BSTree tree)
{
	if (tree == NULL)
	{
		return;
	}

	if (tree->left != NULL)
	{
		destroy_bstree(tree->left);
	}

	if (tree->right != NULL)
	{
		destroy_bstree(tree->right);
	}

	free(tree);
}
