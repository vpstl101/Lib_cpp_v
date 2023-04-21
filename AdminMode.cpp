#include <iostream>
#include <sstream>
#include <string>
#include "AdminMode.h"
#include "Member.h"

bool AdminMode::AdminLogin(string id, string pw) {
    return (id == "1111" && pw == "1111") ? true : false;
}

void AdminMode::AdminMenu() const {
    cout << "===== Admin Mode Entering =====" << endl;
    cout << "1. Add Book" << endl;      // 북 추가
    cout << "2. Delete Book" << endl;   // 북 삭제
    cout << "3. Member Info" << endl;   // 회원 정보
    cout << "4. All Book List" << endl; // 전체 북 리스트
    cout << "0. Exit " << endl;
}

void AdminMode::BookList() {
    bookArr[arrNum++] = new BookInfo(listLen++, "one", "엮은이", ENABLE, "123");
    bookArr[arrNum++] = new BookInfo(listLen++, "이순신의 바다", "엮은이", ENABLE, "123");
    bookArr[arrNum++] = new BookInfo(listLen++, "3333", "엮은이", UNABLE, "123");
    bookArr[arrNum++] = new BookInfo(listLen++, "four4", "엮은이", UNABLE, "123");
    bookArr[arrNum++] = new BookInfo(listLen++, "four4", "지은이", UNABLE, "333");
}

void AdminMode::AddBooks() {
    string title, writer, ActDate;  // ActDate, ExpDate; borrow 대출
    bool bStatus;

    cout << "=== Add Books ===" << endl;
    cout << "Book Name : ";
    cin >> title;
    cout << "Writer : ";
    cin >> writer;
    cout << "(Status)ENABLE:1/UNABLE:0 >> : ";
    cin >> bStatus;
    cout << "Date : ";
    cin >> ActDate;
    cout << "" << endl;

    bookArr[arrNum++] = new BookInfo(listLen++, title, writer, bStatus, ActDate);
}

int AdminMode::SearchBook() {
    string sVal;
    stringstream ssVal;
    cout << "Primary Num or Title : ";
    cin >> sVal;

    // admin 북리스트가 g에 없다
    for (int i = 0; i < arrNum; i++) {
        if (bookArr[i]->GetTitle() == sVal) {
            bookArr[i]->GetList();
            return i;
        } else {
            int iVal;
            ssVal << sVal;
            ssVal >> iVal;
            if (bookArr[i]->GetPrimary() == iVal) {
                bookArr[i]->GetList();
                return i;
            }
        }
    }
    return -1;
}

void AdminMode::DeletBook() {
    int num = SearchBook();
    if (num >= 0) {
        for (int i = num; i < arrNum; i++)
            bookArr[i] = bookArr[i + 1];
        --arrNum;
        cout << "success" << endl;
    } else
        cout << "fail" << endl;
}

// 내 위시리시트 추가 하기
void AdminMode::ShowBookList() {
    for (int i = 0; i < arrNum; i++)
        bookArr[i]->GetList();
}

/*void AdminMode::MemSndData(CreatArray<MemberShip *> &data, int num, string id, string pw, string name, string phoneNum) {
    string *rID, *rPW, rPhone;

    string rName;
    rMmemNum=num;
    RmemArr[rMmemNum++] =new MemberShip(id, pw, name, phoneNum);

    //RmemArr[rMmemNum++] = new MemberShip(id, pw, name, phoneNum);

}*/

void AdminMode::ShowMemList() {
    cout << "ad" << endl;
    for (int i = 0; i < rMmemNum; i++)
    {
        cout << "====Pk : ["<<i<<"]===="<< endl;
        cout << "ID : " << RmemArr[i]->GetID() << endl;
        cout << "PW : " << RmemArr[i]->GetPW() << endl;
        cout << "Name : " << RmemArr[i]->GetName() << endl;
        cout << "Phone Num : " << RmemArr[i]->GetPhoneNum() << endl;
        cout << "===========================" << endl;
    }

}

void AdminMode::AdminAP() {



    LibManager *gLib, Lib;
    LibManager *pLib2 = new AdminMode();
    gLib = &Lib;

    string a;
    int choice;
    BookList();

    while (1) {
        AdminMenu();
        cout << "choice : ";
        cin >> choice;

        switch (choice) {
            case ADD:
                AddBooks();
                break;
            case DEL:
                DeletBook();
                break;
            case INFO:
                ShowMemList();
                break;
            case LIST:
                ShowBookList();
                break;
            case EXIT:
                return;
            default:
                break;
        }
    }
}