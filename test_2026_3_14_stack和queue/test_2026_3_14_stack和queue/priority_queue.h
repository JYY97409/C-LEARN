#pragma once
#include<iostream>
#include<stack>
#include<queue>
#include<list>
#include"stack.h"
#include"queue.h"
using namespace std;


namespace jyy
{
	template <class T, class Container = vector<int>>
	class priority_quque
	{
	public:
		
		void push(const T& val)
		{
			_con.push_back(val);
			Adjustup(_con.size()-1);
		}

		void pop()
		{
			swap(_con[0]£¬_con[_con.size() - 1]);
			Adjustdown(0);
		}

		T top()
		{
			return _con.top();
		}

		bool empty()
		{
			return _con.empty();
		}

		size_t size()
		{
			return _con.size();
		}

	private:

		void Adjustdown(size_t cur)
		{

		}
	
		void Adjustup(size_t cur)
		{

		}


		Container _con;
	};



}

