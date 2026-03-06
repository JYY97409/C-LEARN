#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include<iostream>
#include<cassert>
using namespace std;



namespace jyy
{
	class string
	{

		friend ostream& operator<<(ostream& out, const string& s);

		friend istream& operator>>(istream& in, string& s);
	public:

		void reserve(size_t n)
		{
			assert(n > _capacity);
			char*  tmp = new char[n + 1] ;
			//依旧忽略了要给'\0'留下空间		
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

		void begin();
		void end();
		
		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void append(const char* str);
		void erase(size_t pos, size_t len);

		void swap(string& s);
		string substr(size_t pos);
		size_t find(size_t pos, char ch);
		size_t find(size_t pos, const char* str);

		bool operator==(const string& s);
		bool operator!=(const string& s);
		
		bool operator>=(const string& s);
		bool operator>(const string& s);
		
		bool operator<=(const string& s);
		bool operator<(const string& s);




		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;


		static const size_t npos = -1;
	};


	istream& operator>>(istream& in, string& s);
	ostream& operator<<(ostream& out, const string& s);


	

	
}