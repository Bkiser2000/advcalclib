#ifndef COMMUN_HPP
#define COMMUN_HPP

#include <vector>
#include <complex>
#include <string>

namespace comms {
    // Error correction (Hamming codes)
    std::vector<int> hammingEncode(const std::vector<int>& data);
    std::vector<int> hammingDecode(const std::vector<int>& encoded);
    
    // Signal modulation (QPSK - Quadrature Phase Shift Keying)
    std::vector<std::complex<double>> qpskModulate(const std::vector<int>& bits);
    std::vector<int> qpskDemodulate(const std::vector<std::complex<double>>& signal);
    
    // Channel simulation with noise
    std::vector<std::complex<double>> addNoise(const std::vector<std::complex<double>>& signal,
                                              double snrDb);
    
    // Frequency hopping (anti-jamming)
    std::vector<std::complex<double>> frequencyHop(const std::vector<std::complex<double>>& signal,
                                                  const std::vector<int>& hopSequence,
                                                  double baseFreq, double hopRate);
    
    // Mesh routing optimization
    struct Node {
        int id;
        double x, y; // coordinates
        double signalStrength;
    };
    
    std::vector<int> findOptimalRoute(const std::vector<Node>& nodes, int source, int dest);
    
    // Link quality assessment
    double calculateLinkQuality(double distance, double txPower, double frequency);
}

#endif
