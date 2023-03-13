//
// Created by CMS on 2023-03-07.
//

#include <iostream>
#include "LibManager.h"
#include "AdminMode.h"
#include "Member.h"
#include "LoginException.h"

using namespace std;

void LibManager::PrintMenu() const
{
    cout << "------ Library Main Menu ------" << endl;
    cout << "1. Log_in " << endl;             // 로그인
    cout << "2. Sign_in Membership " << endl; // 회원가입
    cout << "3. Find ID/PW " << endl;         // ID/PW찾기
    cout << "4. Sign_out " << endl;           // 탈퇴
    cout << "0. Exit " << endl;
}

int LibManager::PrintMenuCopy()
{
    int choice;
    cout << "------ Library Main Menu ------" << endl;
    cout << "1. Log_in " << endl;
    cout << "2. Sign_in Membership " << endl;
    cout << "3. Find ID/PW " << endl;
    cout << "4. Sign_out " << endl;
    cout << "0. Exit " << endl;
    cout << "CHOICE : ";
    cin >> choice;
    cout << "" << endl;
    return choice;
}

void LibManager::GeneralMenu()
{
    int choice;
    cout << "===== Wellcome Intellectual Library =====" << endl;
    cout << "------ Menu ------" << endl;
    cout << "1. My Info " << endl;       // 내정보
    cout << "2. Borrow Books " << endl;  // 대출
    cout << "3. Return Books " << endl;  // 반납
    cout << "4. Keep Books " << endl;    // 장바구니
    cout << "5. Book Search " << endl;   // 도서검색
    cout << "6. Donate a Book " << endl; // 기증
    cin >> choice;
}

int LibManager::Login()
{
    string id, pw, name, phoneNum;
    AdminMode ad; // 이게 맞는지 확인해야됨
    int MemNum = mem.GetElemSum(); // 회원가입 ID 총 갯수

    cout << "===Log_in===" << endl;
    cout << "0. Go Back " << endl;
    cout << "============ " << endl;
    cout << "ID : ";
    cin >> id;
    cout << "PW : ";
    cin >> pw;
    cout << "" << endl;

    if (id == "0" || pw == "0") // 뒤로가기
        return GO_BACK;

    if (ad.AdminLogin(id, pw)) // 관리자 **확인하기
        return ADMIN;

    for (int i = 0; i < MemNum; i++)
    {
        if (mem.GetItem(i)->GetID() == id && mem.GetItem(i)->GetID() == pw)
        {
            cout << "++ Log_in Successful ++" << endl
                 << endl;
            return GENERAL;
        }
    }
    cout << "++ Log_in Failed ++" << endl
         << endl;
    return GO_BACK;
}

int LibManager::MakeMemberShip()
{
    string id, pw, name, phoneNum;

    int MemNum = mem.GetElemSum();

    cout << "=== Make Membership ===" << endl;

    try
    {
        cout << "ID : ";
        cin >> id;

        if (id.size() < 3 || id.size() > 5) // 3~5 자리 검사
            throw LogInException(id);

        for (int i = 0; i < MemNum; i++)
        {
            if (mem.GetItem(i)->GetID() == id) // 중복 검사
                throw LogInException(id);
        }
    }
    catch (LogInException &ex)
    {
        ex.IDReport();
        return MakeMemberShip();
    }

    try
    {
        cout << "PW : ";
        cin >> pw;

        if (pw.size() < 4 || pw.size() > 6) // 4~6 자리 검사
            throw PWException(pw);
    }
    catch (PWException &ex)
    {
        ex.PWReport();
        return MakeMemberShip();
    }
    cout << "NAME : ";
    cin >> name;
    cout << "Phone NumBer : ";
    cin >> phoneNum;
    cout << "" << endl;

    cout << "++ Member registration completed ++" << endl
         << endl;

    mem.Insert(new MemberShip(id, pw, name, phoneNum));

    return GO_BACK;
}