//#include<iostream>
//
////默认构造：系统生成的、全缺省构造函数
//using namespace std;
//class Time
//{
//public:
//	
//	Time(int hour)
//	:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
// private:
//	 int _hour;
//	 };
//class Date
//{
//public:
//
//	
//	Date(int& xx, int year = 1900, int month = 1, int day = 1)//这里的缺省值有没有使用看的是有没有显式传参
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		, _n(1)
//		, _ref(xx)
//		,_t(1)
//	{ }
//	//初始化列表是每个成员定义初始化的地方（定义+初始化）
//
//private:
//	//C++11
//	//声明，缺省值->初始化
//	//系统生成的默认的构造也会用它
//
//	int _year = 1900;
//	int _month = 1;
//	int _day = 1;
//	//这里的缺省值是最保险的
//
//
//	//这些成员是可以先定义再初始化的
//
//	// error C2512: “Time”: 没有合适的默认构造函数可⽤
//	// error C2530 : “Date::_ref” : 必须初始化引⽤
//	// error C2789 : “Date::_n” : 必须初始化常量限定类型的对象
//	//这三个成员在定义的时候就一定要同步的初始化
//
//
//	
//	const int _n = 1;
//	int& _ref;
//	Time _t = 1;
//};
////初始化列表是定义和初始化统一的，不管我们有没有显式实现，都会走这个初始化列表
//
//int main()
//{
//	int x = 1;
//	Date date1(x, 2026, 1, 31);
//
//	return 0;
//}



//#include<iostream>
// using namespace std;
//
// class A
// {
// public:
//	 A(int a)
//		: _a1(a)
//		, _a2(_a1)
//	{}
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2 = 2;
//	int _a1 = 2;
//};
//int main()
//{
//	A aa(1);
//	aa.Print();
//}


//这个函数的定义顺序是顺着声明的顺序来的，而且定义是先于初始化的，但是语法上是可以认为他们是同步进行的







//// 实现⼀个类，计算程序中创建出了多少个类对象？
//#include<iostream>
//using namespace std;
//class A
//
//
//
//{
//public:
//	A()
//	{
//		++_scount;
//	}
//	A(const A& t)
//	{
//		++_scount;
//	}
//	~A()
//	{
//		--_scount;
//	}
//	static int GetACount()
//	{
//		return _scount;
//	}
//private:
//	// 类⾥⾯声明
//	static int _scount;
//};
//// 类外⾯初始化
//int A::_scount = 0;
//int main()
//{
//	 cout << A::GetACount() << endl;
//	 A a1, a2;
//	 A a3(a1);
//	 cout << A::GetACount() << endl;
//	 cout << a1.GetACount() << endl;
//	
//	// 编译报错：error C2248: “A::_scount”: ⽆法访问 private 成员(在“A”类中声明)
//	//cout << A::_scount << endl;
//		
//	return 0;
//}
////static成员，static修饰的成员变量，实际上像是全局变量，但是收到类域的限定
////使用static修饰的成员函数中没有this指针，就是所有成员所共有的，但是不偏袒于任何一个成员
////正是因为static修饰的成员变量是全局的，所以声明要在全局中声明
//
//
////要注意的是：后构造的先析构，先析构局部的，再析构全局的



//内部类其实是一个独立的类，只不过是受类域和访问限定符的限制，是不存在包含与被包含的关系的
//相应的，在内存上不存在从属关系，代表着我们不会在实例化类的时同时实例化它的内部类

//我们可以认为内部类就是专门为另一个类设计的

//#include<iostream>
//using namespace std;
//class A
//{
//private:
//	static int _k;
//	int _h = 1;
//public:
//	class B // B默认就是A的友元
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << _k << endl; //OK
//			cout << a._h << endl; //OK
//		}
//		int _b1;
//	};
//};
//int A::_k = 1;
//int main()
//{
//	cout << sizeof(A) << endl;
//	A::B b;
//	A aa;
//	b.foo(aa);
//	return 0;
//}
#include<iostream>
#include<algorithm>
using namespace std;

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}

private:
	int _a;
};

class Solution {
public:
	int Sum_Solution(int n) {
		//...
		return n;
	}
};

bool myfunction(int i, int j) { return (i > j); }

int main()
{
	A aa1;  //有名对象

	//我们可以认为这种有名对象是面向对象的
	//而无名对象可以被认为是面向过程的

	// 不能这么定义对象，因为编译器无法识别下面是一个函数声明，还是对象定义
	//A aa2();

	// 生命周期只在当前一行
	A(); // 匿名对象
	A(1);

	Solution st;
	cout << st.Sum_Solution(10) << endl;

	// 为了更方便
	cout << Solution().Sum_Solution(10) << endl;

	int a[] = { 32,71,12,45,26,80,53,33 };
	// < 升序
	sort(a, a + 8);

	// > 降序
	sort(a, a + 8, myfunction);

	/*greater<int> gt;
	sort(a, a + 8, gt);*/

	sort(a, a + 8, greater<int>());

	return 0;
}