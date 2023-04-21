//
// Created by CMS on 2023-03-13.
//

#ifndef LIBPROJECT1_ADMINMODE_H
#define LIBPROJECT1_ADMINMODE_H


#include "CreatArray.h"
#include "LibManager.h"

class AdminMode : public LibManager {
public:
    CreatArray<BookInfo *> bookArr;
    CreatArray<MemberShip *> RmemArr;
    int arrNum;
    int listLen;
    int rMmemNum;

public:
    enum A_MENU {
        EXIT,
        ADD,
        DEL,
        INFO,
        LIST
    };
    enum BORROW {
        UNABLE,
        ENABLE
    };

    AdminMode()
            : LibManager(), arrNum(0), listLen(1), rMmemNum(0){};

    bool AdminLogin(string id, string pw);

    void AdminMenu() const;

    void AddBooks();

    void AdminAP();

    void ShowBookList();

    void BookList();

    int SearchBook();

    void DeletBook();

    //void MemSndData(CreatArray<MemberShip *> &data, int num, string id, string pw, string name, string phoneNum);

    void ShowMemList();

};

#endif //LIBPROJECT1_ADMINMODE_H
