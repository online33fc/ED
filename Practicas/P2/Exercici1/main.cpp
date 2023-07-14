#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "PilaEstatica.h"

using namespace std;

void casProva1(){
    PilaEstatica* q = new PilaEstatica(3);
    cout << "Estructura creada" <<endl;
    q->afegirElement(10);
    q->afegirElement(11);
    q->elementFront();
    q->afegirElement(12);
    try{
        q->afegirElement(13);
    }catch (string e){
        cout << e << endl;
    }
    q->imprimeix();
    q->elementFront();
    q->treureElement();
    q->afegirElement(14);
    q->imprimeix();
    q->elementFront();
    q->treureElement();
    q->treureElement();
    q->treureElement();
    try{
        q->treureElement();
    }catch (string e){
        cout << e << endl;
    }
    
}

int main(int argc, char** argv) {
    int num, element;
    PilaEstatica* q = new PilaEstatica(3); // no se si ha de ser aixi
    casProva1(); 
    vector<string> arr_options {" 1. Inserir element a la pila", " 2. Treure element de la pila", " 3. Consultar el top de la pila",
     " 4. Imprimir tot el contingut de la PilaEstatica", " 5. Imprimir la posició del top de la pila", " 6. Sortir"};
    cout << "Hola, que vols fer?" << endl;
    
    do{
        for(vector<string>::const_iterator it = arr_options.begin(); it != arr_options.end(); ++it){
            cout << ' ' << *it;
            cout << '\n';
        }  
        cin >> num;

        switch(num){

            case 1:
                cout << "quin element vols insertar " << endl;
                cin >> element;
                q->afegirElement(element);
                break;
            
            case 2:
                q->treureElement();
                break;

            case 3:
                q->elementFront();
                break; 

            case 4:
                q->imprimeix();
                break; 
            
            case 5:
                q->elementFront();
                break;

            case 6:
                cout << " " << endl; 
                break;

            default:
                cout << "Opcio incorrecte" << endl;
                break;  
        }

    }while(num != 6);
    
    delete q;
    return 0;
}