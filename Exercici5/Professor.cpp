#include "Professor.h"
#include <iostream>
#include <string>
#include <stdexcept> 

using namespace std;

Professor::Professor(){

}

Professor::Professor(string nom, int anyNaixement){
    this->nom = nom;
    this->anyNaixement = anyNaixement;
}

void Professor::demanarDades(){
    cout << "Nom? ";
    cin >> nom;
    cout << "Any de neixament? ";
    cin >> anyNaixement;
}

int Professor::getEdat(){
    int edat = 2023 - anyNaixement;
    return edat;
}

void Professor::print(){
    cout << "Professor(Nom ==> " << this->nom << ", Naixement ==> " << this->anyNaixement << ")";
}