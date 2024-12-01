#include <iostream>
#include <fstream>
#include "Treemap.h"

using namespace std;

int main()
{
	//Initialise map of words/letters
	TreeMap<string, vector<string>> wordMap;

	//Read from file
	ifstream fin("C:\\Users\\Hannah\\source\\repos\\ADS_2024_CA2_h_k\\ADS_2024_CA2_h_k\\p11s.txt");
	if(fin)
	{
		cout << "File loaded successfully!" << endl;

	}
	else
	{
		cout << "Unable to open file." << endl;
	}

	return 0;

}