#include<iostream>
#include<algorithm>
#include<set>


using namespace std;
//int main()
//{
//
//	set<int,greater<int>> S;
//	//和之前的优先级队列是一样的，都是将less作为默认比较的仿函数
//	S.insert(2);
//	S.insert(5);
//	S.insert(7);
//	S.insert(8);
//	S.insert(3);
//
//	auto it = S.begin();
//
//	while (it != S.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	
//	return 0;
//}

int main()
{
	multiset<int> s1 = { 1,4,3,5,7,2 };

	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}