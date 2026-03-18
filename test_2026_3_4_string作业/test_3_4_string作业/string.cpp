#define _CRT_SECURE_NO_WARNINGS 1
#include"string.h"


namespace jyy
{
	ostream& operator<<(ostream& out, const string& s)
	{
		cout << s._str;
		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		
		int i = 0;
		const int N = 256;
		char buff[N];

		char ch;
		ch = cin.get();
		while (ch != '\n')
		{
			buff[i++] = ch;
			ch = cin.get();
			if (i == N - 1)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}
		}

		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}

		return in;
	}

	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		
		if (_size == _capacity)
		{
			reserve(2 * _capacity);
		}

		for (size_t cur = _size; cur > pos; --cur)
		{
			_str[cur] = _str[cur - 1];
		}
		_str[pos] = ch;
		++_size;
		_str[_size] = '\0';

	}
	void string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);

		size_t len = strlen(str);
		
		if (len + _size > _capacity)
		{
			reserve(len + _size > 2 * _capacity ? len + _size : 2 * _capacity);
		}

		for (size_t cur = _size + len; cur >= pos + len; --cur)
		{
			_str[cur] = _str[cur - len];
		}

		for (size_t i = 0; str[i] != '\0'; i++)
		{
			_str[pos++] = str[i];
		}

		_size += len;
		_str[_size] = '\0';
	}
	void string::append(const char* str)
	{
		if (str == "")
			return;


		size_t len = strlen(str);
		if (len + _size > _capacity)
		{
			reserve(len + _size > 2 * _capacity ? len + _size + 1 : 2 * _capacity);
		}
		//此处少考虑了要申请存放'\0'的空间

		for (size_t cur = 0; str[cur] != '\0'; cur++)
		{
			_str[_size++] = str[cur];
		}
		_str[_size] = '\0';
	}
	void string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);

		size_t cur = pos;
		while (cur + len <= _size)
		{
			_str[cur] = _str[cur + len];
			++cur;
		}

		_size -= len;
		_str[_size] = '\0';
	}


	string string::substr(size_t pos)
	{
		assert(pos < _size);
		
		string ret;
		ret.reserve(_size - pos);

		while (pos < _size)
		{
			ret += _str[pos++];
		}
		
		return ret;
	}

	

	
	size_t string::find(size_t pos, char ch)
	{
		assert(pos < _size);


		while (pos < _size)
		{
			if (_str[pos++] == ch)
				return pos;
		}

		return npos;
	}
	size_t string::find(size_t pos, const char* str)
	{

		assert(pos < _size);

		char* ret = strstr(_str + pos, str);

		if (ret == nullptr)
			return npos;

		return ret - _str;
	}

	//天天二指禅，真是累人

	bool string::operator==(const string& s)
	{
		if (strlen(s._str) != strlen(_str))
			return false;
		int i = 0,j = 0;
		while (i < s._size && j < _size)
		{
			if (s._str[i++] != _str[j++])
				return false;
		}

		return true;
	}
	bool string::operator!=(const string& s)
	{
		return !operator==(s);
	}

	bool string::operator>=(const string& s)
	{
		return operator==(s) || operator>(s);
	}
	bool string::operator>(const string& s)
	{
		int i = 0, j = 0;
		while (i < s._size && j < _size)
		{
			if (s._str[i++] < _str[j++])
				return true;
		}
		
		return false;
	}

	bool string::operator<=(const string& s)
	{
		return !operator>(s);
	}
	bool string::operator<(const string& s)
	{
		return !operator>=(s);
	}


}