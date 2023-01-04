//
// Created by admpaw on 04.01.2023.
//

#ifndef AICAPROJECT_COMPRESSDATA_H
#define AICAPROJECT_COMPRESSDATA_H


#include "../Base/Settings.h"

class CompressData {
    bool compressBit = false;
    int indexInTable = -1;
    unsigned int resultCountBits = 0;
    block originalByte = 0;
};


#endif //AICAPROJECT_COMPRESSDATA_H
