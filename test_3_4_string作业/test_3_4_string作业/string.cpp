#define _CRT_SECURE_NO_WARNINGS 1
#include"string.h"


namespace jyy
{
	ostream& operator<<(ostream& _cout, const jyy::string& s)
	{
		return cout;
	}

	istream& operator>>(istream& _cin, jyy::string& s)
	{
		return cin;
	}

	

}