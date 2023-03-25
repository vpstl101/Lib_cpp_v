//
// Created by CMS on 2023-03-07.
//

#include <iostream>
#include "LibManager.h"
#include "AdminMode.h"
#include "Member.h"
#include "LoginException.h"

using namespace std;

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

void LibManager::GeneralMenu() {
    int choice;
    cout << "===== Wellcome Intellectual Library =====" << endl;
    cout << "------ Menu ------" << endl;
    cout << "1. My Book Info " << endl;       // 내정보
    cout << "2. Book Search " << endl;   // 검색
    cout << "3. Borrow Books " << endl;  // 대출
    cout << "4. Return Books " << endl;  // 반납
    cout << "5. Storage a Books " << endl;    // 장바구니
    cout << "6. Donate a Book " << endl; // 기증
    cin >> choice;
}

void LibManager::Login() {
    string id, pw, name, phoneNum;
    AdminMode aMode; // 이게 맞는지 확인해야됨

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

    if (aMode.AdminLogin(id, pw)) // 관리자 **확인하기
        aMode.AdminApplication();

    for (int i = 0; i < memNum; i++) {
        if (memArr[i]->GetID() == id && memArr[i]->GetPW() == pw) {
            cout << "++ Log_in Successful ++" << endl
                 << endl;
            GeneralMenu(); // gener 메뉴로
        }
    }
    cout << "++ Log_in Failed ++" << endl
         << endl;
    return;
}

//void LibManager::Through(string (&fptr)(), string info) {
//
//
//    for (int i = 0; i < memNum; i++) {
//        if (memArr[i]->(&fptr)() == info)
//            cout << "fptr(val) : " << memArr[i]->(&fptr)() << endl;
//    }
//}

void LibManager::MakeMemberShip() {
    string id, pw, name, phoneNum;

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

    //return GO_BACK;
}

void LibManager::Recover() {
    int choice;
    string rID, rPW, rName, rPH;

    cout << "1. Find my ID " << endl;
    cout << "2. Find my PW " << endl;
    cout << "Choice : ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "My Name is : ";
            cin >> rName;

            //Through(GetName(), rName);
            /*for (int i = 0; i < memNum; i++) {
                if (memArr[i]->GetName() == rName)
                    cout << "Your ID : " << memArr[i]->GetID() << endl;
                else
                    cout << "No such information exists" << endl << endl;
            }*/
            break;
        case 2:
            cout << "My ID is : ";
            cin >> rID;
            for (int i = 0; i < memNum; i++) {
                if (memArr[i]->GetID() == rID)
                    cout << "Your PW : " << memArr[i]->GetPW() << endl;
                else
                    cout << "No such information exists" << endl << endl;
            }
            break;
        default:
            cout << "Plz Re-input" << endl;
            break;
    }
}

LibManager::~LibManager() {
    for (int i = 0; i < memNum; i++)
        delete memArr[i];
}
