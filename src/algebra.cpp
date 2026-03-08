#include <iostream>
#include <cmath>
#include <vector>
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

double solvePolynomial(double* coefficients, int degree, double x) {
    double result = 0;
    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * calc::expo(x, degree - i);
    }
    return result;
}

double solveCubic(double a, double b, double c, double d) {
    // This function is complex and typically requires numerical methods for solving cubic equations.
    // For simplicity, we will not implement it here and return an error message.
    std::cerr << "Error: Solving cubic equations is not implemented!" << "\n";
    return 0;
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

double differenceOfSquares(double a, double b) {
    double diffSq = (a - b) * (a + b);
    return diffSq;
}

double binomialExpansion(double a, double b, int n) {
    double result = 0;
    for (int k = 0; k <= n; k++) {
        double coeff = calc::expo(a, n - k) * calc::expo(b, k);
        result += coeff;
    }
    return result;
}

double greatestCommonFactor(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Vector magnitude (length)
double vectorMagnitude(const std::vector<double>& v) {
    if (v.empty()) {
        std::cerr << "Error: Empty vector\n";
        return -1;
    }
    double sum = 0;
    for (double val : v) {
        sum += val * val;
    }
    return calc::squrt(sum);
}
    
    // Dot product
double dotProduct(const std::vector<double>& v1, const std::vector<double>& v2) {
    if (v1.size() != v2.size()) {
        std::cerr << "Error: Vectors must be same size\n";
        return -1;
    }
    double result = 0;
    for (size_t i = 0; i < v1.size(); i++) {
        result += v1[i] * v2[i];
    }
    return result;
}
    
    // Cross product (3D vectors only)
std::vector<double> crossProduct(const std::vector<double>& v1, const std::vector<double>& v2) {
    std::vector<double> result;
        if (v1.size() != 3 || v2.size() != 3) {
            std::cerr << "Error: Cross product requires 3D vectors\n";
            return result;
        }
        result.push_back(v1[1] * v2[2] - v1[2] * v2[1]);
        result.push_back(v1[2] * v2[0] - v1[0] * v2[2]);
        result.push_back(v1[0] * v2[1] - v1[1] * v2[0]);
        return result;
}
    
    // Vector normalization
std::vector<double> normalizeVector(const std::vector<double>& v) {
    std::vector<double> result;
        double magnitude = vectorMagnitude(v);
        if (magnitude == 0) {
            std::cerr << "Error: Cannot normalize zero vector\n";
            return result;
        }
        
        for (double val : v) {
            result.push_back(val / magnitude);
        }
        return result;
}
    
    // Vector addition
std::vector<double> vectorAdd(const std::vector<double>& v1, const std::vector<double>& v2) {
    std::vector<double> result;
        if (v1.size() != v2.size()) {
            std::cerr << "Error: Vectors must be same size\n";
            return result;
        }
        for (size_t i = 0; i < v1.size(); i++) {
            result.push_back(v1[i] + v2[i]);
        }
        return result;
}
    
    // Vector subtraction
std::vector<double> vectorSubtract(const std::vector<double>& v1, const std::vector<double>& v2) {
    std::vector<double> result;
        if (v1.size() != v2.size()) {
            std::cerr << "Error: Vectors must be same size\n";
            return result;
        }
        for (size_t i = 0; i < v1.size(); i++) {
            result.push_back(v1[i] - v2[i]);
        }
        return result;
}
    
    // Scalar multiplication
std::vector<double> scalarMultiply(const std::vector<double>& v, double scalar) {
    std::vector<double> result;
        for (double val : v) {
            result.push_back(val * scalar);
        }
        return result;
}
    
    // Angle between two vectors (in radians)
double angleBetweenVectors(const std::vector<double>& v1, const std::vector<double>& v2) {
    if (v1.size() != v2.size()) {
        std::cerr << "Error: Vectors must be same size\n";
        return -1;
        }
        double dot = dotProduct(v1, v2);
        double mag1 = vectorMagnitude(v1);
        double mag2 = vectorMagnitude(v2);
        if (mag1 == 0 || mag2 == 0) {
            std::cerr << "Error: Cannot compute angle for zero vector\n";
            return -1;
        } 
        return acos(dot / (mag1 * mag2));
}
    
    // Matrix multiplication (2x2)
void matrixMultiply2x2(double a[2][2], double b[2][2], double result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }
    
    // Matrix determinant (2x2)
double determinant2x2(double a[2][2]) {
    return (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);
}
    
    // Matrix determinant (3x3)
double determinant3x3(double a[3][3]) {
    return a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])
            - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
            + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
}
    
    // Matrix inverse (2x2)
void inverseMatrix2x2(double a[2][2], double result[2][2]) {
    double det = determinant2x2(a);
        if (det == 0) {
            std::cerr << "Error: Matrix is singular (determinant = 0)\n";
            return;
        }
        result[0][0] = a[1][1] / det;
        result[0][1] = -a[0][1] / det;
        result[1][0] = -a[1][0] / det;
        result[1][1] = a[0][0] / det;
}
    
    // Print vector
void printVector(const std::vector<double>& v) {
    std::cout << "[ ";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i < v.size() - 1) std::cout << ", ";
        }
        std::cout << " ]\n";
    }
}