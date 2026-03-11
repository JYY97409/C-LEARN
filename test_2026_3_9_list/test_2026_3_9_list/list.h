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



	template<class T>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T> iterator;
	
		list_iterator(Node* node)
		{
			_node = node;
		}

		iterator operator++()
		{
			_node = _node->next;
			return *this;
		}
		iterator operator--()
		{
			_node = _node->prev;
			return *this;
		}
		
		bool operator !=(const iterator&  it)const
		{
			return !(it._node == _node);
		}
		bool operator ==(const iterator& it)const
		{
			return !it != *this;
		}

		T operator*()const
		{
			return _node->_data;
		}

		
	public:
		Node* _node;
	};


	template<class T>
	class list
	{
	public:
		typedef list_node<T> Node;
		typedef list_iterator<T> iterator;


		list()
		{
			_head = new Node();
			_head->next = _head;
			_head->prev = _head;
			_size = 0;
		}
		void push_back(T x)
		{
			
			/*Node* new_node = (new Node(x));

			Node* tail = _head->prev;

			tail->next = new_node;
			new_node->prev = tail;

			new_node->next = _head;
			_head->prev = new_node;

			++_size;*/
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
			
			prev->next = next;
			next->prev = prev;

			delete to_delete;

			--_size;
			return ret;
		}

		iterator begin()
		{
			return iterator(_head -> next);
 		}

		iterator end()
		{
			return iterator(_head);
		}
	
	private:
		Node* _head;
		size_t _size;
	};
	
	
}