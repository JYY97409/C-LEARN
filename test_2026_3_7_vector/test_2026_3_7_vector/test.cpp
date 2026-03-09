#include<iostream>
#include<vector>
#include"vector.h"
using namespace std;

void test_vector1();

int main()
{
	jyy::test_vector5();
	return 0;
}

void test_vector1()
{

	vector<int> v1;

	vector<int> v2(10, 1);

	vector<int> v3(++v2.begin(), --v2.end());

	for (auto ch : v2)
	{
		cout << ch << " ";
	}
	cout << endl;



	for (size_t i = 0; i < 10; i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	vector<int>::iterator cur = v3.begin();


	while (cur != v3.end())
	{
		cout << *cur << " ";
		cur++;
	}
	cout << endl;
}

void test_vector2()
{
	vector<int> v1(10, 1);
	vector<int> v2(20, 1);


	v1.resize(15, 2);
	for (auto ch : v1)
	{
		cout << ch << " ";
	}
	cout << endl;
	v2.resize(15, 2);
	for (auto ch : v2)
	{
		cout << ch << " ";
	}
	cout << endl;
}

void test_vector3()
{
	vector<int> v1(10, 1);
	vector<int> v(10, 2);
	v1.push_back(10);
	
	v1.insert(v1.begin() + 3, 20);
	for (auto ch : v1)
	{
		cout << ch << " ";
	}
	cout << endl;
}

void test_vector4()
{

	vector<string> v1;
	string s1("xxxx");
	
	v1.push_back(s1);
	v1.push_back("yyyyy");

	//此处存在问题：如果仅仅是采用auto,会多出很多的深拷贝，这里还是使用引用好
	for (const auto& ch : v1)
	{
		cout << ch << " ";
	}
	cout << endl;

	vector<int> v2(5, 1);
	vector<vector<int>> vv(10, v2);
	cout << vv[2][2] << endl;
	vv.operator[](2).operator[](2) = 3;
	cout << vv[2][2] << endl;

}



