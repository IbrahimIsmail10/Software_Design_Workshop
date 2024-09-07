#ifndef COMMON_HPP
#define COMMON_HPP

#include <array>
#include<functional>

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

    bool operator==(const ShowTimeS& other) const {
        return m_movieDay == other.m_movieDay && m_time == other.m_time;
    }
};

struct ShowTimeHash {
    size_t operator()(const ShowTimeS& showTime) const {
        int value1 = (int)showTime.m_movieDay;
        int value2 = (int)showTime.m_time;

        size_t hash1 = hash<int>{}(value1);
        size_t hash2 = hash<int>{}(value2);
        return hash1 ^ (hash2 << 1);
    }
};
#endif