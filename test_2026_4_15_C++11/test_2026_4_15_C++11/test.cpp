#define _CRT_SECURE_NO_WARNINGS
#include"list.h"
#include<iostream>
#include<vector>
#include<map>
#include<cassert>
#include<list>
#include<functional>
using namespace std;

//struct Point
//{
//	int _x;
//	int _y;
//};
//
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//
//	Date(const Date& d)
//		:_year(d._year)
//		, _month(d._month)
//		, _day(d._day)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

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
//	Date d2(2025, 1, 1);
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


//template<class T>
//void func(const T& x)
//{}
//
//int main()
//{
//	// 左值：可以取地址
//	// 以下的p、b、c、*p、s、s[0]就是常见的左值
//	int* p = new int(0);
//	int b = 1;
//	const int c = b;
//	*p = 10;
//	string s("111111");
//	s[0] = 'x';
//
//	cout << &c << endl;
//	cout << (void*)&s[0] << endl;
//
//	// 左值引用给左值取别名
//	int& r1 = b;
//	int*& r2 = p;
//	int& r3 = *p;
//	string& r4 = s;
//	char& r5 = s[0];
//	
//
//
//	// 右值：不能取地址
//	double x = 1.1, y = 2.2;
//	// 以下几个10、x + y、fmin(x, y)、string("11111")都是常见的右值
//	10;
//	x + y;
//	fmin(x, y);
//	string("11111");
//
//	//cout << &10 << endl;
//	//cout << &(x+y) << endl;
//	//cout << &(fmin(x, y)) << endl;
//	//cout << &string("11111") << endl;
//
//	// 右值引用给右值取别名
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//	string&& rr4 = string("11111");
//
//	// 左值引用不能直接引用右值，但是const左值引用可以引用右值
//	const int& rx1 = 10;
//	const double& rx2 = x + y;
//	const double& rx3 = fmin(x, y);
//	const string& rx4 = string("11111");
//
//	// 右值引用不能直接引用左值，但是右值引用可以引用move(左值)
//	int&& rrx1 = move(b);
//	int*&& rrx2 = move(p);
//	int&& rrx3 = move(*p);
//	string&& rrx4 = move(s);
//	string&& rrx5 = (string&&)s;
//	//其实完全可以认为是强制类型转换，所以move是完全不影响原来左值的性质的
//
//	// b、r1、rr1都是变量表达式，都是左值
//	cout << &b << endl;
//	cout << &r1 << endl;
//	cout << &rr1 << endl;
//	//其实move就是强制类型转换，也就是说move是不会影响被move的值的
//
//	int i = 1;
//	int* ptr = (int*)i;
//
//	// int&& rr1 = 10;
//	// 这里要注意的是，rr1的属性是左值，所以不能再被右值引用绑定，除非move一下
//	int& r6 = rr1;
//
//	//int&& rrx6 = rr1;
//	int&& rrx6 = move(rr1);
//
//	//左值引用的表达式是左值，右值的表达式也是左值
//
//	//一切引用都是指针
//	return 0;
//}


//但是简单的将返回值类型改成&&类型不是很好的方式，这是因为返回值处在函数栈桢的位置，这个条件是没法改变的，所以是没办法延长的


//
//class Solution {
//public:
//	// 传值返回需要拷贝
//	bit::string addStrings(bit::string num1, bit::string num2) {
//		bit::string str;
//		int end1 = num1.size() - 1, end2 = num2.size() - 1;
//		// 进位
//		int next = 0;
//		while (end1 >= 0 || end2 >= 0)
//		{
//			int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
//			int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
//			int ret = val1 + val2 + next;
//			next = ret / 10;
//			ret = ret % 10;
//			str += ('0' + ret);
//		}
//		if (next == 1)
//			str += '1';
//		reverse(str.begin(), str.end());
//		//cout << &str << endl;
//
//		return str;
//	}
//};
//
//int main()
//{
//	// ...
//
//	bit::string	ret;
//	ret = Solution().addStrings("11111111111111111111", "222222222222222222222222222");
//	cout << ret.c_str() << endl;
//	//cout << &ret<< endl;
//	//可以发现是直接使用一块空间，这还算是比较激进的优化
//	return 0;
//}

//int main()
//{
//	//string ret = Solution().addStrings("11111111111111111111", "222222222222222222222222222");
//	//cout << ret << endl;
//
//	bit::string s1("11111111111111111");
//
//	bit::string s3 = s1;
//	bit::string s4 = bit::string("222222222");
//	bit::string s5 = move(s1);
//	//左值还是不要轻易的move ，容易出事
//
//	return 0;
//}



