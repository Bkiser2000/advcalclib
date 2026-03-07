#include <iostream>
#include <geom.hpp>
#include <calc.hpp>
#include <algebra.hpp>

namespace calculus {
    double derivative(double (*func)(double), double x, double h) {
        if (h <= 0) {
            std::cerr << "Error: Step size must be positive!" << "\n";
            return -1;
        }
        double result = (func(x + h) - func(x)) / h;
        //std::cout << "Derivative at x = " << x << " is approximately: " << result << "\n";
        return result;
    }

    double integral(double (*func)(double), double a, double b, int n) {
        if (n <= 0) {
            std::cerr << "Error: Number of subdivisions must be positive!" << "\n";
            return -1;
        }
        double h = (b - a) / n;
        double sum = 0.5 * (func(a) + func(b));
        for (int i = 1; i < n; i++) {
            sum += func(a + i * h);
        }
        double result = sum * h;
        //std::cout << "Integral from " << a << " to " << b << " is approximately: " << result << "\n";
        return result;
    }
} 