#include <string>
#include <iostream>
#include "Functions.h"
using namespace std;


class Ticket {
public:
    Ticket(const string& seatNumber, int hall_num, int price, ShowTimeS showTime, const string& movie_name) 
    : seatNumber(seatNumber), hall_number(hall_num), price(price), showTime(showTime), movie_name(movie_name) {}

    void DisplayTicket() {
        cout << "Ticket Information" << endl;
        cout << "Movie Name: " << movie_name << endl;
        cout << "Hall Number: " << hall_number;
        cout << "    Seat Number: " << seatNumber << endl;
        cout << "Price: " << price << endl;
        cout << "Show Time: " <<dayToString(showTime.m_movieDay) <<"  "<<timeToString(showTime.m_time) << endl;
    }


private:
    string seatNumber;
    int hall_number;
    int price;
    ShowTimeS showTime;
    string movie_name;
    string user_mail;
};