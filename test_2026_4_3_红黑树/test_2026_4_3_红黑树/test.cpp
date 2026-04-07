#include<iostream>
#include"Tree.h"

#include"Mymap.h"
#include"Myset.h"

using namespace std;

//void TestRBTree1()
//{
//	dataTree<int, int> t;
//	// 常规的测试用例
//	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	// 特殊的带有双旋场景的测试用例
//	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//
//	for (auto e : a)
//	{
//		t.Insert({ e, e });
//	}
//
//	t.InOrder();
//	cout << t.IsBalance() << endl;
//}
//void TestRBTree2()
//{
//	const int N = 1000000;
//	vector<int> v;
//	v.reserve(N);
//	srand(time(0));
//	for (size_t i = 0; i < N; i++)
//	{
//		v.push_back(rand() + i);
//	}
//
//	size_t begin2 = clock();
//	dataTree<int, int> t;
//	for (auto e : v)
//	{
//		t.Insert(make_pair(e, e));
//	}
//	size_t end2 = clock();
//
//	cout << "Insert:" << end2 - begin2 << endl;
//	cout << t.IsBalance() << endl;
//
//	cout << "Height:" << t.Height() << endl;
//	cout << "Size:" << t.Size() << endl;
//
//	size_t begin1 = clock();
//	// 确定在的值
//	for (auto e : v)
//	{
//		t.Find(e);
//	}
//	// 随机值
//	for (size_t i = 0; i < N; i++)
//	{
//		t.Find((rand() + i));
//	}
//	size_t end1 = clock();
//	cout << "Find:" << end1 - begin1 << endl;
//}


//int main()
//{
//
//	//TestRBTree2();
//	return 0;
//}

void Print(const jyy::set<int>& s)
{
	jyy::set<int>::const_iterator it = s.end();
	while (it != s.begin())
	{
		--it;
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	jyy::set<int> s;
	s.insert(5);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(6);

	jyy::set<int>::iterator sit = s.begin();
	//*sit += 10;
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	Print(s);


	jyy::map<string, string> dict;
	dict.insert({ "sort", "排序" });
	dict.insert({ "left", "左边" });
	dict.insert({ "right", "右边" });

	dict["left"] = "左边，剩余";
	dict["insert"] = "插入";
	dict["string"];

	jyy::map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		// 不能修改first，可以修改second
		//it->first += 'x';
		it->second += 'x';

		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	for (auto& data : dict)
	{
		cout << data.first << ":" << data.second << endl;
	}

	return 0;
}
