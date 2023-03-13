//
// Created by CMS on 2023-03-13.
//
#include <iostream>
#include "AdminMode.h"

bool AdminMode::AdminLogin(string id, string pw)
{
    return (id == "1111" && pw == "1111") ? true : false;
}
int AdminMode::AdminMenu()
{
    int choice;

    cout << "===== Admin Mode Entering =====" << endl;
    cout << "1. Add Book" << endl;    // 북 추가
    cout << "2. Delet Book" << endl;  // 북 삭제
    cout << "3. Member Info" << endl; // 회원정보
    cout << "0. Exit " << endl;
    cout << "choice : ";
    cin >> choice;

    return choice;
    // if (choice == 1)
    //     AddBooks();
}

void AdminMode::AddBooks()
{
    string bookName, writer;

    cout << "=== Add Books ===" << endl;
    cout << "Book Name : ";
    cin >> bookName;
    cout << "Writer : ";
    cin >> writer;
    cout << "" << endl;
}

void AdminMode::AdminApplication()
{
    int choice;

    while (1)
    {
        choice = AdminMenu();
        switch (choice)
        {
            case 1:
            default:
                break;
        }
    }
}
