#include <iostream>
#include <cmath>
#include <geom.hpp>
#include <calc.hpp>
#include <algebra.hpp>

namespace calculus {
    // Derivative using central difference 
    double derivative(double (*func)(double), double x, double h) {
        if (h <= 0) {
            std::cerr << "Error: Step size must be positive!" << "\n";
            return NAN;
        }
        // Central difference: f'(x) ≈ (f(x+h) - f(x-h)) / (2h)
        double result = (func(x + h) - func(x - h)) / (2 * h);
        return result;
    }

    // Integral using trapezoidal rule
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

    double limit(double (*func)(double), double x, double h) {
        if (h <= 0) {
            std::cerr << "Error: Step size must be positive!" << "\n";
            return NAN;
        }
        // Limit as h approaches 0: lim(h->0) (f(x+h) - f(x)) / h
        double result = (func(x + h) - func(x)) / h;
        return result;
    }

    double partialDerivative(double (*func)(double, double), double x, double y, double h) {
        if (h <= 0) {
            std::cerr << "Error: Step size must be positive!" << "\n";
            return NAN;
        }
        // Partial derivative with respect to x: ∂f/∂x ≈ (f(x+h, y) - f(x-h, y)) / (2h)
        double result = (func(x + h, y) - func(x - h, y)) / (2 * h);
        return result;
    }
} 