#pragma once
#include<iostream>
using namespace std;

namespace jyy
{
	template<class T>
	struct Node
	{
		Node(T data = 0)
			:_data(data)
			,_next(nullptr)
		{}
		T _data;
		Node<T>* _next;
	};

	template<class T>
	class queue
	{
	public:
		queue()
		{
			_front = new Node<T>();
			_tail = _front;
			_size = 0;
		}

		//Î²²å
		void push(const T& x)
		{
			Node<T>* new_node = new Node<T>(x);
			_tail->_next = new_node;
			_tail = new_node;
			++_size;
		}
		//Í·É¾
		void pop()
		{
			if (empty())
				return;

			Node<T>* to_delete = _front;
			_front = _front->_next;
			delete to_delete;
		}
		size_t size()
		{
			return _size;
		}


		bool empty()
		{
			return _front == _tail;
		}
		T front()
		{
			return _front->_next->_data;
		}

		T tail()
		{
			return _front->_data;
		}
		

	private:
		Node<T>* _front;
		Node<T>* _tail;
		size_t _size;
	};
}