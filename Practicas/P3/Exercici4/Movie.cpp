#include "Movie.h"
#include <iostream>
#include <string>
#include <stdexcept> 

using namespace std;

Movie::Movie() {
    movieID = 0;
    title = "";
    rating = 0.0f;
}

Movie::Movie(int movieID, string title, float rating){
    this->movieID = movieID;
    this->title = title;
    this->rating = rating;
}

Movie::Movie(const Movie& orig){
    this->movieID = orig.movieID;
    this->title = orig.title;
    this->rating = orig.rating;
}

int Movie::getMovieID() const{
    return movieID;
}

string Movie::getTitle() const{
    return title;
}

float Movie::getRating() const{
    return rating;
}

void Movie::setMovieID(int _movieID){
    movieID = _movieID;
}

void Movie::setTitle(string _title){
    title = _title;
}

void Movie::setRating(float _rating){
    rating = _rating;
}

string Movie::toString() const{
    return "MovieID: " + to_string(movieID) + ", title: " + title + ", Rating: " + to_string(rating);
}

void Movie::print() const{
    cout << "( " << movieID << "::" << title << "::" << rating << " )" << endl; 
}