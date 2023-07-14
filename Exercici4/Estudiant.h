#ifndef ESTUDIANT_H
#define ESTUDIANT_H

#include <iostream>
#include <string>
using namespace std;

class Estudiant{
    private:
        string nom; //el this-> nom es aquest
        int any;
        int asignatures;
    public:
        Estudiant();
        Estudiant(string, int, int);
        void print();
        void demanarDades();
        int getEdat();
};

#endif /* ESTUDIANT_H */