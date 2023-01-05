//
// Created by admpaw on 04.01.2023.
//

#ifndef AICAPROJECT_TABLE_H
#define AICAPROJECT_TABLE_H


#include "../../Base/Settings.h"

class Table {
private:
    virtual void arrange(int &foundedIndex) = 0;

    virtual void remember(block &originalByte) = 0;

public:
    virtual int find(block &originalByte) = 0;

    virtual unsigned int currentTableEntropy() = 0;
};


#endif //AICAPROJECT_TABLE_H
