#include "Estudiant.h"
#include <iostream>
#include <string>
#include <stdexcept> 

using namespace std;

Estudiant::Estudiant(){
    
}

void Estudiant::demanarDades(){
    cout << "Nom? ";
    cin >> nom;
    cout << "Any de neixament? ";
    cin >> any;
    cout << "Asignatures? ";
    cin >> asignatures;
}

Estudiant::Estudiant(string nom, int any, int asignatures) {
    this->nom = "";
    this->any = 0;
    this->asignatures = 0;
}

int Estudiant::getEdat(){
    int edat = (2023 - this->any);
    return edat;
}

void Estudiant::print(){
    cout << "Estudiant(Nom ==> " << this->nom << ", Naixement ==> " << this->any << ", Assignatures ==>" << this->asignatures << ")";
}


