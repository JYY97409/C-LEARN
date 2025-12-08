
//
#include<iostream>


namespace jyy
{
	int rand = 100;
	int add(int i, int j)
	{
		return i + j;
	}
}
//using namespace jyy;
//using jyy::add;


////命名空间是为了解决C语言中的令人头疼的名字冲突的问题的
//int a = 2;
//int main()
//{
//	printf("%d\n", ::rand);
//	//::之前没有指定的是啥
//	printf("%d\n", rand);
//	int a = 1;
//	float b = 0.11;
//	printf("%d\n", a);
//	printf("%d\n", ::a);
//	printf("%d", jyy::add(1, 1));
//	printf("\n");
//	//左边啥都不写，默认是全局的
//	//自动识别类型
//	std::cin >> a >> b;
//	std::cout << a <<" "<< b << std::endl;
//	std::cout << a << " " << b << std::endl;
//	//流插入，一次只能插一个
//	// 
//	return 0;
//}
//int main()
//{
//	double a = 2.22222;
//	printf("%.2lf\n", a);
//
//	return 0;
//}

using namespace std;

//int main()
//{
//	const int a = 0;
//	const int& ra = a;
//	//int& ra=a;
//	//是权限放大
//
//
//	int b = 0;
//	const int& rb = b;
//	//权限缩小是可行的
//
//	//缩小权限就像是包含与被包含的区别
//	//引用就像是创建了一个其他的权限 
//
//	const int& r = 20;
//
//	int a = (a + b);
//	//单纯的拷贝
//
//	const int& rr = (a + b);
//	//
//
//	//临时对象是不能被改变的
//
//	//临时对象
//
//	//权限是可以缩小的，但是不能放大
//
//	double d = 12.34;
//	int a = d;
//
//	int& a = d;
//}
 
//void cmp(int& rx, int& ry)
//{
//	int temp = rx;
//	rx = ry;
//	ry = temp;
//}
////引用指的是两个名字指向的是一个空间
//int main() 
//{
//	int x = 1;
//	int y = 2;
//
//	return 0;
//}

int add(int x, int y)
{
	return x + y;
}
double add(double x, double y)
{
	return x + y;
}
int what(int i = 1, int j = 2)
{
	return i + j;
}
//缺省函数说是
int main()
{
	int i = 1;
	int j = 2;
	double x = 1.2;
	double y = 2.3;
	cout << add(i, j) << endl;
	cout << add(x, y) << endl;
	cout << what() << endl;



	const int& a = (i + j);

	//i+j的返回值是一个常值，是不可以被改变的
	//权限是可以被缩小的，但是不能被扩大


	return 0;
}
//函数重载说是