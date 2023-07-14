#ifndef CLIENT_H
#define CLIENT_H

#include <vector>
#include <iostream>
#include <string>
#include "Mascota.h"
using namespace std;

class Client{
    private:
    string nom;
    string adreca;
    string poblacio;
    string telefon;
    string dni;
    int edat;
    vector<Mascota> mascotes;
        
    public:
    Client(string, string, string, string, string, int);
    string getAdreca();
    string getPoblacio();
    string getNom();
    string getTelefon();
    string getDNI();
    int getEdat();
    void print();
    void afegeixMascota(string, string, string, char, string, int);
    void eliminaMascota(string);
    void mostraMascotes(); 
};

#endif /* CLIENT_H */