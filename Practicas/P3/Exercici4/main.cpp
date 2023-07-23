#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <chrono>
#include "MinHeap.h"
#include "NodeHeap.h"
#include "CercadorMoviesHeap.h"
#include "Movie.h"

using namespace std;

/*

*/

/*

EXERCICI 5: El temps d'insercio es mes rapid en un heap que en un arbre degut a que un heap es 
una estructura mes compacta i que es pot tractar similar a un array

* Nota *: no tinc l'altre part del exercici perque no he sigut capaç de fer que funcionesin el cases
que es necesitaven a l'exercici 2 i 4

Operació              | ArbreBinari                                      |  MinHeap
-----------------------------------
insercio Arbre petit  | Temps transcorregut: 0.0014834 segons            | Temps transcorregut: 0.0014864 segons
movie_rating_small.txt| Temps transcorregut: 0.0016667 segons            | Temps transcorregut: 0.0002434 segons
                      | Temps transcorregut: 0.0016743 segons            | Temps transcorregut: 0.0004648 segons
                      | Temps transcorregut: 0.0015857 segons            | Temps transcorregut: 0.0004847 segons
                      | Temps transcorregut: 0.001678 segons             | Temps transcorregut: 0.0004467 segons
-----------------------------------
Inserció arbre gran   | Temps transcorregut: 0.0018633 segons            | Temps transcorregut: 0.0003207 segons
movie_rating.txt      | Temps transcorregut: 0.0015391 segons            | Temps transcorregut: 0.0003964 segons
                      | Temps transcorregut: 0.0018824 segons            | Temps transcorregut: 0.0004505 segons
                      | Temps transcorregut: 0.0016295 segons            | Temps transcorregut: 0.0004205 segons
                      | Temps transcorregut: 0.0019444 segons            | Temps transcorregut: 0.0004443 segons
---------------------------------
Cerca arbre petit     |                                                  |
cercaPelicules.txt    |                                                  |
                      |                                                  |
                      |                                                  |
                      |                                                  |
-------------------------------
Cerca arbre gran      |                                                  |
cercaPelicules.txt    |                                                  |
                      |                                                  |
                      |                                                  |
                      |                                                  |


*/

int main(int argc, char** argv) { 
    int num;
    ifstream file;
    CercadorMoviesHeap cercador;
    
    
    vector<string> arr_options {" 1. Demanar a l'usuari el nom del fitxer", " 2. Mostrar l'arbre segons l'ID en ordre creixent", " 3. Llegir el fitxer",
     " 4. Visualitzar la profunditat de l'arbre", " 5. Esborrar les n pel·licules", " 6. Sortir del programa"};
    cout << "Hola, que vols fer?" << endl;
    
    do{
        for(vector<string>::const_iterator it = arr_options.begin(); it != arr_options.end(); ++it){
            cout << ' ' << *it;
            cout << '\n';
        }  
        cin >> num;

        switch (num) {
            case 1: {
                char resposta;
                string filename;
                cout << "Quin fitxer vols (P/G)?" << endl;
                cin >> resposta;

                
                if(resposta == 'P'){
                    filename = "movie_rating_small.txt";
                }else if(resposta == 'G'){
                    filename = "movie_rating.txt";
                }else{
                    cout << "Lletra invalida " <<endl;
                    break;
                }

                file.open(filename);
                if(!file.is_open()){
                    cout << "No s'ha pogut obrir l'arxiu " <<endl;
                } 
                

                auto begin = chrono::steady_clock::now();
                cercador.appendMovies(filename);
                auto end = chrono::steady_clock::now();
                double insertionTime = chrono::duration_cast<chrono::duration<double>>(end - begin).count();
                cout << "Movies carregades correctament!" << endl;
                cout << "Temps transcorregut: " << insertionTime << " segons" << endl;
                break;
            }
            case 2: {
                cercador.imprimir40x40recursiu();
                break;
            }
            case 3: {
                int movieID;
                int contador = 0;

                auto begin = chrono::steady_clock::now();
                cercador.buscarMovie(movieID);
                auto end = chrono::steady_clock::now();
                double tempsBusqueda = chrono::duration_cast<chrono::duration<double>>(end - begin).count();

                cout << "Temps busqueda: " << tempsBusqueda << " segons" << endl;
                cout << "Numero de elements trobats: " << contador << endl;

            }
            case 4: {
                try {
                    int Depth = cercador.height();
                    cout << "La profunditat es: " << Depth << endl;
                } catch (const exception& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 5: {
                int n;
                cout << "Digues quantes movies vols eliminar: ";
                cin >> n;
                cercador.eliminarMinimaMovie(n);
                cout << "Movies eliminades correctament" << endl;
                break;
            }
            case 6: {
                cout << "Sortir del programa" << endl;
                break;
            }
            default: {
                cout << "Aquesta opcio no es valida" << endl;
                break;
            }
        }

    }while(num != 6);
    
    return 0;
}