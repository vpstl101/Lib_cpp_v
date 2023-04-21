//
// Created by CMS on 2023-03-07.
//

#ifndef LIBPROJECT1_MEMBER_H
#define LIBPROJECT1_MEMBER_H

#include "CreatArray.h"

using namespace std;

class MemberShip {
private:
    string id;
    string pw;
    string name;
    string phoneNum;

public:
    MemberShip(string _id, string _pw, string _name, string _phoneNum);

    const string &GetID() const;

    const string &GetPW() const;

    const string &GetName() const;

    const string &GetPhoneNum() const;

    void GetMemList() const;
};


#endif //LIBPROJECT1_MEMBER_H
