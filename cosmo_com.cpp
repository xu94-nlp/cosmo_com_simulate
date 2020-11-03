#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include "nlohmann/json.hpp"

typedef nlohmann::json config;

int main(int argc, char** argv)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int k = 1; k < 15; k++)
    {
        SetConsoleTextAttribute(hConsole, k);
        std::cout << k << "The color testing..." << std::endl;
    }
    // Default configuration file operator.
    // 默认配置文件算子.
    config config_operator;
}