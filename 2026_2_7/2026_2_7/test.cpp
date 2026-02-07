#include<iostream>
using namespace std;

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//// 定位new/replacement new
//int main()
//{
//	// p1现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
//		A* p1 = (A*)malloc(sizeof(A));
//	new(p1)A; // 注意：如果A类的构造函数有参数时，此处需要传参
//	p1->~A();
//	free(p1);
//	A* p2 = (A*)operator new(sizeof(A));
//	new(p2)A(10);
//	p2->~A();
//	operator delete(p2);
//	return 0;
//}
//
//
//
//int main()
//{
//	
//	A* a1 = new A(1);
//
//    
//
//
//	return 0;
//}


//template<class T>
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
//
//template<typename T1, typename T2>
//void func(const T1& x, const T2 y)
//{
//
//}
//
//
//template<class T>
//T Add(const T& x, const T& y)
//{
//	return x + y;
//}
//
//
//template<class T>
//T* Mynew(int  n)
//{
//	return  new T[n];
//}
//
//
//int main()
//{
//	int i = 10, j = 20;
//	double m = 10.1, n = 20.1;
//
//	cout << Add(i, (int)m) << endl;
//	cout << Add((double)i, m) << endl;
//
//	cout << Add<int>(i, m) << endl;
//	cout << Add<double>(i, m) << endl;
//
//	cout << Add<float>(i, m) << endl;
//	//显式类型转换（相当于是指定了将要转换的类型）
//
//	float* p1 = Mynew<float>(5);
//
//	return 0;
//}




template<class T>
class Stack
{
public:
	Stack(int n = 4)
		:_array( new T[n])
		, _size(0)
		, _capacity(n)
	{
	}
	~Stack()
	{
		delete[] _array;
		_array = nullptr;
		_size = _capacity = 0;
	}
	

	void Push(const T& x);

private:
	T* _array;
	size_t _size;
	size_t _capacity;


};

template<class X>
void Stack<X>::Push(const X& x)//这里是需要注意的点
{
	if (_size == _capacity)
	{
		X* tmp = new X[_capacity * 2];
		memcpy(tmp, _array, sizeof(X) * _size);
		delete[] _array;
		_array = tmp;
		_capacity *= 2;
	}

	_array[_size++] = x;
}
//这里template的名字实际上是不重要的，在编译器看来是都一样的



int main()
{

	Stack<int> st1(4);
	Stack<double> st2(5);


	Stack<double>* pst = new Stack<double>;
	delete pst;
	//这里delete的是我们手动申请的内存
	Stack<float> psr();

	//what can i say
	//manba out




	return 0;
}





