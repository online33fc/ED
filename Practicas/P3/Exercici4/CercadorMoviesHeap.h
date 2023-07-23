#ifndef CERCADORMOVIESHEAP_H
#define CERCADORMOVIESHEAP_H

#include <iostream>
#include <stdexcept>
#include <fstream>
#include "Movie.h"
#include "MinHeap.h"
#include "NodeHeap.h"
using namespace std;

class CercadorMoviesHeap{
    public:
        CercadorMoviesHeap();
        CercadorMoviesHeap(const CercadorMoviesHeap & orig);
        virtual ~CercadorMoviesHeap();
        void appendMovies(string filename);
        void insertarMovie(int movieID, string title, float rating);
        string mostrarMovie(int movieID);
        Movie buscarMovie(int movieID);
        float buscarRatingMovie(int movieID);
        void eliminarMinimaMovie(int n);
        int height() const;
        //
        void imprimir40x40recursiu() const;

    private:
    // Aqui posareu tots els mètodes auxiliars
    MinHeap<int, Movie> heap;
    int heightAux(int index) const;
    void imprimir40x40recursiuAux(int index, int& contador) const; 
    
};

CercadorMoviesHeap::CercadorMoviesHeap(){}

CercadorMoviesHeap::CercadorMoviesHeap(const CercadorMoviesHeap & orig) : heap(orig.heap){}

CercadorMoviesHeap::~CercadorMoviesHeap(){}
  
void CercadorMoviesHeap::appendMovies(string filename){
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

void CercadorMoviesHeap::insertarMovie(int movieID, string title, float rating){ 
    Movie movie(movieID, title, rating);
    heap.inserir(movieID, movie);
}

string CercadorMoviesHeap::mostrarMovie(int movieID){
    Movie movie = buscarMovie(movieID);
    if (movie.getMovieID() != -1) {
        return movie.toString();
    } else {
        return "Movie not found";
    }
}

Movie CercadorMoviesHeap::buscarMovie(int movieID){
    return heap.cerca(movieID);
}

float CercadorMoviesHeap::buscarRatingMovie(int movieID){
    Movie movie = buscarMovie(movieID);
    if (movie.getMovieID() != -1) {
        return movie.getRating();
    } else {
        return -1.0f; // Movie no trobada
    }
}

void CercadorMoviesHeap::eliminarMinimaMovie(int n){
    for(int i = 0; i < n; i++){
        heap.eliminaMinim();
    }
}


int CercadorMoviesHeap::height() const{
    return heightAux(0); 
}

int CercadorMoviesHeap::heightAux(int index) const{
    if(index >= heap.tamany()){ 
        return -1;
    }else{
        int leftIndex = 2 * index + 1;
        int rightIndex = 2 * index + 2;

        int leftSubIndex = heightAux(leftIndex);
        int rightSubIndex = heightAux(rightIndex);

        return 1 + max(leftSubIndex, rightSubIndex);
    }
}

void CercadorMoviesHeap::imprimir40x40recursiu() const{
    int contador = 0;
    imprimir40x40recursiuAux(0, contador);
}

void CercadorMoviesHeap::imprimir40x40recursiuAux(int index, int& contador) const{
    if(index >= heap.tamany()){ 
        return;
    }
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;

    imprimir40x40recursiuAux(leftIndex, contador);

    cout << heap.valorMinim().toString();

    imprimir40x40recursiuAux(rightIndex, contador);
}

#endif // CERCADORMOVIESHEAP_H