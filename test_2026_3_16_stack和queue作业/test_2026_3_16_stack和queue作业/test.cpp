#include"stack_queue.h"
#include<iostream>
#include<stack>
#include<deque>
#include<list>
#include<vector>
#include<algorithm>
#include"priority.h"
using namespace std;

void test1()
{
	jyy::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);


	while (!q.empty())
	{
		cout << q.back() << " ";
		q.pop();
	}
	cout << endl;
	jyy::stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	st.push(7);
	st.push(8);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;

}
void test2()
{
	jyy::priority_queue<int> pq;
	pq.push(1);
	pq.push(6);
	pq.push(5);
	pq.push(4);
	pq.push(9);
	pq.push(3);
	pq.push(2);
	pq.push(10);
	
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

}
int main()
{
	test2();
	return 0;
}