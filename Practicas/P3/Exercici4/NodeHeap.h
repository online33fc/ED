#ifndef NODEHEAP_H
#define NODEHEAP_H

#include <iostream>
#include <stdexcept>
using namespace std;

template<class Clau, class Valor>
class NodeHeap {
    public: 
        NodeHeap(const Clau& key);
        //NodeHeap(const NodeHeap<Clau,Valor >& orig);
        

        /* Modificadors */
        void setKey(Clau _key);
        void setValue(Valor _value);

        /* Consultors */
        const Clau& getKey() const;
        const Valor& getValue() const;
        
    private:
        Clau key;
        Valor value;
};

template <class Clau, class Valor>
NodeHeap<Clau, Valor>::NodeHeap(const Clau& key){
    this->key = key;
    this->value = value;
}

template <class Clau, class Valor>
const Clau& NodeHeap<Clau, Valor>::getKey() const{
    return key;
}

template <class Clau, class Valor>
const Valor& NodeHeap<Clau, Valor>::getValue() const{
    return value;
}

template <class Clau, class Valor>
void NodeHeap<Clau, Valor>::setKey(Clau _key){
    key = _key;
}

template <class Clau, class Valor>
void NodeHeap<Clau, Valor>::setValue(Valor _value){
    value = _value;
}

#endif // NODEHEAP_H