#pragma once
#include <memory>
#include <stddef.h>
#include <stdlib.h>
#include <iostream>

class KeString
{
public:
	KeString() = default;
	KeString(const char* str);
	~KeString();

	int len();
	KeString sub(const int start, const int end);	//left equal but right not equal.
	void append(const char* str);
	int find(const char* str);
	KeString* split(const char* str);

	KeString& operator=(const KeString& str);
	bool operator==(const KeString& str);
	friend std::ostream& operator<<(std::ostream& os, const KeString& keStr);

protected:
	size_t CalcuLength(const char* str);

private:
	size_t keStrSize = 0;
	char* keString = nullptr;
};