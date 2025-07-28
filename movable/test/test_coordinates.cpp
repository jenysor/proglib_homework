#include "gtest/gtest.h"
#include "movable.h"

TEST(TestCoordinates, Coordinates_Compare_Equal)
{
    Coordinates a{.x = 12.0, .y = 5.0};
    Coordinates b{.x = 12.0, .y = 5.0};

    ASSERT_TRUE(a == b);
}

TEST(TestCoordinates, Coordinates_Compare_NotEqualX)
{
    Coordinates a{.x = 12.0, .y = 5.0};
    Coordinates b{.x = -7.0, .y = 5.0};

    ASSERT_FALSE(a == b);
}

TEST(TestCoordinates, Coordinates_Compare_NotEqualY)
{
    Coordinates a{.x = 12.0, .y = 5.0};
    Coordinates b{.x = 12.0, .y = 3.0};

    ASSERT_FALSE(a == b);
}

TEST(TestCoordinates, Coordinates_Compare_NotEqualXY)
{
    Coordinates a{.x = 12.0, .y = 5.0};
    Coordinates b{.x = -7.0, .y = 3.0};

    ASSERT_FALSE(a == b);
}