#include <cstdlib>
#include <istream>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <string>
#include "Posicio.h"
#include "NodeLlista.h"
#include "Llista.h"

/*
1. Has implementat la Llista amb templates? Sigui quina sigui la teva resposta, justifica el motiu pel
qual has pres aquesta decisió.

Resposta:Sí, aixi no es depen d'un tipus de dada en concret

2. Has implementat el constructor amb l’initializer_list? Sigui quina sigui la teva resposta, justifica
el motiu pel qual has pres aquesta decisió.

3. Tenint en compte la teva implementació del TAD Llista, indica per a cadascuna de les operacions
del TAD Llista quin és el seu cost computacional teòric. Justifica la resposta.

La función tamany() tiene un coste computacional constante, O(1).
La función esBuida() tiene un coste computacional constante, O(1).
La función principi() tiene un coste computacional constante, O(1).
La función final() tiene un coste computacional constante, O(1).
La función rprincipi() tiene un coste computacional constante, O(1).
La función rfinal() tiene un coste computacional constante, O(1).
La función inserirDespres() tiene un coste computacional constante, O(1).
La función inserirAbans() tiene un coste computacional constante, O(1).
La función inserirPrincipi() tiene un coste computacional constante, O(1).
La función inserirFinal() tiene un coste computacional constante, O(1).
La función elimina() tiene un coste computacional constante, O(1).

4. Creieu que la classe NodeLlista hauria estat millor implementar-la amb encadenaments simples?
Justifica la teva resposta. 
Resposta:NO aumenta el cost d'algunes operacions
*/



int main() {
    int num_paraules;
    cout << "Introdueix quantes paraules vols inserir: ";
    cin >> num_paraules;

    Llista<string> llista;
    string paraula;
    NodeLlista<string>* node = new NodeLlista<string>(paraula);
    Posicio<string> posicio(node);


    for (int i = 0; i < num_paraules; ++i) {
        string paraula;
        cout << "Introdueix una paraula: ";
        cin >> paraula;

        char inserir_Principi;
        cout << "Inserir al principi? (s/n) ";
        cin >> inserir_Principi;

        if (inserir_Principi == 's') {
            llista.inserirPrincipi(paraula);
        } else {
            char inserir_Final;
            cout << "Inserir al final? (s/n) ";
            cin >> inserir_Final;

            if (inserir_Final == 's') {
                llista.inserirFinal(paraula);
            } else {
                string pos;
                cout << "A quina posicio vols inserir? ";
                cin >> pos;

                char abans_Posicio;
                cout << "Inserir abans de la posicio? (s/n) ";
                cin >> abans_Posicio;

                if (abans_Posicio == 's') {
                    llista.inserirAbans(posicio, paraula); 
                } else {
                    llista.inserirDespres(posicio, paraula);
                }
            }
        }
    }

    cout << "Iteracio (amb position) endavant:\n";
    for (Posicio<string> p = llista.principi(); p != llista.final(); ++p) {
        cout << p.element() << "\n";
    }

    cout << "Iteracio (amb position) endarrere:\n";
    for (Posicio<string> p = llista.rprincipi(); p != llista.rfinal(); --p) {
        cout << p.element() << "\n";
    }

    return 0;
}