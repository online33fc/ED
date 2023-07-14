#ifndef NODELLISTA_H
#define NODELLISTA_H

#include <iostream>
#include <string>
using namespace std;

template <class Element>
class NodeLlista {
public:
    NodeLlista(Element element); //construeix el node amb l’element que rep com a paràmetre
    Element accedirElement(); //retorna l’element que hi ha guardat al node
    NodeLlista<Element>* accedirSeguent(); // retorna l’adreça del següent node o nullptr en cas que no hi hagi següent
    void fixarSeguent(NodeLlista<Element>* seguent); //modifica l’adreça de _seguent per l’adreça rebuda com a paràmetre
    NodeLlista<Element>* accedirAnterior(); //retorna l’adreça del node anterior o nullptr en cas que no hi hagi anterior
    void fixarAnterior(NodeLlista<Element>* anterior); //Modifica l’adreça de _anterior per l’adreça rebuda com a paràmetre

private:
    Element _element; // Element del node
    NodeLlista<Element>* _anterior; // Apuntador al node anterior
    NodeLlista<Element>* _seguent; // Apuntador al següent node
};

//Metodes

template <class Element>
NodeLlista<Element>::NodeLlista(Element element){
    _element = element;
    _anterior = nullptr;
    _seguent = nullptr;
}

template <class Element>
Element NodeLlista<Element>::accedirElement(){
    return _element;
}

template <class Element>
NodeLlista<Element>* NodeLlista<Element>::accedirSeguent(){
    return _seguent;
}

template <class Element>
void NodeLlista<Element>::fixarSeguent(NodeLlista<Element>* seguent){
    _seguent = seguent;
}

template <class Element>
NodeLlista<Element>* NodeLlista<Element>::accedirAnterior(){
    return _anterior; 
}

template <class Element>
void NodeLlista<Element>::fixarAnterior(NodeLlista<Element>* anterior){ 
    _anterior = anterior;
}

#endif // NODELLISTA_H