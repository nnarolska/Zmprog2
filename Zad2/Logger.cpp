#include "Logger.h"
#include <iostream>
using namespace std;
Logger* Logger::logger = nullptr;
Logger::Logger() : licznik(0) {}
Logger* Logger::GetInstance() {
    if (logger == nullptr) {
        logger = new Logger();
    }
    return logger;
}
void Logger::Log(const string& wpis) {
    if (licznik < 100) {
        zapisy[licznik++] = wpis;
    }

    for (int i = 0; i < licznik; i++) {
        cout << zapisy[i] << endl;
    }
}
