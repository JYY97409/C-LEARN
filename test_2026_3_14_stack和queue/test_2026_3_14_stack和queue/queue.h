#pragma once
#include<iostream>
#include<stack>
#include<queue>
#include<list>
#include<vector>
using namespace std;
namespace jyy
{
	template<class T, class Container = list<T>>
	class queue
	{
	public:
		T back()const
		{
			return _con.back();
		}
		T front()const
		{
			return _con.front();
		}

		void pop()
		{
			_con.pop_back();
		}

		void push(const T& t)
		{
			_con.push_front(t);
		}

		void size()const
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}
