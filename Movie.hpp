#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <string>
#include <vector>
#include <unordered_map>

#include "Common.hpp"

using namespace std;



class MovieC {
    public:
        MovieC() = default;
        MovieC(const string& title, const vector<MovieGenreE>& genre, float rating, const vector<ShowTimeS>& showTimes) : 
            m_title(title), m_genre(genre), m_rating(rating), m_showTimes(showTimes)
        {}
        void SetTitle(const string& title) { m_title = title; }
        const string& GetTitle() const { return m_title; }
        void SetGenre(const vector<MovieGenreE>& genre) { m_genre = genre; }
        void AddGenre(MovieGenreE genre) { m_genre.emplace_back(genre); }
        const vector<MovieGenreE>& GetGenreVec() const { return m_genre; }
        void SetRating(float rating) { m_rating = rating; }
        const float& GetRating() const { return m_rating; }
        void AddShowTime(const ShowTimeS& showTime) { m_showTimes.emplace_back(showTime) ; }
        const vector<ShowTimeS>& GetShowTime() const { return m_showTimes; }
        string GetGenreStr();
        vector<MovieC> CreateMovies();
        void Displayshowtimes();
        ShowTimeS GetShowTimeByIdx(int idx) const { return m_showTimes[idx]; }

    private:
        string m_title;
        vector<MovieGenreE> m_genre;
        float m_rating;
        vector<ShowTimeS> m_showTimes;
        const unordered_map<MovieGenreE, string> m_genreStr = {
            { MovieGenreE::ACTION,              "Action"           },
            { MovieGenreE::COMEDY,              "Comedy"           },
            { MovieGenreE::DRAMA,               "Drama"            },
            { MovieGenreE::THRILLER,            "Thriller"         },
            { MovieGenreE::HORROR,              "Horror"           },
            { MovieGenreE::SCIENCE_FICTION,     "Science fiction"  },
            { MovieGenreE::ROMANCE,             "Romance"          }
        };
};

class MovieBuilder {
    public:
        MovieBuilder& SetTitle(const string& title);
        MovieBuilder& SetGenre(const vector<MovieGenreE>& genre);
        MovieBuilder& AddGenre(MovieGenreE genre);
        MovieBuilder& SetRating(float rating);
        MovieBuilder& AddShowTime(const ShowTimeS& showTime);
        MovieC Build();
    private:
        string m_title;
        vector<MovieGenreE> m_genre;
        float m_rating;
        vector<ShowTimeS> m_showTimes;
};

#endif