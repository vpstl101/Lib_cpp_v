//
// Created by CMS on 2023-03-13.
//
#include <iostream>
#include<vector>
#include "AdminMode.h"

bool AdminMode::AdminLogin(string id, string pw) {
    return (id == "1111" && pw == "1111") ? true : false;
}

void AdminMode::AdminMenu() const{
    cout << "===== Admin Mode Entering =====" << endl;
    cout << "1. Add Book" << endl;      // 북 추가
    cout << "2. Delete Book" << endl;   // 북 삭제
    cout << "3. Member Info" << endl;   // 회원 정보
    cout << "4. All Book List" << endl; // 전체 북 리스트
    cout << "0. Exit " << endl;
}

void AdminMode::BookList()
{
    bookArr[arrNum++] = new BookInfo(listLen++, "삼국지", "엮은이", ENABLE, "123");
    bookArr[arrNum++] = new BookInfo(listLen++, "이순신의 바다", "엮은이",ENABLE, "123");
    bookArr[arrNum++] = new BookInfo(listLen++, "3333", "엮은이", UNABLE,"123");
    bookArr[arrNum++] = new BookInfo(listLen++, "4번쨰", "엮은이", UNABLE,"123");
}

void AdminMode::AddBooks() {
    string title, writer, date;  // borrowDate, returnDate; borrow 대출 return 반납
    //int iStatus;
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
    cin >> date;
    cout << "" << endl;
    
    bookArr[arrNum++] = new BookInfo(listLen++,title, writer, bStatus, date);
}

void AdminMode::ShowBookList() {
    for (int i = 0; i < arrNum; i++) {
        cout << "===== Catalog of Books =====" << endl;
        cout << "Primary Num : " << bookArr[i]->GetPrimary() << endl;
        cout << "Book Name : " << bookArr[i]->GetTitle() << endl;
        cout << "Writer : " << bookArr[i]->GetWriter() << endl;
        bookArr[i]->GetStatPrint();
        cout << "Date : " << bookArr[i]->GetDate() << endl;
        cout << "======================================" << endl;
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
