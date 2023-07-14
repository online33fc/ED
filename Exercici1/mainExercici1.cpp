#include<iostream>
#include <cstdlib>

using namespace std;

int main(){
	string nom;
	int num;
	string arr_options[] = {"Sortir", "Benvinguda"};

	cout << "Hola, com et dius? ";
	cin >> nom;
	cout << "Hola, " << nom << " que vols fer?" <<endl;

	do{
        for(int i = 0; i < 2; i++){
            cout << ' ' << i+1 << ". "<< arr_options[i]  << endl;
        }

        cin >> num;
        switch(num){
            case 1:
                num = 0; //li dono el valor de 0 d'aquesta manera acaba el bucle quan selecciono la primera opció
                cout << "Fins a la propera " << nom <<endl;
                break;

            case 2:
                cout << "Benvingut/da a l'assignatura d'estructura de dades " << nom << endl;
                break;
				
            default:
                break;  
        }

    }while(num != 0);
	
	return 0;
}