#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "ArbreBinari.h"
#include "NodeBinari.h"

using namespace std;

void CasDeProva(){ 
    try{
    //Pas 1
    ArbreBinari<int, int> tree1;

    //Pas 2
    int testKeys[] = {2, 0, 8, 45, 76, 5, 3, 40};
    int testValues[] = {5, 5, 1, 88, 99, 12, 9, 11};
    for(int i = 0; i < 8 ; i++){
        tree1.insert(testKeys[i], testValues[i]);
    }

    //Pas 3
    cout<<"PreOrder = {";
    tree1.imprimirPreordre();
    cout<<"} \n";

    //Pas 4
    cout<<"InOrder = {";
    tree1.imprimirInordre();
    cout<<"} \n";

    //Pas 5
    cout<<"PostOrder = {";
    tree1.imprimirPostordre(); 
    cout<<"} \n";

    //Pas 6
    cout<<"Els valors del rang 5, 45 son... ";
    tree1.obteValorsRang(5,45);
    
    //Pas 7
    ArbreBinari<int, int> tree2(tree1);
    
    //Pas 8
    tree2.imprimirCami(40);

    //Pas 9
    tree2.eliminaMinim(); 
    tree2.imprimirInordre();

    //Pas 10
    }catch(invalid_argument & e){
        cout<<"Error: "<<e.what()<<endl;
    }
}

int main(int argc, char** argv) {
    CasDeProva();
    return 0;
}