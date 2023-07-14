#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <iostream>
#include <string>
using namespace std;

class Professor {
    private:
        string nom;
        int anyNaixement;

    public:
        Professor();
        Professor(string nom, int anyNaixement);
        void demanarDades();
        int getEdat();
        void print();
};

#endif // PROFESSOR_H