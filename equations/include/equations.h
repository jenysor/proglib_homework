#ifndef PROGLIB_HOMEWORK_EQUATIONS_H
#define PROGLIB_HOMEWORK_EQUATIONS_H

#include <set>

class Equation {
public:
    static std::set<double> solve(double a, double b, double c);

    static void check(double a, double b, double c);

private:
    static constexpr double eps{1e-7};
};

#endif // PROGLIB_HOMEWORK_EQUATIONS_H
