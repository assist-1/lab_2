#include <gtest/gtest.h>
#include "/mnt/d/CLionProjects/calc/calc_lib.h"


//make_double
TEST (MakeDouble, Test1) {
    char a[3] = {'1', '.', '3'};
    int len = 3;
    EXPECT_DOUBLE_EQ(1.3, make_double(a, len));
}

TEST (MakeDouble, Test2) {
    char a[5] = {'+', '5', '4', '.', '6'};
    int len = 5;
    EXPECT_DOUBLE_EQ(54.6, make_double(a, len));
}

TEST (MakeDouble, Test3) {
    char a[4] = {'-', '0', '.', '4'};
    int len = 4;
    EXPECT_DOUBLE_EQ(-0.4, make_double(a, len));
}

TEST (MakeDouble, Test4) {
    char a[4] = {'0', '.', '0', '4'};
    int len = 4;
    EXPECT_DOUBLE_EQ(0.04, make_double(a, len));
}


//priotrity
TEST (Priority, Test1) {
    char a = '+';
    EXPECT_EQ(1, priority(a));
}

TEST (Priority, Test2) {
    char a = '-';
    EXPECT_EQ(1, priority(a));
}

TEST (Priority, Test3) {
    char a = '*';
    EXPECT_EQ(2, priority(a));
}

TEST (Priority, Test4) {
    char a = '/';
    EXPECT_EQ(2, priority(a));
}

TEST (Priority, Test5) {
    char a = '(';
    EXPECT_EQ(-1, priority(a));
}

TEST (Priority, Test6) {
    char a = ')';
    EXPECT_EQ(-1, priority(a));
}

TEST (Priority, Test7) {
    char a = 'a';
    EXPECT_EQ(0, priority(a));
}


//make_operation
TEST (MakeOperation, Test1) {
    double a = 2.1, b = 4.5;
    char op = '+';
    EXPECT_DOUBLE_EQ(6.6, make_operation(a, b, op));
}

TEST (MakeOperation, Test2) {
    double a = 7.5, b = 1.3;
    char op = '-';
    EXPECT_DOUBLE_EQ(6.2, make_operation(a, b, op));
}

TEST (MakeOperation, Test3) {
    double a = -10.0, b = 2.0;
    char op = '/';
    EXPECT_DOUBLE_EQ(-5.0, make_operation(a, b, op));
}

TEST (MakeOperation, Test4) {
    double a = 0.5, b = 0.2;
    char op = '*';
    EXPECT_DOUBLE_EQ(0.1, make_operation(a, b, op));
}

TEST (MakeOperation, Test5) {
    double a = -2.1, b = 4.5;
    char op = '+';
    EXPECT_DOUBLE_EQ(2.4, make_operation(a, b, op));
}


//check_forward
TEST (CheckFroward, Test1){
    char str[3] = {'1', '+', '2'};
    int len = 3;
    EXPECT_EQ(true, check_forward(str, len));
}

TEST (CheckFroward, Test2){
    char str[10] = {'-', '1', '+', '2', '*', '(', '3', '+', '4', ')'};
    int len = 10;
    EXPECT_EQ(true, check_forward(str, len));
}

TEST (CheckFroward, Test3){
    char str[6] = {'1', '+', '(', '-', '2', ')'};
    int len = 6;
    EXPECT_EQ(true, check_forward(str, len));
}

TEST (CheckFroward, Test4){
    char str[5] = {'1', '+', ' ', '-', '2'};
    int len = 5;
    EXPECT_EQ(false, check_forward(str, len));
}

TEST (CheckFroward, Test6){
    char str[4] = {'(', '1', '+', '2'};
    int len = 4;
    EXPECT_EQ(false, check_forward(str, len));
}


//check_reverse
TEST (CheckReverse, Test1){
    char str[5] = {'1', ' ', '2', ' ', '+'};
    int len = 5;
    EXPECT_EQ(true, check_reverse(str, len));
}

