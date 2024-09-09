#include "Cinema.hpp"
#define DEPIT "debit"
#define CREDIT "credit"
#define PAYPAL "paypal"
unique_ptr<CinemaC> CinemaC::m_cinemaInst = nullptr;
ShowTimeS show_time;
UserC user;
string username;
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

void CinemaC::DisplayHall(int hall_num) const
{
        cout<<"Hall Number: "<<hall_num<<endl;
        m_halls[hall_num-1]->displayHall();
}

void CinemaC::get_movie_ShowTime(int idx) {
    m_movies[idx].Displayshowtimes();
}

void CinemaC::AssignMoviesToHalls()
{
    for(int i = 0;i< m_movies.size();i++) {
        for(auto& showTime : m_movies[i].GetShowTime()) {
            for(auto& hall : m_halls) {
                if(hall->Assign_ShowTime_To_Hall(i, showTime)){
                    // m_hallShowtimes[hall->getHallNumber()].push_back({i, showTime});
                    break;
                }
            }
        }
    }
}

int CinemaC::GetHallNumber(int film_idx , int showtime_idx) const
{
    show_time = m_movies[film_idx].GetShowTimeByIdx(showtime_idx);
            
    for(auto& hall : m_halls) {
        if(hall->isShowTimeAssigned(film_idx, show_time)) {
            return hall->getHallNumber();
        }
    }
    return -1;
}

void CinemaC::ReserveSeat(int hall_num, int movie_idx, int showtime_idx, const string& seatNumber)
{
    auto hall = m_halls[hall_num-1];
    auto seat = hall->findSeat(seatNumber);
    if(seat) {
        if(hall->isSeatAvailable(seatNumber)) {
            cout << "This Seat is "<< seat->getCategory()<<endl;
            int price = c_DayPrice.at(show_time.m_movieDay) + c_TimePrice.at(show_time.m_time) + c_categoryPrice.at(seat->getCategory());
            if(PaymentProcess(price)){
                seat->isAvailable = false;
                cout<<"Seat Reserved"<<endl;
                Ticket ticket(seatNumber, hall_num, price, show_time, m_movies[movie_idx].GetTitle());
                ticket.DisplayTicket();
                AddUserToHistory(user, m_movies[movie_idx]);
            }
            else{ cout<<"Payment Failed"<<endl;}  
        } 
        else {
            cout<<"Seat is not available"<<endl;
        }
    } 
    else {
        cout<<"Seat not found"<<endl;
    }
}

bool CinemaC::PaymentProcess(int price)
{
    cout<<"Total Price: "<<price<<endl;
    cout<<"Do you want to complete payment? (y/n): ";
    string s; cin>>s;
    if (s == "y")
    {
        string payment_type;
        cout<<"Enter Payment Type: ";
        cin>>payment_type;
        if(payment_type == DEPIT || payment_type == CREDIT) {
            string security_code;
            string phone;
            cout<<"Enter Your Name: ";
            cin>>username;
            cout<<"Enter Security Code: ";
            cin>>security_code;
            cout<<"Enter Phone Number: ";
            cin>>phone;
            user.SetUsername(username);
            user.SetPhoneNum(stoi(phone));
            payment = PaymentFactory::CreatePayment(payment_type, security_code, phone);
            if(payment) {
                payment->ProcessPayment();
                return true;
            } else {
                cout<<"Invalid Payment Type"<<endl;
                return false;
            }
        }
        else if(payment_type == PAYPAL) {
            string email;
            string password,phone;
            cout<<"Enter Your Name: ";
            cin>>username;
            cout<<"Enter Email: ";
            cin>>email;
            cout<<"Enter Password: ";
            cin>>password;
            cout<<"Enter Phone Number: ";
            cin>>phone;
            user.SetUsername(username);
            user.SetPhoneNum(stoi(phone));
            payment = PaymentFactory::CreatePayment(payment_type,password, email);
            if(payment) {
                payment->ProcessPayment();
                return true;
            } else {
                cout<<"Invalid Payment Type"<<endl;
                return false;
            }
        } 
        else {
            cout<<"Invalid Payment Type"<<endl;
            return false;
        }
    }
               
}

void CinemaC::AddUserToHistory(UserC& user, MovieC& movie) 
{
    user.AddMovieTohistory(movie);
    users.push_back(make_shared<UserC>(user));
    m_usersToMovies[movie.GetTitle()].push_back(user.GetUsername());
}

void CinemaC::DisplayUsersWatchingMovie(int movie_idx)
{
    cout<<"Users Watching "<<m_movies[movie_idx].GetTitle()<<endl;
    for(auto& user : m_usersToMovies[m_movies[movie_idx].GetTitle()]) {
        cout<<user<<endl;
    }
}

void CinemaC::userMoviesHistory(const string& username)
{
    for(auto& user : users) {
        if(user->GetUsername() == username) {
            user->DisplayHistory();
            return;
        }
    }
    cout<<"User not found"<<endl;
}



