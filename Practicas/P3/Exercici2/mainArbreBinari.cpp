#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <chrono>
#include <sstream>
#include "ArbreBinari.h"
#include "NodeBinari.h"
#include "CercadorMoviesAB.h"
#include "Movie.h"

using namespace std;

int main(int argc, char** argv) { 
    int num;
    ifstream file;
    CercadorMoviesAB cercador;
    
    
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
                cout << "Movies loaded successfully!" << endl;
                cout << "Insertion time: " << insertionTime << " seconds" << endl;
                break;
            }
            case 2: {
                cercador.imprimir40x40recursiu();
                break;
            }
            case 3: {
                ifstream file("cercaPelicules.txt");
                int contador = 0;
                int movieID;
                auto begin = chrono::steady_clock::now();
                
                while(file >> movieID){
                    Movie movie = cercador.buscarMovie(movieID); //no pasa d'aquesta linea
                    if (movie.getMovieID() != -1) {
                        contador++;
                    }
                }

                auto end = chrono::steady_clock::now();
                double tempsBusqueda = chrono::duration_cast<chrono::duration<double>>(end - begin).count();

                cout << "Temps de busqueda: " << tempsBusqueda << " segons" << endl;
                cout << "Numero de elements trobats: " << contador << endl;

                file.close();
                break;
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