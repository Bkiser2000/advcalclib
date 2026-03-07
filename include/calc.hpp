#ifndef CALC_H
#define CALC_H

namespace calc {

double returnVal(double a, double b);

double add(double Num1, double Num2);

double sub(double Num1, double Num2);

double mult(double Num1, double Num2);

double div(double Num1, double Num2);

double expo(double Num1, double Num2);

double squrt(double Num1);

double degrees_F(double CTemp);

double degrees_C(double Num1);

double mean(double* values, int count);

double median(double* values, int count);

double mode(double* values, int count);
}

#endif
