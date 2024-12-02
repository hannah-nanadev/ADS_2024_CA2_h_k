#include <iostream>
#include <fstream>
#include "Treemap.h"

using namespace std;

int main()
{
	//Initialise map of words/letters
	TreeMap<string, vector<string>> wordMap;

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
					wordMap.get(firstChar).push_back(word);
				}
				else
				{
					vector<string> newVector = { word };
					wordMap.put(firstChar, newVector);
				}
			}
			catch (logic_error)
			{
				cout << "An error occurred." << endl;
			}

		}

		cout << "List of letters:" << endl;
		wordMap.keySet().printInOrder();

	}
	else
	{
		cout << "Unable to open file." << endl;
	}

	return 0;

}