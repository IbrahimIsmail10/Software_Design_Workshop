#ifndef COMMON_HPP
#define COMMON_HPP

#include <array>
#include <map>

using namespace std;

const unsigned int c_NumRows = 4;
const unsigned int c_NumCols = 8;

// Aliases
using seatsArr = array<array<bool, c_NumCols>, c_NumRows>;

enum class DayE {
    SATURDAY,
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
};


enum class TimeE {
    NINE_AM,
    TWELVE_PM,
    THREE_PM,
    SIX_PM,
    NINE_PM,
    TWELEVE_AM
};

enum class HallE {
    HALL_1,
    HALL_2,
    HALL_3
};

enum class MovieGenreE {
    ACTION,
    COMEDY,
    DRAMA,
    THRILLER,
    HORROR,
    SCIENCE_FICTION,
    ROMANCE
};

struct ShowTimeS {
    DayE m_movieDay;
    TimeE m_time;
};
#endif