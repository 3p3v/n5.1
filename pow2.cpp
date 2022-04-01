#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
vector<T> pow2(vector<T> const& input)
{
    vector<T> helper(input.size());
    transform(begin(input), end(input), begin(helper), [](const T& value){return value*value;});
    return vector<T>{helper};
}

TEST(Pow2Test, Test)
{
    vector<long> input =    {2, 5,  10,  15,  20,  25,  30,  45,   100};
    vector<long> expected = {4, 25, 100, 225, 400, 625, 900, 2025, 10000};
    auto actual = pow2(input);

    ASSERT_EQ(expected, actual);
}

int main(int ac, char ** av)
{
    ::testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}

