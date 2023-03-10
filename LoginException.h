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
    string val;

public:
    LogInException(string val)
    {
        this->val = val;
    }
    void IDReport()
    {
        cerr << "duplication or ID digits is from 3 ~ 5" << endl;
    }
};

#endif //LIBPROJECT1_LOGINEXCEPTION_H
