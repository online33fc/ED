#pragma once

#include "SingleNode.hpp"

#include <iostream>
#include <initializer_list>
#include <stdexcept>

// CLASSE PER L'EXAMEN 2a AVAL 2023 

/*
 *  NOM: xxxxxxxx
 *  COGNOM: xxxxxxxx
 *  DNI O NIUB: xxxxxxxx
 */


template <class Element>
class SpecialQueue
{
public:
    // Constructors i destructor 
    SpecialQueue();
    SpecialQueue(const SpecialQueue& other); //0.5 punts 
    virtual ~SpecialQueue(); // 0.5 punts 
    
    // Metodes normals 
    bool isEmpty() const; // 0.25 punts 
    int size() const; // 0.25 punts 
    void print();  // 0.5 punts 
    void enqueue(const Element& element);  // 1 punt 
    Element dequeue(); // 1 punt 
    
    // Metodes especials 
    void enqueueFront(const Element& e1, const Element& e2);  // 2 punts
    void swapThirdPenultimate();   // 2 punts 
    void dequeueIfExists(Element e);  // 2 punts 
    
    
private:
    SingleNode<Element>* _first;     // el cap, per on es desencua
    SingleNode<Element>* _last;      // el cul, per on s'encua (si s'elimina s'ha de canviar l'enqueue i que faci bucle)
};

/************* constructors i destructor *****************/
// Code here 
template <class Element>
SpecialQueue<Element>::SpecialQueue(){
    _last = nullptr;
    _first = nullptr;
}

template <class Element>
SpecialQueue<Element>::SpecialQueue(const SpecialQueue& other){
    _last = other._last;
    _first = other._first;
}

template <class Element>
SpecialQueue<Element>::~SpecialQueue(){
    delete _last;
    delete _first;
}


/************* metodes normals *****************/

/*
 * isEmpty: Mira si es cua buida.
 */
// Code here
template <class Element>
bool SpecialQueue<Element>::isEmpty() const{
    return (_first == nullptr); //si el _first es nullptr no hi ha cap element, també es podria posar return this->size() == 0;
}

/*
 * size: Calcula el tamany de la llista iterativament.
 */
// Code here
template <class Element>
int SpecialQueue<Element>::size() const{
    //creo un nodo para recorrer la lista mientras el next no sea nulo i sumo 1 a una variable int, luego la retorno
    SingleNode<Element>* tmp = _first;
    int _size = 0;
    while(tmp->getNext() != nullptr){
        _size++;
        tmp->setNext(tmp->getNext());
    }
    return _size;
}


/*
 * enqueue: Metode que encua pel final
 */
// Code here 
template <class Element>
void SpecialQueue<Element>::enqueue(const Element& element){
    SingleNode<Element>* newNode = new SingleNode<Element>(element); //Creem un nou node
    _last->setNext(newNode); //fem que el nou node sigui l'ultim
    _last = newNode; //actualitzem la ultima posicio

}


/*
 * dequeue: Metode que desencua pel principi (FIFO)
 */
// Code here 
template <class Element>
Element SpecialQueue<Element>::dequeue(){
    Element eliminat = _first->getElement(); //he de posar el getElement perque _first es un punter 
    _first->setNext(_first->getNext()); //hacemos que el first ahora sea el que esta en la segunda posicion
    return eliminat;
}
/*
 * Metode print
 * Te en compte l'ultim element per no imprimir la coma.
 */
// Code here 
template <class Element>
void SpecialQueue<Element>::print(){ //He pensat en fer-ho amb un while i anar imprimint els valors fins que arribem al final de la queue
    SingleNode<Element>* tmp = _first;
    cout << "[";
    while(tmp->getNext() != nullptr){
        cout << tmp << ", "; //imprimeixo als valors
        tmp->setNext(tmp->getNext()); //segueixo recorrent la fila
    }
    cout << "]";
}


/************* metodes especials  *****************/

/*
 * Metode enqueueFront
 * afegeix dos elements a l'inici de la cua
 */
// Code here 
template <class Element>
void SpecialQueue<Element>::enqueueFront(const Element& e1, const Element& e2){
    SingleNode<Element>* primer = new SingleNode<Element>(e1); //creem un nou node
    SingleNode<Element>* segon = new SingleNode<Element>(e2); //creem un nou node
    if(isEmpty()){
        primer->setNext(segon);
        segon->setNext(nullptr);
        _first = primer;
        _last = segon;
    }
    //primer fem la conexio de segon amb l'actual _first, per tant ara tindriem 22,1,2,3,4
    segon->setNext(_first);
    //Despres fem la conexio de primer amb el segon
    primer->setNext(segon);
    _first = primer; // i per ultim actualitzem el punter
    
}



/*
 * Metode swapThirdPenultimate 
 * funcio per intercanviar el tercer node amb el penultim node de la cua 
 */
// Code here 
template <class Element>
void SpecialQueue<Element>::swapThirdPenultimate(){
    if(isEmpty()){
        throw out_of_range("No hi ha cal valor per intercanviar");
    }
    if(this->size() < 3){ //fem size menor a 4 perque almenys ha d'haver 3 elements 
        throw out_of_range("No hi ha prous elements a la queue per fer aquest metode");
    }

    //aqui hacer como quedaria si hay 4 elementos porque el 3 seria el penultimo
    if(this->size() == 4){
        throw invalid_argument("Com hi ha 4 elements el swap quedaria igual");
    }
    //creamos nodo para la penultima posicion y para la tercera
    SingleNode<Element>* penultimo = new SingleNode<Element>();
    SingleNode<Element>* tercer = new SingleNode<Element>();
    tercer = _first->getNext()->getNext(); //guardamos la tercera posicion, que va a ir en la penultima
    penultimo = _first; //asignamos first porque vamos a ir recorriendo la lista
    while(penultimo->getNext()->getNext() != nullptr){
        penultimo->setNext(penultimo->getNext());
    }
    //aqui ya tenemos la posicion penultima guardada, ahora tenemos que hacer el intercanvio
    //si tenemos exactamente 3 elementos tenemos que cambiar el orden de la segunda y la tercera poscion
    if(this->size() == 3){
        _first->setNext(tercer);
        tercer->setNext(penultimo);
    }else{
        _first->getNext()->setNext(penultimo); //la segona posició te com a seguent el penultim
        //el anterior al penultimo lo tiene que apuntar a el tercero
        penultimo->setNext(tercer); //aixo deu estar malament pero no se com accedir al anterior del penultim sense crear una nova variable
        //y el tercero al ultimo
        tercer->setNext(_last);
    }
}



/*
 * Metode dequeueIfExists
 * Elimina de la cua TOTES les aparicions de l'element e
 */
// Code here 
template <class Element>
void SpecialQueue<Element>::dequeueIfExists(Element e){
    //Comprobacions
    if(isEmpty()){
        throw out_of_range("No hi ha cap valor a la queue");
    }
    //creamos un nodo para recorrer la queue, i que tenga el _first
    SingleNode<Element>* tmp = _first;
    //ahora recoremos mientras el proximo no sea nullptr, comprobamos si es el valor que buscamos i luego seguimos avanzando en el bucle para salir de él
    while(tmp->getNext() != nullptr){
        if(tmp->getNext()->getElement() == e){ //comprobamos si el elemento siguiente es igual al valor
            tmp->setNext(tmp->getNext()->getNext()) //saltamos 2 posiciones, ejemplo si e = 2 y yo tengo 1,2,3 quiero hacer que el next del 1 sea el 3
        }
        tmp->setNext(tmp->getNext());
    }
}

