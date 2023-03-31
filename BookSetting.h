//
// Created by CMS on 2023-03-30.
//

#ifndef LIBPROJECT1_BOOKSETTING_H
#define LIBPROJECT1_BOOKSETTING_H

#include <iostream>

using namespace std;

class BookSetting {
private:
    int PrimaryKey;
    string BookName;
    string Writer;
    string Publisher;
public:
    BookSetting(int _PrimaryKey, string _BookName, string _Writer, string _Publisher);
/*    const int &GetID() const;
    const string &GetPW() const;
    const string &GetName() const;
    const string &GetPhoneNum() const;*/


};


#endif //LIBPROJECT1_BOOKSETTING_H
