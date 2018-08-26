#include "catch.hpp"
#include "algorithm.h"


TEST_CASE("algorithm")
{
    SECTION("insertion_sort")
    {
        vector<int> v1{ 3,2,1,5,4 };
        vector<int> r1{ 1,2,3,4,5 };
        vector<int> r11{ 1,2,3,5,4 };

        insertion_sort(v1);

        REQUIRE(v1 == r1);
        REQUIRE_FALSE(v1 == r11);
    }
}