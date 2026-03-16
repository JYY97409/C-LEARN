#pragma once
#include<iostream>
#include<stack>
#include<queue>
#include<list>
#include<vector>
using namespace std;

namespace jyy
{

	template<class T, class Container = std::vector<T>>
	class stack
	{

	public:
		T top()const
		{
			return _con.back();
		}

		void pop()
		{
			_con.pop_back();
		}

		void push(const T& t)
		{
			_con.push_back(t);
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
