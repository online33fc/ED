#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>
#include "NodeHeap.h"
using namespace std;

template<class Clau, class Valor>
class MinHeap {
    public:
        MinHeap(); // constructor
        MinHeap(const MinHeap<Clau,Valor>& orig); // constructor còpia
        int tamany(); // retorna el nombre d'elements que hi ha al heap
        bool esBuit(); // retorna cert si és buit, fals en cas contrari
        void inserir(const Clau& clau, const Valor& valor);
        Clau minim(); // retorna la clau mínima
        Valor valorMinim(); // retorna el valor de la clau mínima
        void eliminaMinim(); // elimina el node amb valor minim
        void imprimir(); // Imprimeix per pantalla tot el Heap, una línia per a cada nivellde l'arbre
        Valor cerca(const Clau& clau); // cerca al heap una clau donada
        int altura(); // retorna l'alçada del heap

    private:
        vector<NodeHeap<Clau, Valor> > data;
        int mida;
        // aquí sota definiu les funcions auxiliars
        void heapifyDown(int index);
};

template<class Clau, class Valor>
MinHeap<Clau, Valor>::MinHeap(){
    this->mida = 0;
}

template<class Clau, class Valor>
MinHeap<Clau, Valor>::MinHeap(const MinHeap<Clau, Valor>& orig){
    this->mida = orig.mida; 
    this->data = orig.data;
}

template<class Clau, class Valor>
int MinHeap<Clau, Valor>::tamany(){
    return mida;
}

template<class Clau, class Valor>
bool MinHeap<Clau, Valor>::esBuit(){
    return mida == 0;
}

template<class Clau, class Valor>
void MinHeap<Clau, Valor>::inserir(const Clau& clau, const Valor& valor){
    NodeHeap<Clau, Valor> node(clau);
    node.setValue(valor);


    data.push_back(node);
    mida++;

    int actualIndex = mida-1;
    int parentIndex = (actualIndex-1)/2;

    while(actualIndex > 0 && data[actualIndex].getKey() < data[parentIndex].getKey()){
        swap(data[actualIndex], data[parentIndex]);
        actualIndex = parentIndex;
        parentIndex = (actualIndex-1)/2;
    }

    heapifyDown(0);
}

template<class Clau, class Valor>
Clau MinHeap<Clau, Valor>::minim(){
    if(esBuit()){
        throw invalid_argument("El heap es buit");
    }
    
    return data[0].getKey(); 
}

template<class Clau, class Valor>
Valor MinHeap<Clau, Valor>::valorMinim(){
    if(esBuit()){
        throw invalid_argument("El heap es buit ");
    }
    return data[0].getValue();
}

template<class Clau, class Valor>
void MinHeap<Clau, Valor>::eliminaMinim(){
    if(esBuit()){
        throw invalid_argument("El heap es buit");
    }

    NodeHeap<Clau, Valor> aux = data[0];
    data[0] = data[mida-1];
    mida--;
    heapifyDown(0);
}

template<class Clau, class Valor>
void MinHeap<Clau, Valor>::imprimir(){
    cout << "[";
    for(int i = 0; i< mida; i++){
        cout << "(" << data[i].getKey() << " " << data[i].getValue() << ")" << endl;
        if(i < mida-1){
            cout << ", ";
        }
    }
    cout << "]";
}

template<class Clau, class Valor>
Valor MinHeap<Clau, Valor>::cerca(const Clau& clau){
    for(int i = 0; i < mida; i++){
        if(data[i].getKey() == clau){
            return data[i].getValue();
        }
    }
}

template<class Clau, class Valor>
int MinHeap<Clau, Valor>::altura(){
    if(esBuit()){
        throw invalid_argument("Es buit ");
    }

    int n = mida;
    int nivells = log2(n + 1) -1;
    return nivells;
}

template<class Clau, class Valor>
void MinHeap<Clau, Valor>::heapifyDown(int index){
    int menor = index;
    int esquerra = 2 * index + 1;
    int dreta = 2 * index + 2;

    if(esquerra < mida && data[esquerra].getKey() < data[menor].getKey()){
        menor = esquerra;
    }

    if(dreta < mida && data[dreta].getKey() < data[menor].getKey()){
        menor = dreta;
    }

    if(menor != index) {
        std::swap(data[index], data[menor]);
        heapifyDown(menor);
    }
}

#endif // MINHEAP_H