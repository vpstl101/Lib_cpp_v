//
// Created by CMS on 2023-03-07.
//

#include <iostream>
#include "LibManager.h"
#include "Member.h"
#include "LoginException.h"

using namespace std;

void LibManager::PrintMenu() const {
    cout << "=== Wellcome Genius Library ===" << endl;
    cout << "---Menu---" << endl;
    cout << "1. Log_in " << endl;
    cout << "2. Sign_in Membership " << endl;
    cout << "3. Find ID/PW " << endl;
    cout << "4. Sign_out " << endl;
    cout << "0. Exit " << endl;
}

inline bool LibManager::AdminLogin(string id, string pw) {
    return (id == "1111" && pw == "1111") ? true : false;
}

void LibManager::AdminMode() {
    int choice;
    cout << "===== Admin Mode Entering =====" << endl;
    cout << "1. Add Book" << endl;      // 추가
    cout << "2. Delet Book" << endl;    // 삭제
    cout << "3. Member Modify" << endl; // 회원수정
    cout << "0. Exit " << endl;
    cout << "choice : ";
    cin >> choice;

    if (choice == 1)
        AddBooks();
}

void LibManager::AddBooks() {
    string bookName, writer;

    cout << "===Log_in===" << endl;
    cout << "Book Name : ";
    cin >> bookName;
    cout << "Writer : ";
    cin >> writer;
    cout << "" << endl;
}

void LibManager::GeneralMode() const {
    cout << "===== WellCome 'Intelligent Library' =====" << endl;
    cout << "1. Book" << endl;      // 대출

}

int LibManager::Login() {
    string id, pw, name, phoneNum;
    int MemNum;

    cout << "===Log_in===" << endl;
    cout << "ID : ";
    cin >> id;
    cout << "PW : ";
    cin >> pw;
    cout << "" << endl;

    MemNum = mem.GetElemSum(); // 회원가입 ID 총 갯수

    if (AdminLogin(id, pw)) {

        AdminMode();
        exit(0);
    }


    for (int i = 0; i < MemNum; i++) {
        if (mem.GetItem(i)->GetID() == id) {
            cout << "++ Log_in Successful ++" << endl;
            cout << "" << endl;
            return GENERAL;
        }

    }
    cout << "++ Log_in Failed ++" << endl;
    cout << "" << endl;
}

void LibManager::MakeMemberShip() {
    string id, pw, name, phoneNum;
    int MemNum = mem.GetElemSum();
    cout << "===Make Membership===" << endl;
    cout << "ID : ";

    try {
        cin >> id;
        for (int i = 0; i < MemNum; i++) {
            if (mem.GetItem(i)->GetID() == id) {
                throw LogInException(id);
            }
        }
    }
    catch (LogInException &ex) {
        ex.Whats();
        return MakeMemberShip();
    }

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
