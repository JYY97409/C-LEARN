#include<iostream>
#include<vector>
#include"HashTable.h"
using namespace std;

void test_hash1()
{
	HashTable<int, int > h1;
	int a[] = { 19,30,5,36,13,20,21,12 };
	for (auto e : a)
	{
		h1.insert({e,e});
	}
	h1.erase(30);

	
	auto ret1 = h1.find(20);
	if (ret1)
	{
		cout << "找到了" << endl;
	}

	auto ret = h1.find(30);
	if (ret)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没有找到" << endl;
	}

}


int main()
{
	test_hash1();
	
	return 0;
}