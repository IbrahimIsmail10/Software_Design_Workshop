#include<iostream>
#include "Movie.hpp"
#include "Cinema.hpp"
using namespace std;

class Display
{
    public:
        void Show();
};

void Display::Show()
{
    CinemaC cinema = *CinemaC::GetCinemaInst();
    int movie_choice, showtime_choice;
    string seat_choice;
    MovieC movie;
    vector<MovieC> movies = movie.CreateMovies();
    cinema.CreateHalls(3);
    for (auto& movie : movies) {
        cinema.AddMovie(movie);
    }
    cinema.AssignMoviesToHalls();

    while (true)
    {
        cout<< "Welcome to Cinema"<<endl;
        cout<< "Choose an option: "<<endl;
        cout<< "1)Admin Login"<<endl;
        cout<< "2)User Login"<<endl;
        cout<< "3)Exit"<<endl;
        int choice;
        cin>>choice;
        if (choice == 1)
        {
            cout<< "1)showing all movies"<<endl;
            cout<< "2) Add Movie"<<endl;
            cout<< "3) Add Showtime"<<endl;
            cout<< "4) show all users watching movie "<<endl;
            cout<< "5) Exit"<<endl;
            int choice;
            cin>>choice;
            if (choice == 1)
            {
                cinema.GetMovies();
            }
            else if(choice == 2){
              //handle it later
            }

            else if(choice == 3){
                cout<<"choose a movie to add showtime: ";
                cinema.GetMovies();
                cin>> movie_choice;
                cout<<"Enter day of Showtime: ";
                cout<<"1) Saturday"<<endl;
                cout<<"2) Sunday"<<endl;
                cout<<"3) Monday"<<endl;
                cout<<"4) Tuesday"<<endl;
                cout<<"5) Wednesday"<<endl;
                cout<<"6) Thursday"<<endl;
                cout<<"7) Friday"<<endl;
                int showtime_day;
                cin>>showtime_day;
                cout<<"Enter Showtime: ";
                cout<<"1) 9 AM"<<endl;
                cout<<"2) 12 PM"<<endl;
                cout<<"3) 3 PM"<<endl;
                cout<<"4) 6 PM"<<endl;
                cout<<"5) 9 PM"<<endl;
                cout<<"6) 12 AM"<<endl;
                int showtime_time;
                cin>>showtime_time;
               ShowTimeS showtime = {static_cast<DayE>(showtime_day-1), static_cast<TimeE>(showtime_time-1)};
               showtime = static_cast<ShowTimeS>(showtime); // Remove the type, just assign the value

                cinema.AddShowTime(showtime, movie_choice-1);
            }
            else if(choice == 4){
                cout<<"choose a movie to show users: ";
                cinema.GetMovies();
                cin>> movie_choice;
                cinema.DisplayUsersWatchingMovie(movie_choice-1);
            }
            else{
                break;
            }

            
            
        }

        else if(choice == 2)
        {
            
            cout << "1) Reserve a seat" << endl;
            cout << "2) Show Movies You Watch Before" << endl;
            cout << "3) Exit" << endl;
            int choice;
            cin >> choice;
            if (choice == 1)
            {
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
            }
            else if (choice == 2)
            {
                cout << "Movies You Watch Before: " << endl;
                string username;
                cout << "Enter Your Username: ";
                cin >> username;
                cinema.userMoviesHistory(username);
            }
            else
            {
                break;
            }
                
        }
        else{
            break;
        }
    }     
}
