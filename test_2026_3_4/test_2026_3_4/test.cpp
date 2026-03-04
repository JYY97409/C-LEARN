
//#include"string.h"
#include<iostream>
using namespace std;
//
//
//
//
//int main()
//{
//
//	jyy::test_string2();
//	return 0;
//}

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



class Solution {
public:

    void myreverse(string& s, int left, int right)
    {
        right -= 1;
        char tmp;
        while (left < right)
        {
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            ++left;
            --right;
        }
    }

    string reverseWords(string s)
    {
        int left = 0;
        int right = 0;

        right = s.find_first_of(" ");
        while (right != string::npos)
        {
            myreverse(s, left, right);
            left = right + 1;
            right = s.find_first_of(" ", right + 1);
        }
        right = s.size();
        myreverse(s, left, right);

        return s;
    }
};


int main()
{
    string str("Let's take LeetCode contest");
        
    cout<<Solution().reverseWords(str) << endl;

    return 0;
}