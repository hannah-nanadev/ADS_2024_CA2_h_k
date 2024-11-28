#pragma once
#include "Entity.h"
template<class K, class V>
class TreeMap {
	BinaryTree<Entity<K, V>> map;
public:
	void clear();
	bool containsKey(K key);
	V& get(K key);
	BinaryTree<K> keySet();
	void put(K& key, V& value);
	int size();
	bool removeKey(K key);
	V& operator[](K key);
};

template<class K, class V>
void TreeMap<K, V>::put(K& key, V& value)
{
	Entity<K, V> e;
	e.key = key;
	e.value = value;
	map.add(e);
}
template<class K, class V>
V& TreeMap<K, V>::get(K key)
{
	Entity<K, V> e;
	e.key = key;
	return map.get(e).value;
}

template<class K, class V>
void TreeMap<K, V>::clear()
{
	map.clear();
}

template<class K, class V>
int TreeMap<K, V>::size()
{
	return map.count();
}