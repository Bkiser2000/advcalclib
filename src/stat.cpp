#include "stat.hpp"
#include "calc.hpp"
#include <iostream>

namespace stat {

double mean(double* values, int count) {
    double mean = values[0];
    double total = 0;
    for (int i = 0; i < count; i++) {
        total += values[i];
    }
    mean = total / count;
    return mean;
}

double median(double* values, int count) {
    double median = values[0];
    if (count % 2 == 1) {
        median = values[count / 2];
    } else {
        median = (values[count / 2 - 1] + values[count / 2]) / 2.0;
    }
    return median;
}

double mode(double* values, int count) {
    double mode = values[0];
    int max_count = 0;
    for (int i = 0; i < count; i++) {
        int freq = 0;
        for (int j = 0; j < count; j++) {
           if (values[i] == values[j]) {
               freq++;
           }
        }
        if (freq > max_count) {
            max_count = freq;
            mode = values[i];
        }
    }
    return mode;
}

double varianceS(double* values, int count) {
    if (count <= 1) {
        std::cerr << "Error: At least two values are required to calculate variance!\n";
        return -1;
    }
    
    double meanValue = mean(values, count);
    //std::cout << "Mean: " << meanValue << "\n";
    
    double sumSquaredDiffs = 0;
    for (int i = 0; i < count; i++) {
        double diff = values[i] - meanValue;
        double squared = diff * diff;
        sumSquaredDiffs += squared;
        //std::cout << "  values[" << i << "] = " << values[i] << ", diff = " << diff 
                  //<< ", squared = " << squared << ", running sum = " << sumSquaredDiffs << "\n";
    }
    
    double variance = sumSquaredDiffs / (count - 1);
    //std::cout << "Sum of squared differences: " << sumSquaredDiffs << "\n";
    //std::cout << "Divided by (n-1) = " << (count - 1) << " = " << variance << "\n";
    std::cout << "Variance (Sample): " << variance << "\n";
    return variance;
}

double varianceP(double* values, int count) {
    if (count <= 0) {
        std::cerr << "Error: At least one value is required to calculate variance!\n";
        return -1;
    }
    double meanValue = mean(values, count);
    double sumSquaredDiffs = 0;
    for (int i = 0; i < count; i++) {
        sumSquaredDiffs += calc::expo(values[i] - meanValue, 2);
    }
    double variance = sumSquaredDiffs / count;
    std::cout << "Variance (Population): " << variance << "\n";
    return variance;
}

double stdDevS(double* values, int count) {
    double variance = varianceS(values, count);
    if (variance < 0) {
        return -1;
    }
    double stdDev = calc::squrt(variance);
    std::cout << "Standard Deviation (Sample): " << stdDev << "\n";
    return stdDev;
}

double stdDevP(double* values, int count) {
    double variance = varianceP(values, count);
    if (variance < 0) {
        return -1;
    }
    double stdDev = calc::squrt(variance);
    std::cout << "Standard Deviation (Population): " << stdDev << "\n";
    return stdDev;
}

double prob(double favorable, double total) {
    if (total <= 0) {
        std::cerr << "Error: Total number of outcomes must be positive!\n";
        return -1;
    }
    if (favorable < 0) {
        std::cerr << "Error: Favorable outcomes cannot be negative!\n";
        return -1;
    }
    double probability = favorable / total;
    std::cout << "Probability: " << probability << "\n";
    return probability;
}

double zScore(double value, double mean, double stdDev) {
    if (stdDev <= 0) {
        std::cerr << "Error: Standard deviation must be positive!\n";
        return -1;
    }
    double z = (value - mean) / stdDev;
    std::cout << "Z-Score: " << z << "\n";
    return z;
}

// Get Z-score for common confidence levels
double getZScore(double confidenceLevel) {
    if (confidenceLevel == 0.90) return 1.645;
    if (confidenceLevel == 0.95) return 1.96;
    if (confidenceLevel == 0.99) return 2.576;
    if (confidenceLevel == 0.999) return 3.291;
    
    // For custom confidence levels, use approximation
    // This is a simplified linear interpolation
    if (confidenceLevel > 0.95 && confidenceLevel < 0.99) {
        return 1.96 + (confidenceLevel - 0.95) * (2.576 - 1.96) / (0.99 - 0.95);
    }
    
    std::cerr << "Warning: Non-standard confidence level, using 95% Z-score (1.96)\n";
    return 1.96; // Default to 95%
}

// Confidence interval calculation
double conInt(double mean, double stdDev, int sampleSize, double confidenceLevel) {
    if (stdDev <= 0 || sampleSize <= 0 || confidenceLevel <= 0 || confidenceLevel >= 1) {
        std::cerr << "Error: Standard deviation and sample size must be positive, "
                  << "and confidence level must be between 0 and 1!\n";
        return -1;
    }
    
    // Get Z-score for the confidence level
    double z = getZScore(confidenceLevel);
    
    // Calculate standard error
    double standardError = stdDev / calc::squrt(sampleSize);
    
    // Calculate margin of error
    double marginOfError = z * standardError;
    
    // Calculate confidence interval bounds
    double lowerBound = mean - marginOfError;
    double upperBound = mean + marginOfError;
    
    std::cout << "Confidence Interval (" << (confidenceLevel * 100) << "%): [" 
              << lowerBound << ", " << upperBound << "]\n";
    std::cout << "Margin of Error: " << marginOfError << "\n";
    
    return marginOfError;
}

// Return confidence interval as a struct
ConfidenceInterval conIntS(double mean, double stdDev, int sampleSize, double confidenceLevel) {
    ConfidenceInterval ci = {0, 0, 0};
    
    if (stdDev <= 0 || sampleSize <= 0 || confidenceLevel <= 0 || confidenceLevel >= 1) {
        std::cerr << "Error: Invalid parameters for confidence interval\n";
        return ci;
    }
    
    double z = getZScore(confidenceLevel);
    double standardError = stdDev / calc::squrt(sampleSize);
    double marginOfError = z * standardError;
    
    ci.lowerBound = mean - marginOfError;
    ci.upperBound = mean + marginOfError;
    ci.marginOfError = marginOfError;
    
    return ci;
}

// T-score for small sample sizes (n < 30)
double getTScore(int sampleSize, double confidenceLevel) {
    // Simplified t-distribution values (df = n-1, two-tailed)
    // For a complete implementation, use a t-table or statistical library
    
    if (sampleSize < 2) return -1;
    
    int df = sampleSize - 1;
    
    // Common t-values for 95% confidence
    if (confidenceLevel == 0.95) {
        if (df == 1) return 12.706;
        if (df == 2) return 4.303;
        if (df == 3) return 3.182;
        if (df == 4) return 2.776;
        if (df == 5) return 2.571;
        if (df >= 10 && df < 20) return 2.228;
        if (df >= 20 && df < 30) return 2.086;
        if (df >= 30) return 1.96; // Approaches Z-score as df increases
    }
    
    return 1.96; // Default fallback
}

// Confidence interval using t-distribution (for small samples)
ConfidenceInterval conIntT(double mean, double stdDev, int sampleSize, double confidenceLevel) {
    ConfidenceInterval ci = {0, 0, 0};
    
    if (stdDev <= 0 || sampleSize <= 0 || confidenceLevel <= 0 || confidenceLevel >= 1) {
        std::cerr << "Error: Invalid parameters for t-confidence interval\n";
        return ci;
    }
    
    double t = getTScore(sampleSize, confidenceLevel);
    if (t < 0) {
        std::cerr << "Error: Cannot calculate t-score\n";
        return ci;
    }
    
    double standardError = stdDev / calc::squrt(sampleSize);
    double marginOfError = t * standardError;
    
    ci.lowerBound = mean - marginOfError;
    ci.upperBound = mean + marginOfError;
    ci.marginOfError = marginOfError;
    
    std::cout << "T-Confidence Interval (" << (confidenceLevel * 100) << "%): [" 
              << ci.lowerBound << ", " << ci.upperBound << "]\n";
    
    return ci;
}
}