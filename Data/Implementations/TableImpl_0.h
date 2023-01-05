//
// Created by admpaw on 04.01.2023.
//

#ifndef AICAPROJECT_TABLEIMPL_0_H
#define AICAPROJECT_TABLEIMPL_0_H


#include "../Interfaces/Table.h"
#include "../CompressData.h"

class TableImpl_0 : public Table {
private:
    Settings settings;
    block *table;

    block cullingCount = settings.maxCullingCount;
    block currentOccupation = 0;

    CompressData data;

    void arrange(int &foundedIndex) override;

    void remember(block &originalByte) override;

public:
    explicit TableImpl_0(Settings settings);

    int find(block &originalByte) override;

    unsigned int currentTableEntropy() override;

};


#endif //AICAPROJECT_TABLEIMPL_0_H
