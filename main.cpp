#include<iostream>
#include "Movie.hpp"
// #include "Functions.cpp"
#include "Cinema.hpp"
using namespace std;

CinemaC cinema = *CinemaC::GetCinemaInst();
int main ()
{;
    MovieC movie;
    vector<MovieC> movies = movie.CreateMovies();
    cinema.CreateHalls(3);
    for (auto& movie : movies) {
        cinema.AddMovie(movie);
    }
    cinema.GetMovies();
    int choice ;
    cout<<"choose a movie to see its showtimes: ";
    cin>> choice;
    cinema.get_movie_ShowTime(choice-1);

    
    
    return 0;
}