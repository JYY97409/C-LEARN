#include"Date.h"
#include<iostream>
int main()
{
	Date date1(2027, 3, 1);
	Date date2(2026, 1, 29);
	std::cout << date1 - date2 << std::endl;
	if (date1 != date2)
		std::cout << "date1!=date2" << std::endl;
	if(!(date1 == date2))
		std::cout << "date1!=date2" << std::endl;
	date1++;
	date1++;
	date1++;
	date1++;
	date1++;
	date1++;
	date1++;
	date1++;
	date1++;
	date1++;
	date1++;
	date1++;
	date1++;
	date1.DisplayDate();
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1--;
	date1.DisplayDate();
	date1 += -35;
	date1.DisplayDate();
	return 0;
}