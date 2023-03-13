//
// Created by CMS on 2023-03-07.
//

#ifndef LIBPROJECT1_LIBMANAGER_H
#define LIBPROJECT1_LIBMANAGER_H

#include "Container.h"
#include "AdminMode.h"

using namespace std;

class LibManager : public AdminMode {
private:
    Container<MemberShip *> mem;

public:
    enum {
        GO_BACK = -1,
        EXIT,
        LOG_IN,
        MAKE_EMBER,
        FIND_MY_INFO,
        WITHDRAWAL,
        ADMIN,
        GENERAL
    };

    LibManager()
            : AdminMode() {}; // ***상속 맞는지 확인하기

    // inline bool AdminLogin(string id, string pw);
    void PrintMenu() const;

    int PrintMenuCopy();
    // void AdminMode();
    // void AddBooks();

    void GeneralMenu();

    int Login();

    int MakeMemberShip();
};


#endif //LIBPROJECT1_LIBMANAGER_H
