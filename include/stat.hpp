#ifndef STAT_H
#define STAT_H

struct ConfidenceInterval {
    double lowerBound;
    double upperBound;
    double marginOfError;
};

namespace stat {
  
    double mean(double* values, int count);
    double median(double* values, int count);
    double mode(double* values, int count);

    // Variance and standard deviation
    double varianceS(double* values, int count);      // Sample variance
    double varianceP(double* values, int count);      // Population variance
    double stdDevS(double* values, int count);        // Sample std dev
    double stdDevP(double* values, int count);        // Population std dev
    
    // Probability
    double prob(double favorable, double total);
    
    // Z-scores and confidence intervals
    double zScore(double value, double mean, double stdDev);
    double getZScore(double confidenceLevel);
    double conInt(double mean, double stdDev, int sampleSize, double confidenceLevel);
    ConfidenceInterval conIntS(double mean, double stdDev, int sampleSize, double confidenceLevel);
    
    // T-distribution (for small samples)
    double getTScore(int sampleSize, double confidenceLevel);
    ConfidenceInterval conIntT(double mean, double stdDev, int sampleSize, double confidenceLevel);
}
#endif
