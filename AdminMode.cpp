#include <iostream>
#include <cctype>
#include <string>
#include "AdminMode.h"


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
    bookArr[arrNum++] = new BookInfo(listLen++, "삼국지", "엮은이", ENABLE, "123");
    bookArr[arrNum++] = new BookInfo(listLen++, "이순신의 바다", "엮은이", ENABLE, "123");
    bookArr[arrNum++] = new BookInfo(listLen++, "3333", "엮은이", UNABLE, "123");
    bookArr[arrNum++] = new BookInfo(listLen++, "4번쨰", "엮은이", UNABLE, "123");
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
    //bStatus = iStatus;
    cout << "Date : ";
    cin >> ActDate;
    cout << "" << endl;

    bookArr[arrNum++] = new BookInfo(listLen++, title, writer, bStatus, ActDate);
}

void AdminMode::DelBook() {
    string val;
    cout << "Primary Num or Title : enter : " << endl;
    cin >>val;

    //if(isdigit(stoi(val)))

    //cin.ignore(val);
    //getline(cin, val);

    for (int i = 0; i < arrNum; i++) {
        if (bookArr[i]->GetTitle() == val)
            cout<<bookArr[i]->GetTitle()<<endl;
    }
}

// 내 위시리시트 추가 하기
void AdminMode::ShowBookList() {
    for (int i = 0; i < arrNum; i++) {
        cout << "===== Catalog of Books =====" << endl;
        cout << "Primary Num : " << bookArr[i]->GetPrimary() << endl;
        cout << "Book Name : " << bookArr[i]->GetTitle() << endl;
        cout << "Writer : " << bookArr[i]->GetWriter() << endl;
        cout << ((bookArr[i]->Status() == ENABLE) ? "Stat : ENABEL" : "Stat : UNABLE") << endl;
        cout << "Date : " << bookArr[i]->GetDate() << endl;
        cout << "================================" << endl;
    }
}

void AdminMode::AdminAP() {
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
                DelBook();
                break;
            case INFO:
                break;
            case ALL_LIST:
                ShowBookList();
                break;
            case EXIT:
                return;
            default:
                break;
        }
    }
}