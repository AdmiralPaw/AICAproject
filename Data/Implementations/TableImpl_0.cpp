//
// Created by admpaw on 04.01.2023.
//

#include <cmath>
#include "TableImpl_0.h"
#include "../../Utils/Utils.h"

TableImpl_0::TableImpl_0(Settings settings) : settings(settings) {
    this->table = new block[this->settings.maxTableSize];
}

int TableImpl_0::find(block &originalByte) {
    for (int i = 0; i <= currentOccupation; i++) {
        if (originalByte == table[i]) {
            arrange(i);
            return i;
        }
    }
    remember(originalByte);
    return -1;
}

void TableImpl_0::arrange(int &foundedIndex) {
    block temp = table[foundedIndex];
    memcpy(&table[1], &table[0], foundedIndex * sizeof(block));
    table[0] = temp;

    if (cullingCount > 0) {
        cullingCount--;
    } else {
        currentOccupation = currentOccupation - 1;
        cullingCount = this->settings.maxCullingCount;
    }
}

void TableImpl_0::remember(block &originalByte) {
    memcpy(&table[1], &table[0], currentOccupation * sizeof(block));
    this->table[0] = originalByte;
    if (this->currentOccupation + 1 < this->settings.maxTableSize) {
        this->currentOccupation = this->currentOccupation + 1;
    }
}

unsigned int TableImpl_0::currentTableEntropy() {
    return ceil(log2(currentOccupation == 0 ? 1.0 : (double) currentOccupation));
}
