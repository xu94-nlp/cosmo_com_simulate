#include <iostream>
#include <vector>

#include <string>
#include <codecvt>
#include <locale>

#include <fstream>
#include <algorithm>
#include <windows.h>
#include "nlohmann/json.hpp"

// #define __DEBUG__ 1

typedef nlohmann::json config;
std::string CONFIG_FILE_NAME = "system.cfg";
const int NO_ERROR_OCCUR = 0;
const int COLOR_DARK_GREEN = 2;
const int COLOR_GRAY = 8;
const int COLOR_GRASS_GREEN = 10;
const int COLOR_SKY_BLUE = 11;
const int COLOR_BLOOD_RED = 12;
const int COLOR_YELLOW = 14;
const int COLOR_WHITE = 15;
typedef struct {
    int iMsgID;
    std::string strPrefix;
    int iPrefixColor;
    std::string strContent;
    int iContentColor;
} MessageObj;
// Return color code by text modifier. 根据文字修饰返回颜色代码。
int getColorCode(std::string strColor)
{
    if (strColor == "white")
        return COLOR_WHITE;
    if (strColor == "yellow")
        return COLOR_YELLOW;
    if (strColor == "blood red")
        return COLOR_BLOOD_RED;
    if (strColor == "sky blue")
        return COLOR_SKY_BLUE;
    if (strColor == "grass green")
        return COLOR_GRASS_GREEN;
    if (strColor == "gray")
        return COLOR_GRAY;
    if (strColor == "dark green")
        return COLOR_DARK_GREEN; 
}
int compareMessageID(const void *a, const void *b)
{
    MessageObj *msgA = (MessageObj *)a;
    MessageObj *msgB = (MessageObj *)b;
    return (msgA->iMsgID - msgB->iMsgID);
}

int main(int argc, char** argv)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::ios_base::sync_with_stdio(false);
    std::locale loc("C.UTF-8");
    std::wcout.imbue(loc);
    /* Initialization. 初始化过程 */
    // Change default text code. 更改默认文字编码.
    
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
        msgProtocals[i].strPrefix = cfgOperator["msgs"][i]["prefix"];
        msgProtocals[i].iPrefixColor = getColorCode(cfgOperator["msgs"][i]["prefix_color"]);
        msgProtocals[i].strContent = cfgOperator["msgs"][i]["content"];
        msgProtocals[i].iContentColor = getColorCode(cfgOperator["msgs"][i]["content_color"]);
    }
    // Communicate Process. // 通讯过程
    std::wcout << L"测试中文输出" << std::endl;
    for (int i = 0; i < iMaxMsgLength; i++)
    {
        SetConsoleTextAttribute(hConsole, msgProtocals[i].iPrefixColor);
        // std::wcout << msgProtocals[i].strPrefix << " ";
        SetConsoleTextAttribute(hConsole, msgProtocals[i].iContentColor);
        // std::wcout << msgProtocals[i].strContent << std::endl;
    }
    SetConsoleTextAttribute(hConsole, COLOR_WHITE);
    return NO_ERROR_OCCUR;
}