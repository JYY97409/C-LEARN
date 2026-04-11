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
	

}


int main()
{
	test_hash1();
	
	return 0;
}