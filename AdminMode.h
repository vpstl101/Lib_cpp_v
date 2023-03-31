//
// Created by CMS on 2023-03-13.
//

#ifndef LIBPROJECT1_ADMINMODE_H
#define LIBPROJECT1_ADMINMODE_H

#include "BookInfo.h"
#include "CreatArray.h"

using namespace std;

class AdminMode {
private:
    CreatArray<BookInfo *> bookArr;
    //BookLIstArray<BookSetting *> BookArr;
    int arrNum;
public:
    enum BORROW {
        UNABLE,
        ENABLE
    };

    AdminMode() : arrNum(0) {};

    bool AdminLogin(string id, string pw);

    void AdminMenu() const;

    void AddBooks();

    void AdminAP();

    void ShowBookList();

    int BookList();
};

#endif //LIBPROJECT1_ADMINMODE_H
