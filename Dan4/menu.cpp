#include <iostream>

using namespace std;

void StringInputMenu(void) {
	cout << endl << "Как вы хотите ввести строку?" << endl
		<< "1)Консольный ввод" << endl
		<< "2)Ввод из файла" << endl
		<< "Ваш выбор: ";
}

void EndProgramMenu(void) {
	cout << endl << "Хотите повторить программу?" << endl
		<< "1 - Да" << endl
		<< "2 - Нет" << endl
		<< "Ваш выбор: ";
}

void StringOrTestingMenu(void) {
	cout << endl << "Что вы хотите?" << endl
		<< "1)Преобразование строки" << endl
		<< "2)Протестировать программу" << endl
		<< "Ваш выбор: ";
}

void CodingOrDecodingMenu(void) {
	cout << endl << "Что вы хотите?" << endl
		<< "1)Закодировать строку" << endl
		<< "2)Декодировать строку" << endl
		<< "Ваш выбор: ";
}