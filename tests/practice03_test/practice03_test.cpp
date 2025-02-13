#include "gtest/gtest.h"
#include "practice03.cpp"

TEST(MathUtilsTest, SumRange) {
    ASSERT_EQ(MathUtils::sumRange(1, 5), 10);  
    ASSERT_EQ(MathUtils::sumRange(5, 5), 0);  
}

TEST(MathUtilsTest, ContainsNegative) {
    std::vector<int> numbers1 = {3, -1, 5, 7};
    std::vector<int> numbers2 = {3, 1, 5, 7};

    ASSERT_TRUE(MathUtils::containsNegative(numbers1)); 
    ASSERT_FALSE(MathUtils::containsNegative(numbers2)); 
}

TEST(MathUtilsTest, FindMax) {
    std::vector<int> numbers1 = {3, -1, 5, 7};
    std::vector<int> numbers2 = {3, 3, 3, 3};

    ASSERT_EQ(MathUtils::findMax(numbers1), 7); 
    ASSERT_EQ(MathUtils::findMax(numbers2), 3); 
}