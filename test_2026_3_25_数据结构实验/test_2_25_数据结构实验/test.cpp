#include<iostream>
using namespace std;

template<class T>
class Node
{
public:

	Node(T val)
		:_data(val)
		,left(nullptr)
		,right(nullptr)
	{ }

	T _data;
	Node* left;
	Node* right;
};
template<class T>
class Tree
{
	typedef Node<T> Node;
public:
	Node* CreateBtree()
	{
		//先序创建二叉树
		char val = 0;
		cin >> val;
		if (val == '#')
		{
			return nullptr;
		}

		Node* new_node = new Node(val);
		
		cout << "请输入左子树的值" << endl;
		Node* left = CreateBtree();
		new_node->left = left;

		cout << "请输入右子树的值" << endl;
		Node* right = CreateBtree();
		new_node->right = right;


		return new_node;
	}
	Tree()
	{
		_root = CreateBtree();
	}

	void destory_tree(Node* root)
	{
		if (root == nullptr)
			return;

		destory_tree(root->left);
		destory_tree(root->right);

		delete root;
	}

	~Tree()
	{
		if (_root == nullptr)
			return;

		destory_tree(_root->left);
		destory_tree(_root->right);

		delete _root;

	}

	//前序遍历
	void PreOrder(Node* root )
	{
		if (root == nullptr)
			return;
		cout << root->_data;
		PreOrder(root->left);
		PreOrder(root->right);

	}
	//中序遍历
	void InOrder(Node* root )
	{
		if (root == nullptr)
			return;
		InOrder(root->left);
		cout << root->_data;
		InOrder(root->right);
	}

	void PestOrder(Node* root )
	{
		if (root == nullptr)
			return;
		PestOrder(root->left);
		PestOrder(root->right);
		cout << root->_data;
	}

	void PreOrder()
	{
		if (_root == nullptr)
			return;
		cout << _root->_data;
		PreOrder(_root->left);
		PreOrder(_root->right);

	}
	//中序遍历
	void InOrder()
	{
		if (_root == nullptr)
			return;
		InOrder(_root->left);
		cout << _root->_data;
		InOrder(_root->right);
	}

	void PestOrder()
	{
		if (_root == nullptr)
			return;
		PestOrder(_root->left);
		PestOrder(_root->right);
		cout << _root->_data;
	}

	

	void CountDegree(Node* root)
	{
		if (root == nullptr)
			return;

		int child_count = 0;
		if (root->left) child_count++;
		if (root->right) child_count++;

		switch (child_count)
		{
		case(0):
			{
				count0++;
				break;
			}
		case(1):
			{
				count1++;
				break;
			}
		case(2):
			{
				count2++;
				break;
			}
		}

		CountDegree(root->left);
		CountDegree(root->right);
	}
	void CountDegree()
	{
		if (_root == nullptr)
			return;

		int child_count = 0;
		if (_root->left) child_count++;
		if (_root->right) child_count++;

		switch (child_count)
		{
		case(0):
			{
				count0++;
				break;
			}
		case(1):
			{
				count1++;
				break;
			}
		case(2):
			{
				count2++;
				break;
			}
		}

		CountDegree(_root->left);
		CountDegree(_root->right);
	}

	int GetDeepth()
	{
		if (_root == nullptr)
			return 0;
		int left_deep = GetDeepth(_root->left) + 1;
		int right_deep = GetDeepth(_root->right) + 1;

		return (left_deep > right_deep ? left_deep : right_deep );
	}
	int GetDeepth(Node* root)
	{
		if (root == nullptr)
			return 0;
		int left_deep = GetDeepth(root->left) + 1;
		int right_deep = GetDeepth(root->right) + 1;

		return (left_deep > right_deep ? left_deep : right_deep);
	}
public:
	int count0 = 0;
	int count1 = 0;
	int count2 = 0;

private:
	
	Node* _root;
};



int main()
{
	Tree<char> tree1;
	tree1.PreOrder();

	tree1.CountDegree();
	cout << tree1.count0 << " " << tree1.count1 << " " << tree1.count2 << endl;

	cout << tree1.GetDeepth() << endl;

	return 0;
}

