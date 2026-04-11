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
class HashData
{
	

public:
	pair<K, V> _data;
	State _state = EMPTY;
};


template<class K, class V>
class HashTable
{
public:
	HashTable(int size = 11)
		:_table(size)
		, _n(0)
	{}

	bool insert(const pair<K,V>& kv)
	{
		if (_n * 10 / _table.size() > 7)
		{
			HashTable<K, V> new_hash(_table.size()*2);

			for (auto e : _table)
			{
				new_hash.insert(e._data);
			}

			_table.swap(new_hash._table);
			_n = new_hash._n;
		}

		int hash0 = kv.first % _table.size();
		int i = 1;
		int hashi = hash0;
		while (_table[hashi]._state == EXIST)
		{
			//当该位置是有数据的时候是需要移动的
			hashi = (hashi + i) % _table.size();
			i++;
		}
		
		_table[hashi]._data = kv;
		_table[hashi]._state = EXIST;
		_n++;
		return true;
	}


	//整体就是先取模，然后++
	//这里不是vector 的指针是因为vector实际上是顺序表，不是数组
	HashData<K, V>* find(const K& key)
	{
		int hash0 = key % _table.size();
		if (_table[hash0]._state == EXIST && _table[hash0]._data.first == key)
		{
			return &_table[hash0];
		}
		int i = 1;
		int hashi = hash0;
		while (_table[hashi]._state != EMPTY)
		{
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
		HashData<K, V>* kv = find(key);

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
	vector <HashData<K,V>> _table;
	size_t _n;
};