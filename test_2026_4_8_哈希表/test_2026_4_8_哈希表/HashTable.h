#pragma once
#include<iostream>
#include<vector>

using namespace std;


enum State
{
	EXIST,
	EMPTY,
	DELETE
};


template<class K, class V>
class HashNode
{
	/*HashNode(const pair<K,V>& data = make_pair(0,0))
		:_data(data)
		, _state(EMPTY)
	{ }*/


	//构造函数在没有显示实现时候会自己调用自定义类型的构造函数（浅拷贝）
public:
	pair<K, V> _data;
	State _state = EMPTY;
};
//模板特化
template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}

};

template<>
struct HashFunc<string>
{
	size_t operator()(const string& key)
	{	
		size_t ret = 0;
		int flag = 1;
		for (auto ch : key)
		{
			ret = ret * 131 + ch;
		}
		return ret;
	}
};


//仿函数解决类型转换问题
//常见类型使用模板特化
//实际上是反映了哈希对key的要求就是key可以转成整形
//哈希表需要key支持转成整形和支持等于比较
//这里还是存在一个问题：参数不应该传当前参数，而是传n + 1
inline unsigned long __stl_next_prime(unsigned long n)
{
	// Note: assumes long is at least 32 bits.
	static const int __stl_num_primes = 28;
	static const unsigned long __stl_prime_list[__stl_num_primes] = {
		53, 97, 193, 389, 769,
		1543, 3079, 6151, 12289, 24593,
		49157, 98317, 196613, 393241, 786433,
		1572869, 3145739, 6291469, 12582917, 25165843,
		50331653, 100663319, 201326611, 402653189, 805306457,
		1610612741, 3221225473, 4294967291
	};
	const unsigned long* first = __stl_prime_list;
	const unsigned long* last = __stl_prime_list + __stl_num_primes;
	const unsigned long* pos = lower_bound(first, last, n);
	return pos == last ? *(last - 1) : *pos;
}




namespace open_adress
{

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		HashTable(int size = 11)
			:_table(size)
			, _n(0)
		{}

		bool insert(const pair<K, V>& data)
		{
			if (find(data.first))
			{
				return false;
			}

			if (_n * 10 / _table.size() > 7)
			{
				HashTable<K, V> new_hash(_table.size() * 2);

				for (auto e : _table)
				{
					new_hash.insert(e._data);
				}

				_table.swap(new_hash._table);
				_n = new_hash._n;
			}
			Hash hashF;
			size_t hash0 = hashF(data.first) % _table.size();
			size_t i = 1;
			size_t hashi = hash0;
			while (_table[hashi]._state == EXIST)
			{
				//当该位置是有数据的时候是需要移动的
				hashi = (hashi + i) % _table.size();
				i++;
			}

			_table[hashi]._data = data;
			_table[hashi]._state = EXIST;
			_n++;
			return true;
		}


		//整体就是先取模，然后++
		//这里不是vector 的指针是因为vector实际上是顺序表，不是数组
		HashNode<K, V>* find(const K& key)
		{
			Hash hashF;
			size_t hash0 = hashF(key) % _table.size();
			if (_table[hash0]._state == EXIST && _table[hash0]._data.first == key)
			{
				return &_table[hash0];
			}
			size_t i = 1;
			size_t hashi = hash0;
			while (_table[hashi]._state != EMPTY)
			{
				//这导致哈希表的key需要支持==，而map只需要支持小于比较就行
				if (_table[hashi]._state == EXIST && _table[hashi]._data.first == key)
				{
					return &_table[hashi];
				}
				//当该位置是有数据的时候是需要移动的
				hashi = (hashi + i) % _table.size();
				i++;
			}


			return nullptr;
		}

		bool erase(const K& key)
		{
			HashNode<K, V>* data = find(key);

			if (data == nullptr)
				return false;
			else
			{
				data->_state = DELETE;
				--_n;
				return true;
			}
		}
	private:
		vector <HashNode<K, V>> _table;
		size_t _n;
	};
}

namespace hash_bucket
{
	template<class T>
	class HashNode
	{
	public:
		using Node = HashNode<T>;

		HashNode<T>(const T& data)
			:_data(data)
			, _state(EMPTY)
			, _next(nullptr)
		{}

		//构造函数在没有显示实现时候会自己调用自定义类型的构造函数（浅拷贝）
	public:
		T _data;
		State _state = EMPTY;
		Node* _next = nullptr;
	};

