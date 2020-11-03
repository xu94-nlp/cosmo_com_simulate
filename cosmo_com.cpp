#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>
#include "nlohmann/json.hpp"

#define __DEBUG__ 1

typedef nlohmann::json config;
std::string CONFIG_FILE_NAME = "system.cfg";

struct MessageObj {
    int iMsgID;
    std::string strPrefix;
    int iPrefixColor;
    std::string strContent;
    int iContentColor;
};

int main(int argc, char** argv)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    #ifdef __DEBUG__
        for (int k = 0; k < 16; k++)
        {
            SetConsoleTextAttribute(hConsole, k);
            std::cout << k << "The color testing..." << std::endl;
        }
    #endif
    /* Initialization. 初始化过程 */
    // Default configuration file operator. 默认配置文件算子.
    std::ifstream fConfigFileInput("system.cfg");
    config cfgOperator;
    fConfigFileInput >> cfgOperator;

    // Initialize Message Protocal. 初始化通信协议。
    int iMaxMsgLength = cfgOperator["msgs"].size();
    MessageObj msgProtocals[iMaxMsgLength] = {0};
    for (int i=0; i < iMaxMsgLength; i++)
    {
        msgProtocals[i].iMsgID = cfgOperator["msgs"][i]["msg_id"];
        
    }
    std::cout << cfgOperator["msgs"].size() << std::endl;

}