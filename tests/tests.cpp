#include <catch2/catch.hpp>
#define CONFIG_CATCH_MAIN

#include "vector2.h"
#include <iostream>

TEST_CASE("Vector2 integer addition")
{
    SECTION("Positive addition")
    {
        CHECK(Vector2{2, 4} + Vector2{5, 6} == Vector2{7, 10});
    }

    SECTION("Negative addition")
    {
        CHECK(Vector2{2, 4} + Vector2{5, -6} == Vector2{7, -2});
        CHECK(Vector2{2, 4} + Vector2{-5, -6} == Vector2{-3, -2});
    }

}

TEST_CASE("Vector2 integer subtraction")
{
    SECTION("Positive subtraction")
    {
        CHECK(Vector2{2, 4} - Vector2{5, 6} == Vector2{-3, -2});
    }

    SECTION("Negative subtraction")
    {
        CHECK(Vector2{5, 10} - Vector2{-5, -4} == Vector2{10, 14});
    }
}

TEST_CASE("Vector2 dot product")
{
    CHECK(Vector2{5, 0}.dotProduct(Vector2{2, 5}) == 10);
    CHECK(Vector2{5, 1}.dotProduct(Vector2{2, 5}) == 15);
    CHECK(Vector2{5, -1}.dotProduct(Vector2{2, 5}) == 5);
    CHECK(Vector2{-5, 0}.dotProduct(Vector2{2, 5}) == -10);
    CHECK(Vector2{-5, 0}.dotProduct(Vector2{-2, 5}) == 10);
}