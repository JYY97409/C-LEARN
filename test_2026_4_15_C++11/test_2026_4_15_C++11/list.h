#pragma once
#pragma once
#include<iostream>
#include<list>
#include<cassert>
using namespace std;

namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(char* str)-构造" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 拷贝构造" << endl;
			reserve(s._capacity);
			for (auto ch : s)
			{
				push_back(ch);
			}
		}

		void swap(string& ss)
		{
			::swap(_str, ss._str);
			::swap(_size, ss._size);
			::swap(_capacity, ss._capacity);
		}

		//移动构造
		string(string&& s)noexcept
		{
			cout << "string(string&& s) -- 移动构造" << endl;
			// 转移掠夺你的资源
			swap(s);
		}
		//也就是将资源转移出来，这也是右值引用的类型是左值的原因

		string& operator=(const string& s)
		{
			cout << "string& operator=(const string& s) -- 拷贝赋值" <<
				endl;
			if (this != &s)
			{
				_str[0] = '\0';
				_size = 0;
				reserve(s._capacity);
				for (auto ch : s)
				{
					push_back(ch);
				}
			}
			return *this;
		}

		// 移动赋值
		string& operator=(string&& s)noexcept
		{
			cout << "string& operator=(string&& s) -- 移动赋值" << endl;
			swap(s);
			return *this;
		}

		~string()
		{
			//cout << "~string() -- 析构" << endl;
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				if (_str)
				{
					strcpy(tmp, _str);
					delete[] _str;
				}
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}
	private:
		char* _str = new char('\0');
		size_t _size = 0;
		size_t _capacity = 0;
	};
}
namespace jyy
{
	template<class T>
	class list_node
	{
	public:
		//这里还是一个注意的点：const是为了减少拷贝,T()是为了使用默认构造，拥有更好的适配性

		list_node() = default;

		/*template<class X>
		list_node(X&& data = T())
			:_data(forward<X>(data))
			, next(nullptr)
			, prev(nullptr)
		{}*/
		template<class ...Args>
		list_node(Args&&... args)
			:_data(forward<Args>(args)...)
			,next(nullptr)
			,prev(nullptr)
		{ }

		T _data;
		list_node<T>* next;
		list_node<T>* prev;
	};

	template<class T, class Ref, class  Ptr>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T, Ref, Ptr> Self;

		//这里的Self可以非常好的兼容两个类型的迭代器
		list_iterator(Node* node)
			:_node(node)
		{}

		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}
		Self& operator++()
		{
			_node = _node->next;
			return *this;
		}
		Self& operator--()
		{
			_node = _node->prev;
			return *this;
		}

		Self operator++(int)
		{
			iterator ret = *this;
			_node = _node->next;
			return ret;
		}
		Self operator--(int)
		{
			iterator ret = *this;
			_node = _node->prev;
			return ret;
		}

		bool operator !=(const Self& it)const
		{
			return it._node != _node;
		}
		bool operator ==(const Self& it)const
		{
			return it._node == _node;
		}

	public:
		Node* _node;
	};

	template<class Contianer>
	void printf_contianer(const Contianer& con)
	{

		auto it = con.begin();
		while (it != con.end())
		{
			*it += 10;
			++it;
		}
		cout << endl;

		for (auto e : con)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	
	
	template<class T>
	class list
	{
	public:
		typedef list_node<T> Node;
		/*typedef list_iterator<T> iterator;
		typedef list_const_iterator<T> const_iterator;*/

		typedef list_iterator<T, T&, T*>  iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
		//可以认为这是在类中声明了迭代器的类型，然后在模版中直接套用
		list()
		{
			_head = new Node();
			_head->next = _head;
			_head->prev = _head;
			_size = 0;
		}

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_back(T&& x)
		{
			insert(end(), move(x));
		}

		/*iterator insert(iterator it, T&& data)
		{
			Node* new_node = new Node(move(data));

			Node* next = it._node;
			Node* prev = it._node->prev;

			prev->next = new_node;
			new_node->prev = prev;

			next->prev = new_node;
			new_node->next = next;
			++_size;
			return --it;
		}

		iterator insert(iterator it,const T& data)
		{
			Node* new_node = new Node(data);

			Node* next = it._node;
			Node* prev = it._node->prev;

			prev->next = new_node;
			new_node->prev = prev;

			next->prev = new_node;
			new_node->next = next;
			++_size;
			return --it;
		}*/
		///////////////////////////////
		template<class... Args>
		void emplace_back(Args&&... args)
		{
			insert(end(), forward<Args>(args)...);
		}

		void push_front(T x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}
		/*template<class X>
		iterator insert(iterator it, X&& data)
		{
			Node* new_node = new Node(forward<X>(data));

			Node* next = it._node;
			Node* prev = it._node->prev;

			prev->next = new_node;
			new_node->prev = prev;

			next->prev = new_node;
			new_node->next = next;
			++_size;
			return --it;
		}*/

		
		template<class... Args>
		iterator insert(iterator it,Args&&... args)
		{
			Node* new_node = new Node(forward<Args>(args)...);

			Node* next = it._node;
			Node* prev = it._node->prev;

			prev->next = new_node;
			new_node->prev = prev;

			next->prev = new_node;
			new_node->next = next;
			++_size;
			return --it;
		}



		iterator erase(iterator it)
		{
			assert(it != end());

			Node* to_delete = it._node;
			Node* next = it._node->next;
			Node* prev = it._node->prev;
			iterator ret = ++it;
			//这里存在bug，会使it指向下一个位置，从而delete错误的位置
			prev->next = next;
			next->prev = prev;

			delete to_delete;

			--_size;
			return ret;
		}

		iterator begin()
		{
			return iterator(_head->next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin()const
		{
			return	const_iterator(_head->next);
		}
		const_iterator end()const
		{
			return const_iterator(_head);
		}

	private:
		Node* _head;
		size_t _size;
	};

}