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
template<class K, class V>
struct RBTreeNode
{
	// 这里更新控制平衡也要加入parent指针
	pair<K, V> _kv;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	Colour _col;


	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
	{}
};


template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv )  
	{
		//还是先插入

		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		Node* cur = _root;
		Node* parent = cur->_parent;
		while (cur)
		{
			if (kv.first > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kv.first < cur->_kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		
		cur = new Node(kv);
		if (kv.first > parent->_kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;

		}
		cur->_parent = parent;
		cur->_col = RED;

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
		return true;
	}
	


	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
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
		Check(_root, 0, refNum);
	}


private:

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}


		_InOrder(root->_left);
		cout << root->_kv.first << " ";
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


		return Check(root->_left, blackNum, refNum) &&
			Check(root->_right, blackNum, refNum);


	}
	Node* _root = nullptr;
};