#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <memory> 
using namespace std;

class Seat {
public:
    string seatNumber;
    bool isAvailable;

    Seat(const string& number) : seatNumber(number), isAvailable(true) {}

    virtual ~Seat() = default;
    virtual string getCategory() const = 0;
};

class RegularSeat : public Seat {
public:
    RegularSeat(const string& number) : Seat(number) {}
    string getCategory() const override { return "Regular"; }
};

class PremiumSeat : public Seat {
public:
    PremiumSeat(const string& number) : Seat(number) {}
    string getCategory() const override { return "Premium"; }
};

class GoldSeat : public Seat {
public:
    GoldSeat(const string& number) : Seat(number) {}
    string getCategory() const override { return "Gold"; }
};


class SeatFactory {
    private:
       static bool isRegularSeat(char row, char number) {
            return  row == 'A' || row == 'B' || 
            (row== 'C' && (number == '1' || number == '5')) || 
            (row == 'D' && (number == '1' || number == '5'));
        }
       static bool isPremiumSeat(char row, char number) {
             return (row == 'C' && (number >= '2' && number <= '4')) || 
             (row == 'D' && (number >= '2' && number <= '4'));
        }

        static bool isGoldSeat(char row) {
            return (row == 'E');
        }

    public:
        static shared_ptr<Seat> createSeat(const string& number) {
            if(number.size() != 2) {
                throw invalid_argument("Invalid seat number");
            }
            char row = number[1];
            char seatNumber = number[0];
            if (isRegularSeat(row, seatNumber)) {
                return make_shared<RegularSeat>(number);
            } else if (isPremiumSeat(row, seatNumber)) {
                return make_shared<PremiumSeat>(number);
            } else if (isGoldSeat(row)) {
                return make_shared<GoldSeat>(number);
            }
            throw invalid_argument("Invalid seat number");

        }
};

