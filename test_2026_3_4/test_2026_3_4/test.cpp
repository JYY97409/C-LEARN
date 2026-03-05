
#include"string.h"
#include<iostream>
using namespace std;


namespace jyy
{
	void test_string1()
	{
		jyy::string s1;
		jyy::string s2("hello world");
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;



		for (int i = 0; i < s2.size(); i++)
		{
			cout << s2[i] << " ";
		}
		cout << endl;

		for (auto ch : s2)
		{
			cout << ch << " ";
		}
		cout << endl;

		string::iteartor it = s2.begin();
		while (it != s2.end())
		{
			cout << *it << " ";
			++it;
		}
		s2.push_back(' ');
		s2 += 'w';
		cout << s2.c_str() << endl;

	}

	void test_string2()
	{
		string s1("hello wrold");

		s1.append(" what can i say");
		cout << s1.c_str() << endl;
	}

	void test_string3()
	{
		string s1("hello wrold");
		cout << s1.c_str() << endl;
		s1.insert(0, "what can i say");
		cout << s1.c_str() << endl;


		string s2("hello wrold");
		s2.insert(5, "what can i say");
		cout << s2.c_str() << endl;


	}

	void test_string4()
	{
		string s1("hello wrold");
		cout << s1.c_str() << endl;


		cout << s1.find(0, 'h') << " " << s1.find( 0 ,"he") << endl;

		string ret = s1.substr(5);

		cout << ret.c_str() << endl;
	}

	void test_string5()
	{
		string s1 = "hello wrold";
		cout << s1 << endl;
		string s2;

		cin >> s1;
		cout << s1 << endl;
		s2 = "what can i say";
		cout << s2 << endl;


	}
}

int main()
{

	jyy::test_string5();
	return 0;
}

//class Solution {
//public:
//    string multiply(string num1, string num2)
//    {
//        if (num1.c_str() == "0" || num2.c_str() == "0")
//            return 0;
//
//        int pos1 = num1.size();
//        int pos2 = num2.size();
//
//        string ret(pos1+pos2,'0');
//        int num = 0;
//        int now = 0;
//        reverse(num1.begin(), num1.end());
//        reverse(num2.begin(), num2.end());
//
//        for (int i = 0; i < pos1; i++)
//        {
//            for (int j = 0; j < pos2; j++)
//            {
//                 num = (num1[i] - '0') * (num2[j] - '0');
//               
//                if (ret[i+j]=='0')
//                {
//                    ret[i+j] = num + '0';
//                }
//                else
//                {
//                    ret[i] = ret[i] + num;
//                    int n = i;
//                    while (ret[n] - '0' > 10)
//                    {
//                        ret[n+1] = (ret[n] - '0') / 10;
//                        ret[n] = (ret[n] - '0') % 10 + '0';
//                        ++n;
//                    }
//                }
//                    
//               
//
//            }
//        }
//        reverse(ret.begin(), ret.end());
//        return ret;
//    }
//};
//



//class Solution {
//public:
//
//    void myreverse(string& s, int left, int right)
//    {
//        right -= 1;
//        char tmp;
//        while (left < right)
//        {
//            tmp = s[left];
//            s[left] = s[right];
//            s[right] = tmp;
//            ++left;
//            --right;
//        }
//    }
//
//    string reverseWords(string s)
//    {
//        int left = 0;
//        int right = 0;
//
//        right = s.find_first_of(" ");
//        while (right != string::npos)
//        {
//            myreverse(s, left, right);
//            left = right + 1;
//            right = s.find_first_of(" ", right + 1);
//        }
//        right = s.size();
//        myreverse(s, left, right);
//
//        return s;
//    }
//};
//
//
//int main()
//{
//    string str("Let's take LeetCode contest");
//        
//    cout<<Solution().reverseWords(str) << endl;
//
//    return 0;
//}