#include<iostream>
#include<string>

using namespace std;
class Person
{
public:
	Person(const string& name ,int age = 18)
		:_name(name)
		,_age(age)
	{}
	void operator=(const Person& s)
	{
		_name = s._name;
		_age = s._age;
	}
	string _name;
	int _age;

};

class Student : public virtual Person 
{
public:
	Student(const string& name, int num = 114514)
		:Person(name)
		,_num(num)
	{}
	//这里是应用了切片
	void operator=(const Student& s)
	{
		Person::operator=(s);
		_num = s._num;
	}
	
	int _num;
};
class Teacher : public virtual Person
{
public:
	Teacher(const string& name ,const string& position = "沈阳大街")
		:Person(name)
		,_position(position)
	{}
	string _position;
};


//这里就是先在出现二义性得地方声明虚函数，但是此时二义性内容是存在一个公共空间，不属于任何一个对象
//出于从属关系的考量，我们需要在对象中显示调用Person类的构造函数
class Display : public Student,public Teacher
{
public:
	Display(const string& name)
		:Student(name)
		,Teacher(name)
		,Person(name)
	{}

	string _position;
};

int main()
{
	Display d1("张三");

	cout << d1._name << endl;
	cout << d1._name << endl;
	cout << d1.Teacher::_position << endl;
	cout << d1._num << endl;



	return 0;
}


//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//
//
//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//int main()
//{
//	Student sobj;
//	// 1.派⽣类对象可以赋值给基类的指针/引⽤
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	// ⽣类对象可以赋值给基类的对象是通过调⽤后⾯会讲解的基类的拷⻉构造完成的
//	Person pobj = sobj;
//	//2.基类对象不能赋值给派⽣类对象，这⾥会编译报错
//	sobj = pobj;
//	return 0;
//}


// C++11的⽅法
class Base final
{
public:
	void func5() { cout << "Base::func5" << endl; }
protected:
	int a = 1;
private:
	// C++98的⽅法
	/*Base()
	{}*/
};