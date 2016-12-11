#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer
{

public:
    Customer(int id, std::string name);
    std::string GetName();
    void SetName(std::string name);
    int GetId();
    void SetPay(bool paymentMade);
    bool AcceptProgram();


private:
    int id;
    std::string name;
    bool hasPayed;

};

#endif // CUSTOMER_H
