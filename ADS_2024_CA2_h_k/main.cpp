#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Please select one of the following: " << endl
		<< "1 - Words from txt file" << endl
		<< "2 - Apps from csv file" << endl
		<< "3 - Exit" << endl
		<< ">";

	bool run;
	do {
		string input;
		cin >> input;
		
		try
		{
			int inputI = stoi(input);
		
			switch (inputI)
			{
				case 1:
				{
					cout << "Opening words/letters from txt app:" << endl;
					run = false;
					break;
				}
				case 2:
				{
					cout << "Opening apps from csv app:" << endl;
					run = false;
					break;
				}
				case 3:
				{
					cout << "Thank you!" << endl;
					run = false;
					break;
				}
				default:
				{
					cout << "Invalid input. Please try again." << endl << ">";
					run = true;
					break;
				}
			}
		}
		catch (...)
		{
			cout << "Invalid input. Please try again." << endl << ">";
			run = true;
		}

	} while (run);

	return 0;
}

