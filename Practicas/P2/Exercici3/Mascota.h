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
        string getNom() const;
        string getTipus() const;
        string getRaca() const;
        char getGenere() const;
        string getColor() const;
        int getEdat() const;
        void print() const;
};

Mascota::Mascota(string nom, string tipus, string raca, char genere, string color, int edat){
    this->nom = nom;
    this->tipus = tipus;
    this->raca = raca;
    this->genere = genere;
    this->color = color;
    this->edat = edat;
}

string Mascota::getNom() const{
    return nom;
}

string Mascota::getTipus() const{
    return tipus;
}

string Mascota::getRaca() const{
    return raca;
}

char Mascota::getGenere() const{
    return genere;
}

string Mascota::getColor() const{
    return color;
}

int Mascota::getEdat() const{
    return edat;
}

void Mascota::print() const{
    cout << "El nom de la mascota es " << this->nom << ", el tipus es " << this->tipus << ", la raÃ§a es " << this->raca << ", el genere es " 
    << this->genere << ", el seu color es " << this->color << " i la seva edat es " << this->edat;
}

#endif /* MASCOTA_H */