#pragma once
#include<iostream>
using namespace std;

namespace key
{
	template <class K >
	class BSTNode
	{
	public:
		BSTNode(K key)
			:_key(key)
			, _left(nullptr)
			, _right(nullptr)
		{
		}
		K _key;
		BSTNode* _left;
		BSTNode* _right;

	};

	template <class K>
	class BSTree
	{
		using Node = BSTNode<K>;


	public:

		BSTree()
			:_root(nullptr)
		{}
		~BSTree()
		{
			Destory(_root);
		}

		BSTree(const BSTree& t)
		{
			_root = copy(t._root);
		}

		BSTree& operator=(BSTree tmp)
		{
			std::swap(_root, tmp->_root);
			return *this;
		}

		bool Insert(K key)
		{
			Node* newnode = new Node(key);

			if (_root == nullptr)
			{
				_root = newnode;
				return true;
			}
			Node* cur = _root;
			Node* parent = nullptr;
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
			return true;
		}
		
		bool Erase(K key)
		{
			//删除还是需要区分情况的，主要分三种情况
			//1、需要删除的节点没有子节点，直接删除
			//2、需要删除的节点存在一个子节点，将这个节点剩下的节点接上去
			//3、需要删除的节点存在两个子节点，在左子树上找到最右边的节点，在右子树上找到最左边的节点
			if (_root == nullptr)
				return false;
			Node* cur = _root;
			Node* parent = nullptr;

			while (cur)
			{
				if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
					//大于往右走
				}
				else if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					break;
				}
			}

			if (cur == nullptr)
				return false;

			if (cur->_left == nullptr && cur->_right == nullptr)
			{
				if (_root == cur)
				{
					_root = nullptr;
				}
				else
				{
					if (parent->_left == cur)
						parent->_left = nullptr;
					if (parent->_right == cur)
						parent->_right = nullptr;
				}
				delete cur;
			}
			//节点左子树为空
			else if (cur->_left == nullptr)
			{
				if (parent)
				{
					if (parent->_left == cur)
						parent->_left = cur->_right;
					else if (parent->_right == cur)
						parent->_right = cur->_right;
				}

				if (cur == _root)
					_root = cur->_right;
				delete cur;
			}
			//节点右子树为空
			else if (cur->_right == nullptr)
			{
				if (parent)
				{
					if (parent->_left == cur)
						parent->_left = cur->_left;
					else if (parent->_right == cur)
						parent->_right = cur->_left;
				}
				
				if (cur == _root)
					_root = cur->_left;
				delete cur;
			}
			//节点是满的
			else 
			{
				//需要找到左子树最右边的节点，或者是找到右子树最左边的节点
				//我们这里还是找右子树的最左边的节点吧
				Node* node = cur->_right;
				Node* NodeParent = cur;
				while (node->_left)
				{
					if (node->_left)
					{
						NodeParent = node;
						node = node->_left;
					}
					else
					{
						break;
					}
				}
				if (NodeParent)
				{
					if (NodeParent->_left == node)
					{
						NodeParent->_left = node->_right;
					}
					else
					{
						NodeParent->_right = node->_right;
					}
				}
				
				
				cur->_key = node->_key;

				delete node;
			}
			return true;
		}
		Node* find(K key)
		{
			if (_root == nullptr)
				return nullptr;
			Node* cur = _root;

			while (cur)
			{
				if (key > cur->_key)
				{
					cur = cur->_right;
					//大于往右走
				}
				else if (key < cur->_key)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}

			return cur;
		}
		
		void InOrder()
		{
			InOrder(_root);
			cout << endl;
		}


		


	private:
		void InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			InOrder(root->_left);
			cout << root->_key << " ";
			InOrder(root->_right);

		}
		void Destory(Node* root)
		{
			if (root == nullptr)
				return;

			Destory(root->_left);
			Destory(root->_right);

			delete root;

		}

		Node* copy(const Node* node)
		{
			if (node == nullptr)
				return nullptr;

			Node* newnode = new Node(node->_key);
			Node* left = copy(node->_left);
			Node* right = copy(node->_right);

			newnode->_left = left;
			newnode->_right = right;

			return newnode;
		}



		Node* _root = nullptr;


	};
}


namespace key_value
{


