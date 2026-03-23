#include<iostream>
using namespace std;

//class Car
//{
//public:
//	virtual void  func() = 0
//	{
//		cout << "what can i say" << endl;
//	}
//
//
//};
//
//int main()
//{
//
//	return 0;
//}


//class A
//
//{
//
//public:
//
//    virtual void func()
//
//    {
//
//        cout << "A::f()" << endl;
//
//    }
//
//};
//
//
//
//class B : public A
//
//{
//
//private:
//
//    virtual void func()
//
//    {
//
//        cout << "B::f()" << endl;
//
//    }
//
//    static void func()
//    {
//
//    }
//
//
//
//};
//
//
//int main()
//{
//
//    A* pa = (A*)new B;
//
//    pa->func();
//
//    return 0;
//}
//


//class A
//{
//public:
//	virtual ~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//	virtual void func1()
//	{
//
//	}
//	virtual void func2()final
//	{
//
//	}
//};
//class B : public A {
//public:
//	virtual ~B()
//	{
//		cout << "~B()->delete:" << _p << endl;
//		delete _p;
//	}
//	/*virtual void func1(size_t i)override
//	{
//
//	}
//	virtual void func2()
//	{
//
//	}*/
//protected:
//	int* _p = new int[10];
//};
//// 只有派⽣类Student的析构函数重写了Person的析构函数，下⾯的delete对象调⽤析构函数，才能
////构成多态，才能保证p1和p2指向的对象正确的调⽤析构函数。
//int main()
//{
//	A* p1 = new A;
//	A* p2 = new B;
//	delete p1;
//	delete p2;
//	return 0;
//}

class A {};
class B : public A {};

// 协变
class Person {
public:
	virtual A* BuyTicket()
	{
		cout << "买票-全价" << endl;
		return nullptr;
	}
};

class Student : public Person {
public:
	virtual B* BuyTicket()
	{
		cout << "买票-打折" << endl;
		return nullptr;
	}
};

void Func(Person* ptr)
{
	ptr->BuyTicket();
}

//int main()
//{
//	Person ps;
//	Student st;
//
//	Func(&ps);
//	Func(&st);
//
//	return 0;
//}
class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
	void func5() { cout << "Base::func5" << endl; }
protected:
	int a = 1;
};

class Derive : public Base
{
public:
	// 重写基类的func1
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func1" << endl; }
	void func4() { cout << "Derive::func4" << endl; }

protected:
	int b = 2;
};
int main()
{
	int i = 0;
	static int j = 1;
	int* p1 = new int;
	const char* p2 = "xxxxxxxx";
	printf("栈:%p\n", &i);
	printf("静态区:%p\n", &j);
	printf("堆:%p\n", p1);
	printf("常量区:%p\n", p2);

	Base b;
	Derive d;
	Base* p3 = &b;
	Derive* p4 = &d;
	printf("Person虚表地址:%p\n", *(int*)p3);
	printf("Student虚表地址:%p\n", *(int*)p4);
	printf("虚函数地址:%p\n", &Base::func1);
	printf("普通函数地址:%p\n", &Base::func5);
	return 0;
}