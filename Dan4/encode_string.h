#pragma once
#include <iostream>
#include <string>

enum TransformingChoice {
	CODING_CHOICE = 1,
	DECODING_CHOICE
};

std::string CodingString(std::string input_string, int number_of_characters);

std::string DecodingString(std::string input_string);

int CodingOrDecodingChoice(void);