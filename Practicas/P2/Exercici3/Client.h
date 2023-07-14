#ifndef CLIENT_H
#define CLIENT_H

#include <vector>
#include <iostream>
#include <string>
#include "Mascota.h"

using namespace std;

class Client{
    public:
        Client(string, string, string, string, string, int);
        string getAdreca() const;
        string getPoblacio() const;
        string getNom() const;
        string getTelefon() const;
        string getDNI() const;
        int getEdat() const;
        void print();
        void afegeixMascota(string, string, string, char, string, int);
        void eliminaMascota(string);
        void mostraMascotes() const; 

    private:
        string nom;
        string adreca;
        string poblacio;
        string telefon;
        string dni;
        int edat;
        vector<Mascota> mascotes;   
};

Client::Client(string nom, string adreca, string poblacio, string telefon, string dni, int edat){
    this->nom = nom;
    this->adreca = adreca;
    this->poblacio = poblacio;
    this->telefon = telefon;
    this->dni = dni;
    this->edat = edat;
}

string Client::getAdreca() const{
    return adreca;
}

string Client::getPoblacio() const{
    return poblacio;
}

string Client::getNom() const{
    return nom;
}

string Client::getTelefon() const{
    return telefon;
}

string Client::getDNI() const{
    return dni;
}

int Client::getEdat() const{
    return edat;
}

void Client::print(){
    cout << "El nom del client es " << this->nom << ", la seva adreÃ§a es " << this->adreca << ", la seva poblacio es " << this->poblacio
    << ", el seu telefon es " << this->telefon << ", el seu dni es " << this->dni << " i la seva edat es " << this->edat;
}

void Client::afegeixMascota(string nom, string tipus, string raca, char genere, string color, int edat){
    Mascota mascota(nom, tipus, raca, genere, color, edat);
    mascotes.push_back(mascota);
}

void Client::eliminaMascota(string nom) {
    for (vector<Mascota>::iterator it = mascotes.begin(); it !=mascotes.end(); ++it){
        if (it->getNom() == nom) {
            mascotes.erase(it);
            break;
        }
    }
    
}

void Client::mostraMascotes() const{
    for(const auto& mascota : mascotes){
        mascota.print();
        cout << "\n" <<endl;
    }
}

#endif /* CLIENT_H */