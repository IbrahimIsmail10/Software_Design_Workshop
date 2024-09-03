#ifndef CINEMA_HPP
#define CINEMA_HPP

#include <string>
#include <vector>
#include <memory>

// #include <optional>
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
        void DisplaySeats() const;
        void get_movie_ShowTime(int idx);
    private:
        static unique_ptr<CinemaC> m_cinemaInst;
    private:
        const vector<unsigned int> m_seatPrice = {
            {60, 90, 90, 130, 130, 90, 90, 60}
        };
        vector<MovieC> m_movies;
        // vector<UserC> m_users;
        vector<shared_ptr<Hall>> m_halls;
        map<int, vector<pair<int, ShowTimeS>>> m_hallShowtimes;
        const map<DayE, float> c_DayPrice = {
            {DayE::THURSDAY, 70},
            {DayE::FRIDAY, 70},
            {DayE::SATURDAY, 64},
            {DayE::SUNDAY, 40},
            {DayE::MONDAY, 20},
            {DayE::TUESDAY, 15},
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
};

#endif
