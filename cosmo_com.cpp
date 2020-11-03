#include <iostream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>
#include <windows.h>

typedef nlohmann::json config;

int main(int argc, char** argv)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int k = 1; k < 255; k++)
    {
        SetConsoleTextAttribute(hConsole, k);
        cout << ""
    }
    // Default configuration file operator.
    // 默认配置文件算子.
    config config_operator;
}