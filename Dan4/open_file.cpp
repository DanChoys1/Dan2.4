#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;

enum Opening {
	FAILED,
	COMPLITE
};

ofstream OpenFileOutput(void) {
	string path = "";
	bool file_open_complit = false;
	ofstream file;
	error_code ec;

	do {
		cout << "Введите путь к файлу" << endl;
		cin.ignore();
		getline(cin, path);

		if (ifstream(path)) {

			if (!filesystem::is_regular_file(path, ec)) {
				cout << "Этот файл не может быть открыт. Попробуйте еще раз" << endl;
				continue;
			}

			cout << "Этот файл существует. Хотите его перезаписать?" << endl;
			string choice;

			do {
				cout << "1 - Да" << endl
					<< "2 - Нет" << endl
					<< "Выбор: ";

				cin >> choice;

				if (choice.compare("2") && choice.compare("1")) {
					cout << "Такого выбора нет." << endl
						<< "Хотите перезаписать файл?" << endl;
				}

			} while (choice.compare("2") && choice.compare("1"));

			if (!choice.compare("2")) {
				continue;
			}

		}

		file.open(path);

		if (!filesystem::is_regular_file(path, ec)) {
			cout << "Этот файл не может быть открыт." << endl;
			continue;
		}

		if (!file.is_open()) {
			cout << "Этот файл не может быть открыт." << endl;
			continue;
		}

		file_open_complit = true;
	} while (!file_open_complit);

	return file;
}

ifstream OpenFileInput(void) {

	cout << "Введите путь к файлу" << endl;
	string path;
	int opening_file = 0;
	error_code ec;
	ifstream file;

	do {

		do {
			getline(cin, path);

			if (!filesystem::is_regular_file(path, ec)) {
				cout << "Этот файл не может быть открыт." << endl
					<< "Введите другой путь или имя файла: ";
			}

		} while (!filesystem::is_regular_file(path, ec));

		file.open(path);

		if (file.is_open()) {

			opening_file = COMPLITE;

		} else {

			cout << "Этот файл не может быть открыт." << endl
				<< "Введите другой путь или имя файла: ";

			opening_file = FAILED;

		}

	} while (opening_file == FAILED);

	return file;
}
