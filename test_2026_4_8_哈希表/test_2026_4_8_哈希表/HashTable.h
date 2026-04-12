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
	/*HashNode(const pair<K,V>& kv)
		:_kv({kv.first,kv.second})
		, _state(EMPTY)
	{ }*/


	//构造函数在没有显示实现时候会自己调用自定义类型的构造函数（浅拷贝）
public:
	pair<K, V> _kv;
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
			if (flag)
			{
				ret += ch * 131;
				flag = 0;
			}
			else
				flag = 1;
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

		bool insert(const pair<K, V>& kv)
		{
			if (find(kv.first))
			{
				return false;
			}

			if (_n * 10 / _table.size() > 7)
			{
				HashTable<K, V> new_hash(_table.size() * 2);

				for (auto e : _table)
				{
					new_hash.insert(e._kv);
				}

				_table.swap(new_hash._table);
				_n = new_hash._n;
			}
			Hash hashF;
			size_t hash0 = hashF(kv.first) % _table.size();
			size_t i = 1;
			size_t hashi = hash0;
			while (_table[hashi]._state == EXIST)
			{
				//当该位置是有数据的时候是需要移动的
				hashi = (hashi + i) % _table.size();
				i++;
			}

			_table[hashi]._kv = kv;
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
			if (_table[hash0]._state == EXIST && _table[hash0]._kv.first == key)
			{
				return &_table[hash0];
			}
			size_t i = 1;
			size_t hashi = hash0;
			while (_table[hashi]._state != EMPTY)
			{
				//这导致哈希表的key需要支持==，而map只需要支持小于比较就行
				if (_table[hashi]._state == EXIST && _table[hashi]._kv.first == key)
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
			HashNode<K, V>* kv = find(key);

			if (kv == nullptr)
				return false;
			else
			{
				kv->_state = DELETE;
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

	template<class K, class V>
	class HashNode
	{
	public:
		using Node = HashNode<K, V>;

		HashNode<K,V>(const pair<K,V> kv)
			:_kv(kv)
			,_state(EMPTY)
			,_next(nullptr)
		{ }

		//构造函数在没有显示实现时候会自己调用自定义类型的构造函数（浅拷贝）
	public:
		pair<K, V> _kv;
		State _state = EMPTY;
		Node* _next = nullptr;
	};




	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		using Node = HashNode<K, V>;


		HashTable<K,V,Hash>(size_t size = 29)
			:_table(size)
			,_n(0)
		{ }

		bool insert(const pair<K, V>& kv)
		{
			if (find(kv.first))
			{
				return false;
			}
			Hash HashFunc;
			if (_n == _table.size())
			{
				//扩容逻辑

				vector<Node*> new_table(__stl_next_prime(_n + 1));
				Node* cur = nullptr;
				for (int i = 0; i < _table.size(); i++)
				{

					cur = _table[i];
					size_t hashi = HashFunc(cur->_kv.first) % new_table.size();
					while (cur)
					{
						Node* next = cur->_next;
						cur->_next = new_table[hashi];
						new_table[hashi] = cur;
						cur = next;
					}

					_table[i] = nullptr;
				}


				_table.swap(new_table);
			}


			size_t hashi = HashFunc(kv.first) % _table.size();
			Node* new_node = new Node(kv);
			new_node->_next = _table[hashi];
			_table[hashi] = new_node;

		}

		bool erase(const K& key)
		{
			Node* ret = find(key);
			if (ret)
			{
				ret->_state = DELETE;
			}
			else
			{
				return false;
			}

		}

		Node* find(const K& key)
		{
			
			Hash HashFunc;
			size_t hashi = HashFunc(key) % _table.size();

			Node* cur = _table[hashi];
			while (cur)
			{
				if (cur->_kv.first == key&&cur->_state!=DELETE)
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