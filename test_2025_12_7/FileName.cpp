#include<iostream>
#include"fuck.h"
//#define ADD(x,y) ((x)+(y))
//
using namespace std;
//inline int add(int x, int y)
//{
//	int ret = x + y;
//	return ret;
//}
//int main()
//{
//	int i = 0;
//	std::cin >> i;
//	std::cout << i << std::endl;
//
//	int a = 2;
//	/*int* pstr = NULL ;
//	int* & rp = pstr;*/
//
//	int x = 1;
//	int y = 2;
//	int ret = ADD(x, y);
//	std::cout << ret << std::endl;
//	const int& b = a + 2 ;
//	printf("%d", add(x, y));
//	return 0;
//}

//inline int& add(int x, int y)
//{
//	int ret = x + y;
//	return ret;
//}
//
//
//int main()
//{
//	int i = 0;
//	int j = 0;
//	cin >> i >> j;
//	int ret = add(i, j) - 1;
//	cout << i << " " << j << " " << ret << endl;
//
//	int* pstr = nullptr;
//	//可以直接隐式转换成其他的指针类型
//	//int str = nullptr;
//	//但是nullptr不能直接转换为int类型的
//	return 0;
//}
//struct Listnode
//{
//	int val;
//	Listnode* next;
//	int arr(int x, int y)
//	{
//		return x + y;
//	}
//};
////在C++中struct 是可以定义函数的
////在C++中struct 的默认权限是public
////在C++中class 的默认权限是pvaite
//using namespace std;
//
//class JYY
//{
//	int pop(int x)
//	{
//
//	}
//public:
//	int push(int u)
//	{
//		return 0;
//	}
//	//在类中，变量是声明，不是定义
//	//
//public:
//	int _a;
//	int _b;
//};
//
////C++中成员变量的定义是很自由的，
//
//int main()
//{
//	JYY jyy;
//	int x = 0;
//	jyy._a = 1;
//	jyy.push(x);
//	return 0;
//}
class JYY
{
private:
	static int add(int x, int y)
	{
		return x + y;
	}
public:
	int addadd(int x, int y, int z)
	{
		return add(x, y) + z;
	}
};
int main()
{
	JYY jyy;
	int ret1 = jyy.addadd(1, 2, 3);
}