#ifndef CINEMA_HPP
#define CINEMA_HPP

#include <string>
#include <vector>
#include <memory>
#include "paymentfactory.cpp"
#include <map>
#include "hall.cpp"
#include "Movie.hpp"
#include "Common.hpp"
// #include "user.hpp"
using namespace std;

class CinemaC {
    public:
        static unique_ptr<CinemaC>& GetCinemaInst();
        void AddMovie(const MovieC& movie) { m_movies.emplace_back(movie);}
        void GetMovies() const { int cnt =1 ; for(auto i : m_movies) cout<<cnt++<<") "<<i.GetTitle()<<endl;}
        // void AddUser(const UserC& user) { m_users.emplace_back(user); }
        // const vector<UserC>& GetUsers() const { return m_users; }
        void CreateHalls(int numberOfHalls);
        void DisplayHall(int hall_num) const;
        void get_movie_ShowTime(int idx);
        void AssignMoviesToHalls();
        int GetHallNumber(int film_idx , int showtime_idx) const;
        void ReserveSeat(int hall_num, int movie_idx, int showtime_idx, const string& seatNumber);
        bool PaymentProcess(int price);
        
    private:
        static unique_ptr<CinemaC> m_cinemaInst;
    private:
        const vector<unsigned int> m_seatPrice = {
            {60, 90, 90, 130, 130, 90, 90, 60}
        };
        Payment *payment;
        // map<int, vector<pair<int, ShowTimeS>>> m_hallShowtimes;
        vector<MovieC> m_movies;
        // vector<UserC> m_users;
        vector<shared_ptr<Hall>> m_halls;
        const map<DayE, float> c_DayPrice = {
            {DayE::THURSDAY, 70},
            {DayE::FRIDAY, 70},
            {DayE::SATURDAY, 65},
            {DayE::SUNDAY, 40},
            {DayE::MONDAY, 30},
            {DayE::TUESDAY, 55},
            {DayE::WEDNESDAY, 30}
        };

        const map<TimeE, float> c_TimePrice = {
            {TimeE::NINE_AM, 5},
            {TimeE::TWELVE_PM, 8},
            {TimeE::THREE_PM, 2},
            {TimeE::SIX_PM, 15},
            {TimeE::NINE_PM, 25},
            {TimeE::TWELEVE_AM, 30}
        };

         const map<string, float> c_categoryPrice = {
            {"Regular", 5},
            {"Premium", 25},
            {"Gold", 30}
        };
};

#endif
