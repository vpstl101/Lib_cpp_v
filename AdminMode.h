//
// Created by CMS on 2023-03-13.
//

#ifndef LIBPROJECT1_ADMINMODE_H
#define LIBPROJECT1_ADMINMODE_H

#include "BookInfo.h"
#include "CreatArray.h"

using namespace std;

class AdminMode
{
private:
    CreatArray<BookInfo *> bookArr;
    int arrNum;
public:
    AdminMode() : arrNum(0){};

    bool AdminLogin(string id, string pw);
    void AdminMenu();
    void AddBooks();
    void AdminApplication();
    void ShowBookList();
};

#endif //LIBPROJECT1_ADMINMODE_H