//int main()
//{
//	auto i ;
//
//
//
//
//	return 0;
//}

//// 由于引用折叠限定，f1实例化以后总是一个左值引用
//template<class T>
//void f1(T& x)
//{}
//
//// 由于引用折叠限定，f2实例化后可以是左值引用，也可以是右值引用
//template<class T>
//void f2(T&& x)
//{}
//
//int main()
//{
//	typedef int& lref;
//	typedef int&& rref;
//	int n = 0;
//
//	// 引用折叠
//	lref& r1 = n; // r1 的类型是 int&
//	lref&& r2 = n; // r2 的类型是 int&
//	rref& r3 = n; // r3 的类型是 int&
//	rref&& r4 = 1; // r4 的类型是 int&&
//
//	// 没有折叠->实例化为void f1(int& x)
//	f1<int>(n);
//	//f1<int>(0); // 报错
//
//	// 折叠->实例化为void f1(int& x)
//	f1<int&>(n);
//	//f1<int&>(0); // 报错
//
//	// 折叠->实例化为void f1(int& x)
//	f1<int&&>(n);
//	//f1<int&&>(0); // 报错
//
//	// 折叠->实例化为void f1(const int& x)
//	f1<const int&>(n);
//	f1<const int&>(0);
//
//	// 折叠->实例化为void f1(const int& x)
//	f1<const int&&>(n);
//	f1<const int&&>(0);
//
//	// 没有折叠->实例化为void f2(int&& x)
//	//f2<int>(n); // 报错
//	f2<int>(0);
//
//	// 折叠->实例化为void f2(int& x)
//	f2<int&>(n);
//	//f2<int&>(0); // 报错
//
//	// 折叠->实例化为void f2(int&& x)
//	//f2<int&&>(n); // 报错
//	f2<int&&>(0);
//
//	return 0;
//}

////万能引用 
//template<class T>
//void Function(T&& t)
//{
//	int a = 0;
//	T x = a;
//	//x++;
//
//	cout << &a << endl;
//	cout << &x << endl << endl;
//}
//
//int main()
//{
//	// 10是右值，推导出T为int，模板实例化为void Function(int&& t)
//	Function(10);
//
//	int a;
//	// a是左值，推导出T为int&，引用折叠，模板实例化为void Function(int& t)
//	Function(a); // 左值
//
//	// std::move(a)是右值，推导出T为int，模板实例化为void Function(int&& t)
//	Function(std::move(a));
//
//	const int b = 8;
//	// b是左值，推导出T为const int&，引用折叠，模板实例化为void Function(const int& t)
//	// 所以Function内部会编译报错，x不能++
//	Function(b);    // const 左值
//
//	// std::move(b)右值，推导出T为const int，模板实例化为void Function(const int&& t)
//	// 所以Function内部会编译报错，x不能++
//	Function(std::move(b)); // const 右值
//
//
//	//如果是没有显示指示Function的类型，那么右值往往是被识别为int类型，而左值往往被识别为引用
//
//	return 0;
//}


//#include"list.h"
//
//
//int main()
//{
//	jyy::list<bit::string> lt;
//	bit::string s1("11111111111");
//	lt.push_back(s1);
//
//	bit::string s2("33333333333");
//	lt.push_back(move(s2));
//
//	lt.push_back("22222222222");
//
//	return 0;
//}


//template <class T>
//int GetArg(const T& x)
//{
//	cout << x << " ";
//	return 0;
//}
//
//template <class ...Args>
//void Arguments(Args... args)
//{}
//
//template <class ...Args>
//void Print(Args... args)
//{
//	// 注意GetArg必须返回或者到的对象，这样才能组成参数包给Arguments
//	Arguments(GetArg(args)...);
//}
//
//int main()
//{
//	Print(1, "xxxx", 1.1);
//
//	return 0;
//}

//int main()
//{
//	jyy::list<bit::string> lt;
//	// 传左值，跟push_back一样，走拷贝构造
//	bit::string s1("111111111111");
//	bit::string s2("111111111111");
//	cout << "*********************************" << endl;
//
//	lt.emplace_back(s1);
//	cout << "*********************************" << endl;
//
//	lt.push_back(s1);
//	cout << "*********************************" << endl;
//
//	// 右值，跟push_back一样，走移动构造
//	lt.emplace_back(move(s1));
//	cout << "*********************************" << endl;
//
//	lt.push_back(move(s2));
//	cout << "*********************************" << endl;
//
//	lt.emplace_back("111111111111");
//	cout << "*********************************" << endl;
//
//	// 直接传参，隐式类型转换
//	lt.push_back("111111111111");
//	cout << "*********************************" << endl;
//
//	return 0;
//}

