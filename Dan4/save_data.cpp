#include <iostream>
#include <fstream>
#include <string>
#include "open_file.h"

using namespace std;

void SaveInputString(string input_string) {
	cout << endl << "������ ��������� �������� ����� � ����?" << endl;

	string choice = "";
	
	do {
		cout << "1 - ��" << endl
			<< "2 - ���" << endl
			<< "�����: ";

		cin >> choice;

		if (choice.compare("2") && choice.compare("1")) {
			cout << "������ ������ ���." << endl
				<< "������ ��������� �������� ����� � ����?" << endl;
		}

	} while (choice.compare("2") && choice.compare("1"));

	if (choice.compare("2")) {
		ofstream file;
		file = OpenFileOutput();

		file << input_string << endl;

		file.close();
	}

};

void SaveChangeString(string transforming_string) {
	cout << endl << "������ ��������� � ���� ��������������� ������?" << endl;
	string choice = "";

	do {
		cout << "1 - ��" << endl
			<< "2 - ���" << endl
			<< "�����: ";

		cin >> choice;

		if (choice.compare("2") && choice.compare("1")) {
			cout << "������ ������ ���." << endl
				<< "������ ��������� � ���� ��������������� ������?" << endl;
		}

	} while (choice.compare("2") && choice.compare("1"));

	if (choice.compare("2")) {
		ofstream file;
		file = OpenFileOutput();

		file << transforming_string << endl;

		file.close();
	}

}