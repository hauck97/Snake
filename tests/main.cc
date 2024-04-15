#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <vector>

#include "snake.h"
#include "LinkedList.h"

bool vectorsAreEqual(const std::vector<int>& v1, const std::vector<int>& v2) {
    return v1.size() == v2.size() && std::equal(v1.begin(), v1.end(), v2.begin());
}

TEST_CASE("Snake head direction is computet right for left", "[snakehead_movement]")
{
    std::vector test_vec {2,2};
    std::vector result_vec {2,0};
    calculateSnakeHeadPosition(test_vec, 97);
    REQUIRE(vectorsAreEqual(test_vec, result_vec));
}

TEST_CASE("Snake head direction is computet right for right", "[snakehead_movement]")
{
    std::vector test_vec {2,2};
    std::vector result_vec {2,4};
    calculateSnakeHeadPosition(test_vec, 100);
    REQUIRE(vectorsAreEqual(test_vec, result_vec));
}

TEST_CASE("Snake head direction is computet right for up", "[snakehead_movement]")
{
    std::vector test_vec {2,2};
    std::vector result_vec {3,2};
    calculateSnakeHeadPosition(test_vec, 115);
    REQUIRE(vectorsAreEqual(test_vec, result_vec));
}

TEST_CASE("Snake head direction is computet right for down", "[snakehead_movement]")
{
    std::vector test_vec {2,2};
    std::vector result_vec {1,2};
    calculateSnakeHeadPosition(test_vec, 119);
    REQUIRE(vectorsAreEqual(test_vec, result_vec));
}
