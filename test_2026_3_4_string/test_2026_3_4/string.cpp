#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

#include"string.h"
using namespace std;


namespace jyy
{

	

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
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}

		size_t cur = _size + 1;
		//此处存在隐式类型转换的风险，范围小的会向范围大的转换，从而出现-1比0小的情况
		while (cur > pos)
		{
			_str[cur] = _str[cur - 1];
			--cur;
		}
		_str[pos] = ch;
		++_size;
		/*size_t cur = _size;
		while (cur >= pos)
		{
			_str[cur + 1] = _str[cur];
			--cur;
		}*/
		//这就是上述提到的情况
	}

	//在pos位置插入一个字符串
	void string::insert(size_t pos, const char* str)
	{

		assert(pos < _size);

		size_t len = strlen(str);
		if (len == 0)
		{
			return;
		}

		if (_size + len > _capacity)
		{
			reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
		}

		size_t cur = _size + len;


		while (cur > pos + len - 1)
		{
			_str[cur] = _str[cur - len];
			--cur;
		}
		

		for (size_t i = 0; i < len; i++)
		{
			_str[pos++] = str[i];
		}
	}


	//从pos位置开始删除
	void string::erase(size_t pos, size_t len)
	{
		assert(pos < _size);
		_size = pos;
		_str[pos] = '\0';
	}

	//从pos位置开始找到字符并返回下标
	size_t string::find(size_t pos, char ch)
	{
		assert(pos < _size);
		for (size_t cur = pos; cur < _size; cur++)
		{
			if (_str[cur] == ch)
				return cur;
		}
		return npos;
	}
	
	size_t string::find(size_t pos,const char* str)
	{
		assert(str != nullptr);

		const char* ret = strstr(_str, str);

		if (ret == nullptr)
			return npos;

		return ret - _str;
	}

	
	string string::substr(size_t pos)
	{

		assert(pos < _size);
		string ret;

		size_t len = _size - pos;
		ret.reserve(len);

		for (size_t i = pos; i < _size; ++i)
		{
			ret._str[ret._size++] = _str[i];
		}
		ret._str[ret._size] = '\0';

		//这里如果不写拷贝构造函数会导致发生浅拷贝，使得_str指向一块已经被释放的空间
		return ret;
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
		
		if (str == nullptr)
			return;

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
	
		if (str == nullptr)
			return *this;
		size_t len = strlen(str);

		if (_size + len > _capacity)
		{
			char* temp = new char[_size + len > 2 * _capacity ? _size + len + 1 : 2 * _capacity];
			strcpy(temp, _str);
			delete[] _str;
			_str = temp;
		}

		strcpy(_str + _size, str);

		_size += len;
		_str[_size] = '\0';

		return *this;
	
	}

	string& string::operator=(const string& s)
	{
		_size = 0;
		size_t len = strlen(s.c_str());
		if(len>_capacity)
		reserve(len > 2*_capacity ? len : 2*_capacity);
		
		for (size_t i = 0; i < s._size; i++)
		{
			_str[_size++] = s._str[i];
		}
		_str[_size] = '\0';
		return *this;
	}


	ostream& operator<<(ostream& out, const string& s)
	{
		/*for (size_t i = 0; s._str[i]!='\0'; ++i)
		{
			cout << s._str[i];
		}
		return out;*/

		for (auto ch : s)
		{
			cout << ch;
		}
		return out;
	}

	istream& operator>> (istream& in,string& s)
	{

		//这里是需要强调的点
		s.clear();

		char ch;
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}
}
