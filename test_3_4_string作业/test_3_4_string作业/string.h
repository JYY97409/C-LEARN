#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include<iostream>
#include<cassert>
using namespace std;



namespace jyy
{
	class string
	{

		friend ostream& operator<<(ostream& _cout, const jyy::string& s);

		friend istream& operator>>(istream& _cin, jyy::string& s);
	public:

		void reserve(size_t n)
		{
			assert(n > _capacity);
			char*  tmp = new char[n] ;
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
		

		string()
			:_str(new char[1]{ '\0' })
			, _size(0)
			, _capacity(0)
		{}
		string(const char* str)
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_size + 1];
			strcpy(_str, str);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

		char* c_str()
		{
			return _str;
		}

		size_t size()
		{
			return _size;
		}

		void operator+=(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}
		
		void operator+=(const char* str)
		{
			size_t len = strlen(str);
			if (len + _size > _capacity)
			{
				reserve(len + _size > 2 * _capacity ? len + _size : 2 * _capacity);
			}
			strcpy(_str + _size, str);
			_size += len;
		}


	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	};


	static  void test_string1()
	{
		string s1;
		string s2("hello wrold");


		//s2 += " what can i say";
		cout << s2.c_str() << endl;
	}

	
}