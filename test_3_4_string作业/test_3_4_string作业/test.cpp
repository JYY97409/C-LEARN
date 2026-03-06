#include"string.h"




namespace jyy
{
	void test_string1()
	{
		string s1;
		string s2("hello wrold");


		//s2 += " what can i say";
		cout << s2.c_str() << endl;
	}

	void test_string2()
	{
		string s1("hello wrold");

		s1.append("what can i say");

		cout << s1 << endl;

		s1.insert(0, '%');
		cout << s1 << endl;

	}
}
int main()
{
	jyy::test_string2();

	return 0;
}