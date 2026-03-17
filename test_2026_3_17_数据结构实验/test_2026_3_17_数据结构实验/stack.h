#pragma once
#include<iostream>

using namespace std;



namespace jyy
{

	template<class T>
	class stack
	{
	public:
		stack(size_t capacity = 4)
			:_size(0)
			,_arr(new T[capacity])
			,_capacity(capacity)
		{}
		T top()
		{
			return _arr[_size - 1];
		}
		void pop()
		{
			_size--;
		}
		bool empty()
		{
			return _size == 0;
		}
		void push(const T& x)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}

			_arr[_size] = x;
			_size++;
		}
		bool full()
		{
			return _size == _capacity;
		}
		void reserve(size_t capacity)
		{
			_capacity = capacity;
			T* temp = new T[_capacity];
			memcpy(temp, _arr, _size * sizeof(T));
			_arr = temp;
		}
	private:
		T* _arr;
		size_t _size;
		size_t _capacity;
	};
}