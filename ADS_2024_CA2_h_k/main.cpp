#include <iostream>
#include <fstream>
#include "BinaryTree.h"
#include "BSTNode.h"
#include "TreeMap.h"

using namespace std;

int main()
{
	TreeMap<int, string> tree;
	int x = 1, y = 2;
	string s1 = "One", s2 = "two";

	tree.put(x, s1);
	tree.put(y, s2);

	cout << tree.get(y) << endl;

	return 0;
}