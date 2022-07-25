#include "KeString.h"

KeString::KeString(const char* str)
{
	if (str)
	{
		keStrSize = 0;
		keStrSize = CalcuLength(str);

		keString = new char[keStrSize];
		for (size_t i = 0; i < keStrSize; i++)
		{
			keString[i] = str[i];
		}
	}
}

KeString::~KeString()
{
	delete keString;
}

int KeString::len()
{
	return keStrSize;
}

KeString KeString::sub(const int start, const int end)
{
	if (end <= start || end > (int)keStrSize || start < 0)
	{
		return nullptr;
	}
	else
	{
		char* str = new char[end - start + 1];
		for (int i = start; i < end; i++)
		{
			str[i - start] = keString[i];
		}
		str[end - start] = '\0';

		return KeString(str);
	}
}

void KeString::append(const char* str)
{
	if (str)
	{
		if (keStrSize != 0)
		{
			size_t oldLen = keStrSize;
			keStrSize += CalcuLength(str) - 1;
			keString = (char*)realloc(keString, keStrSize * sizeof(char));
			for (size_t i = oldLen - 1; i < keStrSize - 1; i++)
			{
				keString[i] = str[i - oldLen + 1];
			}
			keString[keStrSize - 1] = '\0';
		}
		else
		{
			*this = str;
		}
	}
}

int KeString::find(const char* str)
{
	if (str)
	{
		size_t subStrLen = CalcuLength(str) - 1;
		for (size_t i = 0; i < keStrSize - subStrLen - 1; i++)	//Last '\0' needn't find.
		{
			auto tempKeStr = sub(i, i + subStrLen);
			if (tempKeStr == str)
			{
				return i;
			}
		}
	}

	return -1;
}

KeString* KeString::split(const char* str)
{
	int index, count = 0;
	int splitStrLen = CalcuLength(str) - 1;
	int* indexMarks = new int[keStrSize];
	KeString tempCopyString = KeString(keString);
	
	while ((index = tempCopyString.find(str)) != -1)
	{
		indexMarks[count] = index;
		count++;
		tempCopyString = sub(index + 1, CalcuLength(tempCopyString.keString));
	}

	if (count != 0)
	{
		KeString* subStrings = new KeString[count + 1];
		int currentIndex = 0;
		for (int i = 0; i < count; i++)
		{
			subStrings[i] = sub(currentIndex, indexMarks[i]);
			currentIndex += indexMarks[i] + splitStrLen;
		}
		subStrings[count] = sub(currentIndex, keStrSize);

		delete[] indexMarks;
		return subStrings;
	}
	else
	{
		KeString* subStrings = new KeString[1];
		subStrings[0] = *this;
		delete[] indexMarks;
		return subStrings;
	}
}

KeString& KeString::operator=(const KeString& str)
{
	if (this != &str)
	{
		keStrSize = str.keStrSize;
		
		keString = (char*)realloc(keString, keStrSize * sizeof(char));
		for (size_t i = 0; i < keStrSize; i++)
		{
			keString[i] = str.keString[i];
		}
	}

	return *this;
}

size_t KeString::CalcuLength(const char* str)
{
	size_t count = 0;
	if (str)
	{
		while (str[count++] != '\0')
			;
	}

	return count;
}

bool KeString::operator==(const KeString& str)
{
	if (&str == this)
	{
		return true;
	}
	else if	(keStrSize != str.keStrSize)
	{
		return false;
	}
	else
	{
		size_t iter = 0;
		while (iter < keStrSize)
		{
			if (keString[iter] != str.keString[iter])
			{
				break;
			}
			iter++;
		}
		return iter >= keStrSize ? true : false;
	}
}

std::ostream& operator<<(std::ostream& os, const KeString& keStr)
{
	os << keStr.keString;
	return os;
}