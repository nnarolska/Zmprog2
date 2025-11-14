#pragma once
#include <string>
using namespace std;

class Logger {
private:
    Logger(); 
    static Logger* logger;
    string zapisy[100];
    int licznik;

public:
    Logger(const Logger&) = delete;          
    void operator=(const Logger&) = delete;  
    static Logger* GetInstance();
    void Log(const string& wpis);
};
