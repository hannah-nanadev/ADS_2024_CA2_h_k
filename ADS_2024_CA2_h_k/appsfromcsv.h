#pragma once
#include "TreeMap.h"

struct App;
template <class K>
void display(TreeMap<K, BinaryTree<App*>>& map);
bool displayMenu(TreeMap<string, BinaryTree<App*>>& map);
bool displayMenu(TreeMap<int, BinaryTree<App*>>& map);
bool displayMenu(TreeMap<float, BinaryTree<App*>>& map);
void printAppsInOrder(BinaryTree<App*> appTree);
void printAppsInOrder(BSTNode<App*>* appNode);
int appsFromCSV();
