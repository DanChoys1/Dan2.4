#include <iostream>
#include <string>
#include "input.h"
#include "save_data.h"
#include "encode_string.h"
using namespace std;

unique_ptr<Input> ChoiceInputType(bool *user_selected_file_input);
int GetInt(void);

void StringInterface(void) {
	bool user_selected_file_input = false;

	unique_ptr<Input> inp = ChoiceInputType(&user_selected_file_input);

	string input_string = inp->Read();

	string transforming_string = "";

	if (CodingOrDecodingChoice() == CODING_CHOICE) {
		cout << "При каком минимальном кол-ве повторяющихся символов вы хотите заменять их на {буква, кол-во}?" << endl;
		int number_of_characters = 0;

		do {
			cout << "Кол-во: ";
			number_of_characters = GetInt();

			if (number_of_characters <= 0) {
				cout << "Количество должно быть больше 0. Попробуйте другое число." << endl;
			}

		} while (number_of_characters <= 0);

		transforming_string = CodingString(input_string, number_of_characters);

	} else {

		transforming_string = DecodingString(input_string);

	}
	cout << "Преобразованное предложение" << endl;
	cout << transforming_string;

	if (user_selected_file_input != true) {
		SaveInputString(input_string);
	}

	SaveChangeString(transforming_string);
}
