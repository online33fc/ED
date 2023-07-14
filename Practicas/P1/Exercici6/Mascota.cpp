#include "Mascota.h"
#include <iostream>
#include <string>
#include <stdexcept> 

using namespace std;

Mascota::Mascota(string nom, string tipus, string raca, char genere, string color, int edat){
    this->nom = nom;
    this->tipus = tipus;
    this->raca = raca;
    this->genere = genere;
    this->color = color;
    this->edat = edat;
}

string Mascota::getNom(){
    return nom;
}

string Mascota::getTipus(){
    return tipus;
}

string Mascota::getRaca(){
    return raca;
}

char Mascota::getGenere(){
    return genere;
}

string Mascota::getColor(){
    return color;
}

int Mascota::getEdat(){
    return edat;
}

void Mascota::print(){
    cout << "El nom de la mascota es " << this->nom << ", el tipus es " << this->tipus << ", la raça es " << this->raca << ", el genere es " 
    << this->genere << ", el seu color es " << this->color << " i la seva edat es " << this->edat;
}