#include <iostream>
#include <string>
#include "KeString.h"

int main()
{
	auto str1 = KeString("test1");
	auto str2 = KeString("test2, test3");
	str1 = "test3";
 	int len = str1.len();
 	KeString sub1 = str1.sub(1, 2);
 	str1.append("append");
 	bool equal = str1 == "test3append";
 	int index = str1.find("es");
 	KeString* ret = str2.split(",");

	std::cout << sub1 << std::endl;
	std::cout << str1 << std::endl;
	std::cout << equal << std::endl;
	std::cout << index << std::endl;
	std::cout << ret[0] << ret[1] << std::endl;
}
