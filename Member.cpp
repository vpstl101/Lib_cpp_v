//
// Created by CMS on 2023-03-07.
//

#include <iostream>
#include <cstring>

#include "Member.h"
#include "LoginException.h"

using namespace std;

MemberShip::MemberShip(string id, string pw, string name, string phoneNum) {
    this->id = id;
    this->pw = pw;
    this->name = name;
    this->phoneNum = phoneNum;
}

const string &MemberShip::GetID() const // 5자리 이상
{
    return id;
}

const string &MemberShip::GetPW() const // 8자리 이상 정규식
{
    return pw;
}

const string &MemberShip::GetName() const {
    return name;
}

const string &MemberShip::GetPhoneNum() const {
    return phoneNum;
}