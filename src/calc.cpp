#include "calc.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

namespace calc {

double add(double Num1, double Num2) {
    double sum = Num1 + Num2;
    return sum;
}
 
double sub(double Num1, double Num2) {
    double difference = Num1 - Num2;
    return difference;
}

double mult(double Num1, double Num2) {
    double product = Num1 * Num2;
    return product;
}

double div(double Num1, double Num2) {
    if (Num2 > 0) {
        double quotient = Num1 / Num2;
        return quotient;
    } else {
      std::cout << "Cannot divide by zero!";
      return 0;
    }
}

double expo(double Num1, double Num2) {
    double power = 1;
    for (int i = 0; i < Num2; i++) {
        power *=  Num1;
    }
    return power;
}

double squrt(double Num1) {
    if (Num1 < 0) {
        std::cerr << "Error: Cannot take square root of negative number!\n";
        return -1;
    }
    if (Num1 == 0) return 0;
    if (Num1 == 1) return 1;
    
    // Newton-Raphson: x_{n+1} = (x_n + S/x_n) / 2
    // where S is the number we're finding the square root of
    double guess = Num1;
    double epsilon = 1.0e-15;
    double previous;
    
    do {
        previous = guess;
        guess = (guess + Num1 / guess) / 2.0;
    } while (guess != previous && (guess - previous > epsilon || previous - guess > epsilon));
    
    return guess;
}

double cubrt(double Num1) {
    double guess = Num1 / 3.0;
    double epsilon = 0.00001;
    while (true) {
        double newGuess = (2 * guess + Num1 / (guess * guess)) / 3;
        if (abs(newGuess - guess) < epsilon) {
            break;
        }
        guess = newGuess;
    }
    return guess;
}

double fact(double Num1) {
    if (Num1 < 0) {
        std::cerr << "Error: Negative input!" << "\n";
        return -1;
    }
    if (Num1 == 0 || Num1 == 1) return 1;
    double result = 1;
    for (int i = 2; i <= Num1; i++) {
        result *= i;
    }
    return result;
}

double degrees_F(double CTemp) {
    double fahrenTemp;
    fahrenTemp = CTemp * 1.8 + 32;
    //cout << "Temperature: " << fahrenTemp << "F\n";
    return fahrenTemp;
}

double degrees_C(double FTemp) {
    double celciusTemp;
    celciusTemp = (FTemp - 32) * 5 / 9;
    //cout << "Temperature: " << celciusTemp << "C\n";
    return celciusTemp;
}

double log(double value) {
    if (value > 0) {
        double logValue = 0;
        double term = (value - 1) / (value + 1);
        double termSquared = term * term;
        int n = 1;
        while (abs(term) > 0.00001) {
            logValue += term / n;
            term *= termSquared;
            n += 2;
        }
        logValue *= 2;
        //cout << "Natural Log: " << logValue << "\n";
        return logValue;
    } else {
        std::cerr << "Error: Value must be positive!" << "\n";
        return -1;
    }
}

double FtoK(double FTemp) {
    double kelvinTemp;
    kelvinTemp = (FTemp - 32) * 5 / 9 + 273.15;
    //cout << "Temperature: " << kelvinTemp << " K\n";
    return kelvinTemp;
}

double CtoK(double CTemp) {
    double kelvinTemp;
    kelvinTemp = CTemp + 273.15;
    //cout << "Temperature: " << kelvinTemp << " K\n";
    return kelvinTemp;
}
}
