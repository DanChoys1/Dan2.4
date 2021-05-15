#include <iostream>
#include <string>
#include "input.h"
#include "save_data.h"
#include "encode_string.h"

using namespace std;

unique_ptr<Input> ChoiceInputType(void);
int GetInt(void);

void StringInterface(void) {
	unique_ptr<Input> inp = ChoiceInputType();
	string input_string = inp->Read();

	string transforming_string = "";

	if (CodingOrDecodingChoice() == CODING_CHOICE) {
		cout << "��� ����� ����������� ���-�� ������������� �������� �� ������ �������� �� �� {�����,���-��}?" << endl;
		int number_of_characters = 0;

		do {
			cout << "���-��: ";
			number_of_characters = GetInt();

			if (number_of_characters <= 0) {
				cout << "���������� ������ ���� ������ 0. ���������� ������ �����." << endl;
			}

		} while (number_of_characters <= 0);

		transforming_string = CodingString(input_string, number_of_characters);

	} else {

		transforming_string = DecodingString(input_string);

	}
	cout << "��������������� �����������" << endl;
	cout << transforming_string;

	if (!inp->IsFileInput()) {
		SaveInputString(input_string);
	}

	SaveChangeString(transforming_string);
}
