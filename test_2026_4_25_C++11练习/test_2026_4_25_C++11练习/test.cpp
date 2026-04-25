#include<iostream>
#include<vector>
#include<map>
#include<cassert>
using namespace std;

template<class T>
void func(const T& x)
{}

int main()
{
	// 左值：可以取地址
	// 以下的p、b、c、*p、s、s[0]就是常见的左值
	int* p = new int(0);
	int b = 1;
	const int c = b;
	*p = 10;
	string s("111111");
	s[0] = 'x';

	cout << &c << endl;
	cout << (void*)&s[0] << endl;

	// 左值引用给左值取别名
	int& r1 = b;
	int*& r2 = p;
	int& r3 = *p;
	string& r4 = s;
	char& r5 = s[0];
	


	// 右值：不能取地址
	double x = 1.1, y = 2.2;
	// 以下几个10、x + y、fmin(x, y)、string("11111")都是常见的右值
	10;
	x + y;
	fmin(x, y);
	string("11111");

	//cout << &10 << endl;
	//cout << &(x+y) << endl;
	//cout << &(fmin(x, y)) << endl;
	//cout << &string("11111") << endl;

	// 右值引用给右值取别名
	int&& rr1 = 10;
	double&& rr2 = x + y;
	double&& rr3 = fmin(x, y);
	string&& rr4 = string("11111");

	// 左值引用不能直接引用右值，但是const左值引用可以引用右值
	const int& rx1 = 10;
	const double& rx2 = x + y;
	const double& rx3 = fmin(x, y);
	const string& rx4 = string("11111");

	// 右值引用不能直接引用左值，但是右值引用可以引用move(左值)
	int&& rrx1 = move(b);
	int*&& rrx2 = move(p);
	int&& rrx3 = move(*p);
	string&& rrx4 = move(s);
	string&& rrx5 = (string&&)s;
	//其实完全可以认为是强制类型转换，所以move是完全不影响原来左值的性质的

	// b、r1、rr1都是变量表达式，都是左值
	cout << &b << endl;
	cout << &r1 << endl;
	cout << &rr1 << endl;
	//其实move就是强制类型转换，也就是说move是不会影响被move的值的

	int i = 1;
	int* ptr = (int*)i;

	// int&& rr1 = 10;
	// 这里要注意的是，rr1的属性是左值，所以不能再被右值引用绑定，除非move一下
	int& r6 = rr1;

	//int&& rrx6 = rr1;
	int&& rrx6 = move(rr1);

	//左值引用的表达式是左值，右值的表达式也是左值

	//一切引用都是指针
	return 0;
}