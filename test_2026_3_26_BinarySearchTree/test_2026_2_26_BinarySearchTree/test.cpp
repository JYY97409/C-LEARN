#include<iostream>
using namespace std;
#include"BinraySearchTree.h"
//int main()
//{
//	key::BSTree<int>  tree1;
//
//	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	for (auto e : a)
//	{
//		tree1.Insert(e);
//	}
//
//	tree1.InOrder();
//	return 0;
//}

//int main()
//{
//	key::BSTree<int> t;
//	int a[] = { 8, 3, 1, 10, 1, 6, 4, 7, 14, 13};
//	for (auto e : a)
//	{
//		t.Insert(e);
//	}
//
//	t.InOrder();
//
//	t.Insert(16);
//	t.Insert(3);
//	t.InOrder();
//
//	t.Erase(3);
//	t.InOrder();
//
//	t.Erase(8);
//	t.InOrder();
//
//	for (auto e : a)
//	{
//		t.Erase(e);
//		t.InOrder();
//	}
//
//	return 0;
//}

void TestBSTree()
{
	key_value::BSTree<string, string> dict;
	dict.Insert("insert", "²åÈë");
	dict.Insert("erase", "É¾³ý");
	dict.Insert("left", "×ó±ß");
	dict.Insert("string", "×Ö·û´®");

	string str;
	while (cin >> str)
	{
		auto ret = dict.find(str);
		if (ret)
		{
			cout << str << ":" << ret->_val << endl;
		}
		else
		{
			cout << "µ¥´ÊÆ´Ð´´íÎó" << endl;
		}
	}

	string strs[] = { "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Ó£ÌÒ", "Æ»¹û", "Ó£ÌÒ", "Æ»¹û", "Ó£ÌÒ", "Æ»¹û" };
	// Í³¼ÆË®¹û³öÏÖµÄ´Î
	key_value::BSTree<string, int> countTree;
	for (auto str : strs)
	{
		auto ret = countTree.find(str);
		if (ret == NULL)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_val++;
		}
	}
	countTree.InOrder();
}

int main()
{
	TestBSTree();
	return 0;
}