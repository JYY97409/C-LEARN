#pragma once
#include<iostream>
#include<cassert>
using namespace std;

namespace jyy
{
    template<class T>

    class vector

    {

    public:

        // Vector的迭代器是一个原生指针

        typedef T* iterator;

        typedef const T* const_iterator;

        iterator begin()
        {
            return _start;
        }

        iterator end()
        {
            return _finish;
        }

        const_iterator begin()const
        {
            return _start;
        }

        const_iterator end()const
        {
            return _finish;
        }

        const_iterator cbegin()
        {

        }

        const_iterator cend() const
        {

        }

        // construct and destroy


        //这里是直接告诉编译器这个是用默认构造函数
        vector() = default;

        vector(int n, const T& value = T())
        {
            resize(n, value);
        }

        //成员函数作为函数模版
        template<class InputIterator>

        vector(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }

        vector(const vector<T>& v)
        {
            size_t len = v.size();

            reserve(len);
            
            for (size_t i = 0; i < len; i++)
            {
                push_back(v._start[i]);
            }
        }
        
        vector<T>& operator= (vector<T> v)
        {
            swap(v);

            return *this;
        }

        ~vector()
        {
            delete[] _start;
            _start = _finish = _end_of_storage = nullptr;
        }

        // capacity

        size_t size() const
        {
            return _finish - _start;
        }

        size_t capacity() const
        {
            return _end_of_storage - _start;
        }

        void reserve(size_t n)
        {
            if (n <= capacity())
                return;

            size_t old_size = size();

            T* tmp = new T[n];
            // memcpy(tmp, _start, old_size * sizeof(T));
            //这里的memcpy容易出现浅拷贝的问题
            
            for (size_t i = 0; i < old_size; i++)
            {
                tmp[i] = _start[i];
            }
            delete[] _start;

            _start = tmp;
            _finish = _start + old_size;
            _end_of_storage = _start + n;

        }

        void resize(size_t n, const T& value = T())
        {
            if (n < size())
            {
                _finish = _start + n;
            }

            if (n > capacity())
            {
                reserve(n + size() > 2 * capacity() ? n + size() : 2 * capacity());
            }

            T* end = _start + n;

            while (_finish < end)
            {
                *(_finish++) = value;
            }
        }

        ///////////////access///////////////////////////////

        T& operator[](size_t pos)
        {
            assert(pos < size());
            return *(_start + pos);
        }

        const T& operator[](size_t pos)const
        {
            assert(pos < size());
            return *(_start + pos);
        }

        ///////////////modify/////////////////////////////

        void push_back(const T& x)
        {
            if (_finish == _end_of_storage)
            {
                reserve(capacity() == 0 ? 4 : 2 * capacity());
            }

            *(_finish++) = x;
        }

        void pop_back()
        {
            --_finish;
        }

        void swap(vector<T>& v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_end_of_storage, v._end_of_storage);
        }

        iterator insert(iterator pos, const T& x)
        {
            assert(pos < _finish);
            if (_finish == _end_of_storage)
            {
                reserve(capacity() == 0 ? 4 : 2 * capacity());
            }
            auto cur = _finish;

            while (cur >= _start)
            {
                *(cur + 1) = *cur;
                --cur;
            }
            *pos = x;
            ++_finish;
            return pos;
        }

        iterator erase(iterator pos)
        {
            assert(pos < _finish);
            auto cur = pos;

            while (cur < _finish - 1)
            {
                *(cur) = *(cur + 1);
                cur++;
            }
            --_finish;
            return pos;
        }
    private:

        iterator _start = nullptr; // 指向数据块的开始

        iterator _finish = nullptr; // 指向有效数据的尾

        iterator _end_of_storage = nullptr; // 指向存储容量的尾

    };
    template <class T>
    void printf_vector(const vector<T>& v)
    {
 


        auto it = v.begin();
        while (it != v.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }

    template <class  Container>
    void printf_container(const  Container& v)
    {

        auto it = v.begin();
        while (it != v.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }
    void test_vector()
    {
        vector<int> v1(10, 5);
        printf_vector(v1);

        v1.insert(v1.begin(), 3);
        v1.insert(v1.begin() + 4, 5);
        printf_vector(v1);


        v1.erase(v1.begin() + 4);
        printf_vector(v1);

        v1.push_back(20);
        printf_vector(v1);


        v1.resize(10);
        printf_vector(v1);


    }

    void test_vector1()
    {
        vector<int> v(10, 1);
        vector<int> v1 = v;
        
        vector<int> v2;
        v2 = v1;

        printf_vector(v);
        printf_vector(v1);
        printf_vector(v2);


        vector<int> v3(v2.begin() + 3, v2.end());
        printf_vector(v3);
        


        vector<string> v4 ;
        v4.push_back("11111111111111111");
        v4.push_back("11111111111111111");
        v4.push_back("11111111111111111");
        v4.push_back("11111111111111111");
        printf_container(v4);

        v4.push_back("11111111111111111");
        printf_container(v4);

    }

}