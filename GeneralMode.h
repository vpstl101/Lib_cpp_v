//
// Created by CMS on 2023-03-27.
//

#ifndef LIBPROJECT1_GENERALMODE_H
#define LIBPROJECT1_GENERALMODE_H

#include "BookInfo.h"
#include "CreatArray.h"
#include "AdminMode.h"

class GeneralMode : public AdminMode {
public:
    GeneralMode()
            : AdminMode() {};
public:
    enum G_MENU {
        EXIT,
        BOOK_INFO,
        SEARCH,
        LOAN,
        RETURN,
        STORAGE,
        DONATE
    };
    void GeneralMenu() const;

    void GernerAP();

};


#endif //LIBPROJECT1_GENERALMODE_H
