#include "Movie.hpp"
#include "Functions.cpp"

string MovieC::GetGenreStr()
{
    string genreStr = "";
    for(const auto& genre : m_genre) {
        genreStr += (m_genreStr.at(genre) + ", ");
    }
    if(!(genreStr.empty())) {
        genreStr.pop_back();
        genreStr.pop_back();
    }
    return genreStr;
}

MovieBuilder& MovieBuilder::SetTitle(const string& title) { m_title = title; return *this; }


MovieBuilder& MovieBuilder::SetGenre(const vector<MovieGenreE>& genre) { m_genre = genre; return *this; }


MovieBuilder& MovieBuilder::AddGenre(MovieGenreE genre) { m_genre.emplace_back(genre); return *this; }


MovieBuilder& MovieBuilder::SetRating(float rating) { m_rating = rating; return *this; }


MovieBuilder& MovieBuilder::AddShowTime(const ShowTimeS& showTime) { m_showTimes.emplace_back(showTime); return *this; }


MovieC MovieBuilder::Build() { return MovieC(m_title, m_genre, m_rating, m_showTimes); }

vector<MovieC> MovieC::CreateMovies()
{
    vector<MovieC> movies;
    MovieBuilder movieBuilder;
    movies.push_back(movieBuilder.SetTitle("Mr Ben").AddGenre(MovieGenreE::COMEDY).SetRating(8.5)
           .AddShowTime({DayE::SUNDAY, TimeE::TWELVE_PM}).AddShowTime({DayE::SUNDAY,TimeE::NINE_AM}).Build());
   
    MovieBuilder movieBuilder1;
    movies.push_back(movieBuilder1.SetTitle("Joker 2").AddGenre(MovieGenreE::DRAMA).SetRating(7.2)
            .AddShowTime({DayE::MONDAY, TimeE::THREE_PM}).AddShowTime({DayE::TUESDAY,TimeE::NINE_AM}).Build());
   
    MovieBuilder movieBuilder2;
    movies.push_back(movieBuilder2.SetTitle("Ghosted").AddGenre(MovieGenreE::ACTION).SetRating(9.0)
            .AddShowTime({DayE::SATURDAY,TimeE::NINE_AM}).AddShowTime({DayE::SATURDAY,TimeE::SIX_PM}).Build());
   
    MovieBuilder movieBuilder3;
    movies.push_back(movieBuilder3.SetTitle("The Conjuring").AddGenre(MovieGenreE::HORROR).SetRating(6.5)
            .AddShowTime({DayE::THURSDAY,TimeE::NINE_AM}).AddShowTime({DayE::THURSDAY,TimeE::TWELEVE_AM}).Build());
   
    MovieBuilder movieBuilder4;
    movies.push_back(movieBuilder4.SetTitle("The Old Guard").AddGenre(MovieGenreE::ACTION).SetRating(8.0)
            .AddShowTime({DayE::WEDNESDAY,TimeE::NINE_AM}).AddShowTime({DayE::WEDNESDAY,TimeE::TWELEVE_AM}).Build());
    return movies;
}

void MovieC::Displayshowtimes()
{
    int cnt =1;
    cout<<this->m_title<<endl;
    for(auto i : this->m_showTimes){
        cout <<cnt<< ")Day: " << dayToString(i.m_movieDay) << " Time: " << timeToString(i.m_time) << endl;
        cnt++;
    }
}