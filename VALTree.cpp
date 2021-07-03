#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 平衡二叉树节点
template <typename T>
struct AvlNode
{
	T data;
	int height; // 当前节点的高度
	AvlNode<T> *left;
	AvlNode<T> *right;

	AvlNode<T> (const T theData)
		: data(theData), left(nullptr), right(nullptr), height(0)
	{
	}
};

// AvlTree
template <typename T>
class AvlTree
{
public:
	AvlTree<T>() :root(nullptr) {}
	~AvlTree<T>() {}
	AvlNode<T> *root;

	// 插入节点
	void Insert(AvlNode<T> *&t, T x);
	// 删除节点
	bool Delete(AvlNode<T> *&t, T x);
	// 查找是否存在给定值得节点
	bool Contains(AvlNode<T> *t, const T x) const;
	// 中序遍历
	void InorderTraversal(AvlNode<T> *t);
	// 前序遍历
	//void PreorderTraversal(AvlNode<T> *t);
	// 最小值节点
	AvlNode<T> *FindMin(AvlNode<T> *t) const;
	// 最大值节点
	AvlNode<T> *FindMax(AvlNode<T> *t) const;

private:
	// 求树的高度
	int GetHeight(AvlNode<T> *t);
	// 单旋转, 左左
	AvlNode<T> *LL(AvlNode<T> *t);
	// 单旋转, 右右
	AvlNode<T> *RR(AvlNode<T> *t);
	// 双旋转, 左右
	AvlNode<T> *LR(AvlNode<T> *t);
	// 双旋转, 右左
	AvlNode<T> *RL(AvlNode<T> *t);
};

template <typename T>
AvlNode<T> *AvlTree<T>::FindMax(AvlNode<T> *t) const
{
	if (nullptr == t)
	{
		return t;
	}
	if (nullptr == t->right)
	{
		return t;
	}

	return FindMax(t->right);
}

template <typename T>
AvlNode<T> *AvlTree<T>::FindMin(AvlNode<T> *t) const
{
	if (nullptr == t)
	{
		return t;
	}
	if (nullptr == t->left)
	{
		return t;
	}

	return FindMin(t->left);
}

template <typename T>
int AvlTree<T>::GetHeight(AvlNode<T>* t)
{
	if (nullptr == t)
	{
		return -1;
	}
	else
	{
		return t->height;
	}
}

// 单旋转
// 左左插入导致的不平衡
template <typename T>
AvlNode<T> *AvlTree<T>::LL(AvlNode<T> *t)
{
	AvlNode<T> *q = t->left;
	t->left = q->right;
	q->right = t;
	t = q;
	t->height = max(GetHeight(t->left), GetHeight(t->right)) + 1;
	q->height = max(GetHeight(q->left), GetHeight(q->right)) + 1;

	return q;
}

// 单旋转
// 右右插入导致的不平衡
template <typename T>
AvlNode<T> *AvlTree<T>::RR(AvlNode<T> *t)
{
	AvlNode<T> *q = t->right;
	t->right = q->left;
	q->left = t;
	t = q;
	t->height = max(GetHeight(t->left), GetHeight(t->right)) + 1;
	q->height = max(GetHeight(q->left), GetHeight(q->right)) + 1;

	return q;
}

// 双旋转
// 插入点位于t的左子树的右子树
template <typename T>
AvlNode<T> *AvlTree<T>::LR(AvlNode<T> *t)
{
	// 双旋转可以通过两次单旋转实现
	// 对t的左节点进行RR旋转, 再对根节点进行LL旋转
	AvlNode<T> *q = RR(t->left); // 旋转
	t->left = q; // 连接, 因为此时t的左节点已经改变了
	return LL(t);
}

// 双旋转
// 插入点位于t的右子树的左子树
template <typename T>
AvlNode<T> *AvlTree<T>::RL(AvlNode<T> *t)
{
	// 双旋转可以通过两次单旋转实现
	// 对t的右节点进行LL旋转, 再对根节点进行RR旋转
	AvlNode<T> *q = LL(t->right); // 旋转
	t->right = q;
	return RR(t);
}

