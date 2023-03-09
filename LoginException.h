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
    LogInException(string val) {
        this->val = val;
    }

    void Whats()
    {
        cout << "Please enter at least 5 digits of your ID." << endl;
    }
};

#endif //LIBPROJECT1_LOGINEXCEPTION_H
