//
// Created by CMS on 2023-03-07.
//

#ifndef LIBPROJECT1_LIBMANAGER_H
#define LIBPROJECT1_LIBMANAGER_H


#include "Container.h"

using namespace std;
class LibManager
{
private:
    Container<MemberShip *> mem;

public:
    LibManager(){};
    void PrintMenu() const;
    void Login();
    void MakeMemberShip();
};


#endif //LIBPROJECT1_LIBMANAGER_H
