#include<iostream>
#include<string>
using namespace std;


class String
{
public:



private:




};



int main()
{
	string s1;
	string s2("Hello World");
	string s3 = s2;
	string s4 = "manba";
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;


	/*cin >> s1;
	cout << s1;*/



	string s5(s2, 5);
	cout << s5<<endl;


	s5[0] = 'h';
	cout << s5 << endl;

	return 0;
}