#pragma once
#include<iostream>
#include<vector>
#include"HashTable.h"
using namespace std;


namespace jyy
{

	template <class K, class V, class Hash = HashFunc<K>>
	class unordered_map
	{
	public:

		struct KeyofMap
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};
		typedef typename  hash_bucket::HashTable<K, pair<const K, V>, KeyofMap, Hash>::iterator iterator;
		typedef typename  hash_bucket::HashTable<K, pair<const K, V>, KeyofMap, Hash>::const_iterator const_iterator;
		typedef hash_bucket::HashTable<K, pair<const K, V>, KeyofMap, Hash> Hashtable;
		typedef unordered_map<K, V, Hash> Self;


		bool insert(const pair<K, V> kv)
		{
			return _ht.insert(kv).second;
		}


		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}

		const_iterator begin()const
		{
			return _ht.begin();
		}
		iterator end()const
		{
			return _ht.end();
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.insert(key);


			return ret.first->second;
		}



	private:
		hash_bucket::HashTable<K, pair<const K, V>, KeyofMap, Hash> _ht;
	};
}