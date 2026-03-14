#ifndef CALCULUS_H
#define CALCULUS_H

#include <vector>

namespace calculus {

double derivative(double (*func)(double), double x, double h);

double integral(double (*func)(double), double a, double b, int n);

double limit(double (*func)(double, double), double x, double y, double h);

double partialDerivative(double (*func)(double, double), double x, double y, double h);

void bitReverse(std::vector<std::complex<double>>& x);

std::vector<std::complex<double>> fft(const std::vector<double>& signal);

std::vector<double> ifft(const std::vector<std::complex<double>>& frequency);

std::vector<double> powerSpectrum(const std::vector<double>& signal);

double dominantFrequency(const std::vector<double>& signal, double sampleRate);

// Signal geometry operations
    
// Frequency domain filtering
std::vector<double> lowPassFilter(const std::vector<double>& signal, 
                                     double cutoffFreq, double sampleRate);
// Signal convolution (via FFT)
std::vector<double> convolve(const std::vector<double>& signal1,
                                const std::vector<double>& signal2);
    
// Cross-correlation for signal alignment
std::vector<double> crossCorrelate(const std::vector<double>& signal1,
                                      const std::vector<double>& signal2);
    
// Wavelet transform (Morlet wavelet)
std::vector<std::vector<double>> waveletTransform(const std::vector<double>& signal,
                                                     double minFreq, double maxFreq);
// Signal smoothing via frequency domain
std::vector<double> smoothSignal(const std::vector<double>& signal, int windowSize);
}

#endif
