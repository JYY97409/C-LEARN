#pragma once
#include<iostream>
#include<cassert>
using namespace std;


namespace jyy
{

	template<class T>
	class linear_list
	{
	public:
		linear_list(size_t capacity = 4)
			:_arr(new T[capacity])
			,_size(0)
			,_capacity(capacity)
		{}

		void push(const T& x)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}
			_arr[_size++] = x;
		}

		void insert(size_t pos,const T& x)
		{
			assert(pos < _size && pos > 0);
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}
			size_t cur = _size;

			while (cur > pos)
			{
				_arr[cur] = _arr[cur - 1];
				cur--;
			}
			_arr[pos] = x;
			_size++;
		}
		void erase(size_t pos)
		{
			assert(pos < _size && pos > 0);
			while (pos < _size - 1)
			{
				_arr[pos] = _arr[pos + 1];
				pos++;
			}
			_size--;
		}
		void pop()
		{
			_size--;
		}
		T top()
		{
			assert(_size > 0);

			return _arr[_size - 1];
		}
		bool empty()
		{
			return _size == 0;
		}
		size_t size()
		{
			return _size;
		}

		void reserve(size_t capacity)
		{
			_capacity = capacity;
			T* temp = new T[_capacity];

			memcpy(temp, _arr,_size*sizeof(T));
			_arr = temp;
		}


		T& operator[](size_t n)
		{
			assert(n < _size);
			return _arr[n];
		}
	private:

		T* _arr;
		size_t _size;
		size_t _capacity;
	};
}


