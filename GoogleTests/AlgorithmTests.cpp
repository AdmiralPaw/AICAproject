//
// Created by admpaw on 05.01.2023.
//

#include <gtest/gtest.h>
#include "../Base/Settings.h"
#include "../Base/Interfaces/Algorithm.h"
#include "../Base/Implementations/AlgorithmImpl_0.h"

class AlgorithmTests : public ::testing::Test {
protected:
    Settings settings = Settings(16, 8, 4);
    Algorithm *algorithm = new AlgorithmImpl_0();
    block input[32] = {
            0, 1, 1, 1,
            2, 0, 0, 0,
            0, 1, 2, 0,
            3, 5, 6, 7,
            8, 9, 1, 1,
            1, 0, 2, 2,
            2, 2, 0, 1,
            0, 0, 3, 1
    };
    int i = 0;

    void inputChecker(bool compressBit, int indexInTable, block originalByte, unsigned int resultCountBits) {
        CompressData data = algorithm->compress(input[i++]);
        ASSERT_EQ(data.compressBit, compressBit);
        ASSERT_EQ(data.indexInTable, indexInTable);
        ASSERT_EQ(data.originalByte, originalByte);
        ASSERT_EQ(data.resultCountBits, resultCountBits);
    }
};

TEST_F(AlgorithmTests, CompressTesting) {
    inputChecker(false, -1, 0, 9);
    inputChecker(false, -1, 1, 9);
    inputChecker(true, 0, 1, 2);
    inputChecker(true, 0, 1, 2);

    inputChecker(false, -1, 2, 9);
    inputChecker(true, 2, 0, 3);
    inputChecker(true, 0, 0, 3);
    inputChecker(true, 0, 0, 3);

    inputChecker(true, 0, 0, 3);
    inputChecker(true, 2, 1, 3);
    inputChecker(true, 2, 2, 3);
    inputChecker(true, 2, 0, 2);

    inputChecker(false, -1, 3, 9);
    inputChecker(false, -1, 5, 9);
    inputChecker(false, -1, 6, 9);
    inputChecker(false, -1, 7, 9);

    inputChecker(false, -1, 8, 9);
    inputChecker(false, -1, 9, 9);
    inputChecker(false, -1, 1, 9);
    inputChecker(true, 0, 1, 4);

    inputChecker(true, 0, 1, 4);
    inputChecker(true, 7, 0, 4);
    inputChecker(false, -1, 2, 9);
    inputChecker(true, 0, 2, 4);

    inputChecker(true, 0, 2, 4);
    inputChecker(true, 0, 2, 4);
    inputChecker(true, 1, 0, 4);
    inputChecker(true,2, 1, 4);

    inputChecker(true, 1, 0, 4);
    inputChecker(true, 0, 0, 4);
    inputChecker(false, -1, 3, 9);
    inputChecker(true, 2, 1, 4);

}