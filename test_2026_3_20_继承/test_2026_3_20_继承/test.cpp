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