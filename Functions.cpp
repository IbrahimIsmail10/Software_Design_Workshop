#include"Functions.h"
using namespace std;


string dayToString(DayE day) {
    switch (day) {
        case DayE::SATURDAY: return "SATURDAY";
        case DayE::SUNDAY: return "SUNDAY";
        case DayE::MONDAY: return "MONDAY";
        case DayE::TUESDAY: return "TUESDAY";
        case DayE::WEDNESDAY: return "WEDNESDAY";
        case DayE::THURSDAY: return "THURSDAY";
        case DayE::FRIDAY: return "FRIDAY";
        default: return "UNKNOWN";
    }
}
string timeToString(TimeE time) {
    switch (time) {
        case TimeE::NINE_AM: return "9 AM";
        case TimeE::TWELVE_PM: return "12 PM";
        case TimeE::THREE_PM: return "3 PM";
        case TimeE::SIX_PM: return "6 PM";
        case TimeE::NINE_PM: return "9 PM";
        case TimeE::TWELEVE_AM: return "12 AM";
        default: return "UNKNOWN";
    }
}