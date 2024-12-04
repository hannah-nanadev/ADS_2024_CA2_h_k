#include <iostream>
#include <fstream>
#include "Treemap.h"
#include "BinaryTree.h"

using namespace std;
int selectField();

template <class K, class V>
void display(TreeMap<K, V>& map)
{
	//display all keys
	// allow the user to select 1 key
	// print list from key
	// display VAlues
}

struct App
{
	int id;
	string appName;
	string developer;
	string platform;
	string releaseDate;
	float price;
};

int main()
{
	int selection = selectField();

	if (selection == 1)
	{
		TreeMap<int, BinaryTree<App*>> map;
	}
	else if (selection == 6)
	{
		TreeMap<float, BinaryTree<App*>> map;
	}
	else
	{
		TreeMap<string, BinaryTree<App*>> map;
	}

	return 0;
}

int selectField()
{
	bool run = true;
	int selection;
	while (run)
	{
		cout << "Select one of the following:" << endl;
		cout << "1 - ID" << endl;
		cout << "2 - App Name" << endl;
		cout << "3 - Developer" << endl;
		cout << "4 - Platform" << endl;
		cout << "5 - Release Date" << endl;
		cout << "6 - Price" << endl;

		cin >> selection;
		if (selection <= 0 || selection >= 7)
		{
			cout << "Invalid input. Please try again." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			run = false;
		}
	}

	return selection;
	
}