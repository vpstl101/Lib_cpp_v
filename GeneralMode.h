//
// Created by CMS on 2023-03-27.
//

#ifndef LIBPROJECT1_GENERALMODE_H
#define LIBPROJECT1_GENERALMODE_H

#include "BookInfo.h"
#include "CreatArray.h"
#include "AdminMode.h"

class GeneralMode : public AdminMode {
private:
    CreatArray<BookInfo *> bookArr;
    int arrNum;

public:
    GeneralMode()
            : AdminMode(), arrNum(0) {};

    void GeneralMenu() const;

    void SearchBook();

    void GernerAP();

};


#endif //LIBPROJECT1_GENERALMODE_H
