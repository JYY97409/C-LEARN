#include <iostream>
#include <map>
#include <string>

using namespace std;

char transform(char it)
{
    if (it >= 'A' && it <= 'Z')
    {
        it += ('a' - 'A');

    }

    return it;
}

int main()
{
    //怎么识别单词是一个问题r
    string st1;
    getline(cin, st1);
    map<string, int> ret;
    auto it = st1.begin();
    while (it != st1.end())
    {
        string st2;
        while (*it != ' ' && *it != '.')
        {
            char c = transform(*it);
            st2.push_back(c);
            ++it;

        }
        st2.push_back('\0');
        ret[st2]++;

        ++it;
    }
    for (auto e : ret)
    {
        cout << e.first << ":" << e.second << endl;
    }

    return 0;
}