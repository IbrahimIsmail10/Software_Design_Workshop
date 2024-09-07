#include <iostream>
#include "Authorizer.cpp"

using namespace std;

class Payment {
 public:
  virtual void ProcessPayment() = 0;
};


class BankingPayment : public Payment {
 protected:
    string security_code_;   
    string phone_number_;
    Authorizer *authorizer_;
 public:
    BankingPayment(string security_code, string phone) : security_code_(security_code)  {
      this->phone_number_ = phone;
      authorizer_ = new SMSAuthorizer(phone_number_);

    }
};

class OtherPayment : public Payment {
 protected:
  Authorizer* authorizer_;
  string email;
  string password;
 public:
  OtherPayment(string email, string pass) {
    this->email = email;
    this->password = pass;
    authorizer_ = new NotRobotAuthorizer(email);
  }
};

class DepitPayment : public BankingPayment {
 public:
  DepitPayment(string security_code, string phone) : BankingPayment(security_code , phone) {}
  void ProcessPayment() override {
    cout << "Processing debit payment type" << " ----" ;
    this->authorizer_->Authorize();
    cout << "Payment successfully!"<< endl;
  }
};

class CreditPayment : public BankingPayment {
 public:
  CreditPayment(string security_code, string phone) : BankingPayment(security_code, phone) {}
  void ProcessPayment() override {
    cout << "Processing credit payment type" << "----";
    this->authorizer_->Authorize();
    cout<< "Payment successfully!"<< endl;
  }
};

class PayPalPayment : public OtherPayment {
  private:
 public:
  PayPalPayment(string email,string pass) : OtherPayment(email,pass) {}
  void ProcessPayment() override {
    cout << "Processing PayPal payment type" << "----";
    this->authorizer_->Authorize();
    cout <<"Payment successfully!"<< endl;
  }
};
