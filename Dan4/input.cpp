#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "open_file.h"
#include "input.h"

using namespace std;

enum ChoiceTypeInput {
	CHOICE_KEYBOARD = 1,
	CHOICE_FILE
};

enum Opening {
	FAILED,
	COMPLITE
};

int GetInt(void);
void StringInputMenu(void);

string KeyboardInput::Read() {
	cout << "Введите предложение (чтобы остановить ввод введите 'Q'): ";
	string input_string;
	string line = "";

	do {
		line = "";
		getline(cin, line);
		
		if (line != "Q") {
			input_string = input_string + line + '\n';
		}

	} while (line != "Q");

	return input_string;
}

string FileInput::Read() {
	ifstream file;
	string input_string = "";
	bool correctness_string = 0;

	do {
		cout << endl << "Ввод предложения." << endl;
		file = OpenFileInput();

		string line;

		while (!file.eof()) {
			getline(file, line);
			input_string += line;
		}

		if (!input_string.length()) {
			cout << "Файл ничего не содержит. Попробуйте еще раз." << endl;
			continue;
		}

		correctness_string = COMPLITE;

		cout << endl << "Введённое предложение:" << endl
			<< input_string << endl;

		file.close();
	} while (correctness_string == FAILED);

	return input_string;
}

unique_ptr<Input> ChoiceInputType(bool *user_selected_file_input) {
	int choice = 0;

	do {
		StringInputMenu();
		choice = GetInt();

		if (choice == CHOICE_KEYBOARD) {

			return unique_ptr<KeyboardInput>(new KeyboardInput);

		} else if (choice == CHOICE_FILE) {

			*user_selected_file_input = true;
			return unique_ptr<FileInput>(new FileInput);

		} else {

			cout << "Такого выбора нет" << endl;

		}

	} while ((choice != CHOICE_KEYBOARD) && (choice != CHOICE_FILE));

	exit(0);
}
