#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "equations.h"

TEST(Equasion, Solve_NoRoots)
{
    std::set<double> etalon{};
    ASSERT_EQ(etalon, Equation::solve(1,0,1));
}

TEST(Equasion, Solve_TwoRoots)
{
    std::set<double> etalon{-1,1};
    ASSERT_EQ(etalon, Equation::solve(1,0,-1));
}

TEST(Equasion, Solve_OneRoot)
{
    std::set<double> etalon{-1};
    ASSERT_EQ(etalon, Equation::solve(1,2,1));
}

TEST(Equasion, Solve_NullCoef)
{
    ASSERT_THROW(Equation::solve(0,2,1), std::runtime_error);
}

TEST(Equasion, Solve_TwoRoots_LessEps)
{
    std::set<double> etalon{1.00005};
    ASSERT_EQ(etalon, Equation::solve(1,-2.0001, 1.0001));
}

TEST(Equasion, Solve_NanCoef)
{
    ASSERT_THROW(Equation::solve(NAN, NAN, NAN), std::runtime_error);
}

TEST(Equasion, Solve_InfCoef)
{
    ASSERT_THROW(Equation::solve(INFINITY, INFINITY, INFINITY), std::runtime_error);
}