#include <calc.hpp>
#include <physics.hpp>
#include <elec.hpp>
#include <geom.hpp>
#include <algebra.hpp>
#include <string>
#include <iostream>
//#include "utils.hpp"
#include <fstream>

namespace utils {
    void saveToFile(const std::string& filename, const std::string& content) {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << content;
            outFile.close();
            std::cout << "Content saved to " << filename << "\n";
        } else {
            std::cerr << "Error: Could not open file " << filename << " for writing!" << "\n";
        }
    }

    void load(const std::string& filename) {
        std::ifstream inFile(filename);
        if (inFile.is_open()) {
            std::string line;
            while (std::getline(inFile, line)) {
                std::cout << line << "\n";
            }
            inFile.close();
        } else {
            std::cerr << "Error: Could not open file " << filename << " for reading!" << "\n";
        }
    }

    void append(const std::string& filename, const std::string& content) {
        std::ofstream outFile(filename, std::ios::app);
        if (outFile.is_open()) {
            outFile << content;
            outFile.close();
            std::cout << "Content appended to " << filename << "\n";
        } else {
            std::cerr << "Error: Could not open file " << filename << " for appending!" << "\n";
        }
    }
}
