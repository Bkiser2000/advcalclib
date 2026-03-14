#include <iostream>
#include <geom.hpp>
#include <calc.hpp>
#include <algorithm>
#include <algebra.hpp>
#include <utils.hpp>
#include <utility>
#include <vector>
#include <complex>

namespace calculus {
// Derivative using central difference 
double derivative(double (*func)(double), double x, double h) {
    if (h <= 0) {
        std::cerr << "Error: Step size must be positive!" << "\n";
        return utils::nan();
    }
    // Central difference: f'(x) ≈ (f(x+h) - f(x-h)) / (2h)
    double result = (func(x + h) - func(x - h)) / (2 * h);
    return result;
}

// Integral using trapezoidal rule
double integral(double (*func)(double), double a, double b, int n) {
    if (n <= 0) {
        std::cerr << "Error: Number of subdivisions must be positive!" << "\n";
        return -1;
    }
    double h = (b - a) / n;
    double sum = 0.5 * (func(a) + func(b));
    for (int i = 1; i < n; i++) {
        sum += func(a + i * h);
    }
    double result = sum * h;
    //std::cout << "Integral from " << a << " to " << b << " is approximately: " << result << "\n";
    return result;
}

double limit(double (*func)(double), double x, double h) {
    if (h <= 0) {
        std::cerr << "Error: Step size must be positive!" << "\n";
        return utils::nan();
    }
    // Limit as h approaches 0: lim(h->0) (f(x+h) - f(x)) / h
    double result = (func(x + h) - func(x)) / h;
    return result;
}

double partialDerivative(double (*func)(double, double), double x, double y, double h) {
    if (h <= 0) {
        std::cerr << "Error: Step size must be positive!" << "\n";
        return utils::nan();
    }
    // Partial derivative with respect to x: ∂f/∂x ≈ (f(x+h, y) - f(x-h, y)) / (2h)
    double result = (func(x + h, y) - func(x - h, y)) / (2 * h);
    return result;
}

void bitReverse(std::vector<std::complex<double>>& x) {
    int n = x.size();
    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        if (i < j) std::swap(x[i], x[j]);
        int m = n / 2;
        while (j >= m) {
            j -= m;
            m /= 2;
        }
        j += m;
    }
}
    
// Cooley-Tukey FFT Algorithm
std::vector<std::complex<double>> fft(const std::vector<double>& signal) {
    int n = signal.size();
        
    // Pad to power of 2
    int powerOf2 = 1;
    while (powerOf2 < n) powerOf2 *= 2;
    std::vector<std::complex<double>> x(powerOf2);
    for (int i = 0; i < n; i++) {
        x[i] = std::complex<double>(signal[i], 0);
    }
    for (int i = n; i < powerOf2; i++) {
        x[i] = std::complex<double>(0, 0);
    }
    // Bit reversal
    bitReverse(x);
        
    // FFT computation
    for (int s = 1; s <= std::log2(powerOf2); s++) {
        int m = 1 << s; // 2^s
        std::complex<double> w(geom::cosine(2 * M_PI / m), -std::sin(2 * M_PI / m));
        for (int k = 0; k < powerOf2; k += m) {
            std::complex<double> wm(1, 0);
            for (int j = 0; j < m / 2; j++) {
                std::complex<double> t = wm * x[k + j + m/2];
                std::complex<double> u = x[k + j];
                x[k + j] = u + t;
                x[k + j + m/2] = u - t;
                wm *= w;
            }
        }
    }
    return x;
}

// Inverse FFT
std::vector<double> ifft(const std::vector<std::complex<double>>& frequency) {
    int n = frequency.size();
        
    // Conjugate input
    std::vector<std::complex<double>> x = frequency;
    for (auto& val : x) {
        val = std::conj(val);
    }
        
    // Forward FFT
    auto result = fft(std::vector<double>(x.size()));
    for (int i = 0; i < x.size(); i++) {
        result[i] = x[i];
    }
        
    // Conjugate and scale
    std::vector<double> output(n);
    for (int i = 0; i < n; i++) {
        output[i] = std::real(std::conj(result[i])) / n;
    }
    return output;
}
    
// Power spectrum (magnitude squared)
std::vector<double> powerSpectrum(const std::vector<double>& signal) {
    auto freq = fft(signal);
    std::vector<double> power(freq.size());
        
    for (int i = 0; i < freq.size(); i++) {
        double real = std::real(freq[i]);
        double imag = std::imag(freq[i]);
        power[i] = (real * real + imag * imag) / signal.size();
    }
    return power;
}
    
