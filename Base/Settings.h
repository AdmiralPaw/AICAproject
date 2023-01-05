//
// Created by admpaw on 04.01.2023.
//

#ifndef AICAPROJECT_SETTINGS_H
#define AICAPROJECT_SETTINGS_H

#include <cstdint>

typedef uint8_t block;

class Settings {
public:
    Settings(unsigned int maxTableSize, unsigned int maxCullingCount, unsigned int maxRefreshValue);

    Settings() = default;

public:
    unsigned int maxTableSize = 16;
    unsigned int maxCullingCount = 8;
    unsigned int maxRefreshValue = 4;
};


#endif //AICAPROJECT_SETTINGS_H
