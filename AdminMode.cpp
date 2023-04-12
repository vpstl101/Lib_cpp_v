#include <iostream>
#include <sstream>
#include <string>
#include "AdminMode.h"
#include "GeneralMode.h"

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

void AdminMode::SearchBook() {
    string sVal;
    stringstream ssVal;
    cout << "Primary Num or Title : ";
    cin >> sVal;

    //admin 북리스트가 g에 없다
    for (int i = 0; i < arrNum; i++) {
        if (bookArr[i]->GetTitle() == sVal)
            bookArr[i]->GetList();
        else {
            int iVal;
            ssVal << sVal;
            ssVal >> iVal;
            if (bookArr[i]->GetPrimary() == iVal)
                bookArr[i]->GetList();
        }
    }
}

// 내 위시리시트 추가 하기
void AdminMode::ShowBookList() {
    cout << "===== a Library Catalog =====" << endl;
    for (int i = 0; i < arrNum; i++)
        bookArr[i]->GetList();
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
                SearchBook();
                break;
            case INFO:
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