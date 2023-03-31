//
// Created by CMS on 2023-03-30.
//

#include "BookSetting.h"

BookSetting::BookSetting(int _PrimaryKey, string _BookName, string _Writer, string _Publisher) {
    PrimaryKey = _PrimaryKey;
    BookName = _BookName;
    Writer = _Writer;
    Publisher = _Publisher;
}
