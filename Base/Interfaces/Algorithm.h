//
// Created by admpaw on 04.01.2023.
//

#ifndef AICAPROJECT_ALGORITHM_H
#define AICAPROJECT_ALGORITHM_H


#include "../../Data/Interfaces/Table.h"
#include "../../Data/CompressData.h"

class Algorithm {
public:
    Algorithm() = default;
    virtual ~Algorithm() = default;
    virtual CompressData compress(block originalByte) = 0;
    //decompressData decompress(originalByte)
};


#endif //AICAPROJECT_ALGORITHM_H
