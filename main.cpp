#include <iostream>
#include "LibManager.h"
#include "AdminMode.h"
// g++ -c 123.cpp
// g++ -o "name" main.cpp 123.o
using namespace std;

int main() {
    LibManager *manager = new AdminMode();
    int choice;

    while (1) {
        manager->PrintMenu();
        cout << "CHOICE : ";
        cin >> choice;
        cout << "" << endl;

        switch (choice) {
            case LibManager::LOG_IN:        // 로그인
                manager->Login();
                break;
            case LibManager::MAKE_EMBER:    // 회원가입
                manager->MakeMemberShip();
                break;
            case LibManager::FIND_MY_INFO:  // 내정보 찾기
                manager->Recover();
                break;
            case LibManager::WITHDRAWAL:    // 회원 탈퇴
                manager->MemberDel();
                break;
            case LibManager::GO_BACK:       // 뒤로가기
                choice = manager->PrintMenuCopy();
                break;
            case LibManager::EXIT:          // 나가기
                return 0;
        }
    }
    return 0;
}

