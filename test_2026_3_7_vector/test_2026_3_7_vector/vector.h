#pragma once
#include<iostream>
#include<cassert>
using namespace std;


namespace jyy
{
	template <class T>
	class vector
	{

	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		vector() = default;
		//在这里，如果我已经实现了构造函数，编译器就不会自动去生成默认构造函数了

		vector(const vector<T>& v)
		{
			reserve(v.size());

			for (auto ch : v)
			{
				push_back(ch);
			}
			
		}
		vector<T> operator=(vector<T> v)
		{
			swap(v);

			return *this;
		}
		//类里面的成员函数，也可以是函数模版
		template <class InputIterator>

		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(size_t n, T t = T())
		{
			resize(n, t);
		}

		vector(int n, T t = T())
		{
			resize(n, t);
		}
		

		void clear()
		{
			_finish = _start;
		}

		const_iterator begin()const
		{
			return _start;
		}

		const_iterator end()const
		{
			return _finish;
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		void reserve(size_t  n)
		{
			size_t old_size = size();
			if (n <= old_size)
				return;

			T* tmp = new T[n];
			//memcpy(tmp, _start, old_size * sizeof(T));
			//这里存在问题：如果是模版类型，会存在浅拷贝的状况，会导致达不到想要的结果
			for (size_t i = 0; i < old_size; i++)
			{
				tmp[i] = _start[i];
			}
			
			_start = tmp;
			_finish = _start + old_size;
			_end_of_storage = _start + n;

		}
		void resize(size_t n, const T x = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);

				while (_finish < _start + n)
				{
					*(_finish++) = x;
				}
			}
		}
		

		void push_back(const T& v)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}

			*_finish = v;
			++_finish;
		}

		T& operator[](size_t n)const
		{
			assert(n < size());

			return *(_start + n);
		}

		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end_of_storage - _start;
		}

		bool empty()const
		{
			return _finish == _start;
		}


		void pop_back()
		{
			assert(!empty());

			--_finish;
		}

		iterator insert(iterator pos, const T& x)
		{

			assert(pos <= _finish);
			assert(pos >= _start);


			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + len;
			}

			iterator cur = end();
			while (cur >= pos)
			{
				*(cur + 1) = *cur;
				--cur;
			}
			
			*pos = x;


			return pos;
		}
		iterator erase(iterator pos)
		{
			assert(pos < _finish);
			auto cur = pos;

			while (cur < _finish - 1)
			{
				*(cur) = *(cur + 1);
				cur++;
			}
			--_finish;
			return pos;
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;

	};

	template <class T>
	void printf_vector(const vector<T>& v)
	{
		/*for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;*/


		/*for (const auto& ch : v)
		{
			cout << ch << " ";
		}
		cout << endl;*/


		typename vector<T>::const_iterator it = v.begin();


		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}


	template <class Container>
	void printf_container(const Container& v)
	{
		/*for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;


		for (const auto& ch : v)
		{
			cout << ch << " ";
		}
		cout << endl;*/


		typename Container::const_iterator it = v.begin();


		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}


	void test_vector1()
	{
		vector<int> v;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;


		for (const auto& ch : v)
		{
			cout << ch << " ";
		}
		cout << endl;
		printf_vector(v);
	}

	void test_vector3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		printf_vector(v);

		v.insert(v.begin() + 2, 40);

		printf_vector(v);


		auto p = find(v.begin(), v.end(), 2);

		if (p < v.end())
		{
			p = v.insert(p, 20);
			*(p + 1) *= 10;
		}


		printf_vector(v);
	}

	void test_vector4()
	{

		vector<int> v;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(4);
		v.push_back(5);
		printf_vector(v);

		auto it = v.begin();


		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else
			{
				++it;
			}
		}
		printf_container(v);
	}

	void test_vector5()
	{
		vector<int> v;
		v.resize(10, 1);
		printf_vector(v);


		v.reserve(20);
		v.resize(15, 2);
		printf_vector(v);


	}


	void test_vector6()
	{

		vector<int> v;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(4);
		v.push_back(5);
		printf_container(v);

		vector<int> v1 = v;
		v.push_back(6); 
		v.push_back(7); 
		v.push_back(8);

		printf_container(v1);

		vector<int> v2;
		v2 = v1;
		printf_container(v);
	}

	void test_vector7()
	{
		vector<int> v(10, 1);
		printf_container(v);

		vector<int> v1 = v;
		printf_container(v1);

	}

	void test_vector8()
	{
		vector<string> v;
		v.push_back("1111111111111111");
		v.push_back("1111111111111111");
		v.push_back("1111111111111111");
		v.push_back("1111111111111111");


		printf_container(v);
		v.push_back("1111111111111111");
		printf_container(v);


	}
}