template <typename T>
void AvlTree<T>::Insert(AvlNode<T> *&t, T x)
{
	if (nullptr == t)
	{
		t = new AvlNode<T>(x);
	}
	else if (x < t->data)
	{
		Insert(t->left, x);
		// 判断平衡情况
		// 分两种情况, 左左和右右
		if (GetHeight(t->left) - GetHeight(t->right) > 1)
		{
			if (x < t->left->data)
			{
				t = LL(t);
			}
			else
			{
				t = LR(t);
			}
		}
	}
	else if (x > t->data)
	{
		Insert(t->right, x);
		if (GetHeight(t->right) - GetHeight(t->left) > 1)
		{
			if (x > t->right->data)
			{
				t = RR(t);
			}
			else
			{
				t = RL(t);
			}
		}
	}
	else
	{
		; // 重复数据不插入
	}

	t->height = max(GetHeight(t->left), GetHeight(t->right)) + 1;
}

template <typename T>
bool AvlTree<T>::Delete(AvlNode<T> *&t, T x)
{
	// t为空
	if (nullptr == t)
	{
		return false;
	}
	else if (t->data == x)
	{
		// 左右子树都非空
		if (nullptr != t->left && nullptr != t->right)
		{
			// 在高度更大的那个子树上进行删除操作
			// 左子树高度大, 删除左子树中值最大的节点, 将其赋值给根节点
			// 右子树高度大, 删除右子树中值最小的节点, 将其赋值给根节点
			if (GetHeight(t->left) > GetHeight(t->right))
			{
				t->data = FindMax(t->left)->data;
				Delete(t->left, t->data);
			}
			else
			{
				t->data = FindMin(t->right)->data;
				Delete(t->right, t->data);
			}
		}
		else
		{
			// 左右子树有一个不为空, 直接用需要删除的节点的子节点替换即可
			AvlNode<T> *old = t;
			if (nullptr != t->left)
			{
				t = t->left;
			}
			else
			{
				t = t->right;
			}
			delete old;
		}
	}
	else if (x < t->data) // 需要删除的节点在左子树中
	{
		// 递归删除左子树上的节点
		Delete(t->left, x);
		// 判断是否仍然满足平衡条件
		if (GetHeight(t->right) - GetHeight(t->left) > 1)
		{
			if (GetHeight(t->right->left) > GetHeight(t->right->right))
			{
				t = RL(t);
			}
			else
			{
				t = RR(t);
			}
		}
		else
		{
			t->height = max(GetHeight(t->left), GetHeight(t->right)) + 1;
		}
	}
	else
	{
		// 递归删除右子树上的节点
		Delete(t->right, x);
		// 判断是否仍然满足平衡条件
		if (GetHeight(t->left) - GetHeight(t->right) > 1)
		{
			if (GetHeight(t->left->right) > GetHeight(t->left->left))
			{
				t = LR(t);
			}
			else
			{
				t = LL(t);
			}
		}
		else
		{
			t->height = max(GetHeight(t->left), GetHeight(t->right)) + 1;
		}
	}

	return true;
}

// 查找节点
template <typename T>
bool AvlTree<T>::Contains(AvlNode<T> *t, const T x) const
{
	if (nullptr == t)
	{
		return false;
	}
	if (x < t->data)
	{
		return Contains(t->left, x);
	}
	else if (x > t->data)
	{
		return Contains(t->right, x);
	}
	else
	{
		return true;
	}
}

// 中序遍历
template <typename T>
void AvlTree<T>::InorderTraversal(AvlNode<T> *t)
{
	if (nullptr != t)
	{
		InorderTraversal(t->left);
		cout << t->data << ' ';
		InorderTraversal(t->right);
	}
}

int main(int argc, char *argv[])
{
	AvlTree<int> tree;
	int value;
	int tmp;
	vector<int> vecvalue = {-1, 1, 20, 12, 18, 16, 15, 13};
	for (auto i : vecvalue)
	{
		tree.Insert(tree.root, i);
	}
	cout << "中序遍历\n";
	tree.InorderTraversal(tree.root);
	cout << '\n';
	cout << "\n请输入要查找的结点：";
	cin >> tmp;
	if (tree.Contains(tree.root, tmp))
	{
		cout << "已找到\n";
	}
	else
	{
		cout << "未找到\n";
	}
	cout << "\n请输入要删除的结点：";
	cin >> tmp;
	tree.Delete(tree.root, tmp);
	cout << "\n删除后的中序遍历\n";
	tree.InorderTraversal(tree.root);
	cout << '\n';

	return 0;
}
