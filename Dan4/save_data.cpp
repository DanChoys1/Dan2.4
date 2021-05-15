#include <iostream>
#include <fstream>
#include <string>
#include "open_file.h"

using namespace std;

void SaveInputString(string input_string) {
	cout << endl << "Хотите сохранить введённый текст в файл?" << endl;

	string choice = "";
	
	do {
		cout << "1 - Да" << endl
			<< "2 - Нет" << endl
			<< "Выбор: ";

		cin >> choice;

		if (choice.compare("2") && choice.compare("1")) {
			cout << "Такого выбора нет." << endl
				<< "Хотите сохранить введённый текст в файл?" << endl;
		}

	} while (choice.compare("2") && choice.compare("1"));

	if (choice.compare("2")) {
		ofstream file;
		file = OpenFileOutput();

		input_string.erase(input_string.length() - 1, 1);
		file << input_string << endl;

		file.close();
	}

};

void SaveChangeString(string transforming_string) {
	cout << endl << "Хотите сохранить в файл преобразованную строку?" << endl;
	string choice = "";

	do {
		cout << "1 - Да" << endl
			<< "2 - Нет" << endl
			<< "Выбор: ";

		cin >> choice;

		if (choice.compare("2") && choice.compare("1")) {
			cout << "Такого выбора нет." << endl
				<< "Хотите сохранить в файл преобразованную строку?" << endl;
		}

	} while (choice.compare("2") && choice.compare("1"));

	if (choice.compare("2")) {
		ofstream file;
		file = OpenFileOutput();

		transforming_string.erase(transforming_string.length() - 1, 1);

		file << transforming_string << endl;

		file.close();
	}

}