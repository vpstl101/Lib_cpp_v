//
// Created by CMS on 2023-03-07.
//

#include <iostream>
#include <functional>


#include "LibManager.h"
#include "AdminMode.h"
#include "GeneralMode.h"
#include "Member.h"
#include "LoginException.h"

using namespace std;

//메뉴
void LibManager::PrintMenu() const {
    cout << "------ Library Main Menu ------" << endl;
    cout << "1. Log_in " << endl;             // 로그인
    cout << "2. Sign_in Membership " << endl; // 회원가입
    cout << "3. Find ID/PW " << endl;         // ID/PW찾기
    cout << "4. Sign_out " << endl;           // 탈퇴
    cout << "0. Exit " << endl;
}

int LibManager::PrintMenuCopy() {
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

//로그인
void LibManager::Login() {
    string id, pw, name, phoneNum;
    AdminMode *pAmode, Amode;
    pAmode = &Amode;

    GeneralMode gMode;
    cout << "===Log_in===" << endl;
    cout << "0. Go Back " << endl;
    cout << "============ " << endl;
    cout << "ID : ";
    cin >> id;
    cout << "PW : ";
    cin >> pw;
    cout << "" << endl;

    if (id == "0" || pw == "0") // 뒤로가기
        return;

    if (pAmode->AdminLogin(id, pw)) // 관리자 **확인하기
        pAmode->AdminAP();

    for (int i = 0; i < memNum; i++) {
        if (memArr[i]->GetID() == id && memArr[i]->GetPW() == pw) {
            cout << "++ Log_in Successful ++" << endl
                 << endl;
            gMode.GernerAP(); // gener 메뉴로
        }
    }
    cout << "++ Log_in Failed ++" << endl
         << endl;
    return;
}

void LibManager::MakeMemberShip() {
    string id, pw, name, phoneNum;
    AdminMode *pAmode = new AdminMode();
    cout << "=== Make Membership ===" << endl;
    try {
        cout << "ID : ";
        cin >> id;

        if (id.size() < 3 || id.size() > 5) // 3~5 자리 검사
            throw LogInException(id);

        for (int i = 0; i < memNum; i++) {
            if (memArr[i]->GetID() == id) // 중복 검사
                throw LogInException(id);
        }
    }
    catch (LogInException &ex) {
        ex.IDReport();
        return MakeMemberShip();
    }

    try {
        cout << "PW : ";
        cin >> pw;

        if (pw.size() < 4 || pw.size() > 6) // 4~6 자리 검사
            throw PWException(pw);
    }
    catch (PWException &ex) {
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


    memArr[memNum++] = new MemberShip(id, pw, name, phoneNum);
    //pAmode->MemSndData(memArr, memNum, id, pw, name, phoneNum);
}

void LibManager::Recover() {
    int choice;

    cout << "1. Find my ID " << endl;
    cout << "2. Find my PW " << endl;
    cout << "Choice : ";
    cin >> choice;
    if (choice == 1)
        return RecoverID();
    else if (choice == 2)
        return RecoverPW();
    else return;
    //return (choice == 1) ? RecoverID() : RecoverPW();
    //    cout << "Plz Re-input"<< endl;

}

void LibManager::RecoverID() {
    string rName;

    cout << "My Name is : ";
    cin >> rName;
    for (int i = 0; i < memNum; i++) {
        if (memArr[i]->GetName() != rName)
            continue;
        else cout << "Your ID : " << memArr[i]->GetID() << endl;
    }
    // cout << "No such information exists" << endl << endl;

}

void LibManager::RecoverPW() {
    string rID;
    cout << "My ID is : ";
    cin >> rID;
    for (int i = 0; i < memNum; i++) {
        if (memArr[i]->GetID() == rID)
            cout << "Your PW : " << memArr[i]->GetPW() << endl;
    }
    cout << "No such information exists" << endl << endl;
}

void LibManager::MemberDel() {
    string answer;
    string dId, dPw, dName, dPhoneNum;
    cout << "you Want to Withdraw Memership? " << endl;
    cout << "Are You Sure? (Y/n)" << endl;
    cin >> answer;

    if (answer == "y" || answer == "Y") {
        cout << "ID : ";
        cin >> dId;
        cout << "PW : ";
        cin >> dPw;
        cout << "NAME : ";
        cin >> dName;
        cout << "Phone NumBer : ";
        cin >> dPhoneNum;

        for (int i = 0; i < memNum; i++) {
            if (memArr[i]->GetID() == dId &&
                memArr[i]->GetPW() == dPw &&
                memArr[i]->GetName() == dName &&
                memArr[i]->GetPhoneNum() == dPhoneNum) {
                memArr[i] = memArr[i + 1];
                cout << "I always got life-changing ideas from books. Good bye Thank U" << endl;
                --memNum;
            } else cout << "Your Info is Incorrect" << endl;
        }

    } else cout << "Menu Return" << endl;

}



void LibManager::ShowMemList(){
    cout<<"gogogo"<<endl;
    for (int i = 0; i < memNum; i++)
        memArr[i]->GetMemList();
}


/*
LibManager::~LibManager() {
    for (int i = 0; i < memNum; i++)
        delete memArr[i];
}
*/