	template<class K, class T, class KeyofT, class Hash>
	class HashTable;


	template<class K,class T,class Ref,class Ptr,class KeyofT,class Hash>
	class Iterator
	{
	public:
		using Node = HashNode<T>;
		using HashTable = HashTable<K, T, KeyofT, Hash>;
		using Self = Iterator<K, T, Ref, Ptr, KeyofT, Hash>;

		Iterator<K, T, Ref, Ptr, KeyofT, Hash>( Node* node , HashTable* ht)
			:_node(node)
			,_ht(ht)
		{}

		Ptr operator->()
		{
			return &(_node->_data);
		}

		Ref operator*()
		{
			return _node->_data;
		}
		
		bool operator==(const Self& s)
		{
			return _node == s._node && _ht == s._ht;
		}
		bool operator!=(const Self& s)
		{
			return !operator==(s);
		}
		
		//前置++
		Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				//这里可以优化一下
				Hash hashf;
				KeyofT kot;
				size_t hashi = hashf(kot(_node->_data)) % _ht->_table.size() + 1;
				while (hashi < _ht->_table.size())
				{
					if (_ht->_table[hashi])
					{
						_node = _ht->_table[hashi];
						break;
					}
					else
					{
						hashi++;
					}
				}

				if (hashi == _ht->_table.size())
				{
					_node = nullptr;
				}
			}

			return *this;
		}

	private:
		Node* _node;
		HashTable* _ht;
	};

	template<class K, class T ,class KeyofT, class Hash>
	class HashTable
	{
		template<class K, class T, class Ref, class Ptr, class KeyofT, class Hash>
		friend class Iterator;
		//模板友元声明需要连上模板参数
	public:
		using Node = HashNode<T>;
		using iterator = Iterator<K, T, T&, T*, KeyofT, Hash>;
		using const_iterator = Iterator<K, T, const T&,const T*, KeyofT, Hash>;


		HashTable<K,T,KeyofT,Hash>(size_t size = 29)
			:_table(size)
			,_n(0)
		{}

		iterator begin()
		{
			Node* cur;
			size_t hashi = 0;
			while (hashi < _table.size())
			{
				if (_table[hashi])
				{
					cur = _table[hashi];
					return iterator(cur,this);
				}
				else
				{
					hashi++;
				}
			}

			return end();
		}

		const_iterator begin()const
		{
			Node* cur;
			size_t hashi = 0;
			while (hashi < _table.size())
			{
				if (_table[hashi])
				{
					cur = _table[hashi];
					return const_iterator(cur, this);
				}
				else
				{
					hashi++;
				}
			}

			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		const_iterator end()const
		{
			return const_iterator(nullptr, this);
		}

		pair<iterator ,bool> insert(const T& data)
		{
			KeyofT kot;
			Node* ret = find(kot(data));
			if (ret)
			{
				return { iterator(ret,this),false };
			}
			Hash hashf;
			if (_n == _table.size())
			{
				//扩容逻辑

				vector<Node*> new_table(__stl_next_prime(_n + 1));
				Node* cur = nullptr;
				for (int i = 0; i < _table.size(); i++)
				{

					cur = _table[i];

					while (cur)
					{
						size_t hashi = hashf(kot(cur->_data)) % new_table.size();
						Node* next = cur->_next;
						cur->_next = new_table[hashi];
						new_table[hashi] = cur;
						cur = next;
					}

					_table[i] = nullptr;
				}


				_table.swap(new_table);
			}

			size_t hashi = hashf(kot(data)) % _table.size();
			Node* new_node = new Node(data);
			new_node->_next = _table[hashi];
			_table[hashi] = new_node;

			return { iterator(new_node,this),true };
		}

		bool erase(const K& key)
		{
			KeyofT kot;
			Hash hashf;
			size_t hashi = hashf(key) % _table.size();
			Node* cur = _table[hashi];
			Node* prev = nullptr;
			while (cur)
			{
				if ( kot(cur->_data) == key)
				{
					if (prev == nullptr)
					{
						_table[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;

					_n--;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}

			}

			return false;
		}

		Node* find(const K& key)
		{
			
			Hash hashf;
			size_t hashi = hashf(key) % _table.size();

			Node* cur = _table[hashi];
			while (cur)
			{
				if (cur->_data.first == key)
					return cur;

				cur = cur->_next;
			}


			return cur;
		}

	private:
		vector<Node*> _table;
		size_t _n;
	};

}