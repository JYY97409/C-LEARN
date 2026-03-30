#pragma once
#include<iostream>
#include<cassert>
using namespace std;


namespace jyy
{
	template<class T,class V> 
	struct AVLTreeNode
	{
		AVLTreeNode(const T& key = T(),const V& data = V())
			: _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _kv(key,data)
			, _bf(0)
		{
		}

		AVLTreeNode<T,V>* _left;
		AVLTreeNode<T,V>* _right;
		AVLTreeNode<T,V>* _parent;
		pair<T, V> _kv;     //这里的pair成员变量就是key和_data
		int _bf;   // 节点的平衡因子
	};


	// AVL: 二叉搜索树 + 平衡因子的限制
	template<class T,class V>
	class AVLTree
	{
		typedef AVLTreeNode<T,V> Node;
	public:
		AVLTree()
			: _root(nullptr)
		{}

		// 在AVL树中插入值为data的节点
		bool Insert(const T& data)
		{
			//先插入，再更新节点
			if (_root == nullptr)
			{
				_root = new Node(data,data);
				return;
			}
			Node* cur = _root;
			Node* parent = cur->_parent;
			//这是控制插入的逻辑
			while (cur)
			{
				if (data < cur->_kv.first)
					cur = cur->_left;
				else if (data > cur->_kv.first)
					cur = cur->_right;
				else
					return false;
			}
			Node* new_node = new Node(data);
			if (data < parent->_kv.first)
				parent->_left = new_node;
			else
				parent->_right = new_node;
			new_node->_parent = parent;

			//这里其实parent也可以等于_root
			while (parent)
			{
				if (cur == parent->_right)
				{
					parent->_bf++;
				}
				else 
				{
					parent->_bf--;
				}
				//这里还是先更新一下parent的平衡因子
				//平衡因子等于右减左
				
				if(parent->_bf == 0)
				{
					//子树高度没变，停止更新
					break;
				}
				else if (parent->_bf == -1 || parent->_bf == 1)
				{
					//此时高度发生变化，应该开始向上更新
					cur = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == -2 || parent->_bf == 2)
				{
					else if (parent->_bf == -2 && cur->_bf == -1)
					{
						RotateR(parent);
						//但是这里的平衡因子应该怎么更新？？？
						//旋转之后高度其实是不存在变化的
						break;
					}
					else if (parent->_bf == 2 && cur->_bf == 1)
					{
						RotateL(parent);
						//这里的向哪里旋转实际上是看的是parent节点的旋转方向
						break;
					}
					else if (parent->_bf == -2 && cur->_bf == 1)
					{
						//左边高，但是cur为根的子树不是完全的左边高
						//所以说这时候就需要先将cur子树左单旋
						RotateLR(parent);

					}
					else if (parent->_bf == 2 && cur->_bf == -1)
					{
						

					}
				}
				else
				{
					assert(false);
				}
				

			}



		}

		// AVL树的验证
		bool IsAVLTree()
		{
			return _IsAVLTree(_pRoot);
		}

	private:
		// 根据AVL树的概念验证pRoot是否为有效的AVL树
		bool _IsAVLTree(Node* root)
		{
			//这里其实可以考虑适用后序遍历的
		}
		size_t _Height(Node* root)
		{
			if (!root)
				return 0;
			size_t heightL = _Height(root->_left) ;
			size_t heightR = _Height(root->_right) ;

			return heightL > heightR ? heightL + 1: heightR + 1;
		}
		size_t _Size(Node& root)
		{
			if (!root)
				return 0;
			return _Size(root->_left) + _Size(root->_right) + 1;
		}
		// 右单旋
		void RotateR(Node* parent)
		{
			//左边高的时候需要右单旋
			Node* subL = parent->_left;
			Node* subLR = subL->_left;

			Node* pParent = parent->_parent;
			
			parent->_left = subLR;
			subL->_right = parent;
			
			parent->_parent = subL;
			subL->_parent = pParent;
			subLR->_parent = parent;
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
			
			subL->_bf = 0;
			parent->_bf = 0;
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
			subRL->_parent = parent;
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

			subR->_bf = 0;
			parent->_bf = 0;
		}
		// 右左双旋
		void RotateRL(Node* parent)
		{
			//不管单旋中有没有更新平衡因子，我们都需要再更新一次，这就是为了降低耦合度

		}
		// 左右双旋
		void RotateLR(Node* parent)
		{

		}

	private:
		Node* _root;
	};

}