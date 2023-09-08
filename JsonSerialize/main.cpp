#include "json/json.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

const std::string &fileName = "D:/SeaStar/Partiti/Patiti/Content/Cooperation/HoudiniDatatable/PointCatch.json";

int main()
{
    Json::Value root;
    std::ifstream file(fileName);
    if (file.is_open())
    {
        file >> root;
        file.close();
    }

    for (auto &&iter : root)
    {
        std::cout << "key: " << iter.toStyledString() << "value: " << iter[iter.toStyledString()] << std::endl;
    }

    return 0;
}