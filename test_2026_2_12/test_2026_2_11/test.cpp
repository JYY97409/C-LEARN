#include<iostream>
#include<string>

using namespace std;


void tsst_string1()
{
	string s1 = "hello wrold";
	string s2("hello wrold");


	cout << s1 << endl;
	cout << s2 << endl;

	//1、下标重载+下标访问
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;
	//2、迭代器
	/////////////////适用于容器和数组
	string::iterator it = s2.begin();
	//auto it=s2.begin();
	//这里要指定类域，不然不知道用哪个迭代器
	while (it != s2.end())
	{
		*it += 2;
		cout << *it << " ";
		

		++it;
	}
	cout << endl;
	//3、范围for（底层是迭代器）
	//auto不可以做参数，但是可以作为返回值

	//这里存在引用和传参的区别
	for (auto& arr : s2)
		//这里一定是:
	{
		arr -= 2;
		cout << arr << " ";
		
	}
	cout << endl;


}

void test_string2()
{
	string s2("hello wrold");


	string::const_iterator it = s2.begin();
	//auto it=s2.begin();
	//这里要指定类域，不然不知道用哪个迭代器
	while (it != s2.end())
	{
		
		cout << *it << " ";
		++it;
	}
	cout << endl;

	string::const_reverse_iterator rit = s2.rbegin();
	while (rit != s2.rend())
	{
		
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	//这里的反向迭代器是比使用正向迭代器反向遍历好用的
	//因为迭代器是左闭右开的，正向迭代器遍历会显得更加笨重


	//总共有四种迭代器
}

void TestPushBack()
{
	// reverse 反转  逆置
	// reserve 保留、预留
	string s;
	// 提前开空间，避免扩容，提高效率
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "capacity changed: " << sz << '\n';

	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

void test_string3()
{
	string s1 = "hello wrold";
	cout << s1 << endl;
	cout << s1.length() << endl;
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
}

void test_string4()
{
	string s1("xxxxxxxxxxxxxxxxxxxxx");
	cout << s1.size()<<endl;
	cout << s1.capacity() << endl << endl;
	
	s1.reserve(20);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl << endl;

	s1.reserve(25);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl << endl;


	s1.reserve(40);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl << endl;
	
	s1.clear();
	cout << s1.size() << endl;
	cout << s1.capacity() << endl << endl;

	s1.shrink_to_fit();
	cout << s1.size() << endl;
	cout << s1.capacity() << endl << endl;

}

int main()
{
	//test_string1();
	//test_string2();
	/*test_string3();*/
	/*TestPushBack();*/

	test_string4();
	return 0;
}