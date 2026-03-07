#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

namespace utils {
    bool saveResult(const std::string& filename, const std::string& label, double result);
    bool appendResult(const std::string& filename, const std::string& label, double result);
    bool saveArray(const std::string& filename, const std::string& label, 
                   const double* values, int count);
    double loadValue(const std::string& filename, const std::string& label);
    std::vector<double> loadArray(const std::string& filename, const std::string& label);
    bool logCalculation(const std::string& filename, const std::string& operation, double result);
    bool clearFile(const std::string& filename);
}

#endif