//int main()
//{
//	jyy::list<pair<bit::string, int>> lt1;
//	// 跟push_back一样
//	// 构造pair + 拷贝/移动构造pair到list的节点中data上
//	pair<bit::string, int> kv("苹果", 1);
//	lt1.emplace_back(kv);
//	cout << "*********************************" << endl;
//
//	// 21:15
//	// 跟push_back一样
//	lt1.emplace_back(move(kv));
//	cout << "*********************************" << endl;
//
//	// 这里达到的效果是push_back做不到的
//	//lt1.emplace_back({ "苹果", 1 }); // 不支持
//	lt1.emplace_back("苹果", 1 ); 
//	cout << "*********************************" << endl;
//
//	lt1.push_back({ "苹果", 1 });
//	cout << "*********************************" << endl;
//
//	return 0;
//}



//int main()
//{
//
//
//
//	return 0;
//}



//#include<algorithm>
//
//struct Goods
//{
//	string _name;  // 名字
//	double _price; // 价格
//	int _evaluate; // 评价
//	// ...
//
//	Goods(const char* str, double price, int evaluate)
//		:_name(str)
//		, _price(price)
//		, _evaluate(evaluate)
//	{
//	}
//};
//
//struct Compare1
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price < gr._price;
//	}
//};
//
//struct Compare2
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price > gr._price;
//	}
//};
//
//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3}, { "菠萝", 1.5, 4 } };
//	// 类似这样的场景，我们实现仿函数对象或者函数指针支持商品中
//	// 不同项的比较，相对还是比较麻烦的，那么这里lambda就很好用了
//
//	// 价格升序
//	//sort(v.begin(), v.end(), Compare1());
//
//	// 价格降序
//	//sort(v.begin(), v.end(), Compare2());
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._price < g2._price; });
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._price > g2._price; });
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._evaluate < g2._evaluate; });
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._evaluate > g2._evaluate; });
//
//	return 0;
//}


//// 包扩展（解析出参数包的内容）
//void ShowList()
//{
//	// 编译器时递归的终止条件，参数包是0个时，直接匹配这个函数
//	cout << endl;
//}
//
//template <class T, class ...Args>
//void ShowList(T&& x, Args&&... args)
//{
//	// 运行时
//	/*if (sizeof...(args) == 0)
//		return;*/
//
//	cout << x << " ";
//	// args是N个参数的参数包
//	// 调用ShowList，参数包的第一个传给x，剩下N-1传给第二个参数包
//	ShowList(args...);
//}
//
//template <class ...Args>
//void Print(Args&&... args)
//{
//	ShowList(args...);
//}


////////////////////////////////////////////////////////////
// 包扩展
//template <class T>
//const T& GetArg(const T& x)
//{
//	cout << x << " ";
//	return x;
//}

// //包扩展
//template <class T>
//const T& GetArg(const T& x)
//{
//	cout << x << " ";
//	return x;
//}
//
//template <class ...Args>
//void Arguments(Args... args)
//{}
//
//template <class ...Args>
//void Print(Args... args)
//{
//	// 注意GetArg必须返回或者到的对象，这样才能组成参数包给Arguments
//	Arguments(GetArg(args)...);
//}


int y = 1;

//int main()
//{
//	// 只能用当前lambda局部域和捕捉的对象和全局对象
//	int a = 0, b = 1, c = 2, d = 3;
//	auto func1 = [a, &b](int x)mutable
//	{
//		// 值捕捉的变量不能修改，引用捕捉的变量可以修改
//		a++;
//		b++;
//		int ret = a + b + x + y;
//		return ret;
//	};
//
//	cout << func1(1) << endl;
//	//func2();
//
//	// 隐式值捕捉
//	// 用了哪些变量就捕捉哪些变量
//	auto func2 = [=]
//	{
//		int ret = a + b + c;
//		return ret;
//	};
//	cout << func2() << endl;
//
//	// 隐式引用捕捉
//	// 用了哪些变量就捕捉哪些变量
//	auto func3 = [&]
//	{
//		a++;
//		c++;
//		//d++;
//	};
//
//	func3();
//	cout << a << " " << b << " " << c << " " << d << endl;
//
//	// 混合捕捉1
//	auto func4 = [&, a, b]
//	{
//		//a++;
//		//b++;
//		c++;
//		d++;
//		return a + b + c + d;
//	};
//
//	func4();
//	cout << a << " " << b << " " << c << " " << d << endl;
//
//	return 0;
//}

