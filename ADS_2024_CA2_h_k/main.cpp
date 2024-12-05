#include <iostream>
#include <fstream>
#include <sstream>
#include "Treemap.h"
#include "BinaryTree.h"

using namespace std;
int selectField();

struct App
{
	int id;
	string appName;
	string developer;
	string platform;
	string releaseDate;
	float price;
};

template <class K>
void display(TreeMap<K, BinaryTree<App*>>& map);
	//display all keys
	// allow the user to select 1 key
	// print list from key
	// display VAlues


template <class K>
void populate(TreeMap<K, BinaryTree<App*>>& map, int selection);

App* constructApp(string csv);

int main()
{
	int selection = selectField();

	if (selection == 1)
	{ //id
		TreeMap<int, BinaryTree<App*>> map;
		ifstream fin("MOCK_DATA.csv");
		if (fin)
		{
			string line;
			getline(fin, line); //Quickly progress past line 1


			while (!fin.eof())
			{
				getline(fin, line);
				App* newApp = constructApp(line);
				if (map.containsKey(newApp->id))
				{
					map.get(newApp->id).add(newApp);
				}
				else
				{
					BinaryTree<App*> appList;
					appList.add(newApp);
					map.put(newApp->id, appList);
				}
				
			}
		}		
		else
		{
			cout << "Error opening file." << endl;
		}
	display(map);

	}
	else if (selection == 6)
	{ //price
		TreeMap<float, BinaryTree<App*>> map;
		ifstream fin("MOCK_DATA.csv");
		if (fin)
		{
			string line;
			getline(fin, line); //Quickly progress past line 1

			while (!fin.eof())
			{
				getline(fin, line);
				App* newApp = constructApp(line);
				if (map.containsKey(newApp->price))
				{
					map.get(newApp->price).add(newApp);
				}
				else
				{
					BinaryTree<App*> appList;
					appList.add(newApp);
					map.put(newApp->price, appList);
				}

			}
		}
		else
		{
			cout << "Error opening file." << endl;
		}
		display(map);
	}
	else
	{ //string fields
		TreeMap<string, BinaryTree<App*>> map;
		ifstream fin("MOCK_DATA.csv");
		if (fin)
		{
			string line;
			getline(fin, line); //Quickly progress past line 1

			switch (selection)
			{
			case 2: //app name
			{
				while (!fin.eof())
				{
					getline(fin, line);
					App* newApp = constructApp(line);
					if (map.containsKey(newApp->appName))
					{
						map.get(newApp->appName).add(newApp);
					}
					else
					{
						BinaryTree<App*> appList;
						appList.add(newApp);
						map.put(newApp->appName, appList);
					}
					break;
				}
			}
			case 3: //developer
			{
				while (!fin.eof())
				{
					getline(fin, line);
					App* newApp = constructApp(line);
					if (map.containsKey(newApp->developer))
					{
						map.get(newApp->developer).add(newApp);
					}
					else
					{
						BinaryTree<App*> appList;
						appList.add(newApp);
						map.put(newApp->developer, appList);
					}
					break;
				}
			}
			case 4: //platform
			{
				while (!fin.eof())
				{
					getline(fin, line);
					App* newApp = constructApp(line);
					if (map.containsKey(newApp->platform))
					{
						map.get(newApp->platform).add(newApp);
					}
					else
					{
						BinaryTree<App*> appList;
						appList.add(newApp);
						map.put(newApp->platform, appList);
					}
					break;
				}
			}
			case 5: //release date
			{
				while (!fin.eof())
				{
					getline(fin, line);
					App* newApp = constructApp(line);
					if (map.containsKey(newApp->releaseDate))
					{
						map.get(newApp->releaseDate).add(newApp);
					}
					else
					{
						BinaryTree<App*> appList;
						appList.add(newApp);
						map.put(newApp->releaseDate, appList);
					}
					break;
				}
			}

			}
		}
		else
		{
			cout << "Error opening file." << endl;
		}
		display(map);
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

template <class K>
void populate(TreeMap<K, BinaryTree<App*>>& map, int selection)
{
	ifstream fin("MOCK_DATA.csv");
	if (fin)
	{
		string line;
		getline(fin, line); //Quickly progress past line 1
		
		while (fin >> line)
		{
			getline(fin, line);
			App* newApp = constructApp(line);

			switch (selection) {
				case 1: {
					if (map.containsKey(newApp->id))
					{
						map.get(newApp->id).add(newApp);
					}
					else
					{
						BinaryTree<App*> appList;
						appList.add(newApp);
						map.put(newApp->id, appList);
					}
					break;
				}
				case 2: {
					if (map.containsKey(newApp->appName))
					{
						map.get(newApp->appName).add(newApp);
					}
					else
					{
						BinaryTree<App*> appList;
						appList.add(newApp);
						map.put(newApp->appName, appList);
					}
					break;
				}
				case 3: {
					if (map.containsKey(newApp->developer))
					{
						map.get(newApp->developer).add(newApp);
					}
					else
					{
						BinaryTree<App*> appList;
						appList.add(newApp);
						map.put(newApp->developer, appList);
					}
					break;
				}
				case 4: {
					if (map.containsKey(newApp->platform))
					{
						map.get(newApp->platform).add(newApp);
					}
					else
					{
						BinaryTree<App*> appList;
						appList.add(newApp);
						map.put(newApp->platform, appList);
					}
					break;
				}
				case 5: {
					if (map.containsKey(newApp->releaseDate))
					{
						map.get(newApp->releaseDate).add(newApp);
					}
					else
					{
						BinaryTree<App*> appList;
						appList.add(newApp);
						map.put(newApp->releaseDate, appList);
					}
					break;
				}
				case 6: {
					if (map.containsKey(newApp->price))
					{
						map.get(newApp->price).add(newApp);
					}
					else
					{
						BinaryTree<App*> appList;
						appList.add(newApp);
						map.put(newApp->price, appList);
					}
					break;
				}
			}
		}
	}
	else
	{
		cout << "Error opening file." << endl;
	}
}

App* constructApp(string csv)
{ //this code's about to be really awkward but we ball
	stringstream sstr(csv);
	const char delim = ',';

	int id;
	string appName;
	string developer;
	string platform;
	string releaseDate;
	float price;

	//set id
	string temp;
	getline(sstr, temp, delim);
	id = stoi(temp);

	//set strings
	getline(sstr, appName, delim);
	getline(sstr, developer, delim);
	getline(sstr, platform, delim);
	getline(sstr, releaseDate, delim);

	//set price
	getline(sstr, temp, delim);
	price = stof(temp);

	return new App{ id, appName, developer, platform, releaseDate, price };
}

template <class K>
void display(TreeMap<K, BinaryTree<App*>>& map)
{
	cout << "Unique instances of selected field: " << endl;
	map.keySet().printInOrder();
};