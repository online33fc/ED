#ifndef CLINICA_H
#define CLINICA_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream> //de cara a poder fer la lectura de dades
#include <sstream>

#include "Llista.h"
#include "Client.h"
#include "Mascota.h"
#include "NodeLlista.h"
#include "Posicio.h"

using namespace std;

class Clinica{
    public:
        Clinica(string nom);
        string getNom();
        void imprimir();
        void afegeixClient(Client client);
        void eliminaClient(string telefon);
        void mostraClients();
        void afegeixMascotaClient(string telefon, Mascota mascota);
        void eliminaMascotaClient(string telefon, string nom_mascota);
        void mostraMascotesClient(string telefon) ;
        int seleccionaOpcioMenu();
        void afegirClientsArxiu(string ruta_arxiu);

    private:
        string nom;
        Llista<Client> clients;
};

Clinica::Clinica(string nom){
    this->nom = nom;
}

string Clinica::getNom(){
    return nom;
}

void Clinica::imprimir(){ 
    cout << "El nom de la clinica es " << nom << endl;
}

void Clinica::afegeixClient(Client client){ 
    for(auto it = clients.principi(); it != clients.final(); ++it){
        if(it.element().getTelefon() == client.getTelefon()){
            throw invalid_argument("El client ja existeix "); 
        }
    }

    if(this->clients.final().element().getTelefon() == client.getTelefon()){
            throw invalid_argument("El client ja existeix ");
    }

    this->clients.inserirFinal(client);
}

void Clinica::eliminaClient(string telefon){
    for(auto it = clients.principi(); it != clients.final(); ++it){
    
        if((*it).getTelefon() == telefon){
            clients.elimina(it);
            cout << "El client ha estat eliminat de la llista." << endl;
            return;
        }
        else{
            throw invalid_argument("El client no existeix a la llista.");
        }
    }  
    
}
       
void Clinica::mostraClients(){ 
    cout << "Clients de la clínica:" << endl;
    for (auto it = clients.principi(); it != clients.final(); ++it) {
        cout << "Nom: " << (*it).getNom() << ", telèfon: " << (*it).getTelefon() << "" <<endl;
        cout << "El nom del client es " << (*it).getNom() << ", la seva adreÃ§a es " << (*it).getAdreca() << ", la seva poblacio es " << (*it).getPoblacio()
    << ", el seu telefon es " << (*it).getTelefon() << ", el seu dni es " << (*it).getDNI() << " i la seva edat es " << (*it).getEdat();
    }
}

void Clinica::afegeixMascotaClient(string telefon, Mascota mascota){
    for (auto it = clients.principi(); it != clients.final(); ++it) {
        if (it.element().getTelefon() == telefon) {
            string nom = mascota.getNom();
            string tipus = mascota.getTipus();
            string raca = mascota.getRaca();
            char genere = mascota.getGenere();
            string color = mascota.getColor();
            int edat = mascota.getEdat();
            Client& client = const_cast<Client&>(*it);
            client.afegeixMascota(nom, tipus, raca, genere, color, edat);
            cout << "Mascota afegida amb èxit" << endl;
            return;
        }
    }
    throw invalid_argument("No s'ha trobat cap client amb aquest número de telèfon");
}

void Clinica::eliminaMascotaClient(string telefon, string nom_mascota){
    for (auto it = clients.principi(); it != clients.final(); ++it) {
        if (it.element().getTelefon() == telefon) {
            try {
                Client& client = const_cast<Client&>(*it); 
                client.eliminaMascota(nom_mascota);
                cout << "Mascota eliminada amb èxit" << endl;
            } catch (const invalid_argument& e) {
                cout << e.what() << endl;
            }
            return;
        }
    }
    throw invalid_argument("No s'ha trobat cap client amb aquest número de telèfon");
}

void Clinica::mostraMascotesClient(string telefon) {
    for(auto it = clients.principi(); it != clients.final(); ++it){
        if(it.element().getTelefon() == telefon){
            it.element().mostraMascotes();
            break;
        }
    }
}

int Clinica::seleccionaOpcioMenu(){
    int opcio;
    cout << "Tria una opcio " <<endl;
    //Mostro les opcions
    cout << "1. Afegir Client " <<endl;
    cout << "2. Eliminar Client " <<endl;
    cout << "3. Afegir Mascota a un client " <<endl;
    cout << "4. Eliminar Mascota d'un client " <<endl;
    cout << "5. Imprimir clients clínica " <<endl;
    cout << "6. Imprimir les mascotes d'un client " <<endl;
    cout << "0. Sortir " <<endl;
    
    //permet a l’usuari seleccionar una
    cout << "Selecciona una de les opcions ";
    cin >> opcio;

    //retorna la opcio triada pel client
    return opcio;
}

void Clinica::afegirClientsArxiu(string ruta_arxiu) {
    ifstream arxiu(ruta_arxiu);
    if (!arxiu) {
        throw invalid_argument("No s'ha pogut obrir l'arxiu " + ruta_arxiu);
    }
    
    string line;
    while (getline(arxiu, line)) {
        istringstream iss(line);
        char tipus;
        string nom, ciutat, telefon;
        iss >> tipus >> nom >> ciutat >> telefon;
        if (tipus != 'C') {
            throw invalid_argument("El fitxer conté dades no vàlides");
        }
        Client client(nom, ciutat, telefon, "", "", 0);
        while (iss) {
            char genere;
            string nom, tipus, raca, color;
            int edat;
            iss >> genere >> nom >> tipus >> raca >> color>> edat;
            if (iss) {
                Mascota mascota(nom, tipus, raca, genere, color, edat);
                client.afegeixMascota(nom, tipus, raca, genere, color, edat);
            }
        }
        afegeixClient(client);
    }
    
    arxiu.close();
}

#endif // CLINICA_H