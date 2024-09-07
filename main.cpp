#include<iostream>
#include "Movie.hpp"
// #include "Functions.cpp"
#include "Cinema.hpp"
using namespace std;

CinemaC cinema = *CinemaC::GetCinemaInst();
int main ()
{
    int movie_choice, showtime_choice;
    string seat_choice;
    MovieC movie;
    vector<MovieC> movies = movie.CreateMovies();
    cinema.CreateHalls(3);
    for (auto& movie : movies) {
        cinema.AddMovie(movie);
    }
    cinema.AssignMoviesToHalls();
    cinema.GetMovies();
    cout<<"choose a movie to see its showtimes: ";
    cin>> movie_choice;
    cinema.get_movie_ShowTime(movie_choice-1);
    cout<<"choose showtimes You want: ";
    cin>> showtime_choice;

    int hall_num = cinema.GetHallNumber(movie_choice-1, showtime_choice-1);
    cinema.DisplayHall(hall_num);
    string s = "y";
    while (s == "y") 
    {
        
         cout<<"choose Seat You want: ";
         cin>> seat_choice;
         cinema.ReserveSeat(hall_num, movie_choice-1, showtime_choice-1, seat_choice);
         cout<<"Do you want to reserve another seat? (y/n): ";
         cin>>s;


    }
    
    


    
    
    return 0;
}