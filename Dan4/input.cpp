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

bool EnglishSymbols (string line) {

	for (int i = 0; i < line.length(); i++) {
		
		if ((static_cast<int>(line[i]) < 32) || (static_cast<int>(line[i]) > 127)) {
			return false;
		}

	}

	return true;
 }

string KeyboardInput::Read() {
	cout << "Введите предложение (чтобы остановить ввод введите 'Q')" << endl;
	string input_string;
	string line = "";
	int i = 1;

	do {
		line = "";
		cout << i++ << ")";
		getline(cin, line);
		
		if (!EnglishSymbols(line)) {
			cout << endl << "Символы, используемые в строке, не поддерживаются" << endl
				<< "Введите другую строку:" << endl;

			i--;
			continue;
		}

		if (line != "Q") {
			input_string = input_string + line + '\n';
		}

	} while (line != "Q");

	return input_string;
}

bool KeyboardInput::IsFileInput(void) {
	return false;
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
			input_string += line + "\n";
		}

		input_string.erase(input_string.length() - 1, 1);

		if (!input_string.length()) {
			cout << "Файл ничего не содержит. Попробуйте еще раз." << endl;
			continue;
		}

		if (!EnglishSymbols(line)) {
			cout << endl << "Символы, используемые в файле, не поддерживаются" << endl;

			continue;
		}

		correctness_string = COMPLITE;

		cout << endl << "Введённое предложение:" << endl << input_string;

		file.close();
	} while (correctness_string == FAILED);

	return input_string;
}

bool FileInput::IsFileInput(void) {
	return true;
}

unique_ptr<Input> ChoiceInputType(void) {
	int choice = 0;

	do {
		StringInputMenu();
		choice = GetInt();

		if (choice == CHOICE_KEYBOARD) {

			return unique_ptr<KeyboardInput>(new KeyboardInput);

		} else if (choice == CHOICE_FILE) {

			return unique_ptr<FileInput>(new FileInput);

		} else {

			cout << "Такого выбора нет" << endl;

		}

	} while ((choice != CHOICE_KEYBOARD) && (choice != CHOICE_FILE));

	string inv_arg = "Went out of the loop";
	throw inv_arg;
}
