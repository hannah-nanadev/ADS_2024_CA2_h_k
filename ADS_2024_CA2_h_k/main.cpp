#include <iostream>
#include <fstream>
#include "Treemap.h"

using namespace std;
int selectField();

template<class K, class V>
TreeMap<K, vector<V>> parseMap(int field);

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

		cin >> selection; //TODO: this explodes if met with a string. Will fix later

		switch (selection) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			run = false; break;
		default:
			cout << "Invalid input. Please try again." << endl;
		}
	}

	return selection;
	
}

template<class K, class V>
TreeMap<K, vector<V>> parseMap(int field)
{

}