	template <class K,class V >
	class BSTNode
	{
	public:
		BSTNode(K key,V val)
			:_key(key)
			,_val(val)
			, _left(nullptr)
			, _right(nullptr)
		{
		}
		K _key;
		V _val;
		BSTNode* _left;
		BSTNode* _right;

	};


	template <class K,class V>
	class BSTree
	{
		using Node = BSTNode<K,V>;


	public:

		BSTree()
			:_root(nullptr)
		{
		}
		~BSTree()
		{
			Destory(_root);
		}
		BSTree(const BSTree& t)
		{
			_root = copy(t._root);
		}

		BSTree& operator=(BSTree tmp)
		{
			std::swap(_root, tmp->_root);
			return *this;
		}

		bool Insert(K key,V val)
		{
			Node* newnode = new Node(key,val);

			if (_root == nullptr)
			{
				_root = newnode;
				return true;
			}
			Node* cur = _root;
			Node* parent = nullptr;
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
			return true;
		}

		bool Erase(K key)
		{
			//删除还是需要区分情况的，主要分三种情况
			//1、需要删除的节点没有子节点，直接删除
			//2、需要删除的节点存在一个子节点，将这个节点剩下的节点接上去
			//3、需要删除的节点存在两个子节点，在左子树上找到最右边的节点，在右子树上找到最左边的节点
			if (_root == nullptr)
				return false;
			Node* cur = _root;
			Node* parent = nullptr;

			while (cur)
			{
				if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
					//大于往右走
				}
				else if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					break;
				}
			}

			if (cur == nullptr)
				return false;

			if (cur->_left == nullptr && cur->_right == nullptr)
			{
				if (_root == cur)
				{
					_root = nullptr;
				}
				else
				{
					if (parent->_left == cur)
						parent->_left = nullptr;
					if (parent->_right == cur)
						parent->_right = nullptr;
				}
				delete cur;
			}
			//节点左子树为空
			else if (cur->_left == nullptr)
			{
				if (parent)
				{
					if (parent->_left == cur)
						parent->_left = cur->_right;
					else if (parent->_right == cur)
						parent->_right = cur->_right;
				}

				if (cur == _root)
					_root = cur->_right;
				delete cur;
			}
			//节点右子树为空
			else if (cur->_right == nullptr)
			{
				if (parent)
				{
					if (parent->_left == cur)
						parent->_left = cur->_left;
					else if (parent->_right == cur)
						parent->_right = cur->_left;
				}

				if (cur == _root)
					_root = cur->_left;
				delete cur;
			}
			//节点是满的
			else
			{
				//需要找到左子树最右边的节点，或者是找到右子树最左边的节点
				//我们这里还是找右子树的最左边的节点吧
				Node* node = cur->_right;
				Node* NodeParent = cur;
				while (node->_left)
				{
					if (node->_left)
					{
						NodeParent = node;
						node = node->_left;
					}
					else
					{
						break;
					}
				}
				if (NodeParent)
				{
					if (NodeParent->_left == node)
					{
						NodeParent->_left = node->_right;
					}
					else
					{
						NodeParent->_right = node->_right;
					}
				}


				cur->_key = node->_key;
				cur->_val = node->_key;


				delete node;
			}
			return true;
		}
		Node* find(K key)
		{
			if (_root == nullptr)
				return nullptr;
			Node* cur = _root;

			while (cur)
			{
				if (key > cur->_key)
				{
					cur = cur->_right;
					//大于往右走
				}
				else if (key < cur->_key)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}

			return cur;
		}

		void InOrder()
		{
			InOrder(_root);
			cout << endl;
		}

	private:
		void InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			InOrder(root->_left);
			cout << root->_key << ":"<<root->_val<<" ";
			InOrder(root->_right);

		}
		void Destory(Node* root)
		{
			if (root == nullptr)
				return;

			Destory(root->_left);
			Destory(root->_right);

			delete root;

		}

		Node* copy(const Node* node)
		{
			if (node == nullptr)
				return nullptr;

			Node* newnode = new Node(node->_key,node->_val);
			Node* left = copy(node->_left);
			Node* right = copy(node->_right);

			newnode->_left = left;
			newnode->_right = right;

			return newnode;
		}



		Node* _root = nullptr;


	};
}