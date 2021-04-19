#include <iostream>
#include <string>
#include <cctype>

using namespace std;

enum TransformingChoice {
	CODING_CHOICE = 1,
	DECODING_CHOICE
};

int GetInt(void);
void CodingOrDecodingMenu(void);

string CodingString(string input_string, int number_of_characters) {
	int last_change_position = 0;

	for (int i = 0; i < (input_string.length() - 1); i++) {
		int first_repeated_character = i;

		if (input_string[i] == '\n') {
			continue;
		}

		while ( (i != (input_string.length() - 1)) && (input_string[i] == input_string[i + 1]) ) {
			i++;
		}

		if (((i + 1) - first_repeated_character) >= number_of_characters) {
			string new_string = "{";
			new_string += input_string[first_repeated_character];
			new_string += ",";
			new_string += to_string((i + 1) - first_repeated_character);
			new_string += "}";

			input_string.replace(first_repeated_character, ((i + 1) - first_repeated_character), new_string);
			i = (first_repeated_character - 1) + new_string.length();
			last_change_position = i;
		}

	}

	if ( (number_of_characters == 1) && (last_change_position == (input_string.length() - 1)) ) {
		string new_string = "{";
		new_string += input_string[last_change_position + 1];
		new_string += ",1}";
		input_string.replace(last_change_position + 1, new_string.length() - 1, new_string);
	}

	return input_string;
}

string DecodingString(string input_string) {
	
	for (int i = 0; i < (input_string.length() - 3); i++) {

		if ((input_string[i] == '{') && (input_string[i + 2] == ',') && (isdigit(input_string[i + 3]))) {
			int safe_index = i;
			int number_of_characters = 0;
			char letter = input_string[i + 1];

			while (isdigit(input_string[i + 3])) {
				number_of_characters = number_of_characters * 10 + static_cast<int>(input_string[i + 3]) - 48;
				i++;
			}

			if (input_string[i + 3] == '}') {
				input_string.replace(safe_index, ( (i + 3) - safe_index + 1), number_of_characters, letter);
				i--;
			}

		}

	}

	return input_string;
};

int CodingOrDecodingChoice() {
	int choice = 0;

	do {
		CodingOrDecodingMenu();
		choice = GetInt();

		switch (choice) {
		case CODING_CHOICE:

			return CODING_CHOICE;

		case DECODING_CHOICE:

			return DECODING_CHOICE;

		default:

			cout << "Такого выбора нет" << endl;

		}

	} while ( (choice != CODING_CHOICE) && (choice != DECODING_CHOICE) );

	exit(0);
}