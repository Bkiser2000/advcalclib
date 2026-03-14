#include <sstream>
#include <vector>
#include <iostream>
#include "utils.hpp"
#include <fstream>
#include <iomanip>
#include <cstring>

namespace utils {
     // Save single result to new file
    bool saveResult(const std::string& filename, const std::string& label, double result) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not create file " << filename << "\n";
            return false;
        }
        
        file << label << ": " << result << "\n";
        file.close();
        std::cout << "Result saved to " << filename << "\n";
        return true;
    }
    
    // Append result to existing file
    bool appendResult(const std::string& filename, const std::string& label, double result) {
        std::ofstream file(filename, std::ios::app);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << "\n";
            return false;
        }
        
        file << label << ": " << result << "\n";
        file.close();
        std::cout << "Result appended to " << filename << "\n";
        return true;
    }
    
    // Save array of results
    bool saveArray(const std::string& filename, const std::string& label, 
                   const double* values, int count) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not create file " << filename << "\n";
            return false;
        }
        
        file << label << ": ";
        for (int i = 0; i < count; i++) {
            file << values[i];
            if (i < count - 1) file << ", ";
        }
        file << "\n";
        
        file.close();
        std::cout << "Array saved to " << filename << "\n";
        return true;
    }
    
    // Load single value from file
    double loadValue(const std::string& filename, const std::string& label) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << "\n";
            return -1;
        }
        
        std::string line;
        while (std::getline(file, line)) {
            size_t pos = line.find(label);
            if (pos != std::string::npos) {
                size_t colonPos = line.find(":", pos);
                if (colonPos != std::string::npos) {
                    std::string valueStr = line.substr(colonPos + 1);
                    try {
                        double value = std::stod(valueStr);
                        file.close();
                        return value;
                    } catch (...) {
                        std::cerr << "Error: Could not parse value\n";
                        return -1;
                    }
                }
            }
        }
        
        file.close();
        std::cerr << "Error: Label '" << label << "' not found in file\n";
        return -1;
    }
    
    // Load array from file
    std::vector<double> loadArray(const std::string& filename, const std::string& label) {
        std::vector<double> result;
        std::ifstream file(filename);
        
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << "\n";
            return result;
        }
        
        std::string line;
        while (std::getline(file, line)) {
            size_t pos = line.find(label);
            if (pos != std::string::npos) {
                size_t colonPos = line.find(":", pos);
                if (colonPos != std::string::npos) {
                    std::string valueStr = line.substr(colonPos + 1);
                    std::stringstream ss(valueStr);
                    std::string token;
                    
                    while (std::getline(ss, token, ',')) {
                        try {
                            // Trim whitespace
                            token.erase(0, token.find_first_not_of(" \t"));
                            token.erase(token.find_last_not_of(" \t") + 1);
                            
                            double value = std::stod(token);
                            result.push_back(value);
                        } catch (...) {
                            std::cerr << "Error: Could not parse value in array\n";
                        }
                    }
                    break;
                }
            }
        }
        
        file.close();
        return result;
    }
    
    // Save calculation log with timestamp
    bool logCalculation(const std::string& filename, const std::string& operation, 
                       double result) {
        std::ofstream file(filename, std::ios::app);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open log file " << filename << "\n";
            return false;
        }
        
        file << operation << " = " << result << "\n";
        file.close();
        return true;
    }
    
    // Clear file contents
    bool clearFile(const std::string& filename) {
        std::ofstream file(filename, std::ios::trunc);
        if (!file.is_open()) {
            std::cerr << "Error: Could not clear file " << filename << "\n";
            return false;
        }
        file.close();
        std::cout << "File " << filename << " cleared\n";
        return true;
    }

    // Create a custom NAN value using bit manipulation
    double createNAN() {
        // IEEE 754 NAN: exponent all 1s, mantissa non-zero
        unsigned long long nanBits = 0x7FF8000000000001ULL;
        double nanValue;
        std::memcpy(&nanValue, &nanBits, sizeof(double));
        return nanValue;
    }
    
    // Check if a double is NAN
    bool isNAN(double value) {
        // NAN is not equal to itself
        return value != value;
    }
    
    // Check if a double is infinity
    bool isInfinite(double value) {
        return value > 1e308 || value < -1e308;
    }
    
    // Check if a double is valid
    bool isValid(double value) {
        return !isNAN(value) && !isInfinite(value);
    }
    
    // Get a NAN value
    double nan() {
        return 0.0 / 0.0;  // Mathematical operations that produce NAN
    }
    
    // Output with custom NAN handling
    double output(const char* label, double result) {
        if (isNAN(result)) {
            std::cerr << "Error: Result is NAN\n";
            return nan();
        }
        
        if (isInfinite(result)) {
            std::cerr << "Error: Result is Infinity\n";
            return nan();
        }
        
        if (label && label[0] != '\0') {
            std::cout << label << ": " << result << "\n";
        } else {
            std::cout << result << "\n";
        }
        return result;
    }
    
    // Output with precision
    double outputPrecision(const char* label, double result, int precision) {
        if (isNAN(result)) {
            std::cerr << "Error: Result is NAN\n";
            return nan();
        }
        
        if (precision < 0) {
            std::cerr << "Error: Precision must be non-negative\n";
            return nan();
        }
        
        if (label && label[0] != '\0') {
            std::cout << label << ": " << std::fixed << std::setprecision(precision) << result << "\n";
        } else {
            std::cout << std::fixed << std::setprecision(precision) << result << "\n";
        }
        return result;
    }
    
    // Output arithmetic with validation
    double outputArithmetic(const char* operation, double num1, double num2, double result) {
        if (!isValid(result)) {
            std::cerr << "Error: Invalid result\n";
            return nan();
        }
        
        std::cout << operation << "(" << num1 << ", " << num2 << ") = " << result << "\n";
        return result;
    }
    
    // Output geometry with validation
    double outputGeometry(const char* shape, const char* property, double result) {
        if (!isValid(result)) {
            std::cerr << "Error: Invalid result\n";
            return nan();
        }
        
        std::cout << shape << " " << property << " = " << result << "\n";
        return result;
    }
    
    // Output physics with validation
    double outputPhysics(const char* quantity, double value, const char* unit) {
        if (!isValid(value)) {
            std::cerr << "Error: Invalid result\n";
            return nan();
        }
        
        std::cout << quantity << ": " << value << " " << unit << "\n";
        return value;
    }
}


