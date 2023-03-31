//
// Created by CMS on 2023-03-27.
//

#ifndef LIBPROJECT1_GENERALMODE_H
#define LIBPROJECT1_GENERALMODE_H

#include "BookInfo.h"
#include "CreatArray.h"
#include "AdminMode.h"


class GeneralMode{
private:
    CreatArray<BookInfo *> bookArr;
    int arrNum;

public:
    GeneralMode() :arrNum(0) {};
            //: AdminMode(),

    void GeneralMenu() const;

    void GernerAP();

};


#endif //LIBPROJECT1_GENERALMODE_H
