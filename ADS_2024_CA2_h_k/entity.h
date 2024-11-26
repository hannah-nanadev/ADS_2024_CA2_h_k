#pragma once
template<class K, class V>
struct Entity {
	K key;
	V value;

	Entity()
	{

	}
	Entity(K key, V value)
	{
		this->key = key;
		this->value = value;
	}

	bool operator<(Entity<K, V>& e)
	{
		return key < e.key;
	}
	bool operator>(Entity<K, V>& e)
	{
		return key > e.key;
	}
	bool operator==(Entity<K, V>& e)
	{
		return key == e.key;
	}
};