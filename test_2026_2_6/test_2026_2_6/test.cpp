#include<iostream>
using namespace std;
class A
{
public:
	A(int a1 = 0,int a2 = 1)
		:_a1(a1)
		,_a2(a2)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a1(aa._a1)
	{
		cout << "A(const A& aa)" << endl;
	}
	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a1 = aa._a1;
		}
		return *this;
	}
	~A()
	{
		cout << "~A()" << endl;
	}

	void Print()
	{
		cout << "A::Print" << "->"<< _a1 <<endl;
	}

	//前置++重载
	A operator++()
	{
		++_a1;
		return *this;

	}
private:
	int _a1 = 1;
	int _a2 = 2;
};

void f1(A aa)
{}

A f2()
{
	A aa(1);
	/*++aa;*/
	return aa;
}



//int main()
//{
//	//A aa1;
//	//A aa2(aa1);
//	//cout << endl;
//
//
//	////这里其实是应该先构造再拷贝的，但是编译器识别到了这是一个连续的过程，认为应该优化
//	//A aa3(A(1));
//	//cout << endl;
//
//
//	////这里应该是先构造一个临时对象，再拷贝构造，这里编译器又识别出了这是一个连贯的过程，所以要优化
//	//A(1);
//	//cout << endl;
//
//
//	//这里相当于是直接调用了返回的临时对象
//	f2().Print();
//	cout << "*******" << endl << endl;
//
//
//	return 0;
//}




//int main()
//{
//	A ret;
//	ret = f2();
//	ret.Print();
//	cout << "***********" << endl << endl;
//}
//


//int main()
//{
//	int* p1 = new int[10];
//	int* p2 = new int;
//
//
//	
//
//
//	int* p3 = new int[10] { 0 };
//	int* p4 = new int[10] {1, 2, 3, 4, 5};
//
//
//	delete[] p1;
//	delete p2;
//	delete[] p3;
//	delete[] p4;
//	return 0;
//}



//int main()
//{
//	A* p1 = new A(1);
//	A* p2 = new A(2, 2);
//
//	A* p3 = new A[3]{ A(1, 1), A(2, 2), A(3, 3) };
//
//	  
//	A* p4 = new A[3]{ {1,1},{2,2},{3,3} };
//	//隐式类型转换
//
//
//	delete(p1);
//	delete(p2);
//
//	//new的数组要将[]使用起来（对应起来）
//	delete[](p3);
//	delete[](p4);
//
//	return 0;
//}


//int main()
//{
//
//	try
//	{
//		void* p1 = new char[1024 * 1024 * 1024];
//
//		cout << p1 << endl;
//		void* p2 = new char[1024 * 1024 * 1024];
//
//		cout << p2 << endl;
//		void* p3 = new char[1024 * 1024 * 1024];
//		cout << p3 << endl;
//
//		int n = 1;
//		while (1)
//		{
//			void* p1 = new char[1024 * 1024 * 1024];
//			cout << n << endl;
//			++n;
//		}
//
//	}
//	catch(const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	//面向对象捕捉错误信息
//
//	//new的底层实际上是malloc，malloc是负责开空间的
//
//	return 0;
//}




class B
{

private:
	int _a1;
	int _a2;
};


int main()
{
	//malloc是用来申请空间的
	//构造函数是用来初始化



	A* p2 = new A[10];
	delete(p2);
	//这里显示实现了析构函数，所以函数栈桢前面多出了4个字节用来存储有几个对象，好调用析构函数
	//内存是整段申请的，我们的指针指向的是连带上了的前面的数字，这时候我们的函数

	///////////////////////////////////////////////////////////////////////////////////////////
	////new的底层就是operator new （也就是malloc+抛异常）和调用构造函数//这个面试的时候问过




	B* p3 = new B[10];
	delete p3;
	//这里的类没有显示实现析构函数所以编译器没有在前面加上那四个字节的数字



	return 0;
}