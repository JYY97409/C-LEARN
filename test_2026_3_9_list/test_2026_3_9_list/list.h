#pragma once
#include<iostream>
#include<list>
#include<algorithm>
#include<cassert>
using namespace std;


namespace jyy
{
	template<class T>
	class list_node
	{
	public:
		//这里还是一个注意的点：const是为了减少拷贝,T()是为了使用默认构造，拥有更好的适配性
		list_node(const T& data = T())
			:_data(data)
			, next(nullptr)
			, prev(nullptr)
		{}

		T _data;
		list_node<T>* next;
		list_node<T>* prev;
	};

	template<class T, class Ref, class  Ptr>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T,Ref,Ptr> Self;
		
		//这里的Self可以非常好的兼容两个类型的迭代器
		list_iterator(Node* node)
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}
		Self& operator++()
		{
			_node = _node->next;
			return *this;
		}
		Self& operator--()
		{
			_node = _node->prev;
			return *this;
		}

		Self operator++(int)
		{
			iterator ret = *this;
			_node = _node->next;
			return ret;
		}
		Self operator--(int)
		{
			iterator ret = *this;
			_node = _node->prev;
			return ret;
		}
		
		bool operator !=(const Self&  it)const
		{
			return it._node != _node;
		}
		bool operator ==(const Self& it)const
		{
			return it._node == _node;
		}

	public:
		Node* _node;
	};



	//template<class T>
	//struct list_const_iterator
	//{
	//	typedef list_node<T> Node;
	//	typedef list_const_iterator<T> const_iterator;

	//	list_const_iterator(Node* node)
	//		:_node(node)
	//	{}

	//	const_iterator& operator++()
	//	{
	//		_node = _node->next;
	//		return *this;
	//	}
	//	const_iterator& operator--()
	//	{
	//		_node = _node->prev;
	//		return *this;
	//	}

	//	const_iterator operator++(int)
	//	{
	//		const_iterator ret = *this;
	//		_node = _node->next;
	//		return ret;
	//	}
	//	const_iterator operator--(int)
	//	{
	//		const_iterator ret = *this;
	//		_node = _node->prev;
	//		return ret;
	//	}

	//	bool operator !=(const const_iterator& it)const
	//	{
	//		return (it._node != _node);
	//	}
	//	bool operator ==(const const_iterator& it)const
	//	{
	//		return it._node ==_node;
	//	}

	//	//此处应该是T&
	//	const T& operator*()
	//	{
	//		return _node->_data;
	//	}
	//	const T* operator->()
	//	{
	//		return &_node->_data;
	//	}
	//	
	//public:
	//	Node* _node;
	//};



	template<class Contianer>
	void printf_contianer(const Contianer& con)
	{

		auto it = con.begin();
		while (it != con.end())
		{
			*it += 10;
			++it;
		}
		cout << endl;

		for (auto e : con)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	template<class T>
	class list
	{
	public:
		typedef list_node<T> Node;
		/*typedef list_iterator<T> iterator;
		typedef list_const_iterator<T> const_iterator;*/

		typedef list_iterator<T, T&, T*>  iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
		//可以认为这是在类中声明了迭代器的类型，然后在模版中直接套用
		list()
		{
			_head = new Node();
			_head->next = _head;
			_head->prev = _head;
			_size = 0;
		}
		void push_back(T x)
		{	
			insert(end(), x);
		}
		void push_front(T x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		iterator insert(iterator it, T data)
		{
			Node* new_node = new Node(data) ;

			Node* next = it._node;
			Node* prev = it._node->prev;

			prev->next = new_node;
			new_node->prev = prev;

			next->prev = new_node;
			new_node->next = next;
			++_size;
			return --it;
		}
		
		iterator erase(iterator it)
		{
			assert(it != end());
			
			Node* to_delete = it._node;
  			Node* next = it._node->next;
			Node* prev = it._node->prev;
			iterator ret = ++it;
			//这里存在bug，会使it指向下一个位置，从而delete错误的位置
			prev->next = next;
			next->prev = prev;

			delete to_delete;

			--_size;
			return ret;
		}

		iterator begin()
		{
			return iterator(_head->next);
 		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin()const
		{
			return	const_iterator(_head->next);
		}
		const_iterator end()const
		{
			return const_iterator(_head);
		}
	
	private:
		Node* _head;
		size_t _size;
	};
	
}






