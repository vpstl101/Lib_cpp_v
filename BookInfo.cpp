//
// Created by CMS on 2023-03-14.
//
#include <iostream>
#include "BookInfo.h"
#include "AdminMode.h"


BookInfo::BookInfo(int primaryKey, string title, string writer, bool status, string date) {
    this->primaryKey = primaryKey;
    this->title = title;
    this->writer = writer;
    this->status = status;
    this->date = date;
}

const int &BookInfo::GetPrimary() {
    return primaryKey;
}

const string &BookInfo::GetTitle() const {
    return title;
}

const string &BookInfo::GetWriter() const {
    return writer;
}

const bool &BookInfo::Status() const {
    return status;
}

/*void BookInfo::GetStatPrint(){
   cout<< ((Status() == AdminMode::BORROW::ENABLE) ?  "ENABEL" : "UNABLE") << endl;
}*/

const string &BookInfo::GetDate() const {
    return date;
}

