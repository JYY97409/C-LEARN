#include<iostream>

using namespace std;

namespace jyy
{
	class Person
	{
	public:

		Person(const string& name ,const size_t& age,const string& address)
			:_name(name)
			,_age(age)
			,_address(address)
		{}
		void Func()
		{
			cout << "Person Func" << endl;
		}

		Person& operator=(const Person& s)
		{
			_name = s._name;
			_age = s._age;
			_address = s._address;
			return *this;
		}

	private:
		string _name = "xxx";
		size_t _age;
		string _address;
	};

	class Student :public Person
	{
	public:
		Student()
			:Person("牢大", 48, "洛杉矶")
			,_number(114514)
		{}
		~Student()
		{

		}


		Student& operator=(const Student& s)
		{
			Person::operator= ( s );
			//这里就是体现了切片的用法，将子类中父类的成员变量切出来
			_number = s._number;

			return *this;
		}

		void Func()
		{
			cout << "Student Func" << endl;
		}

	private:
		size_t _number;
	};
	

}
//可以说就是构造的时候可以认为是
//构造的时候是先构造父类，析构的时候是先析构子类，这个顺序还是挺不一样的
int main()
{
	jyy::Student s1;
	s1.Person::Func();
	s1.Func();

	jyy::Student s2;
	s2 = s1;

	return 0;
}