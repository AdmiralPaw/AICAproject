//
// Created by admpaw on 04.01.2023.
//

#include "AlgorithmImpl_0.h"

CompressData AlgorithmImpl_0::compress(block originalByte) {
    CompressData data;
    data.originalByte = originalByte;
    data.indexInTable = table->find(originalByte);
    if (data.indexInTable == -1) {
        data.compressBit = false;
        data.resultCountBits = (sizeof(block) * 8) + 1;
    } else {
        data.compressBit = true;
        data.resultCountBits = table->currentTableEntropy() + 1;
    }
    return data;
}

AlgorithmImpl_0::AlgorithmImpl_0(Table *table) : table(table) {}
