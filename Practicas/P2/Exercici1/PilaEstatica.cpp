#include "PilaEstatica.h"
#include <iostream>
#include <string>
#include <stdexcept> 

using namespace std;

PilaEstatica::PilaEstatica(int tamany_maxim){
    capacitat = tamany_maxim;
    _front = 0;
    _dades = new int[capacitat];
}

PilaEstatica::PilaEstatica(const PilaEstatica& origen){
    capacitat = origen.capacitat;
    _front = origen._front;
    _dades = origen._dades;
}

PilaEstatica::PilaEstatica(initializer_list<int> elements){
    capacitat = elements.size();
    _front = 0;
    _dades = new int[capacitat];
    for (auto& elem : elements) {
        afegirElement(elem);
    }
}

PilaEstatica::~PilaEstatica(){
    delete []_dades;
}

int PilaEstatica::tamany() const{
    return capacitat;
}

bool PilaEstatica::esBuida() const{
    return capacitat == 0;
}

bool PilaEstatica::esPlena() const{
    return capacitat == TAMANY_MAXIM;
}

int PilaEstatica::elementFront() const{
    if(esBuida()){
        throw string("La pila es buida, no existeix el front");
    }else{
        return _dades[0]; //cout << "Front " << _dades[0] << endl;
    }
}

void PilaEstatica::afegirElement(int e){
    if(!esPlena()){
        //añadir elemento
        cout << "Element " << e << " agregat " << endl;
        _dades[_front] = e;
        //cout
        //aumentar el tamany i actualitzar el top
        capacitat++;
        _front++;
    }else{
        throw string("La pila esta plena");
    }
}

void PilaEstatica::treureElement(){
    if(!esBuida()){
       
    cout << "Element " << _dades[0] << " eliminat " << endl;
    for(int i = 1; i < capacitat; i++){
        _dades[i-1] = _dades[i]; //Shift a l'esquerra
    }
    //cout
    //Pas 2. moure les variables
    _front--; 
    capacitat--;
 
    }else{
        throw string("La pila esta buida");
    }
}

void PilaEstatica::imprimeix() const{
    cout << "[";
    for(int i = 0; i < capacitat; i++){
        cout << _dades[i];
        if(i < capacitat - 1){
            cout << ", ";
        }
    }
    cout << "]";
}