// Get dominant frequency
double dominantFrequency(const std::vector<double>& signal, double sampleRate) {
    auto power = powerSpectrum(signal);
        
    int maxIdx = 0;
    for (int i = 0; i < power.size(); i++) {
        if (power[i] > power[maxIdx]) {
            maxIdx = i;
        }
    }
    return (maxIdx * sampleRate) / signal.size();
}

// Low-pass filter (remove high frequencies)
std::vector<double> lowPassFilter(const std::vector<double>& signal, 
                                 double cutoffFreq, double sampleRate) {
    auto freqDomain = fft(signal);
    int n = freqDomain.size();
    int cutoffBin = (int)(cutoffFreq * n / sampleRate);
    
    // Zero out high frequencies
    for (int i = cutoffBin; i < n - cutoffBin; i++) {
        freqDomain[i] = std::complex<double>(0, 0);
    }
    
    // Convert back to time domain
    return ifft(freqDomain);
}

// Convolution via FFT (very efficient)
std::vector<double> convolve(const std::vector<double>& signal1,
                            const std::vector<double>& signal2) {
    int n = signal1.size() + signal2.size() - 1;
    int powerOf2 = 1;
    while (powerOf2 < n) powerOf2 *= 2;
    
    // Pad signals
    std::vector<double> padded1(powerOf2, 0);
    std::vector<double> padded2(powerOf2, 0);
    for (int i = 0; i < signal1.size(); i++) padded1[i] = signal1[i];
    for (int i = 0; i < signal2.size(); i++) padded2[i] = signal2[i];
    
    // FFT both signals
    auto freq1 = fft(padded1);
    auto freq2 = fft(padded2);
    
    // Multiply in frequency domain
    std::vector<std::complex<double>> product(powerOf2);
    for (int i = 0; i < powerOf2; i++) {
        product[i] = freq1[i] * freq2[i];
    }
    
    // Convert back to time domain
    return ifft(product);
}

// Cross-correlation (for pattern matching in signals)
std::vector<double> crossCorrelate(const std::vector<double>& signal1,
                                  const std::vector<double>& signal2) {
    int n = signal1.size() + signal2.size() - 1;
    int powerOf2 = 1;
    while (powerOf2 < n) powerOf2 *= 2;
    
    std::vector<double> padded1(powerOf2, 0);
    std::vector<double> padded2(powerOf2, 0);
    for (int i = 0; i < signal1.size(); i++) padded1[i] = signal1[i];
    for (int i = 0; i < signal2.size(); i++) padded2[i] = signal2[i];
    
    auto freq1 = fft(padded1);
    auto freq2 = fft(padded2);
    
    // Cross-correlation: conjugate one signal first
    std::vector<std::complex<double>> product(powerOf2);
    for (int i = 0; i < powerOf2; i++) {
        product[i] = freq1[i] * std::conj(freq2[i]);
    }
    
    return ifft(product);
}

// Morlet wavelet transform (time-frequency analysis)
std::vector<std::vector<double>> waveletTransform(const std::vector<double>& signal,
                                                 double minFreq, double maxFreq) {
    std::vector<std::vector<double>> result;
    int numScales = 50;
    
    for (int scale = 0; scale < numScales; scale++) {
        double freq = minFreq + (maxFreq - minFreq) * scale / numScales;
        std::vector<double> wavelet(signal.size());
        
        // Morlet wavelet: exp(i*2*pi*f*t) * exp(-t^2/2)
        for (int t = 0; t < signal.size(); t++) {
            double time = (double)t / signal.size();
            double real = std::cos(2 * M_PI * freq * time) * 
                         std::exp(-time * time / 2);
            wavelet[t] = real;
        }
        
        // Convolve signal with wavelet
        auto convolved = convolve(signal, wavelet);
        result.push_back(convolved);
    }
    
    return result;
}

// Signal smoothing (moving average in frequency domain)
std::vector<double> smoothSignal(const std::vector<double>& signal, int windowSize) {
    // Create smoothing kernel (rectangular window)
    std::vector<double> window(windowSize, 1.0 / windowSize);
    
    // Convolve with window
    return convolve(signal, window);
} 
}