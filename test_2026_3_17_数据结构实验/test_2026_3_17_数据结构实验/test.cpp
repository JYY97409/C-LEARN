#include<iostream>
#include"queue.h"
#include"stack.h"
#include"linear_list.h"
using namespace std;

int main()
{
	
	jyy::queue<int> q1;


	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.push(5);
	q1.push(6);
	q1.push(7);

	while (!q1.empty())
	{
		cout<<q1.front()<<" ";
		q1.pop();
	}
	cout << endl;

	jyy::linear_list<int> l1;
	l1.push(1);
	l1.push(2);
	l1.push(3);
	l1.push(4);
	l1.push(5);
	for (size_t i = 0; i < l1.size(); i++)
	{
		cout << l1[i] << " ";
	}
	cout << endl;

	l1.insert(2, 9);
	l1.insert(2, 7);

	l1.erase(5);
	for (size_t i = 0; i < l1.size(); i++)
	{
		cout << l1[i] << " ";
	}
	cout << endl;


	jyy::stack<int> st1;
	st1.push(1);
	st1.push(2);
	st1.push(3);
	st1.push(4);
	st1.push(5);
	st1.push(6);
	st1.push(7);
	st1.push(8);

	while (!st1.empty())
	{
		cout << st1.top() << " ";
		st1.pop();
	}
	cout << endl;
 	return 0;
}