#ifndef USER_HPP
#define USER_HPP
#include <iostream>
#include <string>
#include <vector>

#include "Movie.hpp"

using namespace std;

class UserC{
	public:
		UserC() = default;
		UserC(const string& username, uint8_t phoneNum) : username(username), m_phoneNum(phoneNum)
		{}
		void SetUsername(const string& name) { username = name; };
		const string& GetUsername() const { return username; }
		void SetPhoneNum(uint8_t phoneNum) { m_phoneNum = phoneNum; }
		const uint8_t& GetPhoneNum() const { return m_phoneNum; } 
		void AddMovieTohistory(const MovieC& movie) { history.push_back(movie); }
		void DisplayHistory() const { for(auto& movie : history) cout<<movie.GetTitle()<<endl; }
	private:
		string username;
		uint8_t m_phoneNum;
		vector<MovieC> history;
};
#endif


