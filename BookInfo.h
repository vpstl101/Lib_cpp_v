//
// Created by CMS on 2023-03-14.
//

#ifndef LIBPROJECT1_BOOKINFO_H
#define LIBPROJECT1_BOOKINFO_H

using namespace std;

class BookInfo {
private:
    int primaryKey;
    string title;
    string writer;
    bool status;
    string date;

public:
    BookInfo(int primaryKey, string title, string writer, bool status, string date);

    const int &GetPrimary();

    const string &GetTitle() const;

    const string &GetWriter() const;

    const bool &Status() const;

    const void GetStatPrint() const;

    const string &GetDate() const;

};


#endif //LIBPROJECT1_BOOKINFO_H
