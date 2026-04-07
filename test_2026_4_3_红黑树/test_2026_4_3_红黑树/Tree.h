#pragma once

#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
enum Colour
{
	RED,
	BLACK
};


// 这里我们默认按key/value结构实现
template<class T>
struct RBTreeNode
{
	// 这里更新控制平衡也要加入parent指针
	T _data;
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	Colour _col;


	RBTreeNode(const T& data)
		:_data(data)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
	{}
};

//在这里加上迭代器

template <class T,class Ref ,class Ptr>
class Iterator 
{
public:
	typedef RBTreeNode<T> Node;
	typedef Iterator<T, Ref, Ptr> Self;
	Node* _node;
	Node* _root;
	//确实是不得不实现以下构造函数
	//这里是为了在operator--时方便更新

	Iterator( Node* node,Node* root)
		:_node(node)
		,_root(root)
	{}

	Iterator(const Self& i)
	{
		_node = i._node;
		_root = i._root;
	}

	//这里实际上是省略了一次->实际上应该调用两个->
	Ptr operator->()
	{
		return &(_node->_data);
	}
	Ref operator*()
	{
		return _node->_data;
	}

	Self& operator++()
	{
		//这里的逻辑是存在右节点就移动到最右节点
		//假如没有最右节点，沿路径到最近的子树在左边的父节点
		if (_node->_right)
		{
			//需要找到右子树的最左值

			Node* cur = _node->_right;
			while (cur->_left)
			{
				cur = cur->_left;
			}
			_node = cur;
		}
		else
		{

			Node* cur = _node;
			Node* parent = _node->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = parent->_parent;
			}
			//这需要复习，还是掌握的不好			
			_node = parent;
		}


		return *this;
	}
	Self operator++(int)
	{
		Self ret(*this);
		operator++();

		return ret;
	}



	Self& operator--()
	{
		if (_node == nullptr)
		{
			Node* cur = _root;
			while (cur->_right)
			{
				cur = cur->_right;
			}
			_node = cur;
		}
		else if(_node->_left)
		{
			Node* cur = _node->_left;
			while (cur->_right)
			{
				cur = cur->_right;
			}
			_node = cur;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_left)
			{
				cur = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}


		return *this;
	}
	Self operator--(int)
	{
		Self ret(*this);
		operator--();

		return ret;
	}


	bool operator==(const Self& i)const
	{
		return _node == i._node;
	}
	bool operator!=(const Self& i)const
	{
		return _node != i._node;
	}


	//这里存在一个误区，operator[]函数并不是迭代器的函数

};



