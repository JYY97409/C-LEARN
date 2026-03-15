#include<iostream>
#include<stack>
#include<queue>
#include<list>
#include"stack.h"
#include"queue.h"
using namespace std;

void test_list1()
{
	// 一个链表节点转移给另一个链表
	std::list<int> mylist1, mylist2;
	std::list<int>::iterator it;

	// set some initial values:
	for (int i = 1; i <= 4; ++i)
		mylist1.push_back(i);      // mylist1: 1 2 3 4

	for (int i = 1; i <= 3; ++i)
		mylist2.push_back(i * 10);   // mylist2: 10 20 30

	it = mylist1.begin();
	++it;                         // points to 2

	mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
	// mylist2 (empty)
	// "it" still points to 2 (the 5th element


// 调整当前链表节点的顺序
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	int x = 0;
	cin >> x;
	it = find(lt.begin(), lt.end(), x);
	if (it != lt.end())
	{
		//lt.splice(lt.begin(), lt, it);
		lt.splice(lt.begin(), lt, it, lt.end());
	}

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list2()
{
	list<int> l1 = { 1,2,3,4,5 };
	list<int> l2;
	l2.splice(l2.begin(),l1, l1.begin(), l1.end());
}
namespace jyy
{
	void test_queue1()
	{
		queue<int> q1;
		q1.push(1);
		q1.push(1);
		q1.push(1);
		q1.push(1);
	}
	void test_stack1()
	{

	}
}

int main()
{
	jyy::test_queue1();
	

	return 0;
}