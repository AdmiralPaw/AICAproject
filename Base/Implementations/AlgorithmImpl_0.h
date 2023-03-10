//
// Created by admpaw on 04.01.2023.
//

#ifndef AICAPROJECT_ALGORITHMIMPL_0_H
#define AICAPROJECT_ALGORITHMIMPL_0_H


#include "../../Data/CompressData.h"
#include "../Interfaces/Algorithm.h"

class AlgorithmImpl_0 : public Algorithm {
private:
    Table *table;

public:
    explicit AlgorithmImpl_0(Table *table);

    CompressData compress(block originalByte) override;
};


#endif //AICAPROJECT_ALGORITHMIMPL_0_H
