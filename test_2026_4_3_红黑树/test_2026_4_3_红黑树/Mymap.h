#pragma once
#include<iostream>
#include<vector>
#include<cassert>
#include"Tree.h"
using namespace std;

namespace jyy
{
	//在这个中实现operator[]，因为通用代码中value的类型是不确定的
	template <class key, class value>
	class map
	{
	public:
		typedef pair<const key, value> T;
		typedef RBTreeNode<T> Node;
		typedef Iterator<T, T&, T*> iterator;
		typedef Iterator<T, const T&, const T*> const_iterator;

		
		class MapKeyofValue
		{
		public:

			const key& operator()(const T& data)const
			{
				return data.first;
			}
		};


		value& operator[](const key& key)
		{
			pair<iterator, bool> ret = _root.Insert({key,value()});
			return (ret.first)->second;
		}

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


		iterator end()
		{
			return _root.end();
		}
		const_iterator end()const
		{
			return const_iterator(nullptr, _root);
		}


	private:
		RBTree<key, T, MapKeyofValue> _root;

		//起码这一层的封装好了
	};

}