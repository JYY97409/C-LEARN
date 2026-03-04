#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include<iostream>
#include<cstring>
using namespace std;

namespace jyy
{
	class string
	{
	public:
		typedef char* iteartor;
		typedef const char* const_iteartor;

		/*string()
			:_str(new char[1] {'\0'})
			,_size(0)
			,_capacity(0)
		{}*/

		iteartor begin()
		{
			return _str;
		}

		iteartor end()
		{
			return _str + _size;
		}

		const_iteartor begin()const
		{
			return _str;
		}

		const_iteartor end()const
		{
			return _str + _size;
		}

		//这里存在权限缩小和放大的问题
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_size + 1];
			strcpy(_str, str);
			//可以发现存在先拷贝再判断的情况，这里的""在内存中实际上是只有\0,而我们可以直接将\0也拷贝进去
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		char* c_str()
		{
			return _str;
		}


		size_t size()
		{
			return _size;
		}

		char& operator[](int n)
		{
			return _str[n];
		}

		const char& operator[](int n)const
		{
			return _str[n];
		}

		void reserve(size_t n);
		void push_back(const char ch);
		void append(const char* str);
		
		string& operator+=(char ch);
		string& operator+=(const char* str);

		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos, size_t len = npos);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static const size_t npos;
	};
		 
	void test_string1();
	void test_string2();
}

