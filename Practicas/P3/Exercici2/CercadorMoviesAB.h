#ifndef CERCADORMOVIESAB_H
#define CERCADORMOVIESAB_H

#include <iostream>
#include <stdexcept>
#include <fstream>
#include "Movie.h"
#include "ArbreBinari.h"
#include "NodeBinari.h"
using namespace std;

class CercadorMoviesAB: protected ArbreBinari<int, Movie>{
    public:
        CercadorMoviesAB();
        CercadorMoviesAB(const CercadorMoviesAB & orig);
        virtual ~CercadorMoviesAB();
        void appendMovies(string filename);
        void insertarMovie(int movieID, string title, float rating);
        string mostrarMovie(int movieID);
        Movie buscarMovie(int movieID);
        float buscarRatingMovie(int movieID);
        void eliminarMinimaMovie(int n);
        int height() const;
        void imprimir40x40recursiu() const;

    private:
    // Aqui posareu tots els mètodes auxiliars
    NodeBinari<int, Movie>* eliminarMinimaMovieAux(NodeBinari<int, Movie>* node);
    int heightAux(NodeBinari<int, Movie>* node) const;
    void imprimir40x40recursiuAux(NodeBinari<int, Movie>* node, int& contador) const;
    
};

CercadorMoviesAB::CercadorMoviesAB() : ArbreBinari<int, Movie>(){
    root = nullptr;
}

CercadorMoviesAB::CercadorMoviesAB(const CercadorMoviesAB & orig) : ArbreBinari<int, Movie>(orig){
    root = nullptr;
    if(orig.root != nullptr){
        root = new NodeBinari<int, Movie>(*orig.root);
    }
}

CercadorMoviesAB::~CercadorMoviesAB(){
    delete root;
}
  
void CercadorMoviesAB::appendMovies(string filename){
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open the file " << filename << endl;
        return;
    }

    int movieID;
    string title;
    float rating;

    while (file >> movieID >> title >> rating) {
        insertarMovie(movieID, title, rating);
    }

    file.close();

}

void CercadorMoviesAB::insertarMovie(int movieID, string title, float rating){
    //busco la pelicula
    if(search(movieID) != nullptr){
        throw invalid_argument("La pelicula ja existeix");
    }else{
        Movie movie(movieID, title, rating);
        insert(movieID, movie);
    }
    
}

string CercadorMoviesAB::mostrarMovie(int movieID){
    //aquest metode rep el ID i fa un cout de les dades
    NodeBinari<int, Movie>* node = search(movieID); //busco la peli
    //si no existeix el ID retorno un missatge d'error
    if(node == nullptr){
        throw invalid_argument("No existeix cap pelicula amb aquest ID");
    }
    return node->getValue().toString();
}

Movie CercadorMoviesAB::buscarMovie(int movieID){
    return this->search(movieID)->getValue();
}

float CercadorMoviesAB::buscarRatingMovie(int movieID){
    NodeBinari<int, Movie>* node = search(movieID);
    if(node == nullptr){
        return -1.0;
    }
    return node->getValue().getRating();
}

void CercadorMoviesAB::eliminarMinimaMovie(int n){
    for(int i = 0; i < n; i++){
        NodeBinari<int, Movie>* minNode = eliminarMinimaMovieAux(root);
        if(minNode != nullptr){
            //Elimina el minNode de l'arbre binari
            if(minNode == root){
                root = nullptr;
            }else{
                NodeBinari<int, Movie>* parent = minNode->getParent();
                if(parent != nullptr) {
                    if(parent->getLeft() == minNode){
                        parent->setLeft(nullptr);
                    }else{
                        parent->setRight(nullptr);
                    }
                }
            }
            delete minNode;
        }else{
            break;
        }
    }
}

NodeBinari<int, Movie>* CercadorMoviesAB::eliminarMinimaMovieAux(NodeBinari<int, Movie>* node){
    if(node == nullptr){
        throw invalid_argument("Es nullptr");
    }

    if(node->getLeft() != nullptr){
        node = node->getLeft();
    }
    return node;
}

int CercadorMoviesAB::height() const{
    if(root == nullptr){
        throw invalid_argument("Es buit");
    }else{
        return heightAux(root);
    }
}

int CercadorMoviesAB::heightAux(NodeBinari<int, Movie>* node) const{
    if(node == nullptr){
        return 0;
    }else{
        int nodeLeft = heightAux(node->getLeft());
        int nodeRight = heightAux(node->getRight());
        return 1 + max(nodeLeft, nodeRight);
    }
}

void CercadorMoviesAB::imprimir40x40recursiu() const{
    int contador = 0;
    imprimir40x40recursiuAux(root, contador);
}

void CercadorMoviesAB::imprimir40x40recursiuAux(NodeBinari<int, Movie>* node, int& contador) const{
    if(node != nullptr){
        imprimir40x40recursiuAux(node->getLeft(), contador);

        node->getValue().print();
        contador++;

        if(contador % 40 == 0){
            char resposta;
            cout << "Vols imprimir les seguents 40 pelicules? (S/N): " << endl;
            cin >> resposta;

            if(resposta == 'N' || resposta == 'n'){
                cout << "No imprimim mes pelicules " << endl;
            }
        }
        imprimir40x40recursiuAux(node->getRight(), contador);
    }
}

#endif // CERCADORMOVIESAB_H