TEST (CheckReverse, Test2){
    char str[5] = {'1', '+', '2', ' ', '+'};
    int len = 5;
    EXPECT_EQ(false, check_reverse(str, len));
}

TEST (CheckReverse, Test3){
    char str[5] = {'1', ' ', '2', ' ', '3'};
    int len = 5;
    EXPECT_EQ(false, check_reverse(str, len));
}

TEST (CheckReverse, Test4){
    char str[9] = {'1', ' ', '2', ' ', '3', ' ', '+', ' ', '*'};
    int len = 9;
    EXPECT_EQ(true, check_reverse(str, len));
}

TEST (CheckReverse, Test5){
    char str[5] = {'1', ' ', '2', ' ', ')'};
    int len = 5;
    EXPECT_EQ(false, check_reverse(str, len));
}


//calculate_reverse
TEST (CalculateReverse, Test1){
    char str[5] = {'1', ' ', '2', ' ', '+'};
    int len = 5;
    EXPECT_DOUBLE_EQ(3.0, calculate_reverse(str, len));
}

TEST (CalculateReverse, Test2){
    char str[9] = {'1', ' ', '2', ' ', '3', ' ', '+', ' ', '*'};
    int len = 9;
    EXPECT_DOUBLE_EQ(5.0, calculate_reverse(str, len));
}

TEST (CalculateReverse, Test3){
    char str[9] = {'1', ' ', '2', ' ', '*', ' ', '6', ' ', '*'};
    int len = 9;
    EXPECT_DOUBLE_EQ(12.0, calculate_reverse(str, len));
}

TEST (CalculateReverse, Test4){
    char str[14] = {'-', '1', ' ', '2', ' ', '3', ' ', '4', ' ', '*', ' ',
                    '-', ' ', '+'};
    int len = 14;
    EXPECT_DOUBLE_EQ(-11.0, calculate_reverse(str, len));
}


//forward_to_reverse
TEST (ForwardToReverse, Test1){
    char str[3] = {'1', '+', '2'};
    int len = 3;
    char answ_str[6] = {'1', ' ', '2', ' ', '+', ' '};
    EXPECT_STREQ(answ_str, forward_to_reverse(str, len));
}

TEST (ForwardToReverse, Test2){
    char str[10] = {'-', '1', '+', '2', '*', '(', '3', '+', '4', ')'};
    int len = 10;
    char answ_str[15] = {'-', '1', ' ', '2', ' ', '3', ' ', '4',
                         ' ', '+', ' ', '*', ' ', '+', ' '};
    EXPECT_STREQ(answ_str, forward_to_reverse(str, len));
}

TEST (ForwardToReverse, Test3){
    char str[6] = {'1', '+', '(', '-', '2', ')'};
    int len = 6;
    char answ_str[7] = {'1', ' ', '-', '2', ' ', '+', ' '};
    EXPECT_STREQ(answ_str, forward_to_reverse(str, len));
}

TEST (ForwardToReverse, Test4){
    char str[11] = {'1', '0', '*', '(', '-', '3', '+', '4', '*', '5', ')'};
    int len = 11;
    char answ_str[16] = {'1', '0', ' ', '-', '3', ' ', '4', ' ', '5', ' ',
                         '*', ' ', '+', ' ', '*', ' '};
    EXPECT_STREQ(answ_str, forward_to_reverse(str, len));
}


//len_of_reversed
TEST (LenOfReversed, Test1){
    char str[17] = {'1', '0', ' ', '-', '3', ' ', '4', ' ', '5', ' ',
                         '*', ' ', '+', ' ', '*', ' ', ';'};
    EXPECT_EQ(16, len_of_reversed(str));
}

TEST (LenOfReversed, Test2){
    char str[8] = {'1', ' ', '-', '2', ' ', '+', ' ', ';'};
    EXPECT_EQ(7, len_of_reversed(str));
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}