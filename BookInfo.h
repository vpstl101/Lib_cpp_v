//
// Created by CMS on 2023-03-14.
//

#ifndef LIBPROJECT1_BOOKINFO_H
#define LIBPROJECT1_BOOKINFO_H

using namespace std;

class BookInfo {
private:
    string title;
    string writer;
    bool status;
    string date;

public:
    BookInfo(string title, string writer, bool status, string date);

    const string &GetTitle() const;

    const string &GetWriter() const;

    const bool &GetStatus() const;

    const string &GetDate() const;

};


#endif //LIBPROJECT1_BOOKINFO_H
