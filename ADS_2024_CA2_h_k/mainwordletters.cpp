#include <iostream>
#include <fstream>
#include "Treemap.h"

using namespace std;
bool menu(TreeMap<string, BinaryTree<string>> map);

int notmain()
{
	//Initialise map of words/letters
	TreeMap<string, BinaryTree<string>> wordMap;

	//Read from file
	ifstream fin("p11s.txt");//C:\\Users\\Hannah\\source\\repos\\ADS_2024_CA2_h_k\\ADS_2024_CA2_h_k
	if(fin)
	{
		cout << "File loaded successfully!" << endl;
		const char delim = ' '; string word; string firstChar;
		while (fin >> word)
		{
			firstChar = word.at(0);

			try {
				if (wordMap.containsKey(firstChar))
				{
					wordMap.get(firstChar).add(word);
				}
				else
				{
					BinaryTree<string> newTree;
					newTree.add(word);
;					wordMap.put(firstChar, newTree);
				}
			}
			catch (logic_error)
			{
				cout << "An error occurred." << endl;
			}

		}

		cout << "List of letters:" << endl;
		wordMap.keySet().printInOrder();

		bool run;
		do {
			run = menu(wordMap);
		} while (run);

	}
	else
	{
		cout << "Unable to open file." << endl;
	}

	return 0;

}

bool menu(TreeMap<string, BinaryTree<string>> map)
{
	cout << "Please input letter from list above to see all associated words, or 'end' to exit." << endl << ">";
	string input;
	cin >> input;

	if (input != "end")
	{
		try
		{
			map.get(input).printInOrder();
		}
		catch (logic_error)
		{
			cout << "Letter " << input << " not found." << endl;
		}
		return true;
	}
	else
	{
		cout << "Thank you for using the program!" << endl;
		return false;
	}
	
}