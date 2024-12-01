#pragma once
#include <queue>
#include "Entity.h"
#include "BinaryTree.h"

template<class K, class V>
class TreeMap {
	BinaryTree < Entity <K, V >> map;
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
V& TreeMap<K, V>::operator[](K key)
{
	return this->get(key);
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

template<class K, class V>
bool TreeMap<K, V>::removeKey(K key)
{
	Entity<K, V> e;
	e.key = key;
	return map.remove(e);
}

template<class K, class V>
bool TreeMap<K, V>::containsKey(K key)
{
	try
	{
		this->get(key);
		return true;
	}
	catch (logic_error)
	{
		return false;
	}
}

template<class K, class V>
BinaryTree<K> TreeMap<K, V>::keySet()
{
	BinaryTree<K> keys;
	queue<BSTNode<K>*> nodeQue;
	nodeQue.push(map.root);

	while(!nodeQue.empty)
	{
		if (nodeQue.front()->left!=nullptr)
		{
			nodeQue.push(nodeQue.front()->right);
		}
		if (nodeQue.front()->right!=nullptr)
		{
			nodeQue.push(nodeQue.front()->right);
		}
		keys.add(nodeQue.front().key);
		nodeQue.pop();
	}

	return keys;

}