#pragma once

#include <string>

using namespace std;

class Input {
public:

	virtual string Read() = 0;

	virtual ~Input() = default;

};

class KeyboardInput final : public Input {
public:

	string Read();

};

class FileInput final : public Input {
public:

	string Read();

};
