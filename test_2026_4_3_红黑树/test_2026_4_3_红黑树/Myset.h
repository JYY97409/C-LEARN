#pragma once
#include<iostream>
#include<vector>
#include<cassert>
#include"Tree.h"
using namespace std;

namespace jyy
{
	template <class key>
	class set
	{
	public:
		typedef key T;
		typedef RBTreeNode<T> Node;
		typedef Iterator<T, T&, T*> iterator;
		typedef Iterator<T, const T&, const T*> const_iterator;
		//曾经搞错了
		///////////////////////////////////////////////////////
		class SetKeyofValue
		{
		public:

			const key& operator()(const key& data)const
			{
				return data;
			}

		};

		bool insert(T data)
		{
			return _root.Insert(data).second;
		}
		size_t Height()
		{
			return _root.Height();
		}
		size_t Size()
		{
			return _root.Size();
		}
		Node* Find(const key& key)
		{
			return _root.Find(key);
		}
		void InOrder()
		{
			_root.InOrder();
		}
		bool IsBalance()
		{
			return _root.IsBalance();
		}

		iterator begin()
		{
			return _root.begin();
		}
		const_iterator begin()const
		{
			return _root.begin();
		}
		//这是消除歧义的方法
		////////////////////////////
		//这个是忘了

		iterator end()
		{
			return _root.end();
		}
		const_iterator end()const
		{
			return _root.end();
		}


	private:
		RBTree<key, key, SetKeyofValue> _root;
	};
}