#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<cassert>
using namespace std;



namespace jyy
{
	class string

	{

	public:

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		string(const char* str = "")
		{
			size_t len = strlen(str);
			_str = new char[len + 1];

			strcpy(_str, str);
			_size = len;
			_capacity = len;

			_str[_size] = '\0';
		}

		string(const string& s)
		{
			string tmp = s._str;
			swap(tmp);
		}

		string& operator=(const string& s)
		{
			string tmp = s._str;
			swap(tmp);
			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

	private:

		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;


	};

	void test_string1()
	{
		string s1("hello wrold");

		string s2 = s1;

		string s3;
		s3 = s2;

	}
}
