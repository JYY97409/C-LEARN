#pragma once
#include<iostream>
using namespace std;
#include<cassert>


namespace jyy 
{
    // List的节点类
    template<class T>
    struct ListNode
    {
        ListNode(const T& val = T())
        {
            _val = val;
            _pPre = nullptr;
            _pNext = nullptr;
        }
        ListNode<T>* _pPre;
        ListNode<T>* _pNext;
        T _val;
    };


    //List的迭代器类
    template<class T, class Ref, class Ptr>
    struct ListIterator
    {
        typedef ListNode<T>* PNode;
        typedef ListIterator<T, Ref, Ptr> Self;
        ListIterator(PNode pNode)
            :_pNode(pNode)
        {}
        
        ListIterator(const Self& l)
            :_pNode(l._pNode)
        {}
        //这里是需要注意的点，要使用模版参数
        Ref operator*()
        {
            return _pNode->_val;
        }
        Ptr operator->()
        {
            return &_pNode->_val;
        }
        Self& operator++()
        {
            _pNode = _pNode->_pNext;
            return *this;
        }
        Self operator++(int)
        {
            Self ret = *this;
            _pNode = _pNode->_pNext;
            return ret;
        }
        Self& operator--()
        {
            _pNode = _pNode->_pPre;
            return *this;
        }
        Self operator--(int)
        {
            Self ret = *this;
            _pNode = _pNode->_pPre;
            return *this;
        }
        bool operator!=(const Self& l)
        {
            return _pNode != l._pNode;
        }
        bool operator==(const Self& l)
        {
            return _pNode == l._pNode;
        }
        PNode _pNode;
    };

    template<class Container>

    void print_container(const Container& con)
    {
        auto it = con.begin();

        while (it != con.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }

    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T*> const_iterator;
    public:
        ///////////////////////////////////////////////////////////////
        // List的构造
        list()
        {
            CreateHead();
        }
        list(int n, const T& value = T())
        {
            CreateHead();
            for (int i = 0; i < n; i++)
            {
                push_back(value);
            }
        }
        //我现在还是有点没绷住what can  i say
        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            CreateHead();
            while (first != last)
            {
                push_back(*first);
                //此处也不会破坏封装，还是不要直接访问来的好
                ++first;
            }
        }
        list(const list<T>& l)
        {
            CreateHead();
            //这里是还在构造过程中，所以如果直接使用this就会产生无限递归的问题
            /*auto it = l.begin();
            while (it != l.end())
            {
                push_back(it._pNode->_val);
                ++it;
            }*/

            for (auto it : l)
            {
                push_back(it);
            }
        }
        list<T>& operator=( list<T> l)
        {
            swap(l);
            return *this;
        }
        ~list()
        {
            clear();
            delete _head;
            _head = nullptr;
        }
        ///////////////////////////////////////////////////////////////
        // List Iterator
        iterator begin()
        {
            return iterator(_head->_pNext);
        }
        iterator end()
        {
            return iterator(_head);
        }
        const_iterator begin()const
        {
            return const_iterator(_head->_pNext);
        }
        const_iterator end()const
        {
            return const_iterator(_head);
        }


        ///////////////////////////////////////////////////////////////
        // List Capacity
        size_t size()const
        {
            return _size;
        }
        bool empty()const
        {
            return _size == 0;
        }


        ////////////////////////////////////////////////////////////
        // List Access
        T& front()
        {
            assert(!empty());
            return _head->_pNext->_val;
        }
        const T& front()const
        {
            assert(!empty());
            return _head->_pNext->_val;
        }
        T& back()
        {
            assert(!empty());
            return _head->_pPre->_val;
        }
        const T& back()const
        {
            assert(!empty());
            return _head->_pPre->_val;
        }


        ////////////////////////////////////////////////////////////
        // List Modify
        void push_back(const T& val) 
        { 
            insert(end(), val);
        }
        void pop_back() 
        {
            erase(--end());
        }
        void push_front(const T& val) 
        { 
            insert(begin(), val);
        }
        void pop_front() 
        { 
            erase(begin());
        }
        // 在pos位置前插入值为val的节点
        iterator insert(iterator pos, const T& val)
        {
            PNode new_node = new Node(val);
            
            
            Node* _pre = pos._pNode->_pPre;
            Node* _next = pos._pNode;


            _pre->_pNext = new_node;
            new_node->_pPre = _pre;

            _next->_pPre = new_node;
            new_node->_pNext = _next;

            _size++;
            return iterator(new_node);
        }
        // 删除pos位置的节点，返回该节点的下一个位置
        iterator erase(iterator pos)
        {
            Node* _pre = pos._pNode->_pPre;
            Node* _next = pos._pNode->_pNext;


            _pre->_pNext = _next;
            _next->_pPre = _pre;

            delete pos._pNode;

            _size--;
            return iterator(_next);
        }
        void clear()
        {
            auto it = begin();
            while (it != end())
            {
                it = erase(it);
            }
            _size = 0;
            _head->_pNext = _head;
            _head->_pPre = _head;
        }
        void swap(list<T>& l)
        {
            std::swap(_head, l._head);
            std::swap(_size, l._size);
        }
    private:
        void CreateHead()
        {
            _head = new Node;
            _head->_pNext = _head;
            _head->_pPre = _head;
            _size = 0;
        }
        PNode _head;
        size_t _size;
    };
};