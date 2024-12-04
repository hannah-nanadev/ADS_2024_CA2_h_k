#include <iostream>
#include <fstream>
#include "Treemap.h"

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


int main()
{
	int selection = selectField();

	return 0;
}

int selectField()
{
	bool run = true;
	int selection;
	while (run)
	{
		cout << "Select one of the following:" << endl;
		cout << "1 - " << endl;
		cout << "2 - " << endl;
		cout << "3 - " << endl;
		cout << "4 - " << endl;
		cout << "5 - " << endl;

		cin >> selection;
		if (selection <= 0 || selection >= 6)
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