#include <iostream>
#include <vector>
#include "calc.hpp"
#include "geom.hpp"
#include "algebra.hpp"
#include "utils.hpp"

namespace algebra {

double solveQuadratic(double a, double b, double c) {
     if (a == 0) {
        std::cerr << "Error: Coefficient 'a' cannot be zero!" << "\n";
        return utils::NAN();
    }
    double discriminant = calc::expo(b, 2) - (4 * a * c);
    //std::cout << "Discriminant: " << discriminant << "\n";
    //std::cout << "sqrt(discriminant): " << calc::squrt(discriminant) << "\n";
    //std::cout << "-b: " << -b << "\n";
    //std::cout << "2*a: " << (2 * a) << "\n";

    if (discriminant < 0) {
        std::cerr << "Error: No real roots!" << "\n";
        return utils::NAN();
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
    // Solve ax³ + bx² + cx + d = 0
    
    if (a == 0) {
        std::cerr << "Error: Coefficient 'a' cannot be zero!\n";
        return 0;
    }
    
    // Normalize: divide by 'a' to get x³ + px² + qx + r = 0
    double p = b / a;
    double q = c / a;
    double r = d / a;
    
    // Convert to depressed cubic: t³ + At + B = 0
    // where t = x - p/3
    double A = q - (p * p) / 3.0;
    double B = (2.0 * p * p * p) / 27.0 - (p * q) / 3.0 + r;
    
    // Cardano's formula
    double discriminant = -(4.0 * A * A * A + 27.0 * B * B);
    
    // Calculate using Cardano's method
    double Asqrt3 = calc::squrt(A * A * A);
    double inside = (B * B / 4.0) + (A * A * A / 27.0);
    
    if (inside < 0) {
        std::cerr << "Error: Complex roots (not implemented)\n";
        return 0;
    }
    
    double C = calc::squrt(inside);
    double u = -B / 2.0 + C;
    double v = -B / 2.0 - C;
    
    // Cube roots
    double u_cbrt = (u >= 0) ? calc::expo(u, 1.0/3.0) : -calc::expo(-u, 1.0/3.0);
    double v_cbrt = (v >= 0) ? calc::expo(v, 1.0/3.0) : -calc::expo(-v, 1.0/3.0);
    
    // First real root
    double t = u_cbrt + v_cbrt;
    double x1 = t - p / 3.0;
    
    std::cout << "Cubic root: " << x1 << "\n";
    return x1;
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

double differenceOfSquares(double a, double b) {
    double diffSq = (a - b) * (a + b);
    return diffSq;
}

// Calculate binomial coefficient C(n, k) = n! / (k!(n-k)!)
double binomialCoefficient(int n, int k) {
    if (k > n || k < 0) {
        std::cerr << "Error: Invalid binomial coefficient\n";
        return -1;
    }
    if (k == 0 || k == n) return 1;
    
    // Simplify: C(n, k) = n! / (k!(n-k)!)
    double numerator = calc::fact(n);
    double denominator = calc::fact(k) * calc::fact(n - k);
    
    return numerator / denominator;
}

// True binomial expansion: (a + b)^n
double binomialExpansion(double a, double b, int n) {
    if (n < 0) {
        std::cerr << "Error: Exponent cannot be negative\n";
        return -1;
    }
    
    // (a + b)^n = Σ C(n,k) * a^(n-k) * b^k
    double result = 0;
    for (int k = 0; k <= n; k++) {
        double coeff = binomialCoefficient(n, k);
        double term = coeff * calc::expo(a, n - k) * calc::expo(b, k);
        result += term;
    }
    
    std::cout << "Binomial expansion of (" << a << " + " << b << ")^" << n 
              << " = " << result << "\n";
    return result;
}

// Print binomial expansion step-by-step
void printBinomialExpansion(double a, double b, int n) {
    if (n < 0) {
        std::cerr << "Error: Exponent cannot be negative\n";
        return;
    }
    
    std::cout << "Binomial Expansion of (" << a << " + " << b << ")^" << n << ":\n";
    
    double result = 0;
    for (int k = 0; k <= n; k++) {
        double coeff = binomialCoefficient(n, k);
        double term = coeff * calc::expo(a, n - k) * calc::expo(b, k);
        result += term;
        
        std::cout << "  k=" << k << ": C(" << n << "," << k << ") * " 
                  << a << "^" << (n - k) << " * " << b << "^" << k 
                  << " = " << coeff << " * " << calc::expo(a, n - k) 
                  << " * " << calc::expo(b, k) << " = " << term << "\n";
    }
    
    std::cout << "Result: " << result << "\n";
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
        return geom::acos(dot / (mag1 * mag2));
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

// Matrix determinant (4x4) using cofactor expansion
double determinant4x4(double a[4][4]) {
    double det = 0;
    
    // Expand along first row
    for (int j = 0; j < 4; j++) {
        // Create 3x3 submatrix by removing row 0 and column j
        double sub[3][3];
        for (int row = 1; row < 4; row++) {
            int col_idx = 0;
            for (int col = 0; col < 4; col++) {
                if (col != j) {
                    sub[row - 1][col_idx] = a[row][col];
                    col_idx++;
                }
            }
        }
        
        // Calculate cofactor with sign
        double sign = (j % 2 == 0) ? 1 : -1;
        det += sign * a[0][j] * determinant3x3(sub);
    }
    
    return det;
}

// Solve 4x4 system using Cramer's rule
// a1*w + b1*x + c1*y + d1*z = e1
// a2*w + b2*x + c2*y + d2*z = e2
// a3*w + b3*x + c3*y + d3*z = e3
// a4*w + b4*x + c4*y + d4*z = e4
bool solveSystem4x4(double a1, double b1, double c1, double d1, double e1,
                    double a2, double b2, double c2, double d2, double e2,
                    double a3, double b3, double c3, double d3, double e3,
                    double a4, double b4, double c4, double d4, double e4,
                    double& w, double& x, double& y, double& z) {
    
    // Coefficient matrix
    double A[4][4] = {
        {a1, b1, c1, d1},
        {a2, b2, c2, d2},
        {a3, b3, c3, d3},
        {a4, b4, c4, d4}
    };
    
    double detA = determinant4x4(A);
    
    if (detA == 0) {
        std::cerr << "Error: No unique solution (determinant = 0)\n";
        return false;
    }
    
    // Matrix for w (replace column 0 with constants)
    double Aw[4][4] = {
        {e1, b1, c1, d1},
        {e2, b2, c2, d2},
        {e3, b3, c3, d3},
        {e4, b4, c4, d4}
    };
    w = determinant4x4(Aw) / detA;
    
    // Matrix for x (replace column 1 with constants)
    double Ax[4][4] = {
        {a1, e1, c1, d1},
        {a2, e2, c2, d2},
        {a3, e3, c3, d3},
        {a4, e4, c4, d4}
    };
    x = determinant4x4(Ax) / detA;
    
    // Matrix for y (replace column 2 with constants)
    double Ay[4][4] = {
        {a1, b1, e1, d1},
        {a2, b2, e2, d2},
        {a3, b3, e3, d3},
        {a4, b4, e4, d4}
    };
    y = determinant4x4(Ay) / detA;
    
    // Matrix for z (replace column 3 with constants)
    double Az[4][4] = {
        {a1, b1, c1, e1},
        {a2, b2, c2, e2},
        {a3, b3, c3, e3},
        {a4, b4, c4, e4}
    };
    z = determinant4x4(Az) / detA;
    
    std::cout << "Solution: w = " << w << ", x = " << x 
              << ", y = " << y << ", z = " << z << "\n";
    return true;
}
}