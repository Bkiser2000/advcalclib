#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

namespace utils {
    // File I/O functions
    bool saveResult(const std::string& filename, const std::string& label, double result);
    bool appendResult(const std::string& filename, const std::string& label, double result);
    bool saveArray(const std::string& filename, const std::string& label, 
                   const double* values, int count);
    double loadValue(const std::string& filename, const std::string& label);
    std::vector<double> loadArray(const std::string& filename, const std::string& label);
    bool logCalculation(const std::string& filename, const std::string& operation, double result);
    bool clearFile(const std::string& filename);
    
    // NAN handling functions
    double createNAN();
    double NAN();
    bool isNAN(double value);
    bool isInfinite(double value);
    bool isValid(double value);
    
    // Output functions
    double output(const char* label, double result);
    double outputPrecision(const char* label, double result, int precision);
    double outputArithmetic(const char* operation, double num1, double num2, double result);
    double outputGeometry(const char* shape, const char* property, double result);
    double outputPhysics(const char* quantity, double value, const char* unit);
}

#endif