class Rate
{
public:
	Rate(double rate)
		: _rate(rate)
	{
	}
	double operator()(double money, int year)
	{
		return money * _rate * year;
	}
private:
	double _rate;
};

int main()
{
	double rate = 0.49;

	// lambda
	auto r2 = [rate](double money, int year) {
		return money * rate * year;
	};

	// 函数对象
	Rate r1(rate);
	r1(10000, 2);
	r2(10000, 2);

	auto func1 = [] {
		cout << "hello world" << endl;
	};

	func1();

	return 0;
}


////移动构造和移动赋值的默认生成机制：在析构、拷贝构造、移动赋值重载中右任意一个没写，生成原则和之前的拷贝构造的默认生成是一致的
//class Person
//{
//public:
//	Person(const char* name = "张三", int age = 1)
//		:_name(name)
//		, _age(age)
//	{}
//
//	Person(const Person& p) = default;
//	Person(Person&& p) = default;
//
//	/*~Person()
//	{}*/
//private:
//	bit::string _name;
//	int _age;
//};
//
//void func(ostream& out)
//{
//}
//
//int main()
//{
//	Person s1;
//	Person s2 = s1;
//	Person s3 = std::move(s1);
//
//	Person s4;
//	//s4 = std::move(s3);
//
//	func(cout);
//
//	return 0;
//}


///////lambda函数之捕获
//int main()
//{
//	int a = 0, b = 1, c = 2;
//	auto func1 = [a, b, c]()
//		{
//			return a + b + c;
//		};
//
//	cout << func1() << endl;
//
//	//自动引用捕获
//	auto func2 = [&, b, c]()
//		{
//			a++;
//			return a + b + c;
//		};
//
//
//	cout << func2() << endl;
//
//	//在[]中写上一个=是自动传值捕获
//	auto func3 = [=]()
//		{
//			return a + b + c;
//		};
//
//	cout << func3() << endl;
//
//	auto func4 = [&]()
//		{
//			return a + b + c;
//		};
//
//	cout << func4() << endl;
//	return 0;
//}
//

//////////bind的使用
using placeholders::_1;
using placeholders::_2;
using placeholders::_3;
//这里其实就是将这些数字封装在place_holdrers这个命名空间中了
int Sub(int a, int b)
{
	return (a - b) * 10;
}

int SubX(int a, int b, int c)
{
	return (a - b - c) * 10;
}


int sub (int a,int b)
{
	return a - b;
}

int subx(int a, int b,int c)
{
	return a + b + c;
}

//bind表达式
//int main()
//{
//
//	int a = 1, b = 2, c = 3;
//
//
//	auto sub1 = bind(sub,_1, _2);
//	cout << sub1(a, b) << endl;
//
//	auto sub5 = bind(sub, _2, _1);
//	cout << sub5(a, b) << endl;
//
//	auto sub2 = bind(sub, 100, _1);
//	cout << sub2(a) << endl;
//	
//	auto sub3 = bind(subx, _1, _2,_3);
//	cout << sub3(a, b,c) << endl;
//
//	auto sub4 = bind(subx, 100 , _1, _2);
//	cout << sub4(a, b) << endl;
//
//	return 0;
//
// 
// 
// 
//}

//int f(int a, int b)
//{
//	return a + b;
//}
//
//struct Functor
//{
//public:
//	int operator() (int a, int b)
//	{
//		return a + b;
//	}
//};
//
//class Plus
//{
//public:
//	Plus(int n = 10)
//		:_n(n)
//	{}
//
//	int plusi(int a, int b)
//	{
//		return a + b;
//	}
//
//	double plusd(double a, double b)
//	{
//		return (a + b) * _n;
//	}
//
//private:
//	int _n;
//};
//
//int main()
//{
//	function<int(int, int)> f1 = f;
//	Plus p1;
//
//	//类的成员函数存在一个隐藏的变量：this指针
//	//可以认为这里的this指针是为了绑定指向哪一个类的实例，这是因为类的成员函数很可能是会调用类的成员变量的，这时候要确保绑定了类的实例
//	//this指针的引用是会决定类中数据的改变与否的，比如传值传参很显然由于创建临时对象的缘故是不会影响原来的数据的
//	
//	
//	function<double(Plus, double, double)> f2 = &Plus::plusi;
//	cout << f2(Plus(), 1.1, 2.2) << endl;
//	
//	function<double(Plus*, double, double)> f3 = &Plus::plusi;
//	cout << f3(&p1, 1.1, 2.2) << endl;
//
//	function<double(Plus&&, double, double)> f4 = &Plus::plusi;
//	cout << f4(move(p1), 1.1, 2.2) << endl;
//
//
//	return 0;
//}


