#pragma once

#include <string>

using namespace std;

class Input {
public:

	virtual string Read() = 0;

	virtual bool IsFileInput(void) = 0;

	virtual ~Input() = default;

};

class KeyboardInput final : public Input {
public:

	string Read();
	
	bool IsFileInput(void);
};

class FileInput final : public Input {
public:

	string Read();

	bool IsFileInput(void);
};
