#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<memory>
#include<functional>
#include<atomic>
#include<thread>
#include<mutex>

using namespace std;


struct Date
{
    int _year;
    int _month;
    int _day;

    Date(int year = 1, int month = 1, int day = 1)
        :_year(year)
        , _month(month)
        , _day(day)
    {}

    ~Date()
    {
        cout << "~Date()" << endl;
    }
};

namespace bit
{


    template<class T>
    class shared_ptr
    {
    public:
        shared_ptr(T* ptr)
            : _ptr(ptr)
            , _pcount(new atomic<int>(1))
        {}

        template<class D>
        shared_ptr(T* ptr, D del)
            : _ptr(ptr)
            , _pcount(new atomic<int>(1))
            , _del(del)
        {}


        //析构函数
        ~shared_ptr()
        {
            if (--(*_pcount) == 0)
            {
                //delete _ptr;
                _del(_ptr);
                delete _pcount;
            }
        }


        //拷贝构造函数
        shared_ptr(const shared_ptr<T>& sp)
            : _ptr(sp._ptr)
            , _pcount(sp._pcount)
        {
            (*_pcount)++;
        }

        // sp1 = sp4;
        // sp4 = sp4;
        // sp1 = sp2;
        shared_ptr<T>& operator=(const shared_ptr<T>& sp)
        {
           if(_ptr!=sp._ptr)
           {
               if (--(*_pcount) == 0)
               {
                   delete _ptr;
                   delete _pcount;
               }

               _ptr = sp._ptr;
               _pcount = sp._pcount;

               ++(*_pcount);

           }
            return *this;
        }

        T& operator*()
        {
            return *_ptr;
        }

        T* operator->()
        {
            return _ptr;
        }

        int use_count()
        {
            return *_pcount;
        }
    private:
        T* _ptr;
        //int* _pcount;
        atomic<int>* _pcount;  // 原子操作

        function<void(T*)> _del = [](T* ptr) {delete ptr; };
    };
};

namespace jyy
{ 
    template<class T>
    class shared_ptr
    {
    public:
        shared_ptr(T* ptr)
            :_ptr(ptr)
            , _pcount(new atomic<int>(1))
        {}
        template<class D>
        shared_ptr(T* ptr, D d_func)
            : _ptr(ptr)
            , _pcount(new atomic<int>(1) )
            ,_delete(d_func)
        {}


        ~shared_ptr()
        {
            if (*_pcount == 1)
            {
                _delete(_ptr);

                delete _pcount;
            }
            else
            {
                (*_pcount)--;
            }
        }


        //拷贝构造说是
        shared_ptr(const shared_ptr<T>& p1)
            : _ptr(p1._ptr)
            , _pcount(p1._pcount)
            , _delete(p1._delete)

        {
            ++(*_pcount);
        }


        shared_ptr<T>& operator = (const shared_ptr<T>& p1)
        {
            //这里要考虑的还是比较多的，主要是不知道之前是不是已经指向空间了

            if (_ptr != nullptr)
            {
                if (--(*_pcount) == 0)
                {
                    _delete(_ptr);
                    delete _pcount;
                }
            }
            
            _ptr = p1._ptr;
            _pcount = p1._pcount;
            _delete = p1._delete;

            ++(*_pcount);


            return *this;
        }


        T* operator->()
        {
            return _ptr;
        }

        T& operator*()
        {
            return *_ptr;
        }

        int use_count()
        {
            return *_pcount;
        }


    private:
        T* _ptr;
        //int* _pcount;
        
        atomic<int>* _pcount;



        function<void(T*)> _delete = [](T* ptr) {delete ptr; };
    };

}







//int main()
//{
//    std::shared_ptr<Date> sp1(new Date(2024, 9, 11));
//    shared_ptr<Date> sp2 = make_shared<Date>(2024, 9, 11);
//    shared_ptr<Date> sp4;
//    //这里存在内存碎片的风险，但是make_shared就是将计数开到数据指针上面，这还是很好的 
//   
//    
//    
//    // if (sp1.operator bool())
//    if (sp1)
//        cout << "sp1 is not nullptr" << endl;
//
//    //if (!sp4)
//    if (!sp4.operator bool())
//        cout << "sp4 is nullptr" << endl;
//
//    //shared_ptr<Date> sp5 = new Date(2024, 9, 11);
//    //unique_ptr<Date> sp6 = new Date(2024, 9, 11);
//
//    return 0;
//}


struct AA
{
    int _a1 = 0;
    int _a2 = 0;

    ~AA()
    {
        cout << "~AA()" << endl;
    }
};

//int main()
//{
//    jyy::shared_ptr<AA> p(new AA);
//    const size_t n = 100000;
//
//    mutex mtx;
//    auto func = [&]()
//    {
//        for (size_t i = 0; i < n; ++i)
//        {
//            // 这里智能指针拷贝会++计数
//            jyy::shared_ptr<AA> copy(p);
//            {
//                unique_lock<mutex> lk(mtx);
//                copy->_a1++;
//                copy->_a2++;
//            }
//        }
//    };
//    //此处不是用atomic的话会引发进程间的相互干扰
//    thread t1(func);
//    thread t2(func);
//
//    t1.join();
//    t2.join();
//
//    cout << p->_a1 << endl;
//    cout << p->_a2 << endl;
//
//    cout << p.use_count() << endl;
//
//    return 0;
//}