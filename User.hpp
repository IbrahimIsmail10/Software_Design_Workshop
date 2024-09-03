#ifndef USER_HPP
#define USER_HPP
#include <iostream>
#include <string>
#include <vector>

#include "Movie.hpp"

using namespace std;

class UserC{
	public:
		UserC(const string& mail, uint8_t phoneNum) : m_mail(mail), m_phoneNum(phoneNum)
		{}
		void SetMail(const string& mail) { m_mail = mail; };
		const string& GetMail() const { return m_mail; }
		void SetPhoneNum(uint8_t phoneNum) { m_phoneNum = phoneNum; }
		const uint8_t& GetPhoneNum() const { return m_phoneNum; } 
	private:
		string m_mail;
		uint8_t m_phoneNum;
};
#endif
