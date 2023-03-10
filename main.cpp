

#include <iostream>
#include "LibManager.h"
// g++ -c 123.cpp
// g++ -o "name" main.cpp 123.o
using namespace std;

#include <iostream>
#include "LibManager.h"
//#include "AdminManager.h"
// g++ -c 123.cpp
// g++ -o "name" main.cpp 123.o
using namespace std;

int main()
{
    LibManager manager;
    int choice;

    manager.PrintMenu();
    cout << "CHOICE : ";
    cin >> choice;

    while (1)
    {
        switch (choice)
        {
            case LibManager::LOG_IN: // 로그인
                choice = manager.Login();
                break;
            case LibManager::MAKE_EMBER: // 회원가입
                choice = manager.MakeMemberShip();
                // manager.MakeMemberShip();
                break;
            case LibManager::FIND_MY_INFO: // 내정보 수정
                manager.MakeMemberShip();
                break;
            case LibManager::WITHDRAWAL: // 회원 탈퇴
                manager.MakeMemberShip();
                break;
            case LibManager::ADMIN: // 관리자모드
                manager.AdminMode();
                break;
            case LibManager::GENERAL: // 일반모드
                manager.GeneralMenu();
                break;
            case LibManager::GO_BACK: // 뒤로가기 **이부분을 수정해야 될듯
                main();
                break;
            case LibManager::EXIT: // 나가기
                exit(0);
            default:
                break;
        }
    }
    return 0;
}

