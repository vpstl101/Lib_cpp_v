

#include <iostream>
#include "LibManager.h"
// g++ -c 123.cpp
// g++ -o "name" main.cpp 123.o
using namespace std;

int main() {
    LibManager manager;
    int grade;
    int choice;
    while (1) {
        manager.PrintMenu();
        cout << "CHOICE : ";
        cin >> choice;
        switch (choice) {
            case LibManager::LOG_IN:    // 로그인
                choice=manager.Login();
                break;
            case LibManager::MAKE_EMBER:    // 회원가입
                manager.MakeMemberShip();
                break;
            case LibManager::FIND_MY_INFO:  //내정보 수정
                manager.MakeMemberShip();
                break;
            case LibManager::WITHDRAWAL:    //회원 탈퇴
                manager.MakeMemberShip();
                break;
            case LibManager::ADMIN:    // 관리자모드
                manager.AdminMode();
                break;

            default:
                break;
        }
    }
    return 0;
}
