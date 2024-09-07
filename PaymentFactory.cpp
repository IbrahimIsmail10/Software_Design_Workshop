#include "payment.cpp"
#include<iostream>

using namespace std;

class PaymentFactory {
 public:
  static Payment *CreatePayment(string payment_type, string security_code, string phone ) {
    if (payment_type == "debit") {
      return new DepitPayment(security_code, phone);
    } else if (payment_type == "credit") {
      return new CreditPayment(security_code, phone);
    } else if (payment_type == "paypal") {
      return new PayPalPayment(phone,security_code);
    } else {
      return nullptr;
    }
  }
};

