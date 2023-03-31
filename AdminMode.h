//
// Created by CMS on 2023-03-13.
//

#ifndef LIBPROJECT1_ADMINMODE_H
#define LIBPROJECT1_ADMINMODE_H

#include "BookInfo.h"
#include "CreatArray.h"
#include "BookLIstArray.h"

using namespace std;

class AdminMode
{
private:
    CreatArray<BookInfo *> bookArr;
    BookLIstArray<BookSetting *> BookArr;
    int arrNum;
public:
    AdminMode() : arrNum(0){};

    bool AdminLogin(string id, string pw);
    void AdminMenu();
    void AddBooks();
    void AdminAP();
    void ShowBookList();
    void BookList();
};

#endif //LIBPROJECT1_ADMINMODE_H
