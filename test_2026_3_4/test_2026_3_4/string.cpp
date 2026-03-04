#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

#include"string.h"
using namespace std;


namespace jyy
{

	static const size_t npos = -1;


	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* temp = new char[n + 1];
			strcpy(temp,_str);
			delete[] _str;
			_str = temp;
		}
	}

	void string::insert(size_t pos, char ch)
	{

	}
	void string::insert(size_t pos, const char* str)
	{

	}
	void string::erase(size_t pos, size_t len)
	{

	}


	void string::push_back(const char ch)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		_str[_size] = ch;
		++_size;
		_str[_size] = '\0';
	}

	void string::append(const char* str)
	{
		size_t len = strlen(str);

		if (_size + len > _capacity)
		{
			char* temp = new char[_size + len > 2 * _capacity ? _size + len + 1  : 2 * _capacity];
			strcpy(temp, _str);
			delete[] _str;
			_str = temp;
		}

		strcpy(_str + _size, str);
		
		_size += len;
		_str[_size] = '\0';
	}

	string& string::operator+=(char ch)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		_str[_size] = ch;
		++_size;
		_str[_size] = '\0';

		return *this;
	}

	string& string::operator+=(const char* str)
	{
		return *this;
	}

	void test_string1()
	{
		jyy::string s1;
		jyy::string s2("hello world");
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;



		for (int i = 0; i < s2.size(); i++)
		{
			cout << s2[i] << " ";
		}
		cout << endl;
		
		for (auto ch : s2)
		{
			cout << ch << " ";
		}
		cout << endl;

		string::iteartor it = s2.begin();
		while (it != s2.end())
		{
			cout << *it << " ";
			++it;
		}
		s2.push_back(' ');
		s2 += 'w';
		cout << s2.c_str() << endl;

	}

	void test_string2()
	{
		string s1("hello wrold");

		s1.append(" what can i say");
		cout << s1.c_str() << endl;
	}
}
