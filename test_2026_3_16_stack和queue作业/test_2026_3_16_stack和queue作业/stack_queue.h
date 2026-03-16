#pragma once
#include<iostream>
#include<stack>
#include<deque>
#include<list>
#include<vector>
#include<algorithm>


using namespace std;
namespace jyy
{
    template<class T, class Con = deque<T>>

    class stack

    {

    public:

        stack()
        {
            Con();
        }

        void push(const T& t)
        {
            _con.push_back(t);
        }

        void pop()
        {
            _con.pop_back();
        }

        T& top()
        {
            return _con.back();
        }

        const T& top()const
        {
            return _con.back();
        }

        size_t size()const
        {
            return _con.size();
        }

        bool empty()const
        {
            return _con.empty();
        }

    private:

        Con _con;

    };



    template<class T, class Con = deque<T>>

    class queue

    {

    public:


        queue()
        {
            Con _con;
        }

        void push(const T& x)
        {
            _con.push_front(x);
        }

        void pop()
        {
            _con.pop_back();
        }

        T& back()
        {
            return _con.back();
        }

        const T& back()const
        {
            return _con.back();
        }

        T& front()
        {
            return _con.front();

        }

        const T& front()const
        {
            return _con.front();
        }

        size_t size()const
        {
            return _con.size();
        }

        bool empty()const
        {
            return _con.empty();
        }

    private:

        Con _con;

    };

}
