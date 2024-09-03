
#include "Cinema.hpp"
unique_ptr<CinemaC> CinemaC::m_cinemaInst = nullptr;

unique_ptr<CinemaC>& CinemaC::GetCinemaInst()
{
    if(!m_cinemaInst) {
        m_cinemaInst = make_unique<CinemaC>();
    }
    return m_cinemaInst;
}

void CinemaC::CreateHalls(int numberOfHalls) 
{
    for(int i = 1; i <= numberOfHalls; ++i) {
        auto hall = make_shared<Hall>(i);
        for(int j = 1; j <=5 ; ++j) {
            hall->addSeat(SeatFactory::createSeat(to_string(j) + "A"));
            hall->addSeat(SeatFactory::createSeat(to_string(j) + "B"));
            hall->addSeat(SeatFactory::createSeat(to_string(j) + "C"));
            hall->addSeat(SeatFactory::createSeat(to_string(j)+ "D"));
            hall->addSeat(SeatFactory::createSeat(to_string(j)+ "E"));
        }
        m_halls.push_back(hall);
    }
}

void CinemaC::DisplaySeats() const
{
    for(const auto& hall : m_halls) {
        cout << "Hall number: " << hall->getHallNumber() << endl;
        hall->displaySeats();
    }
}

void CinemaC::get_movie_ShowTime(int idx) {
    m_movies[idx].getshowtimes();
    }




