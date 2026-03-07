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

		//s1.append(" what can i say");
		cin >> s1;
		cout << s1 << endl;

		//s1.insert(0, '%');
		
		//s1.erase(5, 7);
		s1.insert(0, "hello wrold ");
		cout << s1 << endl;



	}


	void test_string3()
	{
		string s1("hello world");

		string s2 = s1;

		cout << s1 << endl << s2 << endl;

	}
}
int main()
{
	jyy::test_string3();

	return 0;
}