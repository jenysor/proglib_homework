#include "equations.h"
#include <cmath>
#include <stdexcept>

void Equation::check(double a, double b, double c)
{
    if (std::isnan(a) || std::isnan(b) || std::isnan(c)) {
        throw std::runtime_error("coef is NAN");
    }
    else if (std::isinf(a) || std::isinf(b) || std::isinf(c)) {
        throw std::runtime_error("coef is INFINITY");
    }
    else if (std::abs(a) < eps) {
        throw std::runtime_error("a == 0");
    }
}

std::set<double> Equation::solve(double a, double b, double c)
{
    check(a, b, c);

    double discriminant = b * b - 4 * a * c;

    if (discriminant > eps) {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        return {x1, x2};
    }
    else if (discriminant < -eps) {
        return {};
    }
    else {
        double x = -b / (2 * a);
        return {x};
    }
}

