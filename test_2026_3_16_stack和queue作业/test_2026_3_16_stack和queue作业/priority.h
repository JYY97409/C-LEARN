#pragma once

#include<iostream>
#include<stack>
#include<deque>
#include<list>
#include<vector>
#include<algorithm>
#include<cassert>


using namespace std;
namespace jyy
{
	template<class T>
	class less_func
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};
	template<class T>
	class greater_func
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};


	template<class T ,class Con = vector<T> ,class Compare = less_func<T>>
	class priority_queue
	{
	public:
		
		friend class greater_func<T>;
		friend class less_func<T>;

		priority_queue()
		{
			Con();
		}

		template <class InputIterator>

		priority_queue(InputIterator first, InputIterator last)
		{
			Con(first, last);
		}

		bool empty() const
		{
			return _con.empty();
		}

		size_t size() const
		{
			return _con.empty();
		}

		const T& top() const
		{
			return _con[0];
		}

		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp(_con.size() - 1);
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}


	private:
		Con _con;
		Compare _compare;
		void AdjustUp(size_t child)
		{
			assert(child < _con.size());
			int  parent = (child - 1) / 2;
			
			//先是建大堆，那就是如果child 如果是child大就向上调整
			while (parent >= 0)
			{
				
				//if(_con[parent] < _con[child])
				if (_compare(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
				
			}

		}
		void AdjustDown(size_t parent)
		{
			assert(parent >= 0);
			//这里是建大堆，向下调整肯定是先找到下面的较小的值
			size_t child = parent  * 2 + 1;
			
			while (child < _con.size())
			{
				if (parent * 2 + 2 < _con.size() && _compare(_con[parent * 2 + 1], _con[parent * 2 + 2]))
				{
					child = parent * 2 + 2;
				}
				//if(_con[parent]<_con[child])
				if (_compare(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					//这里还是说明符合规则
					break;
				}

			}
		}


		
	};
}

