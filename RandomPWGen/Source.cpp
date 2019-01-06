#include <iostream>
#include <time.h>
#include <string>

using namespace std;

int main() {

	int infLoop = 1;

	while (infLoop == 1 || infLoop == 2) {

		srand(time(NULL));

		int size = 0;
		int asciiVal;
		char asciiChar;
		int intOrChar;
		string password;

		cout << "Enter the size of a password: " << endl;
		cin >> size;

		for (int i = 0; i < size; i++) {

			intOrChar = rand() % 3;

			switch (intOrChar) {

			case 0:
				asciiVal = rand() % 10 + 48;
				break;
			case 1:
				asciiVal = rand() % 26 + 65;
				break;
			case 2:
				asciiVal = rand() % 26 + 97;
				break;
			default:
				break;
			}

			asciiChar = asciiVal;
			if(infLoop == 2)
				cout << "int:	" << asciiVal << "	" << "char:	" << asciiChar << endl;
			password += asciiChar;
		}
		cout << endl;
		cout << "Random genereted password: " << password << endl << endl << endl;

		cout << "Do you want to generate another random password" << endl;
		cout << "Enter your choice (0->Finish, 1->Generate, 2->Generate and show all steps): " << endl;
		if( !(0 <= infLoop <= 2) ){
			cout << "Invalid value, please try again." << endl;
		}
		cin >> infLoop;

	}

	//system("pause");
}