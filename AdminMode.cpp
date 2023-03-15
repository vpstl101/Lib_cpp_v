//
// Created by CMS on 2023-03-13.
//
#include <iostream>
#include "AdminMode.h"

bool AdminMode::AdminLogin(string id, string pw) {
    return (id == "1111" && pw == "1111") ? true : false;
}

void AdminMode::AdminMenu() {
    cout << "===== Admin Mode Entering =====" << endl;
    cout << "1. Add Book" << endl;    // 북 추가
    cout << "2. Delet Book" << endl;  // 북 삭제
    cout << "3. Member Info" << endl; // 회원정보
    cout << "4. All Book List" << endl;    // 전체 북 리스트
    cout << "0. Exit " << endl;
}

void AdminMode::AddBooks() {
    string title, writer, date;  // borrowDate, returnDate; borrow 대출 return 반납
    int iStatus;
    bool bStatus;

    cout << "=== Add Books ===" << endl;
    cout << "Book Name : ";
    cin >> title;
    cout << "Writer : ";
    cin >> writer;
    cout << "Status 1 or 0 : ";
    cin >> iStatus;
    bStatus = iStatus;
    cout << "Date : ";
    cin >> date;
    cout << "" << endl;

    bookArr[arrNum++] = new BookInfo(title, writer, bStatus, date);

}

void AdminMode::ShowBookList() {

    for (int i = 0; i < arrNum; i++) {
        cout << "===== Catalog of Books =====" << endl;
        cout << "Book Name : " << bookArr[i]->GetTitle() << endl;
        cout << "Writer : " << bookArr[i]->GetWriter() << endl;
        cout << "Status : " << bookArr[i]->GetStatus() << endl;
        cout << "Date : " << bookArr[i]->GetDate() << endl;
        cout << "=====================================================" << endl;
    }
}

void AdminMode::AdminApplication() {
    int choice;

    while (1) {
        AdminMenu();
        cout << "choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                AddBooks();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                ShowBookList();
                break;
            case 0:
                return;
                break;
            default:
                break;

        }
    }
}