#include <iostream>
#include <string>
#include <stdexcept> 
#include "Llista.h"
#include "Posicio.h"

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
    cout << "Eliminant LinkedList\n";
    
    for(NodeLlista<Element> * itr = _cap; itr != nullptr; itr =itr->getNext()){
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
    return Posicio<Element>(_cap->accedirSeguent());
}

template <class Element>
Posicio<Element> Llista<Element>::final() const{
    return Posicio<Element>(_cua->accedirAnterior());
}

template <class Element>
Posicio<Element> Llista<Element>::rprincipi() const{
    return Posicio<Element>(_cua->accedirAnterior());
}

template <class Element>
Posicio<Element> Llista<Element>::rfinal() const{
    return Posicio<Element>(_cap->accedirSeguent());
}

template <class Element>
void Llista<Element>::inserirDespres(Posicio<Element>& position, const Element& element){
    NodeLlista<Element>* temp = new NodeLlista<Element>(element);
    posicio.fixarSeguent(temp); 
    _tamany++;
}

template <class Element>
void Llista<Element>::inserirAbans(Posicio<Element>& position, const Element& element){
    NodeLlista<Element>* temp = new NodeLlista<Element>(element);
    Posicio.fixarAnterior(temp); 
    _tamany++;
}

template <class Element>
void Llista<Element>::inserirPrincipi(const Element& element){
    //per inseri al principi he de inserir darrera del sentinella cap i davant del sentinella cua
    Posicio<Element>(_cap).fixarAnterior(new NodeLlista<Element>(element));
    _tamany++;
}

template <class Element>
void Llista<Element>::inserirFinal(const Element& element){ 
    Posicio<Element>(_cua).fixarSeguent(new NodeLlista<Element>(element));
    _tamany++;
}

template <class Element>
void Llista<Element>::elimina(Posicio<Element>& position){
    position.elimina();
}