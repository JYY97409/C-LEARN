#pragma once
#include<iostream>
using namespace std;


template <class K >
class BSTNode
{
public:
	BSTNode(K key)
		:_key(key)
		,_left(nullptr)
		,_right(nullptr)
	{}
	K _key;
	BSTNode* _left;
	BSTNode* _right;

};


template <class K>
class BSTree
{
	using BSTNode = BSTNode<K>;


public:

	

	bool Insert(K key)
	{
		BSTNode* newnode = new BSTNode(key);
		
		if (_root == nullptr)
		{
			_root = newnode;
			return true;
		}
		BSTNode* cur = _root;
		BSTNode* parent = nullptr;
		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		if (key < parent->_key)
		{
			parent->_left = newnode;
		}
		else
		{
			parent->_right = newnode;

		}
		
	}
	void InOrder()
	{
		InOrder(_root);
		cout << endl;
	}
private:
	void InOrder(BSTNode* root)
	{
		if (root == nullptr)
			return;


		InOrder(root->_left);
		cout << root->_key << " ";
		InOrder(root->_right);

	}



	BSTNode* _root = nullptr;
	

};