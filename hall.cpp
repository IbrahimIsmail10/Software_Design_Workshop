#include <vector>
#include "seat.cpp"
#include <iostream>
#include <memory>
using namespace std;

class Hall {
private:
    int hallNum;
    vector<shared_ptr<Seat>> seats; 

public:
    Hall(int number) : hallNum(number) {}

    int getHallNumber() const {
        return hallNum;
    }

    void setHallNumber(int number) {
        hallNum = number;
    }

    void addSeat(const shared_ptr<Seat>& seat) {
        seats.push_back(seat);
    }

    shared_ptr<Seat> findSeat(const string& seatNumber) const {
        for (const auto& seat : seats) {
            if (seat->seatNumber == seatNumber) {
                return seat;
            }
        }
        return nullptr;
    }

    bool removeSeat(const string& seatNumber) {
        for (auto it = seats.begin(); it != seats.end(); ++it) {
            if ((*it)->seatNumber == seatNumber) {
                seats.erase(it);
                return true;
            }
        }
        return false;
    }

    bool isSeatAvailable(const string& seatNumber) const {
        auto seat = findSeat(seatNumber);
        return seat ? seat->isAvailable : false;
    }

    void displaySeats() const {
        int cnt =0;
        for (const auto& seat : seats) {
            if(cnt == 5){
                cnt=0;
                cout<<endl;               
            }
            cout<<seat->seatNumber<< (seat->isAvailable ? "  " : "(X)  ");
            cnt++;
        }
        cout<<endl;
    }

};
