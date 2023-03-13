//
// Created by CMS on 2023-03-07.
//

#ifndef LIBPROJECT1_LOGINEXCEPTION_H
#define LIBPROJECT1_LOGINEXCEPTION_H

#include <iostream>
#include <string>

using namespace std;
class LogInException
{
private:
    string id;

public:
    LogInException(string id)
    {
        this->id = id;
    }
    void IDReport()
    {
        cerr << "duplication or ID digits is from 3 ~ 5" << endl;
    }
};

class PWException
{
private:
    string pw;

public:
    PWException(string pw)
    {
        this->pw = pw;
    }
    void PWReport()
    {
        cerr << "ID digits is from 4 ~ 6" << endl;
    }
};

#endif //LIBPROJECT1_LOGINEXCEPTION_H
