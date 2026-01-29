#pragma once
#include<iostream>
class Date

{

public:

	// 获取某年某月的天数

	int GetMonthDay(int year, int month);

	void DisplayDate();

	// 全缺省的构造函数

	Date(int year = 1900, int month = 1, int day = 1);

	bool CheckDate();
	// 拷贝构造函数

    // d2(d1)

	Date(const Date& d);


	// 赋值运算符重载

    // d2 = d3 -> d2.operator=(&d2, d3)

	Date& operator=(const Date& d);


	// 析构函数

	~Date();


	// 日期+=天数

	Date& operator+=(int day);


	// 日期+天数

	Date operator+(int day);



	// 日期-天数

	Date operator-(int day);



	// 日期-=天数

	Date& operator-=(int day);



	// 前置++

	Date& operator++();



	// 后置++

	Date operator++(int);



	// 后置--

	Date operator--(int);



	// 前置--

	Date& operator--();



	// >运算符重载

	bool operator>(const Date& d);



	// ==运算符重载

	bool operator==(const Date& d);



	// >=运算符重载

	bool operator >= (const Date& d);



	// <运算符重载

	bool operator < (const Date& d);



	// <=运算符重载

	bool operator <= (const Date& d);



	// !=运算符重载

	bool operator != (const Date& d);



	// 日期-日期 返回天数

	int operator-(const Date& d);

	//这里还有流的运算符重载，C++中的cout和cin可以实现自动识别类型的原因就是C++自己写好了函数重载，我们要想我们的自定义类型也可以采用cin、cout就要我们自己写函数重载

private:

	int _year;

	int _month;

	int _day;

};