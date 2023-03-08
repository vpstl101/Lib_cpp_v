//
// Created by CMS on 2023-03-07.
//

#include <iostream>
#include "LibManager.h"
#include "Member.h"
#include "LoginException.h"

using namespace std;

void LibManager::PrintMenu() const
{
    cout << "=== Wellcome Genius Library ===" << endl;
    cout << "---Menu---" << endl;
    cout << "1. Log_in " << endl;
    cout << "2. Sign_in Membership " << endl;
    cout << "3. Find ID/PW " << endl;
    cout << "4. Sign_out " << endl;
    cout << "0. Exit " << endl;
}

void LibManager::Login()
{
    string id, pw, name, phoneNum;
    int MemNum;
    cout << "===Log_in===" << endl;
    cout << "ID : ";
    cin >> id;
    cout << "PW : ";
    cin >> pw;
    cout << "" << endl;

    MemNum = mem.GetElemSum(); // 회원가입 ID 총 갯수

    for (int i = 0; i < MemNum; i++)
    {
        if (mem.GetItem(i)->GetID() == id)
        {
            cout << "++ Log_in Successful ++" << endl;
            cout << "" << endl;
            return;
        }
    }
    cout << "++ Log_in Failed ++" << endl;
    cout << "" << endl;
}
void LibManager::MakeMemberShip()
{
    string id, pw, name, phoneNum;

    cout << "===Make Membership===" << endl;
    cout << "ID : ";
    cin >> id;
    cout << "NAME : ";
    cin >> name;
    cout << "PW : ";
    cin >> pw;
    cout << "Phone NumBer : ";
    cin >> phoneNum;
    cout << "" << endl;

    cout << "++Member registration completed++" << endl;
    cout << "" << endl;
    mem.Insert(new MemberShip(id, pw, name, phoneNum));
}
