#include <iostream>
#include "gtest/gtest.h"
#include "C:\Users\proko\CLionProjects\laba\lab_2\function.cpp"
using std::cout;

TEST (Positiv, forn1) {
    // 2 + 1
    int sign[3] = {7, 4, 7};
    int num[3] = {2, 0, 1};
    ASSERT_EQ(1, Resultfor(sign, num, 3));
}
TEST (Positiv, forn2) {
    // - 2 + (- 0 + 6)*2
    int sign[11] = {4, 7, 3, -1, 4, 7, 3, 7, -2, 2, 7 };
    int num[11] = {0, 2, 0, 0, 0, 0, 0, 6, 0, 0, 2};
    ASSERT_EQ(10, Resultfor(sign, num, 11));
}
TEST (Positiv, revn1) {
    // 1 2 -
    int sign[3] = {7, 7, 4};
    int num[3] = {1, 2, 0};
    ASSERT_EQ(-1, Resultrev(sign, num, 3));
}
TEST (Positiv, revn2) {
    //1 2 + 3 4 * -
    int sign[7] = {7, 7, 3, 7, 7, 2, 4};
    int num[7] = {1, 2, 0, 3, 4, 0, 0};
    ASSERT_EQ(-9, Resultrev(sign, num, 7));
}
TEST (Positiv, difficultfor) {
    //(- 12+  46)*2 + (46/2+13) - 24+ 60/5+( (  (1-2)*2)*6)
    int sign[36] = {-1, 4, 7, 3, 7, -2, 2, 7, 3, -1, 7, 1, 7, 3, 7, -2, 4, 7, 3, 7, 1, 7, 3, -1, -1, -1, 7, 4, 7, -2, 2, 7, -2, 2, 7, -2};
    int num[36] = {0, 0, 12, 0, 46, 0, 0, 2, 0, 0, 46, 0, 2, 0, 13, 0, 0, 24, 0, 60, 0, 5, 0, 0, 0, 0, 1, 0, 2, 0, 0, 2, 0,0,6,0};
    ASSERT_EQ(80, Resultfor(sign, num, 36));
}
TEST (Positiv, difficultrev) {
    //1 2 - 3 4 + * 8 4 / 4 * +
    int sign[13] = {7, 7, 4, 7, 7, 3, 2, 7, 7, 1, 7, 2, 3};
    int num[13] = {1, 2, 0, 3, 4, 0, 0, 8, 4, 0, 4, 0, 0};
    ASSERT_EQ(1, Resultrev(sign, num, 13));
}
TEST (Negativ, forn1) {
    //1 2
    int sign[2] = {7, 7};
    int num[2] = {1, 2};
    ASSERT_EQ(0, Resultfor(sign, num, 2));
}
TEST (Negativ, forn2) {
    //1 -+ 2
    int sign[4] = {7, 4, 3, 7};
    int num[4] = {1, 0,0, 2};
    ASSERT_EQ(0, Resultfor(sign, num, 4));
}
TEST (Negativ, forn3) {
    //1 q 2
    int sign[3] = {7, 12, 7};
    int num[3] = {1, 0,2};
    ASSERT_EQ(0, Resultfor(sign, num, 3));
}
TEST (Negativ, revn1) {
    //1 2
    int sign[2] = {7, 7};
    int num[2] = {1, 2};
    ASSERT_EQ(0, Resultrev(sign, num, 2));
}
TEST (Negativ, revn2) {
    //1 2 --
    int sign[4] = {7, 7, 4, 4};
    int num[4] = {1, 2,0, 0};
    ASSERT_EQ(0, Resultrev(sign, num, 4));
}
TEST (Negativ, revn3) {
    // 1 -
    int sign[2] = {7, 4};
    int num[2] = {1, 0};
    ASSERT_EQ(0, Resultrev(sign, num, 2));
}
TEST (Enter, n1) {
    int argc = 0;
    ASSERT_EQ(0, EnterCheck(argc));
}
TEST (Enter, n2) {
    int argc = 2;
    ASSERT_EQ(0, EnterCheck(argc));
}

int main(int argc1, char **argv1)
{
    ::testing::InitGoogleTest(&argc1, argv1);

    return RUN_ALL_TESTS();
}