//template<class K, class V>
template<class K, class T ,class KeyofValue>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef Iterator<T, T&, T*> iterator;
	typedef Iterator<T,const T&,const T*> const_iterator;

	iterator begin()
	{
		Node* ret = _root;

		while (ret->_left)
		{
			ret = ret->_left;
		}
		return iterator(ret,_root);
	}
	const_iterator begin()const
	{
		Node* ret = _root;

		while (ret->_left)
		{
			ret = ret->_left;
		}
		return const_iterator(ret,_root);
	}
	//这是消除歧义的方法


	iterator end()
	{
		return iterator(nullptr, _root);
	}
	const_iterator end()const
	{
		return const_iterator(nullptr, _root);
	}
	//将nullptr作为end，保证左闭右开原则

 	


	pair<iterator,bool>  Insert(const T& data)  
	{
		//还是先插入
		KeyofValue get;

		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return {iterator(_root,_root),true};
		}

		Node* cur = _root;
		Node* parent = cur->_parent;
		while (cur)
		{
			if (get(data) > get(cur->_data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (get(data) < get(cur->_data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return {iterator(cur,_root),false};
			}
		}

		cur = new Node(data);
		if (get(data) > get(parent->_data))
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;
		cur->_col = RED;

		Node* ret = cur;

		Node* grandparent = parent->_parent;
		Node* uncle = nullptr;
		
		//这里是以parent_col来做判断
		while (parent && parent->_col == RED)
		{
			grandparent = parent->_parent;

			if (grandparent == nullptr)
				break;
			if (parent == grandparent->_left)
			{
				 uncle = grandparent->_right;
			}
			else
			{
				 uncle = grandparent->_left;
			}

			if (uncle && uncle->_col == RED)
			{
				//这时候将uncle节点置为BLACK节点
				uncle->_col = BLACK;
				parent->_col = BLACK;
				grandparent->_col = RED;
				cur = grandparent;
				parent = cur->_parent;

			}
			//这是统一变色处理
			else
			{
				if (parent == grandparent->_left)
				{
					
					if (cur == parent->_left)
					{

						//    g
						//  p   u
						// c
						RotateR(grandparent);
						//但是这里旋转过后需要保证这个根节点是黑色的

						parent->_col = BLACK;
						grandparent->_col = RED;

						//这个还没搞完，改日再议
						break;
						//此时这个子树的根节点还是黑色的，此时不需要向上更新
					}
					else
					{
						//   g 
						//  p   u
						//   c 
						RotateL(parent);
						RotateR(grandparent);

						cur->_col = BLACK;
						grandparent->_col = RED;

					}
				}
				else if (parent == grandparent->_right)
				{
					if (cur == parent->_right)
					{
						//   g 
						//  u    p
						//         c   

						RotateL(grandparent);
						//但是这里旋转过后需要保证这个根节点是黑色的

						parent->_col = BLACK;
						grandparent->_col = RED;

						//这个还没搞完，改日再议
						break;
						//此时这个子树的根节点还是黑色的，此时不需要向上更新
					}
					
					else
					{
						//   g 
						//  u    p
						//     c  

						RotateR(parent);
						RotateL(grandparent);

						cur->_col = BLACK;
						grandparent->_col = RED;
					}
				}
				else
				{
					assert(false);
				}
			}
		}
		_root->_col = BLACK;
		return {iterator(ret,_root),true};
	}
	

	bool IsBalance()
	{	
		//这里其实是嵌套了一层

		if (_root == nullptr)
			return true;

		if (_root->_col == RED)
			return false;
		//检查根节点是不是黑色

		Node* cur = _root;
		int refNum = 0;
		while (cur)
		{
			if (cur->_col == BLACK)
				refNum++;
			
			cur = cur->_left;
		}
		return Check(_root, 0, refNum);
	}

	size_t Height()
	{
		return _Height(_root);
	}

	size_t Size()
	{
		return _Size(_root);
	}

	Node* Find(const K& key)
	{
		KeyofValue get;
		Node* cur = _root;
		while (cur)
		{
			if (key > get(cur->_data))
			{
				cur = cur->_right;
			}
			else if (key < get(cur->_data))
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}


	void InOrder()
	{
		_InOrder(_root);
	}
private:


	size_t _Height(Node* root)
	{
		if (!root)
			return 0;
		size_t heightL = _Height(root->_left);
		size_t heightR = _Height(root->_right);

		return heightL > heightR ? heightL + 1 : heightR + 1;
	}
	size_t _Size(Node* root)
	{
		if (!root)
			return 0;
		return _Size(root->_left) + _Size(root->_right) + 1;
	}


	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}


		_InOrder(root->_left);
		cout << root->_data.first << " ";
		_InOrder(root->_right);
	}
	// 右单旋
	void RotateR(Node* parent)
	{
		//左边高的时候需要右单旋
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		Node* pParent = parent->_parent;

		parent->_left = subLR;
		subL->_right = parent;

		parent->_parent = subL;
		subL->_parent = pParent;
		if (subLR) subLR->_parent = parent;
		//在函数中解决平衡因子的更新

		if (_root == parent)
		{
			_root = subL;
		}
		else
		{
			if (pParent->_left == parent)
				pParent->_left = subL;
			else if (pParent->_right == parent)
				pParent->_right = subL;
		}

	}
	// 左单旋
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		Node* pParent = parent->_parent;

		parent->_right = subRL;
		subR->_left = parent;

		//然后是更新父节点

		parent->_parent = subR;
		if (subRL) subRL->_parent = parent;
		subR->_parent = pParent;

		//再然后是更新父节点的指向

		if (_root == parent)
		{
			_root = subR;
		}
		else
		{
			if (pParent->_left == parent)
				pParent->_left = subR;
			else if (pParent->_right == parent)
				pParent->_right = subR;
		}

	}


	bool Check(Node* root, int blackNum, const int refNum)
	{

		//这里其实就是先将基准值找出来，再通过形参递归，这时
		if (root == nullptr)
		{
			if (blackNum == refNum)
				return true;

			return false;
		}


		if (root->_col == BLACK)
			blackNum++;
		else
		{
			if (root->_parent->_col == RED)
				return false;
		}
		//这里向下检查还是比较困难的，还是从上往下比较好

		return Check(root->_left, blackNum, refNum) &&
			Check(root->_right, blackNum, refNum);


	}
	Node* _root = nullptr;
};