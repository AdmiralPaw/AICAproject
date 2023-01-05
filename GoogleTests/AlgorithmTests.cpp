//
// Created by admpaw on 05.01.2023.
//

#include <gtest/gtest.h>
#include "../Base/Settings.h"
#include "../Base/Interfaces/Algorithm.h"
#include "../Base/Implementations/AlgorithmImpl_0.h"
#include "../Data/Implementations/TableImpl_0.h"

class AlgorithmTests : public ::testing::Test {
protected:
    Settings settings = Settings(8, 8, 4);
    Table *table = new TableImpl_0(settings);
    Algorithm *algorithm = new AlgorithmImpl_0(table);
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
    int counter = 0;

    static const int inputSize = 104857600;
    block largeInput[inputSize]{};

    inline void inputChecker(bool compressBit, int indexInTable, block originalByte, unsigned int resultCountBits) {
        CompressData data = algorithm->compress(input[counter++]);
        ASSERT_EQ(data.compressBit, compressBit);
        ASSERT_EQ(data.indexInTable, indexInTable);
        ASSERT_EQ(data.originalByte, originalByte);
        ASSERT_EQ(data.resultCountBits, resultCountBits);
    }

    void prepareData() {
        srand(0);
        for (unsigned char &i: largeInput) {
            i = rand();
        }
    }

    void speedTest() {
        for (unsigned char &i: largeInput) {
            algorithm->compress(input[i]);
        }
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

TEST_F(AlgorithmTests, SpeedTest) {
    table = new TableImpl_0(settings);
    algorithm = new AlgorithmImpl_0(table);

    prepareData();
    std::clock_t start = clock();

    speedTest();

    std::clock_t end = clock();
    printf("\ndataSize = %d(Mb)", inputSize / 1024 / 1024);
    printf("\ntime = %ld(ms)", end - start);
    printf("\nspeed = %0.2f(Mib/s)\n\n", ((double)inputSize / 1024 / 1024) / (end - start) * 1000);
}