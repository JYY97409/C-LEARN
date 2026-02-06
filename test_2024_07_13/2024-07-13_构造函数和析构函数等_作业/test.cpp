#include"Date.h"
#include<iostream>


void test1()
{
	Date date1(2027, 3, 1);
	Date date2(2026, 1, 29);
	std::cout << date1 - date2 << std::endl;
	if (date1 != date2)
		std::cout << "date1!=date2" << std::endl;
	if (!(date1 == date2))
		std::cout << "date1!=date2" << std::endl;
	
	date1 += -35;
	date1.Print();
}

void test2()
{
	Date date1;
	Date date2(2026, 1, 30);

	std::cout << date1 <<std::endl<< date2;
}
void test3()
{
	Date d1, d2;
	std::cin >> d1 >> d2;
	std::cout << d1 << std::endl << d2<<std::endl;
	std::cout << d1 - d2 << std::endl;
}

void test4()
{
	const Date d1;
	d1.Print();
}
void test5()
{
	Date d1(2026, 1, 30);
	Date d2 = d1;
	std::cout << d1 << std::endl<< d2 << std::endl;
}
int main()
{
	test2();
	test3();
	test5();
	return 0;
}