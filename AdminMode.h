//
// Created by CMS on 2023-03-13.
//

#ifndef LIBPROJECT1_ADMINMODE_H
#define LIBPROJECT1_ADMINMODE_H

#include "BookInfo.h"
#include "CreatArray.h"
#include "LibManager.h"

class AdminMode : public LibManager {
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
        LIST
    };
    enum BORROW {
        UNABLE,
        ENABLE
    };

    AdminMode()
            : LibManager(), arrNum(0), listLen(1) {};

    bool AdminLogin(string id, string pw);

    void AdminMenu() const;

    void AddBooks();

    void AdminAP();

    //virtual void GetList();

   virtual void ShowBookList();

    void BookList();

    void DelBook();

};

#endif //LIBPROJECT1_ADMINMODE_H
