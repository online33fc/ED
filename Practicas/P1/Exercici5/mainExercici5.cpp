#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include "Estudiant.h"
#include "Professor.h"

using namespace std;

int main(int argc, char** argv) {
    int num, comptadorE = 0, comptadorP = 0, comptador = 1, any = 0, asignatures = 0;
    string nom;
    char lletra;
    Estudiant estudiant;
    Professor professor;
    vector<string> arr_options {" 1. Sortir", " 2. Afegir persona", " 3. Llegir fitxer", " 4. Resum persones"};
    ifstream archivo("dades.txt"); //crear aquest arxiu
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
                
                cout << "Prem la lletra P per crear professor o la lletra E per crear estudiant ";
                cin >> lletra;

                switch (lletra){
                case 'E':
                    try{
                        cout << '\n' << endl;
                        cout << "Estudiant " << comptador << endl;
                        estudiant.demanarDades();
                        estudiant.print();
                        cout << "\nEdat del nou estudiant: " << estudiant.getEdat() << endl; 
                        comptador++;
                        comptadorE++;
                    }
                    catch(invalid_argument& e ) {
                        cout << e.what() << endl;
                        cout << "S’ha produit una excepcio" << endl;
                    }
                
                    break;
                
                case 'P':
                    try {
                        cout << '\n' << endl;
                        cout << "Professor " << comptador <<endl;
                        professor.demanarDades();
                        professor.print();
                        cout << "\nEdat del nou professor: " << professor.getEdat() << endl; 
                        comptador++;
                        comptadorP++;
                    } 
                    catch (invalid_argument& e) {
                        cout << "Error: " << e.what() << endl;
                    }

                break;
                
                    
                
                default:
                    cout << "Caracter incorrecte " << endl;
                    break;
                } 
                
                break;

            case 3:
                if(!archivo){
                    throw runtime_error("No s'ha pogut obrir el fitxer\n");
                }

                while (!archivo.eof()){
                    archivo>>lletra;
                    if (lletra == 'E'){
                       archivo >> nom >> any >> asignatures;
                       Estudiant(nom, any, asignatures);
                    } else if(lletra == 'P'){
                        archivo >> nom >> any;
                        Professor(nom, any);
                    }else{
                        throw runtime_error("Tipus de persona Incorrecte");
                    }
                    
                }
                archivo.close();
                break; 

            case 4:
                cout << "Estudiants creats: " << comptadorE << " Professors creats: " << comptadorP << endl;
                break; 

                
            default:
                cout << "Opcio incorrecte" << endl;
                
                break;  
        }
    }while(num != 0);
  
    return 0;
}