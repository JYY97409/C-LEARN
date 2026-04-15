#pragma once
#include<iostream>
#include<vector>

using namespace std;


template <class K, class Hash = HashFunc<K>>
class unordered_set
{
public:
	struct KeyofSet
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
	typedef typename  hash_bucket::HashTable<K, const K, KeyofSet, Hash>::iterator iterator;
	typedef typename  hash_bucket::HashTable<K, const K, KeyofSet, Hash>::const_iterator const_iterator;
	typedef hash_bucket::HashTable<K, const K, KeyofSet, Hash> Hashtable;
	typedef unordered_set<K, Hash> Self;
	bool insert(const K kv)
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

private:
	hash_bucket::HashTable<K, const K, KeyofSet, Hash> _ht;
};