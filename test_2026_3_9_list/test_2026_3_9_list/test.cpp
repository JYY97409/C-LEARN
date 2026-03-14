#include<iostream>
#include<list>
#include<algorithm>
#include"list.h"
using namespace std;


void test_list1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	for (auto it : lt)
	{
		cout << it << " ";
	}
	cout << endl;
}

void test_list2()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);

	for (auto it : lt)
	{
		cout << it << " ";
	}
	cout << endl;

	int n = 0;
	cin >> n;
	auto ret = find(lt.begin(), lt.end(), n);
	lt.insert(ret, 30);
	for (auto it : lt)
	{
		cout << it << " ";
	}
	cout << endl;
	
	//默认是升序 < 
	//可以通过仿函数来实现升序和降序的选择
	//这是类模版，现在还不知道是什么东西
	
	//这里可以直接使用匿名对象
	
	lt.sort(greater<int>());
	for (auto it : lt)
	{
		cout << it << " ";
	}
	cout << endl;
}

void test_list3()
{
	list<int> first;
	first.emplace_back(1);
	first.emplace_back(2);
	first.emplace_back(3);
	first.emplace_back(4);
	first.emplace_back(6);
	first.emplace_back(5);

	first.sort();
	for (auto it : first)
	{
		cout << it << " ";
	}
	cout << endl;
	list<int> second;
	second.emplace_back(1);
	second.emplace_back(7);
	second.emplace_back(8);
	second.emplace_back(9);
	second.emplace_back(10);

	second.sort();
	for (auto it : second)
	{
		cout << it << " ";
	}
	cout << endl;

	first.merge(second);

	//这个函数是为了合并两个有序list

	for (auto it : first)
	{
		cout << it << " ";
	}
	cout << endl;
}




void test_list4()
{
	list<int> lt;
	lt.emplace_back(1);
	lt.emplace_back(3);
	lt.emplace_back(2);
	lt.emplace_back(6);
	lt.emplace_back(1);
	lt.emplace_back(5);
	lt.emplace_back(6);
	lt.emplace_back(8);
	lt.emplace_back(7);
	lt.emplace_back(7);
	lt.emplace_back(9);
	lt.emplace_back(9);

	for (auto it : lt)
	{
		cout << it << " ";
	}
	cout << endl;

	lt.sort();
	lt.unique();

	for (auto it : lt)
	{
		cout << it << " ";
	}
	cout << endl;
}

void test_list5()
{
	list<int> lt1;
	lt1.emplace_back(1);
	lt1.emplace_back(2);
	lt1.emplace_back(3);
	lt1.emplace_back(4);
	lt1.emplace_back(5);
	lt1.emplace_back(6);

	list<int> lt2;

	lt2.emplace_back(10);
	lt2.emplace_back(20);
	lt2.emplace_back(30);
	lt2.emplace_back(40);

}

namespace jyy
{
	void test_list1()
	{
		list<int> l1;

		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		l1.push_back(5);
		l1.push_back(6);
		l1.push_back(7);

		list<int>::iterator it = l1.begin();
		
		size_t n = 0;
		cin >> n;

		for (size_t i = 0; i < n; i++)
		{
			++it;
		}
		it = l1.insert(it,10);
		it = l1.insert(it, 20);

		
		l1.erase(it);
		for (auto ch : l1)
		{
			cout << ch << " ";
		}
		cout << endl;

		//jyy::printf_contianer(l1);
	}
}

int main()
{
	jyy::test_list1();
	return 0;
}