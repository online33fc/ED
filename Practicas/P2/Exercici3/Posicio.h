#ifndef POSICIO_H
#define POSICIO_H
//ha de tenir excepcions

#include "NodeLlista.h"
#include <iostream>
#include <string>
using namespace std;

template <class Element>
class Posicio{
    public:
    Posicio(NodeLlista<Element>* node); //inicialitza la classe Posicio amb el node que rep com a paràmetre.
    Posicio(const Posicio& origen);
    virtual ~Posicio();

    Posicio<Element> next() const; //retorna la següent posició a l’actual
    // Si no hi ha següent posició, aquest mètode ha de llençar una excepció.

    Posicio<Element> anterior() const; // retorna l’anterior posició
    const Element& element() const; // retorna el contingut de l’actual posició
    NodeLlista<Element>* elimina();
    
    void fixarAnterior(NodeLlista<Element>* node); // assigna l’adreça de l’anterior node
    void fixarSeguent(NodeLlista<Element>* node); // assigna l’adreça del següent node

    Posicio<Element> operator++() const; // sobrecarrega operador ++
    Posicio<Element> operator--() const; // sobrecarrega operador --
    bool operator==(const Posicio& other) const; // sobrecarrega operador ==
    bool operator!=(const Posicio& other) const; // sobrecarrega operador !=
    const Element& operator*() const; // sobrecarrega operador contingut

    private:
    NodeLlista<Element>* _node;
};

//Metodes

template <class Element>
Posicio<Element>::Posicio(NodeLlista<Element>* node){
    _node = node;
}

template <class Element>
Posicio<Element>::Posicio(const Posicio& origen){
    _node = origen.node;
}

template <class Element>
Posicio<Element>::~Posicio(){ //falta por hacer

}

template <class Element>
Posicio<Element> Posicio<Element>::next() const{ //falten excepcions
    return Posicio<Element>(_node->accedirSeguent());
}

template <class Element>
Posicio<Element> Posicio<Element>::anterior() const{
    return Posicio<Element>(_node->accedirAnterior());
}

template <class Element>
const Element& Posicio<Element>::element() const{
    return _node->accedirElement();
}

template <class Element>
NodeLlista<Element>* Posicio<Element>::elimina(){ 
    //prev->next = _node->next;
    _node->accedirAnterior()->fixarSeguent(_node->accedirSeguent());
    //_node->prev= _node->prev;
    _node->accedirSeguent()->fixarAnterior(_node->accedirAnterior());
    //del _node
    delete _node;
}

template <class Element>
void Posicio<Element>::fixarAnterior(NodeLlista<Element>* node){
    node->fixarAnterior(_node->accedirAnterior());
    node->fixarSeguent(_node); 
    _node->accedirAnterior()->fixarSeguent(node);
    _node->fixarAnterior(node);
}

template <class Element>
void Posicio<Element>::fixarSeguent(NodeLlista<Element>* node){
    node->fixarSeguent(_node->accedirSeguent());
    node->fixarAnterior(_node);
    _node->accedirSeguent()->fixarAnterior(node);
    _node->fixarSeguent(node);
}

template <class Element>
Posicio<Element> Posicio<Element>::operator++() const{
    return next();
}

template <class Element>
Posicio<Element> Posicio<Element>::operator--() const{
    return anterior();
}

template <class Element>
bool Posicio<Element>::operator==(const Posicio& other) const{
    return _node == other._node;
}

template <class Element>
bool Posicio<Element>::operator!=(const Posicio& other) const{
    return _node != other._node;
}

template <class Element>
const Element& Posicio<Element>::operator*() const{
    return _node->element();
}

#endif // POSICIO_H