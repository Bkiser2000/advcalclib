#ifndef
#define CALCULUS_H

double derivative(double (*func)(double), double x, double h);

double integral(double (*func)(double), double a, double b, int n);

double limit(double (*func)(double, double), double x, double y, double h);

#endif
