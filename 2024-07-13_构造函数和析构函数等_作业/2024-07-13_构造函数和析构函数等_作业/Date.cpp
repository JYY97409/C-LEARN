#include"Date.h"
using namespace std;

int Date::GetMonthDay(int year, int month)
{
	if (month == 0)
	{
		std::cout << "出现错误" << std::endl;
		return -1;
	}
	int arr[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };

	if (2 == month && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		return 29;

	return arr[month];
}


void Swap(int d1, int d2)
{
	int temp = d1;
	d1 = d2;
	d2 = temp;
}

void Date::DisplayDate()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}

Date::Date(int year, int month, int day)
{
	
	_year = year;
	_month = month;
	_day = day;
	if (CheckDate())
		std::cout << "非法日期:";
	DisplayDate();
}
bool Date::CheckDate()
{
	if (_month > 12 || _month < 1
		|| _day<1 || _day>GetMonthDay(_year, _month))
		return true;
	else
		return false;
}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date& Date::operator=(const Date& d)
{
	this->_year = d._year;
	this->_month = d._month;
	this->_day = d._day;
	return *this;
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this-=(-day);
	}
	int month_day = 0;
	_day += day;
	while (_day > (month_day = GetMonthDay(_year, _month)))
	{
		_day -= month_day;
		_month++;
		if (_month == 13)
		{
			_year += 1;
			_month = 1;
		}
	}

	return *this;
}

Date Date::operator+(int day)
{

	Date temp = *this;
	temp += day;
	return temp;
	//这里是一个临时值，所以要使用值传递，不可以使用引用传递（防止丢数据）

}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}
	_day -= day;
	while (_day < 0)
	{
		_month --;
		if (0 == _month)
		{
			_month = 12;
			_year--;
		}
		_day += GetMonthDay(_year,_month);
		
	}
	return *this;
}
//为何一定要采用这种方法？
//因为-是一定要复制的，但是-=是不需要的，如果将主逻辑写在-中，那么不可避免的要出现多调用一次拷贝构造函数的问题
Date Date::operator-(int day)
{
	Date temp = *this;
	temp -= day;
	return temp;
}

Date::~Date() 
{
	
}
//前置++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
//后置++
//这里的后置++的参数是一个空的int类型(这是祖师爷专门用来区分前置和后置的，实际上是不传参的)
Date Date::operator++(int)
{
	Date temp = *this;
	*this += 1;
	return temp;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date temp = *this;
	*this -= 1;
	return temp;
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
		return true;
	if (_year < d._year)
		return false;
	if (_month > d._month)
		return true;
	if (_month < d._month)
		return false;
	if (_day > d._day)
		return true;


	return false;
}

bool Date::operator==(const Date& d) 
{
	return (*this)._year == d._year &&
		(*this)._month == d._month &&
		(*this)._day == d._day;
}

bool Date::operator >= (const Date& d) 
{
	return *this > d || *this == d;
}

bool Date::operator < (const Date& d)
{
	return !(*this > d);
}

bool Date::operator <= (const Date& d)
{
	return *this < d || *this == d;
}

bool Date::operator != (const Date& d)
{
	return !(*this == d);
}

int Date::operator-(const Date& d)
{
	int BigYear = (*this)._year;
	int SmallYear = d._year;
	//经典的假设法
	if (BigYear < SmallYear)
		Swap(BigYear, SmallYear);
	int ret = 0;
	ret += (BigYear - SmallYear) * 365;
	for (int year = SmallYear; year < BigYear; year++)
	{
		if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
			ret += 1;
	}
	int day1 = 0;
	for (int i = 1; i < (*this)._month; i++)
	{
		day1 += GetMonthDay((*this)._year, (*this)._month);
	}
	day1 += (*this)._day;
	int day2 = 0;
	for (int i = 1; i < (*this)._month; i++)
	{
		day2 += GetMonthDay((*this)._year, (*this)._month);
	}
	day2 += d._day;
	return ret + (day1 - day2);
}
//但是我们还可以直接将我们的算法最大程度的复用，直接先比较大小，再依次++
