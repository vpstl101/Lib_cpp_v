//
// Created by CMS on 2023-03-27.
//
#include <iostream>
#include "GeneralMode.h"

void GeneralMode::GeneralMenu() const {
    cout << "===== Wellcome Intellectual Library =====" << endl;
    cout << "------ Menu ------" << endl;
    cout << "1. My Book Info " << endl;     // 내정보
    cout << "2. Book Search " << endl;      // 검색
    cout << "3. Borrow Books " << endl;     // 대출
    cout << "4. Return Books " << endl;     // 반납
    cout << "5. Storage a Books " << endl;  // 장바구니
    cout << "6. Donate a Book " << endl;    // 기증
}

void GeneralMode::GernerAP() {
    int choice;

    while (1) {
        GeneralMenu();
        cout << "choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                //AddBooks();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                //howBookList();
                break;
            case 0:
                return;
                break;
            default:
                break;

        }
    }
}