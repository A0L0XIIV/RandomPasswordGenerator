#include <iostream>
#include <time.h>
#include <string>

using namespace std;

int main() {

	int infLoop = 1;

	while (infLoop == 1 || infLoop == 2) {

		srand(time(NULL));

		char input = '\0';
		bool hasPunctuationChar = false;
		int size = 0;
		int asciiVal;
		char asciiChar;
		int intOrChar;
		string password;

		//Punctuation character question
		cout << "Do you want punctuation characters like (,!,# or just letters and numbers? (Y/N)" << endl;
		cin >> input;
		if (input == 'Y' || input == 'y') {
			hasPunctuationChar = true;
		}
		else {
			hasPunctuationChar = false;
		}

		//Size of the password
		cout << "Enter the size of a password: " << endl;
		cin >> size;

		//Generate random PW
		for (int i = 0; i < size; i++) {

			//Number or letter
			if (hasPunctuationChar) {
				intOrChar = rand() % 4;
			}
			else {
				intOrChar = rand() % 3;
			}

			switch (intOrChar) {
			//Numbers
			case 0:
				asciiVal = rand() % 10 + 48;
				break;
			//Upper case letters
			case 1:
				asciiVal = rand() % 26 + 65;
				break;
			//Lower case letters
			case 2:
				asciiVal = rand() % 26 + 97;
				break;
			//Punctuation characters
			case 3:
				asciiVal = rand() % 15 + 33;
			default:
				break;
			}

			//int to char
			asciiChar = asciiVal;
			//Detailed operation print
			if(infLoop == 2)
				cout << "int:	" << asciiVal << "	" << "char:	" << asciiChar << endl;
			//Add new character to PW
			password += asciiChar;
		}
		cout << endl;
		//Result print
		cout << "Random genereted password: " << password << endl << endl << endl;

		//Program loop
		cout << "Do you want to generate another random password" << endl;
		cout << "Enter your choice (0->Finish, 1->Generate, 2->Generate and show all steps): " << endl;
		if( !(0 <= infLoop <= 2) ){
			cout << "Invalid value, please try again." << endl;
		}
		cin >> infLoop;

	}
	return 0;
}