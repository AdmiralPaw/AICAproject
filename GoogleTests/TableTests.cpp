//
// Created by admpaw on 05.01.2023.
//

#include <gtest/gtest.h>
#include "../Base/Settings.h"
#include "../Data/Interfaces/Table.h"
#include "../Data/Implementations/TableImpl_0.h"

class TableTests : public ::testing::Test {
protected:
    Settings settings = Settings(16, 8, 4);
    Table *table = new TableImpl_0(settings);

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

    void inputChecker(int assertIndex, int assertEntropy) {
        ASSERT_EQ(table->find(input[i++]), assertIndex);
        ASSERT_EQ(table->currentTableEntropy(), assertEntropy);
    }
};

TEST_F(TableTests, TestTableAPI) {
    ASSERT_EQ(table->currentTableEntropy(), 0);
    // Table:
    inputChecker(-1, 1); // 0-> Table: 0                culling 8
    inputChecker(-1, 1); // 1-> Table: 1 0              culling 8
    inputChecker(0, 1);  // 1-> Table: 1 0              culling 7
    inputChecker(0, 1);  // 1-> Table: 1 0              culling 6

    inputChecker(-1, 2); // 2-> Table: 2 1 0            culling 5
    inputChecker(2, 2);  // 0-> Table: 0 2 1            culling 4
    inputChecker(0, 2);  // 0-> Table: 0 2 1            culling 3
    inputChecker(0, 2);  // 0-> Table: 0 2 1            culling 2

    inputChecker(0, 2);  // 0-> Table: 0 2 1            culling 1
    inputChecker(2, 2);  // 1-> Table: 1 0 2            culling 0
    inputChecker(2, 2);  // 2-> Table: 2 1 0            culling 8
    inputChecker(2, 1);  // 0-> Table: 0 2              culling 7

    inputChecker(-1, 2); // 3-> Table: 3 0 2            culling 7
    inputChecker(-1, 2); // 5-> Table: 5 3 0 2          culling 7
    inputChecker(-1, 3); // 6-> Table: 6 5 3 0 2        culling 7
    inputChecker(-1, 3); // 7-> Table: 7 6 5 3 0 2      culling 7

    inputChecker(-1, 3); // 8-> Table: 8 7 6 5 3 0 2    culling 7
    inputChecker(-1, 3); // 9-> Table: 9 8 7 6 5 3 0 2  culling 7
    inputChecker(-1, 3); // 1-> Table: 1 9 8 7 6 5 3 0  culling 7
    inputChecker(0, 3);  // 1-> Table: 1 9 8 7 6 5 3 0  culling 6

    inputChecker(0, 3);  // 1-> Table: 1 9 8 7 6 5 3 0  culling 5
    inputChecker(7, 3);  // 0-> Table: 0 1 9 8 7 6 5 3  culling 4
    inputChecker(-1, 3); // 2-> Table: 2 0 1 9 8 7 6 5  culling 4
    inputChecker(0, 3);  // 2-> Table: 2 0 1 9 8 7 6 5  culling 3

    inputChecker(0, 3);  // 2-> Table: 2 0 1 9 8 7 6 5  culling 2
    inputChecker(0, 3);  // 2-> Table: 2 0 1 9 8 7 6 5  culling 1
    inputChecker(1, 3);  // 0-> Table: 0 2 1 9 8 7 6 5  culling 0
    inputChecker(2, 3);  // 1-> Table: 1 0 2 9 8 7 6    culling 8

    inputChecker(1, 3);  // 0-> Table: 0 1 2 9 8 7 6    culling 7
    inputChecker(0, 3);  // 0-> Table: 0 1 2 9 8 7 6    culling 6
    inputChecker(-1, 3); // 3-> Table: 3 0 1 2 9 8 7 6  culling 6
    inputChecker(2, 3);  // 1-> Table: 1 3 0 2 9 8 7 6  culling 5
}