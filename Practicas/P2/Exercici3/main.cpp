#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "Client.h"
#include "Mascota.h"

using namespace std;

bool buscarCliente(vector<Client>& clients, string dni) {
    for(Client& client : clients) {
        if (client.getDNI() == dni) {
            return true;
        }
    }
    return false;
}

void afegirClient(vector<Client>& clients) {
    string nom, adreca, poblacio, telefon, dni;
    int edat;

    cout << "Introdueix les dades del client:" << endl;
    cout << "Nom: ";
    getline(cin, nom);
    cout << "Adreca: ";
    getline(cin, adreca);
    cout << "Poblacio: ";
    getline(cin, poblacio);
    cout << "Telefon: ";
    getline(cin, telefon);
    cout << "DNI: ";
    getline(cin, dni);
    cout << "Edat: ";
    cin >> edat;
    cin.ignore(); // Limpiamos el buffer de entrada


    if(buscarCliente(clients, dni)) {
        cout << "El client amb DNI " << dni << " ja existeix" << endl;
        return;
    }

    Client client(nom, adreca, poblacio, telefon, dni, edat);
    clients.push_back(client);

    char resposta;
    cout << "Vols afegir una mascota (S/N)? ";
    cin >> resposta;
    cin.ignore(); 

    if(resposta == 'S' or resposta == 's') {
        string nom, tipus, raca, color;
        char genere;
        int edat;

        cout << "Introdueix les dades de la mascota:" << endl;
        cout << "Nom: ";
        getline(cin, nom);
        cout << "Tipus: ";
        getline(cin, tipus);
        cout << "Raca: ";
        getline(cin, raca);
        cout << "Genere (M/F): ";
        cin >> genere;
        cin.ignore(); 
        cout << "Color: ";
        getline(cin, color);
        cout << "Edat: ";
        cin >> edat;
        cin.ignore(); 

        client.afegeixMascota(nom, tipus, raca, genere, color, edat);
    }
}

void eliminarClient(vector<Client>& clients, string dni){
    for(vector<Client>::iterator it = clients.begin(); it !=clients.end(); ++it){
        if(it->getDNI() == dni) {
            clients.erase(it);
            cout << "El client amb DNI " << dni << " ha estat eliminat." << endl;
            return;
        }
    }
    cout << "No s'ha trobat cap client amb el dni " << dni <<endl;
}

void afegirMascota(vector<Client>& clients){
    string nom, tipus, raca, color, dni;
    char genere;
    int edat;

    cout << "Introdueix les dades del client:" << endl;
    cout << "DNI: ";
    getline(cin, dni);


    cout << "Introdueix les dades de la mascota:" << endl;
    cout << "Nom: ";
    getline(cin, nom);
    cout << "Tipus: ";
    getline(cin, tipus);
    cout << "Raca: ";
    getline(cin, raca);
    cout << "Genere (M/F): ";
    cin >> genere;
    cin.ignore(); 
    cout << "Color: ";
    getline(cin, color);
    cout << "Edat: ";
    cin >> edat;
    cin.ignore(); 

    for(vector<Client>::iterator it = clients.begin(); it !=clients.end(); ++it){
        if(it->getDNI() == dni) {
            it->afegeixMascota(nom, tipus, raca, genere, color, edat);
            return;
        }
    }
}

void eliminarMascota(vector<Client>& clients, vector<Mascota>& mascotes){
    string dni, nom;

    cout << "Introdueix les dades del client: " << endl;
    cout << "DNI: ";
    getline(cin, dni);

    cout << "Introdueix les dades de la mascota: " << endl;
    cout << "Nom: ";
    getline(cin, nom);

    for(vector<Client>::iterator it = clients.begin(); it !=clients.end(); ++it){
        if(it->getDNI() == dni) {
            
            for(vector<Mascota>::iterator itMascotes = mascotes.begin(); itMascotes !=mascotes.end(); ++itMascotes){
                if(itMascotes->getNom() == nom){
                    //it->eliminaMascota(itMascotes);
                    mascotes.erase(itMascotes);
                    cout << "Mascota eliminada correctamente" << endl;
                    return;
                }
            }

        }
    }
    cout << "No s'ha pogut trobar el client" << endl;
}

void imprimirClients(vector<Client>& clients){
    for(vector<Client>::iterator it = clients.begin(); it !=clients.end(); ++it){
        cout << "nom " << it->getNom() << ", adreca " << it->getAdreca() << ", poblacio " << it->getPoblacio() << ", telefon " << it->getTelefon() << ", DNI " << it->getDNI() << ", edat " << it->getEdat() << endl;
    }
}

void imprimirMascotes(vector<Client>& clients, vector<Mascota>& mascotes, string dni){
    cout << "Introdueix les dades del client: " << endl;
    cout << "DNI: ";
    getline(cin, dni);

    for(vector<Client>::iterator it = clients.begin(); it !=clients.end(); ++it){
        if(it->getDNI() == dni) {
            
            for(vector<Mascota>::iterator itMascotes = mascotes.begin(); itMascotes !=mascotes.end(); ++itMascotes){
                cout << "El nom de la mascota es " << itMascotes->getNom() << ", el tipus es " << itMascotes->getTipus() << ", la raca es " << itMascotes->getRaca() << ", el genere es " 
                << itMascotes->getGenere() << ", el seu color es " << itMascotes->getColor() << " i la seva edat es " << itMascotes->getEdat() << endl;
            }
        }
    }
}

void sortir(){
    cout << "S'esta tancant la clinica veterinaria" << endl;
}


int main(int argc, char** argv) {
    int num;
    string nom, adreca, poblacio, telefon, dni;
    int edat;
    vector<Client> clients;
    vector<Mascota> mascotes;
    vector<string> arr_options {" 1. Afegir client", " 2. Eliminar client", " 3. Afegir Masota a un client",
     " 4. Eliminar Mascota d'un client", " 5. Imprimir clients clinica", " 6. Imprimir les mascotes d'un client", " 0. Sortir"};
    cout << "Hola, que vols fer?" << endl;
    
    do{
        for(vector<string>::const_iterator it = arr_options.begin(); it != arr_options.end(); ++it){
            cout << ' ' << *it;
            cout << '\n';
        }  
        cin >> num;

        switch(num){
            case 0: //case Sortir
                sortir();
                break;

            case 1:
                cout << "Afegim clients" << endl;
                afegirClient(clients);
                break;
            
            case 2:
                cout << "Eliminar client" << endl;
                eliminarClient(clients, dni);
                break;

            case 3:
                cout << "Afegir Mascota a un client" << endl;
                afegirMascota(clients);
                break; 

            case 4:
                cout << "Eliminar Mascota d'un client" << endl;
                eliminarMascota(clients, mascotes);
                break; 
            
            case 5:
                cout << "Imprimir clients clinica" << endl;
                imprimirClients(clients);
                break;

            case 6:
                cout << "Imprimir les mascotes d'un client" << endl;
                imprimirMascotes(clients, mascotes, dni);
                break;

            default:
                cout << "Opcio incorrecte" << endl;
                break;  
        }
    }while(num != 0);
  
    return 0;
}