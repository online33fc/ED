#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "MinHeap.h"
#include "NodeHeap.h"

using namespace std;

void casDeProvaExercici3() {
    std::cout << " ------------- cas de prova exercici 3 ----------- " << std::endl;
    MinHeap<int, int> heap1;

    int testKeys[] = {2, 0, 8, 45, 76, 5, 3, 40};
    int testValues[] = {5, 5, 1, 88, 99, 12, 9, 11};
    for (int i = 0; i < 8 ; i++) {
    heap1.inserir(testKeys[i], testValues[i]);
    }
    cout << "heap1 ={ ";
    heap1.imprimir();
    cout << "}" << endl;
    cout<<"Mida Heap recent creat: "<<heap1.tamany()<<endl;
    cout<<"Alçada Heap recent creat: "<<heap1.altura()<<endl;
    cout<<"Heap recent creat. is esBuit? (0/1): "<<heap1.esBuit()<<endl;
    cout << "Clau minima " << heap1.minim() << endl;

    cout << "EliminaMinim" << endl;
    heap1.eliminaMinim();
    cout<<"Heap despres eliminar 1. Print: "<<endl;
    heap1.imprimir();
    cout<<"Mida Heap recent creat: "<<heap1.tamany()<<endl;
    cout<<"Alçada Heap recent creat: "<<heap1.altura()<<endl;
    heap1.eliminaMinim();
    cout<<"Heap despres eliminar 2. Print: "<<endl;
    heap1.imprimir();
    cout<<"Mida Heap recent creat: "<<heap1.tamany()<<endl;
    cout<<"Alçada Heap recent creat: "<<heap1.altura()<<endl;
}

int main(int argc, char** argv) {
    casDeProvaExercici3();
    return 0;
}