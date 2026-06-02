#include<iostream>
#include<vector>
#include"HashTable.h"
#include"unordered_map.h"
#include"unordered_set.h"

using namespace std;


//void test_hash1()
//{
//	open_adress::HashTable<int, int > h1;
//	int a[] = { 19,30,5,36,13,20,21,12,17,18};
//	for (auto e : a)
//	{
//		h1.insert({e,e});
//	}
//	h1.erase(30);
//
//	
//	auto ret1 = h1.find(20);
//	if (ret1)
//	{
//		cout << "找到了" << endl;
//	}
//
//	auto ret = h1.find(30);
//	if (ret)
//	{
//		cout << "找到了" << endl;
//	}
//	else
//	{
//		cout << "没有找到" << endl;
//	}
//
//}


//struct Date
//{
//	int _year;
//	int _month;
//	int _day;
//
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//	}
//
//	bool operator==(const Date& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//};
//
//struct DateHashFunc
//{
//	size_t operator()(const Date& d)
//	{
//		size_t hash = 0;
//		hash += d._year;
//		hash *= 131;
//
//		hash += d._month;
//		hash *= 131;
//
//		hash += d._day;
//		hash *= 131;
//
//		return hash;
//	}
//};
//
//
//int main()
//{
//	//int a[] = { 19,30,52,63,11,22 };
//	
//	const char* a1[] = { "abcd", "sort", "insert" };
//	hash_bucket::HashTable<string, string> ht1;
//	for (auto& e : a1)
//	{
//		ht1.insert({ e, e });
//	}
//
//	cout << HashFunc<string>()("abcd") << endl;
//	cout << HashFunc<string>()("bcad") << endl;
//	cout << HashFunc<string>()("aadd") << endl;
//
//	int a2[] = { -19,-30,5,36,13,20,21,12 };
//	hash_bucket::HashTable<int, int> ht2;
//	for (auto e : a2)
//	{
//		ht2.insert({ e, e });
//	}
//
//	// 哈希冲突
//	hash_bucket::HashTable<Date, int, DateHashFunc> ht;
//	ht.insert({ { 2024, 10, 12 }, 1});
//	ht.insert({ { 2024, 12, 10 }, 1 });
//
//	return 0;
//}


int main()
{
	int a2[] = { 19,30,5,36,13,20,21,12,24,96 };
	jyy::unordered_map<int, int> ht2;
	for (auto e : a2)
	{
		ht2.insert({ e, e });
	}

	ht2.insert({ 100, 100 });
	ht2.insert({ 101, 101 });


	return 0;
}



//还是水一下

//void test_map1()
//{
//	jyy::unordered_map<int, int> ht1;
//	int a2[] = { 19,30,5,36,13,20,21,12,24,96 };
//	for (auto e : a2)
//	{
//		ht1.insert({e,e});
//	}
//
//	auto it = ht1.begin();
//	while (it != ht1.end())
//	{
//		cout << it->first << ":" << it->first << " ";
//		++it;
//	}
//
//}
//
//
//int main()
//{
//	test_map1();
//
//	return 0;
//}