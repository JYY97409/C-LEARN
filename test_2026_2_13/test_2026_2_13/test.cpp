#include<iostream>
using namespace std;

void test_string1()
{
	string s("hello world");
	s += " what can i say";
	cout << s << endl;
}
void test_string2()
{
	string s("hello world");
	s.erase(0, 1);
	cout << s << endl;
	
	s.erase(5);
	//这里我们可以使用npos缺省值直接删除所有的数据
	cout << s << endl;

	string ss("hello world");
	ss.replace(5, 1, "%%");
	cout << ss << endl;

	/*size_t pos = 0;
	string sss("hello world hello bit");
	pos = sss.find(' ', pos + 2);
	while (pos != string::npos)
	{
		sss.replace(pos, 1,"%%");
		pos = sss.find(' ', pos + 2);
	}
	cout << sss << endl;*/

	string sss("hello world hello bit");
	string temp;
	for (auto ch : sss)
	{
		if (ch == ' ')
			temp += "%%";
		else
			temp += ch;
	}
	//sss = temp;
	sss.swap(temp);
	cout << sss << endl;

}

void test_string3()
{
	string s("test.cpp");
	size_t pos = s.rfind(".");
	//倒着找
	string suffix = s.substr(pos);
	cout << suffix << endl;

}


void SplitFilename(const std::string& str)
{
	std::cout << "Splitting: " << str << '\n';
	std::size_t found = str.find_last_of("/\\");

	std::cout << " path: " << str.substr(0, found) << '\n';
	std::cout << " file: " << str.substr(found + 1) << '\n';
}


// 16：10
void test_string4()
{
	string s("test.cpp.zip");
	size_t pos = s.rfind('.');
	string suffix = s.substr(pos);
	cout << suffix << endl;

	std::string str("Please, replace the vowels in this sentence by asterisks.");
	std::cout << str << '\n';

	std::size_t found = str.find_first_of("abcdef");
	//实际上是叫find_any_of更好
	//是找到string中符合""中的任意一个字符的下标
	while (found != std::string::npos)
	{
		str[found] = '*';
		found = str.find_first_not_of("abcdef", found + 1);
	}

	std::cout << str << '\n';

	std::string str1("/usr/bin/man");
	std::string str2("D:\\1-教学服务团队\\1-比特课件\\4.C++课件\\C++课件V6-2022年修订\\C++课件--2022修订\\C++进阶课件");

	SplitFilename(str1);
	SplitFilename(str2);
}


void test_string5()
{
	string s("hello wrold");
	
	s.erase(0, 1);
	cout << s << endl;

	s.erase(s.begin());
	cout << s << endl;

	s.erase(--s.end());
	cout << s << endl;

	s.erase(s.size() - 1);
	cout << s << endl;


	string ss("hello wrold");
	ss.erase(6);
	//这里是npos缺省值，是一个极大值
	cout << ss << endl;
	

	string sss("hello wrold hello bit");
	size_t pos = sss.find(' ');
	while (pos != string::npos)
	{
		sss.replace(pos, 1, "%%");
		pos = sss.find(' ', pos + 2);
	}
	cout << sss << endl;
}

void test_string6()
{

	string sss("hello wrold hello bit");
	string tmp;
	tmp.reserve(sss.size());
	for (auto ch : sss)
	{

		if (ch == ' ')
			tmp += "%%";
		else
			tmp += ch;

	}
	cout << tmp << endl;
	sss = tmp;
	cout << sss << endl;

	char* arr = (char*)sss.c_str();
	//c_str是常常在写C++代码时要调用C的接口时使用的
	cout << arr << endl;
}

int main()
{
	//test_string1();
	//test_string2();
	//test_string3();
	test_string4();
	//test_string5();
	//test_string6();
	return 0;
}