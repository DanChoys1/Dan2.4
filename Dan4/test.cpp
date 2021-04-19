#include <iostream>
#include <string>
#include "encode_string.h"
using namespace std;

const int ALL_TEST_PASSED = 6;

enum IncorrectSorting {
	ARR_BUBBLE_SORT,
	ARR_SELECTION_SORT,
	ARR_INSERTION_SORT,
	ARR_SHELL_SORT
};

bool TestingDecoding(string input_string, string expected_string, int value_test_passed) {
	string output_string = DecodingString(input_string);
	if (output_string != expected_string) {
		cout << endl << "Тест" << value_test_passed + 1 << " не пройден. Проверялась декодировка предложения" << endl;

		if (output_string.length() != expected_string.length()) {
			cout << "Длина преобразованной строки не равна длине ожидаемой преобразованной строки." << endl;
		} else {
			cout << "Ошибка в ";
			for (int i = 0; i < output_string.length(); i++) {
				if (output_string[i] != expected_string[i]) {
					cout << i + 1 << " ";
				}
			}

			cout << "элементе(ах) преобразованной строки." << endl;
		}
		
		cout << "Введённая строка: " << input_string << endl;
		cout << "Ожидаемая преобразованная строка: " << expected_string << endl;
		cout << "Преобразованная строка: " << output_string << endl;

		return false;
	}

	return true;
}

bool TestingCoding(string input_string, string expected_string, int number_of_characters, int value_test_passed) {
	string output_string = CodingString(input_string, number_of_characters);
	if (output_string != expected_string) {
		cout << endl << "Тест" << value_test_passed + 1 << " не пройден. Проверялась кодировка предложения" << endl;

		if (output_string.length() != expected_string.length()) {
			cout << "Длина преобразованной строки не равна длине ожидаемой преобразованной строки." << endl;
		}
		else {
			cout << "Ошибка в ";
			for (int i = 0; i < output_string.length(); i++) {
				if (output_string[i] != expected_string[i]) {
					cout << i + 1 << " ";
				}
			}

			cout << "элементе(ах) преобразованной строки." << endl;
		}

		cout << "Введённая строка: " << input_string << endl;
		cout << "Ожидаемая преобразованная строка: " << expected_string << endl;
		cout << "Преобразованная строка: " << output_string << endl;

		return false;
	}

	return true;
}

void Test(void) {
	int value_test_passed = 0;
	string input_string = "Hello, my best friendd! )))";
	int number_of_characters = 2;
	string expected_string = "He{l,2}o, my best frien{d,2}! {),3}";

	if (TestingCoding(input_string, expected_string, number_of_characters, value_test_passed) == true) {
		value_test_passed++;
	}

	input_string = "He{l,2}o, my best frien{d,2}! {),3}";
	number_of_characters = NULL;
	expected_string = "Hello, my best friendd! )))";

	if (TestingDecoding(input_string, expected_string, value_test_passed) == true) {
		value_test_passed++;
	}

	input_string = "I lovvvveeeee programming!!!!!";
	number_of_characters = 4;
	expected_string = "I lo{v,4}{e,5} programming{!,5}";

	if (TestingCoding(input_string, expected_string, number_of_characters, value_test_passed) == true) {
		value_test_passed++;
	}

	input_string = "I lo{v,4}{e,5} programming{!,5}";
	number_of_characters = NULL;
	expected_string = "I lovvvveeeee programming!!!!!";

	if (TestingDecoding(input_string, expected_string, value_test_passed) == true) {
		value_test_passed++;
	}

	input_string = "sorting laboratory is veeeeeeeeeeeeeeeeeery bad";
	number_of_characters = 1;
	expected_string = "{s,1}{o,1}{r,1}{t,1}{i,1}{n,1}{g,1}{ ,1}{l,1}{a,1}{b,1}{o,1}{r,1}{a,1}{t,1}{o,1}{r,1}{y,1}{ ,1}{i,1}{s,1}{ ,1}{v,1}{e,18}{r,1}{y,1}{ ,1}{b,1}{a,1}{d,1}";

	if (TestingCoding(input_string, expected_string, number_of_characters, value_test_passed) == true) {
		value_test_passed++;
	}

	input_string = "{s,1}{o,1}{r,1}{t,1}{i,1}{n,1}{g,1}{ ,1}{l,1}{a,1}{b,1}{o,1}{r,1}{a,1}{t,1}{o,1}{r,1}{y,1}{ ,1}{i,1}{s,1}{ ,1}{v,1}{e,18}{r,1}{y,1}{ ,1}{b,1}{a,1}{d,1}";
	number_of_characters = NULL;
	expected_string = "sorting laboratory is veeeeeeeeeeeeeeeeeery bad";

	if (TestingDecoding(input_string, expected_string, value_test_passed) == true) {
		value_test_passed++;
	}

	if (value_test_passed == ALL_TEST_PASSED) {
		cout << endl << "All test passed" << endl;
	}

}