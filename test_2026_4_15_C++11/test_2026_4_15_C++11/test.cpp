#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct Point
{
	int _x;
	int _y;
};


class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year, int month, int day)" << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date& d)" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

//int main()
//{
//	// C++98支持的
//	int a1[] = { 1, 2, 3, 4, 5 };
//	int a2[5] = { 0 };
//	Point p = { 1, 2 };
//
//	// C++11支持的
//	// 内置类型支持
//	int x1 = { 2 };
//	int x2 = 2;
//
//	// 自定义类型支持
//	// 这里本质是用{ 2025, 1, 1}构造一个Date临时对象
//	// 临时对象再去拷贝构造d1，编译器优化后合二为一变成{ 2025, 1, 1}直接构造初始化d1
//	// 运行一下，我们可以验证上面的理论，发现是没调用拷贝构造的
//	Date d1 = { 2025, 1, 1 };
//	Date d20(2025, 1, 1);
//
//	// 这里d2引用的是{ 2024, 7, 25 }构造的临时对象
//	const Date& d2 = { 2024, 7, 25 };
//
//	// 需要注意的是C++98支持单参数时类型转换，也可以不用{}
//	Date d3 = { 2025 }; // C++11
//	Date d4 = 2025;     // C++98
//	string str = "1111";
//
//	// 可以省略掉=
//	Point p1{ 1, 2 };
//	int x3{ 2 };
//	Date d6{ 2024, 7, 25 };
//	const Date& d7{ 2024, 7, 25 };
//
//	// 不支持，只有{}初始化，才能省略=
//	// Date d8 2025;
//
//	vector<Date> v;
//	v.push_back(d1);
//	v.push_back(Date(2025, 1, 1));
//	// 比起有名对象和匿名对象传参，这里{}更有性价比
//	v.push_back({ 2025, 1, 1 });
//	map<string, string> dict;
//	dict.insert({ "xxx", "yyyy" });
//
//	// 构造+拷贝构造+优化
//	//vector<int> v1 = { 1,2,3,4 };
//	//vector<int> v2 = { 10,20,30,1,1,1,1,1,1,1,1,1};
//	//const vector<int>& v4 = { 10,20,30,1,1,1,1,1,1,1,1,1 };
//
//	vector<int> v1{ 1,2,3,4 };
//	vector<int> v2{ 10,20,30,1,1,1,1,1,1,1,1,1 };
//	const vector<int>& v4 { 10,20,30,1,1,1,1,1,1,1,1,1 };
//
//	// 构造
//	vector<int> v3({ 10,20,30,1,1,1,1,1,1,1,1,1 });
//
//	initializer_list<int> il1 = { 10, 20, 30, 1, 1, 1, 1, 1, 1, 1, 1, 1};
//	int aa1[] = { 10, 20, 30, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
//
//	// initializer_list + {}pair初始化隐式类型转换
//	//map<string, string> dict = { { "xxx", "yyyy" }, { "sort", "zzzz" } };
//
//	return 0;
//}


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


