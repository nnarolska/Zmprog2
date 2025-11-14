// WEL24MX1S4
// Natalia Narolska
// 14.11.2025r.
// Linux VSC
// IP: 10.202.131.83
// Rodzaj argumentów: 3. double oraz long
#include <iostream>
#include <string>

using namespace std;
// Produkt, klasa abstrakcyjna
class Kalkulator{
public:
    virtual ~Kalkulator(){}
    virtual long Dzialanie(double a, long b)const = 0;
};
// Klasy pochodne
// Kalkulator dodawania
class Kalkulator_d : public Kalkulator{
public:
    long Dzialanie(double a, long b) const override{
        return a + b;
    }
};
// Kalkulator odejmowania
class Kalkulator_o : public Kalkulator{
public:
    long Dzialanie(double a, long b) const override{
        return a - b;
    }
};
// Kalkulator mnożenia
class Kalkulator_m : public Kalkulator{
public:
    long Dzialanie(double a, long b) const override{
        return a * b;
    }
};
// Kalkulator dzielenia
class Kalkulator_i : public Kalkulator{
public:
    long Dzialanie(double a, long b) const override {
        if (b == 0) {
            cout << "Błąd: dzielenie przez zero!" << endl;
            return 0;
        }
        return a / b;
    }
};
// Kreator
class Kreator{
private:
    Kalkulator* kalkulator;

public:
    Kreator(char wybor) : kalkulator(nullptr) {
            switch (wybor) {
                case 'd': 
                kalkulator = new Kalkulator_d(); break;
                case 'o': 
                kalkulator = new Kalkulator_o(); break;
                case 'm': 
                kalkulator = new Kalkulator_m(); break;
                case 'i': 
                kalkulator = new Kalkulator_i(); break;
            }
            if (kalkulator == nullptr) {
            cout << "Nieznane działanie!" << endl;
        }
    }
    Kalkulator* DajKalkulator() const {
        return kalkulator;
    }
    ~Kreator() {
        delete kalkulator;
    }
};
class Logger {
private:
    Logger() : licznik(0) {} 
    static Logger* logger;
    string zapisy[100];
    int licznik;

public:
    Logger(const Logger&) = delete;         
    void operator=(const Logger&) = delete; 

    static Logger* GetInstance() {
        if (logger == nullptr) {
            logger = new Logger();
        }
        return logger;
    }

    void Log(const string& wpis) {
        if (licznik < 100) {
            zapisy[licznik++] = wpis;
        }

        for (int i = 0; i < licznik; i++) {
            cout << zapisy[i] << endl;
        }
    }
};

Logger* Logger::logger = nullptr;

int main() {
    char wybor;

    while (true) {
        cout << "\nWybierz działanie(d/o/m/i):\n";
        cin >> wybor;

        Kreator kreator(wybor);
        Kalkulator* k = kreator.DajKalkulator();

        double a;
        long b;

        cout << "Podaj liczbę a: ";
        cin >> a;
        cout << "Podaj liczbę b: ";
        cin >> b;


        long wynik = k->Dzialanie(a, b);
        cout <<"Wynik: " + to_string(wynik) << endl;

        char znak = '?';
        if (wybor == 'd') znak = '+';
        if (wybor == 'o') znak = '-';
        if (wybor == 'm') znak = '*';
        if (wybor == 'i') znak = '/';

        string wpis = to_string(a) + " ";
        wpis += znak;
        wpis += " " + to_string(b);
        wpis += " = " + to_string(wynik);

        Logger::GetInstance()->Log(wpis);
    }
    return 0;
}