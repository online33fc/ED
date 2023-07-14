#ifndef MASCOTA_H
#define MASCOTA_H

#include <iostream>
#include <string>
using namespace std;

class Mascota{
    private:
        string nom;
        string tipus;
        string raca;
        char genere;
        string color;
        int edat;

    public:
        Mascota(string, string, string, char, string, int);
        string getNom();
        string getTipus();
        string getRaca();
        char getGenere();
        string getColor();
        int getEdat();
        void print();
};

#endif /* MASCOTA_H */