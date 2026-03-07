#include <iostream>
#include <cmath>
#include "calc.hpp"
#include "geom.hpp"
#include "algebra.hpp"

namespace algebra {

double solveQuadratic(double a, double b, double c) {
     if (a == 0) {
        std::cerr << "Error: Coefficient 'a' cannot be zero!" << "\n";
        return NAN;
    }
    double discriminant = calc::expo(b, 2) - (4 * a * c);
    //std::cout << "Discriminant: " << discriminant << "\n";
    //std::cout << "sqrt(discriminant): " << calc::squrt(discriminant) << "\n";
    //std::cout << "-b: " << -b << "\n";
    //std::cout << "2*a: " << (2 * a) << "\n";

    if (discriminant < 0) {
        std::cerr << "Error: No real roots!" << "\n";
        return NAN;
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        std::cout << "One real root: " << root << "\n";
        return root;
    } else {
        double root1 = (-b + calc::squrt(discriminant)) / (2 * a);
        double root2 = (-b - calc::squrt(discriminant)) / (2 * a);
        std::cout << "Two real roots: " << root1 << " and " << root2 << "\n";
        return root1;
    }
}

double solveLinear(double a, double b, double c) {
    if (a == 0) {
        std::cerr << "Error: Coefficient 'a' cannot be zero!\n";
        return 0;
    }
    double x = (c - b) / a;
    std::cout << "Solution: x = " << x << "\n";
    return x;
}

double solveSystem2x2(double a1, double b1, double c1, double a2, double b2, double c2) {
    double determinant = (a1 * b2) - (a2 * b1);
    if (determinant == 0) {
        std::cerr << "Error: No unique solution!" << "\n";
        return -1;
    }
    double x = (c1 * b2 - c2 * b1) / determinant;
    double y = (a1 * c2 - a2 * c1) / determinant;
    std::cout << "Solution: x = " << x << ", y = " << y << "\n";
    return 0;
}

double solveSystem3x3(double a1, double b1, double c1, double d1, double a2, double b2, double c2, double d2, double a3, double b3, double c3, double d3) {
    double determinant = a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
    if (determinant == 0) {
        std::cerr << "Error: No unique solution!" << "\n";
        return -1;
    }
    double x = (d1 * (b2 * c3 - b3 * c2) - b1 * (d2 * c3 - d3 * c2) + c1 * (d2 * b3 - d3 * b2)) / determinant;
    double y = (a1 * (d2 * c3 - d3 * c2) - d1 * (a2 * c3 - a3 * c2) + c1 * (a2 * d3 - a3 * d2)) / determinant;
    double z = (a1 * (b2 * d3 - b3 * d2) - b1 * (a2 * d3 - a3 * d2) + d1 * (a2 * b3 - a3 * b2)) / determinant;
    std::cout << "Solution: x = " << x << ", y = " << y << ", z = " << z << "\n";
    return 0;
}

double solveSystem4x4(double a1, double b1, double c1, double d1, double e1, double a2, double b2, double c2, double d2, double e2, double a3, double b3, double c3, double d3, double e3, double a4, double b4, double c4, double d4, double e4) {
    // This function is complex and typically requires matrix operations or Cramer's rule for 4x4 systems.
    // For simplicity, we will not implement it here and return an error message.
    std::cerr << "Error: Solving 4x4 systems is not implemented!" << "\n";
    return 0;
}
}