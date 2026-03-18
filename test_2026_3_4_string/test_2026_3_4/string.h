#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include<iostream>
#include<cstring>
#include<cassert>
using namespace std;

namespace jyy
{


	class string
	{

 	friend ostream& operator<<(ostream& out, const string& s);
	friend istream& operator>> (istream& in, string& s);
	public:
		typedef char* iteartor;
		typedef const char* const_iteartor;

		/*string()
			:_str(new char[1] {'\0'})
			,_size(0)
			,_capacity(0)
		{}*/


		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}
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

		string(const string& s)
		{
			size_t len = strlen(s.c_str());
			reserve(len);
			for (size_t i = 0; i < s._size; i++)
			{
				_str[_size++] = s._str[i];
			}
		}


		char* c_str()const
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
		string& operator=(const string& s);

		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos, size_t len = npos);

		size_t find(size_t pos, char ch);
		size_t find(size_t pos, const char* str);
		string substr(size_t pos);


		

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static const size_t npos = -1;
	};
		
	//这里实际上是写入了流，所以是不可以在前面加上const的
	ostream& operator<<(ostream& out,const string& s);
	istream& operator>> (istream& in,string& s);
	

	void test_string1();
	void test_string2();
	void test_string3();
	void test_string4();
}

