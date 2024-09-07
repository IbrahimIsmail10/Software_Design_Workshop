#include <iostream>
using namespace std;

class Authorizer {
 public:
  virtual void Authorize() = 0;
};

class SMSAuthorizer : public Authorizer {
 protected:
    string phone_number_;   
 public:
    SMSAuthorizer(string phone_number) : phone_number_(phone_number) {}
    void Authorize() override {
      cout << "Authorizing transaction using SMS" << " ----" ;
      cout << "Verifying phone number: {" << phone_number_ << "}" << endl;
    }
};

class NotRobotAuthorizer : public Authorizer {
 protected:
   string email;
 public:
   NotRobotAuthorizer(string email) : email(email) {}
   void Authorize() override {
     cout << "Authorizing transaction using NotRobot" << "----";
     cout <<"Verifying email: {" << email << "}"  << endl;
   }
};

