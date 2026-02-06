#include<iostream>
using namespace std;
class A
{
public:
	A(int a = 0)
		:_a1(a)
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


int main()
{
	int* p1 = new int[10];
	int* p2 = new int;


	


	int* p3 = new int[10] { 0 };
	int* p4 = new int[10] {1, 2, 3, 4, 5};


	delete[] p1;
	delete p2;
	delete[] p3;
	delete[] p4;
	return 0;
}
