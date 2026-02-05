#include<iostream>

//class JYY
//{
//	public:
//		int num;
//		 
//};

//int main()
//{
//
//
//	return 0;
//}
 
//using namespace std;
//// 计算⼀下A/B/C实例化的对象是多⼤？
//class A
//{
//public:
//	void Print()
//	{
//		cout << _ch << endl;
//	}
//private:
//	char _ch;
//	int _i;
//};
//class B
//{
//public:
//	void Print()
//	{
//		//...
//	}
//};
//class C
//{
//};
//int main()
//{
//	A a;
//	B b;
//	C c;
//	cout << sizeof(a) << endl;
//	cout << sizeof(b) << endl;
//	cout << sizeof(c) << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	// void Init(Date* const this, int year, int month, int day)
//	void Init(int year, int month, int day)
//	{
//		// 编译报错：error C2106: “=”: 左操作数必须为左值
//		// this = nullptr;
//		// this->_year = year;
//		_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	void Print()
//	{
//		cout << this->_year << "/" << this->_month << "/" << this->_day << endl;
//		//函数中是不可以直接传this的，但是可以直接在函数内部使用
//		//void* const类型的，其本身是不能被修改的，但是指向的数据是可以被修改的 
//	}
//private:
//	// 这⾥只是声明，没有开空间
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	// Date类实例化出对象d1和d2
//	Date d1;
//	Date d2;
//	// d1.Init(&d1, 2024, 3, 31);
//	d1.Init(2024, 3, 31);
//	d1.Print();
//	d2.Init(2024, 7, 5);
//	d2.Print();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	void Print()
//	{
//		cout << this << endl;
//		//是空指针，但是我们又没有使用它
//		cout << "A::Print()" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = (A*)malloc(sizeof(A));
//	p->Print();
//
//	//mov ecx p
//	//call 一个地址
//	return 0;
//}
////包能动的
////就是一个正常的类
////空指针是将类中的变量置为空，实际上是不影响类中函数的使用的
////因为函数也不在类的空间中


//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	void Print()
//	{
//		cout << "A::Print()" << endl;
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//	return 0;
//}
//包是要GG的
//公用和私有影响的是他们在类里和类外访问的权限

//封装：可以将权限分配的明明白白，管理说是，就像C是粗放的，但是C++是精细的

//1. 函数名与类名相同。
//2. ⽆返回值。(返回值啥都不需要给，也不需要写void，不要纠结，C++规定如此)
//3. 对象实例化时系统会⾃动调⽤对应的构造函数。
//4. 构造函数可以重载。
// 
//基本特性 
//
//5. 如果类中没有显式定义构造函数，则C++编译器会⾃动⽣成⼀个⽆参的默认构造函数，⼀旦⽤⼾显
//式定义编译器将不再⽣成。
//6. ⽆参构造函数、全缺省构造函数、我们不写构造时编译器默认⽣成的构造函数，都叫做默认构造函
//数。但是这三个函数有且只有⼀个存在，不能同时存在。⽆参构造函数和全缺省构造函数虽然构成
//函数重载，但是调⽤时会存在歧义。要注意很多同学会认为默认构造函数是编译器默认⽣成那个叫
//默认构造，实际上⽆参构造函数、全缺省构造函数也是默认构造，总结⼀下就是不传实参就可以调
//⽤的构造就叫默认构造。
//7. 我们不写，编译器默认⽣成的构造，对内置类型成员变量的初始化没有要求，也就是说是是否初始
//化是不确定的，看编译器。对于⾃定义类型成员变量，要求调⽤这个成员变量的默认构造函数初始
//化。如果这个成员变量，没有默认构造函数，那么就会报错，我们要初始化这个成员变量，需要⽤
//初始化列表才能解决，初始化列表，我们下个章节再细细讲解。



//#include<iostream>
//
//using namespace std;
//class DATE
//{
//public:
//	/*DATE()
//	{
//		_year = 1;
//		_month = 1;
//		_day = 1;
//	}*/
//
//	//特性是如果用户不在函数中显示定义的话，会默认给一个无参的（）,但是没有初始化的话，付的是一对不明所以的数
//	//此处想起了我之前在写贪吃蛇的时候的错误，不初始化变量的话是一个负的极大的数
//	
//	//6. ⽆参构造函数、全缺省构造函数、我们不写构造时编译器默认⽣成的构造函数，都叫做默认构造函数。
//
//	//何意味？   他们都可以在不传参的情况下调用
//
//	//这其中，全缺省的函数是最好的，因为他可以将类中的数据初始化，也可以传参按照自己想的方式来初始化
//
//	//这三个函数是互相不兼容的
//
//
//	DATE(int day=1,int month=12,int year=2025)
//	{
//		_year = year;
//		_day = day;
//		_month = month;
//	}
//	void print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////构造函数是一种特殊的函数
////函数名就是
//int main()
//{
//	DATE date;
//	date.print();
//	//为何在调用的时候无参的是没有（）的，因为我们这里的两个函数是构成函数重载的，但是如果我们将（）加上，
//	//我们要如何知道函数重载的是哪一个呢？？？
//	DATE date2;
//	date2.print();
//	return 0;
//}



#include<iostream>
 using namespace std;

 typedef int STDataType;
 class Stack
 {
 public:
	Stack(int n = 4)
	{
		_a = (STDataType*)malloc(sizeof(STDataType) * n);
		if (nullptr == _a)//WC了，这是一个好习惯，我TM的老是在这里掉坑
		{
			perror("malloc申请空间失败");
			return;
		}
		_capacity = n;
		_top = 0;
	}
	 // ...
 private:
	 STDataType * _a;
	 size_t _capacity;
	 size_t _top;
 };

 // 两个Stack实现队列
 class MyQueue
 {
 public:
	 //编译器默认⽣成MyQueue的构造函数调⽤了Stack的构造，完成了两个成员的初始化
 private:
	 Stack pushst;
	 Stack popst;
	 int size;
 };


 int main()
 {
	 MyQueue mq;
	 return 0;
 }

 //大多数场景下面

 //构造函数的特点是应写净写


 ///////////////////////////////////////////////////////////////////////////////////////////
//3. 析构函数
//析构函数与构造函数功能相反，析构函数不是完成对对象本⾝的销毁，⽐如局部对象是存在栈帧的，
//函数结束栈帧销毁，他就释放了，不需要我们管，C++规定对象在销毁时会⾃动调⽤析构函数，完成对
//象中资源的清理释放⼯作。析构函数的功能类⽐我们之前Stack实现的Destroy功能，⽽像Date没有
//Destroy，其实就是没有资源需要释放，所以严格说Date是不需要析构函数的。
//析构函数的特点：
//1. 析构函数名是在类名前加上字符 ~。
//2. ⽆参数⽆返回值。(这⾥跟构造类似，也不需要加void)
//3. ⼀个类只能有⼀个析构函数。若未显式定义，系统会⾃动⽣成默认的析构函数。
//4. 对象⽣命周期结束时，系统会⾃动调⽤析构函数。
//5. 跟构造函数类似，我们不写编译器⾃动⽣成的析构函数对内置类型成员不做处理，⾃定