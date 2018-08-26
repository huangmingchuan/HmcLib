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

    SECTION("merge_sort")
    {
        vector<int> v1{ 3,2,1,5,4 };
        vector<int> r1{ 1,2,3,4,5 };

        vector<int> v2{ 3,2,1,5,4,7,6,9,8 };
        vector<int> r2{ 1,2,3,4,5,6,7,8,9 };

        vector<int> r11{ 1,2,3,5,4 };

        merge_sort(v1);
        merge_sort(v2);

        REQUIRE(v1 == r1);
        REQUIRE(v2 == r2);
        REQUIRE_FALSE(v1 == r11);
    }
}