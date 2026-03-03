#include<iostream>

using namespace std;
void test_string1()
{
	string s("hello wrold");
	s += "  xxxxx";
	cout << s << endl;
	s = "hello wrold";
	cout << s << endl;
	s.insert(0, "what cna i say ");
	cout << s << endl;
}

void test_string2()
{
	string s("test.cpp.zip");
	size_t pos = s.rfind('.');
	string buff = s.substr(pos);
	//从指定位置返回一个子串
	cout << buff << endl;
}

void test_string3()
{
	string s("hello");
	string ss = s + " wrold";
	cout << s + " wrold" << endl;
	cout << ss << endl;
}
int main()
{

	//test_string1();
	test_string3();
	return 0;
}