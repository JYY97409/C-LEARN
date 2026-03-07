#include<iostream>


using namespace std;

int main()
{
	char buff[5];

	buff[0] = 97;
	buff[1] = 98;
	buff[2] = 99;
	buff[3] = 100;
	buff[4] = '\0';
	std::cout << buff << std::endl;

	//此处的英文只要60多个编码就可以表示完全
	//我们现在使用最多的是UTF-8编码（这是一个变长编码，起始的时候是一个字节）


	char str[] = "牛马";

	cout << str << endl;
	cout << strlen(str) << endl;

	str[1]++;
	cout << str << endl;
	
	str[3]++;
	cout << str << endl;
	
	str[1]++;
	cout << str << endl;
	
	str[3]++;
	cout << str << endl;


	char16_t str16[] = u"牛马";
	char32_t str32[] = U"牛马";
	wchar_t wstr[] = L"牛马";

	cout << sizeof(str) << endl;
	cout << sizeof(str16) << endl;
	cout << sizeof(str32) << endl;
	cout << sizeof(wstr) << endl;


	return 0;
}