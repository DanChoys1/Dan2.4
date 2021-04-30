#include <iostream>
#include <string>
#include "main_menu.h"

using namespace std;

enum ChoiceTypeInput {
	CHOICE_STRING = 1,
	CHOICE_TESTING
};

int GetInt(void);
void Test(void);
void StringInterface(void);

int main() {
	setlocale(LC_ALL, "Russian");

	Greeting();

	int choice = 0;
	string choice_repeat = "";
	
	do {

		do {
			StringOrTestingMenu();
			choice = GetInt();

			switch (choice) {
			case CHOICE_STRING:

				StringInterface();

				break;
			case CHOICE_TESTING:

				Test();

				break;
			default:
				cout << "Такого выбора нет. Попробуйте еще раз" << endl;
			}

		} while ( (choice != CHOICE_STRING) && (choice != CHOICE_TESTING) );

		do {
			EndProgramMenu();

			cin >> choice_repeat;

			if (choice_repeat.compare("2") && choice_repeat.compare("1")) {
				cout << "Такого выбора нет" << endl;
			}

		} while (choice_repeat.compare("2") && choice_repeat.compare("1"));
	} while (choice_repeat.compare("2"));

	return 0;
}
