//
// Created by CMS on 2023-03-14.
//
#include <iostream>
#include "BookInfo.h"


BookInfo::BookInfo(string title, string writer, bool status, string date){
    this->title=title;
    this->writer=writer;
    this->date=date;
    this->status=status;
}

const string &BookInfo::GetTitle() const {
    return title;
}

const string &BookInfo::GetWriter() const {
    return writer;
}

const bool &BookInfo::GetStatus() const {
    return status;
}

const string &BookInfo::GetDate() const {
    return date;
}


