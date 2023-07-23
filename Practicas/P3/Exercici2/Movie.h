#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Movie {
public:
    Movie();
    Movie(int movieID, string title, float rating);
    Movie(const Movie& orig);
    int getMovieID() const;
    string getTitle() const;
    float getRating() const;
    void setMovieID(int _movieID);
    void setTitle(string _title);
    void setRating(float _rating);
    string toString() const;
    void print() const;

private:
    int movieID;
    string title;
    float rating;
        
};

#endif // MOVIE_H