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
        }
    return 0;
}