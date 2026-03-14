#include<iostream>
#include"list.h"

using namespace std;

namespace jyy
{
	void test_list1()
	{
		list<int> l1(2 , 1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		l1.push_back(5);
		print_container(l1);
		
		list<int> l2 = l1;
		l1.push_back(6);
		l1.push_back(7);
		l1.push_back(8);

		print_container(l2);

		list<int> l3;

		l3 = l2;
		l3.push_back(9);
		l3.push_back(10);

		print_container(l3);
 	}
}

int main()
{

	jyy::test_list1();

	return 0;
}