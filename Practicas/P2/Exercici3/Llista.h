#ifndef LLISTA_H
#define LLISTA_H

//ha de tenir excepcions
#include "NodeLlista.h"
#include "Posicio.h"
#include <iostream>
#include <string>
using namespace std;

template <class Element>
class Llista{
    public:
    Llista();
    Llista(initializer_list<Element> elements);
    Llista(const Llista<Element>& origen);
    virtual ~Llista();
    int tamany() const;
    bool esBuida() const;
    Posicio<Element> principi() const; // return first position
    Posicio<Element> final() const; // return last position

    // Reverse iteration
    Posicio<Element> rprincipi() const; // return first position
    Posicio<Element> rfinal() const; // return last position
    void inserirDespres(Posicio<Element>& position, const Element& element);
    void inserirAbans(Posicio<Element>& position, const Element& element);
    void inserirPrincipi(const Element& element);
    void inserirFinal(const Element& element);

    void elimina(Posicio<Element>& position);
    
    private:
    NodeLlista<Element>* _cap;
    NodeLlista<Element>* _cua;
    int _tamany;
};

//Metodes
template <class Element>
Llista<Element>::Llista(){
    _cap = nullptr;
    _cua = nullptr;
    _tamany = 0;
}

template <class Element>
Llista<Element>::Llista(initializer_list<Element> elements){
    _cap = nullptr;
    _cua = nullptr;
    _tamany = 0;
    for(auto element : elements){
        inserirFinal(element);
    }
}

template <class Element>
Llista<Element>::Llista(const Llista<Element>& origen){
    _cap = nullptr;
    _cua = nullptr;
    _tamany = 0;
    Posicio<Element> p = origen.principi();
    while (p != origen.final()){
        inserirFinal(p.element());
        p++
    }
    inserirFinal(p.element());
}

template <class Element>
Llista<Element>::~Llista(){
    cout << "Eliminant LinkedList\n\n";
    
    //iterem sobre la llista per eliminar tots els nodes
    for (NodeLlista<Element> * itr = _cap; itr != nullptr; itr =itr->getNext()){
        NodeLlista<Element> * temp = _cap;
        _cap = _cap->getNext();
        delete temp;
    }
}

template <class Element>
int Llista<Element>::tamany() const{
    return _tamany;
}

template <class Element>
bool Llista<Element>::esBuida() const{
    return _tamany == 0;
}

template <class Element>
Posicio<Element> Llista<Element>::principi() const{
    if(esBuida()){
        throw out_of_range("La Llista es buida");
    }
    return Posicio<Element>(_cap);
}

template <class Element>
Posicio<Element> Llista<Element>::final() const{
    if(esBuida()){
        throw out_of_range("La Llista es buida");
    }
    return Posicio<Element>(_cua);
}

template <class Element>
Posicio<Element> Llista<Element>::rprincipi() const{
    if(esBuida()){
        throw out_of_range("La Llista es buida");
    }
    return Posicio<Element>(_cua);
}

template <class Element>
Posicio<Element> Llista<Element>::rfinal() const{
    //Verificar si la lista está vacía
    if(esBuida()){
        throw out_of_range("La Llista es buida");
    }
    return Posicio<Element>(_cap);
}

template <class Element>
void Llista<Element>::inserirDespres(Posicio<Element>& position, const Element& element){
    NodeLlista<Element>* temp = new NodeLlista<Element>(element);
    posicio.fixarSeguent(temp); //setNext() //fixarSeguent
    _tamany++;
}

template <class Element>
void Llista<Element>::inserirAbans(Posicio<Element>& position, const Element& element){
    NodeLlista<Element>* temp = new NodeLlista<Element>(element);
    Posicio.fixarAnterior(temp); //setPrevious()
    _tamany++;
}

template <class Element>
void Llista<Element>::inserirPrincipi(const Element& element){
    //per inseri al principi he de inserir darrera del sentinella cap i davant del sentinella cua
    Posicio<Element>(_cap).fixarAnterior(new NodeLlista<Element>(element));
    _tamany++;
}

/*
    NodeLlista<Element>* nouNode = new NodeLlista<Element>(element);
    nouNode->fixarAnterior(_cua->accedirAnterior());
    nouNode->fixarSeguent(_cua);
    _cua->accedirAnterior()->fixarSeguent(nouNode);
    _cua->fixarAnterior(nouNode);
*/
template <class Element>
void Llista<Element>::inserirFinal(const Element& element){ 
    Posicio<Element>(_cua).fixarSeguent(new NodeLlista<Element>(element));
    _tamany++;
}

template <class Element>
void Llista<Element>::elimina(Posicio<Element>& position){ //queda este metodo
    position.elimina();
}

#endif // LLISTA_H