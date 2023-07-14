#include "Client.h"
#include "Mascota.h"
#include <iostream>
#include <string>
#include <stdexcept> 

using namespace std;


Client::Client(string nom, string adreca, string poblacio, string telefon, string dni, int edat){
    this->nom = nom;
    this->adreca = adreca;
    this->poblacio = poblacio;
    this->telefon = telefon;
    this->dni = dni;
    this->edat = edat;
}

string Client::getAdreca(){
    return adreca;
}

string Client::getPoblacio(){
    return poblacio;
}

string Client::getNom(){
    return nom;
}

string Client::getTelefon(){
    return telefon;
}

string Client::getDNI(){
    return dni;
}

int Client::getEdat(){
    return edat;
}

void Client::print(){
    cout << "El nom del client es " << this->nom << ", la seva adreça es " << this->adreca << ", la seva poblacio es " << this->poblacio
    << ", el seu telefon es " << this->telefon << ", el seu dni es " << this->dni << " i la seva edat es " << this->edat;
}

void Client::afegeixMascota(string nom, string tipus, string raca, char genere, string color, int edat){
    Mascota mascota(nom, tipus, raca, genere, color, edat);
    mascotes.push_back(mascota);
}

void Client::eliminaMascota(string nom){
    for (vector<Mascota>::iterator it = mascotes.begin(); it !=mascotes.end(); ++it){
        if (it->getNom() == nom) {
            mascotes.erase(it);
            break;
        }
    }
    
}

void Client::mostraMascotes(){
    for (Mascota& mascota : mascotes) {
        mascota.print();
        cout << "\n" <<endl;
    }
}