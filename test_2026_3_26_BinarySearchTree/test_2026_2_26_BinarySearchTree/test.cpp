#include<iostream>
using namespace std;
#include"BinraySearchTree.h"
int main()
{
	BSTree<int>  tree1;

	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a)
	{
		tree1.Insert(e);
	}

	tree1.InOrder();
	return 0;
}