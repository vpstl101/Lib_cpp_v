//
// Created by CMS on 2023-03-13.
//

#ifndef LIBPROJECT1_ADMINMODE_H
#define LIBPROJECT1_ADMINMODE_H

#include "BookInfo.h"
#include "CreatArray.h"

class AdminMode {
private:
    CreatArray<BookInfo *> bookArr;
    //BookLIstArray<BookSetting *> BookArr;
    int arrNum;
    int listLen;
public:
    enum MENU {
        EXIT,
        ADD,
        DEL,
        INFO,
        ALL_LIST
    };
    enum BORROW {
        UNABLE,
        ENABLE
    };

    AdminMode() : arrNum(0), listLen(1) {};

    bool AdminLogin(string id, string pw);

    void AdminMenu() const;

    void AddBooks();

    void AdminAP();

    virtual void ShowBookList();

    void BookList();
};

#endif //LIBPROJECT1_ADMINMODE_H
