//
// Created by CMS on 2023-03-07.
//

#ifndef LIBPROJECT1_LIBMANAGER_H
#define LIBPROJECT1_LIBMANAGER_H

#include "Container.h"

using namespace std;

class LibManager {
private:
    Container<MemberShip *> mem;

public:
    enum {
        LOG_IN = 1, MAKE_EMBER, FIND_MY_INFO, WITHDRAWAL, ADMIN, GENERAL
    };

    LibManager() {};

    inline bool AdminLogin(string id, string pw);

    void AdminMode();
    void AddBooks();

    void GeneralMode() const;

    void PrintMenu() const;

    int Login();

    void MakeMemberShip();
};


#endif //LIBPROJECT1_LIBMANAGER_H
