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
bool displayMenu(TreeMap<string, BinaryTree<App*>>& map);
bool displayMenu(TreeMap<int, BinaryTree<App*>>& map);
bool displayMenu(TreeMap<float, BinaryTree<App*>>& map);
void printAppsInOrder(BinaryTree<App*> appTree);
void printAppsInOrder(BSTNode<App*>* appNode);

App* constructApp(string csv);

int appsFromCSV()
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
					}
					break;
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
					}
					break;
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
					}
					break;
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
					}
				break;
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

	bool run;
	do {
		run = displayMenu(map);
	} while (run);
}

bool displayMenu(TreeMap<string, BinaryTree<App*>>& map)
{
	cout << "Please enter one of the above options, or -1 to end." << endl << ">";
	string input;
	getline(cin, input);
	
	if (input != "-1")
	{
		try
		{
			BinaryTree<App*> apps = map.get(input);
			cout << "Found " << apps.count() << " item(s) with field " << input << ":" << endl;
			printAppsInOrder(apps);
		}
		catch (logic_error)
		{
			cout << "Item with this field not found." << endl;
		}
		return true;
	}
	else
	{
		cout << "Thank you for using the program!" << endl;
		return false;
	}
}

bool displayMenu(TreeMap<int, BinaryTree<App*>>& map)
{
	cout << "Please enter one of the above options, or -1 to end." << endl << ">";
	string input;
	cin >> input;
	int inputI = stoi(input);

	if (inputI != - 1)
	{
		try
		{
			BinaryTree<App*> apps = map.get(inputI);
			cout << "Found " << apps.count() << " item(s) with field " << inputI << ":" << endl;
			printAppsInOrder(apps);
		}
		catch (logic_error)
		{
			cout << "Item with this field not found." << endl;
		}
		return true;
	}
	else
	{
		cout << "Thank you for using the program!" << endl;
		return false;
	}
}

bool displayMenu(TreeMap<float, BinaryTree<App*>>& map)
{
	cout << "Please enter one of the above options, or -1 to end." << endl << ">";
	string input;
	cin >> input;
	float inputF = stof(input);

	if (inputF != -1)
	{
		try
		{
			BinaryTree<App*> apps = map.get(inputF);
			cout << "Found " << apps.count() << " item(s) with field " << inputF << ":" << endl;
			printAppsInOrder(apps);
		}
		catch (logic_error)
		{
			cout << "Item with this field not found." << endl;
		}
		return true;
	}
	else
	{
		cout << "Thank you for using the program!" << endl;
		return false;
	}
}

void printAppsInOrder(BinaryTree<App*> appTree)
{
	printAppsInOrder(appTree.root);
	cout << endl;
}

void printAppsInOrder(BSTNode<App*>* appNode)
{
	if (appNode == nullptr)
	{
		return;
	}
	App* cApp = appNode->getItem();

	printAppsInOrder(appNode->getLeft());

	cout << "<ID: " << cApp->id << " - Name: " << cApp->appName
		<< " - Developer: " << cApp->developer << " - Platform: "<< cApp->platform
		<< " - Released on " << cApp->releaseDate << " and costs $" << cApp->price << ">"
		<< endl;

	printAppsInOrder(appNode->getRight());
}