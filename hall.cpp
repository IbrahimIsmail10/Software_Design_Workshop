#include <vector>
#include "seat.cpp"
#include <iostream>
#include <memory>
#include <unordered_set>
#include "Common.hpp"
using namespace std;

class Hall {
private:
    int hallNum;
    vector<shared_ptr<Seat>> seats; 
    unordered_map<int, std::unordered_set<ShowTimeS, ShowTimeHash>> movieShowtimes;

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
        return seat->isSeatAvailable();
    }

    void displayHall() const {
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

     bool isHallFree(const ShowTimeS& showTime) const {
        int totalShowTimes = 0;
        for (const auto& entry : movieShowtimes) {
            totalShowTimes += entry.second.size(); 
        }
        return totalShowTimes < 3;
    }

    bool Assign_ShowTime_To_Hall(int movieIndex, const ShowTimeS& showTime) {

        if (isHallFree(showTime)) {
           auto flag =  movieShowtimes[movieIndex].insert(showTime);
           if (flag.second)
                return true;
        }
        return false;
    }

   bool isShowTimeAssigned(int movieIndex, const ShowTimeS& showTime) const {
        auto it = movieShowtimes.find(movieIndex);
        if (it != movieShowtimes.end()) {
            return it->second.find(showTime) != it->second.end();
        }
        return false;
    }   


};
