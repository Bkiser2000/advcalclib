#ifndef ALGEBRA_H
#define ALGEBRA_H

#include <vector>

namespace algebra {

double solveLinear(double a, double b, double c);

double solveQuadratic(double a, double b, double c);

double solveCubic(double a, double b, double c, double d);

double solveQuartic(double a, double b, double c, double d, double e);

double solvePolynomial(double* coefficients, int degree);

double solveSystem2x2(double a1, double b1, double c1, double a2, double b2, double c2);

double solveSystem3x3(double a1, double b1, double c1, double d1, double a2, double b2, double c2, double d2, double a3, double b3, double c3, double d3);

double solveSystem4x4(double a1, double b1, double c1, double d1, double e1, double a2, double b2, double c2, double d2, double e2, double a3, double b3, double c3, double d3, double e3, double a4, double b4, double c4, double d4, double e4);

double determinant2x2(double a, double b, double c, double d);

double determinant3x3(double a1, double b1, double c1, double a2, double b2, double c2, double a3, double b3, double c3);

double determinant4x4(double a1, double b1, double c1, double d1, double a2, double b2, double c2, double d2, double a3, double b3, double c3, double d3, double a4, double b4, double c4, double d4);

double inverse2x2(double a, double b, double c, double d);

double inverse3x3(double a1, double b1, double c1, double a2, double b2, double c2, double a3, double b3, double c3);

double inverse4x4(double a1, double b1, double c1, double d1, double a2, double b2, double c2, double d2, double a3, double b3, double c3, double d3, double a4, double b4, double c4, double d4);

double differenceOfSquares(double a, double b);

double differenceOfCubes(double a, double b);

double squareOfBinomial(double a, double b);

double sumOfCubes(double a, double b);

double lawOfExponents(double base, double exponent);

double binomialExpansion(double a, double b, int n);

double greatestCommonFactor(int a, int b);

 // Vector functions
double vectorMagnitude(const std::vector<double>& v);
double dotProduct(const std::vector<double>& v1, const std::vector<double>& v2);
std::vector<double> crossProduct(const std::vector<double>& v1, const std::vector<double>& v2);
std::vector<double> normalizeVector(const std::vector<double>& v);
std::vector<double> vectorAdd(const std::vector<double>& v1, const std::vector<double>& v2);
std::vector<double> vectorSubtract(const std::vector<double>& v1, const std::vector<double>& v2);
std::vector<double> scalarMultiply(const std::vector<double>& v, double scalar);
double angleBetweenVectors(const std::vector<double>& v1, const std::vector<double>& v2);
    
// Matrix functions
void matrixMultiply2x2(double a[2][2], double b[2][2], double result[2][2]);
double determinant2x2(double a[2][2]);
double determinant3x3(double a[3][3]);
void inverseMatrix2x2(double a[2][2], double result[2][2]);
    
// Utility
void printVector(const std::vector<double>& v);

}

#endif
