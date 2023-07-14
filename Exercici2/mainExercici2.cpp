#include<iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main(){
	string nom;
	int num;
	vector<string> arr_options {"1. Sortir", "2. Benvinguda", "3. Redefinir el nom"}; //convertir en vector

	cout << "Hola, com et dius? ";
	cin >> nom;
	cout << "Hola, " << nom << " que vols fer?" <<endl;

	do{
        
        for(vector<string>::const_iterator it = arr_options.begin(); it != arr_options.end(); ++it){
            cout << ' ' << *it;
            cout << '\n';
        }

        cin >> num;
        switch(num){
            case 1:
                num = 0; //li dono el valor de 0 d'aquesta manera acaba el bucle quan selecciono la primera opció
                cout << "Fins a la propera" << nom <<endl;
                break;

            case 2:
                cout << "Benvingut/da a l'assignatura d'estructura de dades " << nom << endl;
                break;

            case 3:
                cout << "Hola, com et dius? ";
                cin >> nom;
                cout << "Hola, " << nom << " que vols fer?" <<endl;
                break;

            default:
                break;  
        }
		
    }while(num != 0);
	
	return 0;
}