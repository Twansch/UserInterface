#ifndef COMMUNICATION_H
#define COMMUNICATION_H
#include<string>


class Communication
{
public:
    Communication();
    bool Connect();
    bool WriteFirst();
    bool Write();
    void Read();
};

#endif // COMMUNICATION_H
