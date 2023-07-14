#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "Estudiant.h"

using namespace std;

int main(int argc, char** argv) {
    int num, comptador = 1;
    Estudiant estudiant;
    vector<string> arr_options {" 1. Sortir", " 2. Informar estudiant"};
    cout << "Hola, que vols fer?" << endl;
    
    do{
        for(vector<string>::const_iterator it = arr_options.begin(); it != arr_options.end(); ++it){
            cout << ' ' << *it;
            cout << '\n';
        }  
        cin >> num;

        switch(num){
            case 1:
                num = 0;
                cout << "Fins la propera" << endl;
                break;

            case 2:
                try{
                    cout << '\n' << endl;
                    cout << "Estudiant " << comptador << endl;
                    estudiant.demanarDades();
                    estudiant.print();
                    cout << "\nEdat del nou estudiant: " << estudiant.getEdat() << endl; 
                    comptador++;
                }
                catch(invalid_argument& e ) {
                    cout << e.what() << endl;
                    cout << "S’ha produit una excepcio" << endl;
                }
                
                break;
            default:
                cout << "Opcio incorrecte" << endl;
                
                break;  
        }
    }while(num != 0);
  
    return 0;
}