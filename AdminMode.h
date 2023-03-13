//
// Created by CMS on 2023-03-13.
//

#ifndef LIBPROJECT1_ADMINMODE_H
#define LIBPROJECT1_ADMINMODE_H

using namespace std;

class AdminMode
{
public:
    AdminMode(){};

    bool AdminLogin(string id, string pw);
    int AdminMenu();
    void AddBooks();
    void AdminApplication();
};

#endif //LIBPROJECT1_ADMINMODE_H
