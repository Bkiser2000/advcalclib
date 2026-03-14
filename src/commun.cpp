#include "commun.hpp"
#include "calc.hpp"
#include "calculus.hpp"
#include "physics.hpp"
#include "geom.hpp"
#include <algorithm>

namespace comms {
    
    // Hamming(7,4) error correction
    std::vector<int> hammingEncode(const std::vector<int>& data) {
        std::vector<int> encoded(7);
        encoded[0] = data[0];
        encoded[1] = data[1];
        encoded[2] = data[2];
        encoded[3] = data[3];
        
        // Parity bits
        encoded[4] = data[0] ^ data[1] ^ data[3]; // p1
        encoded[5] = data[0] ^ data[2] ^ data[3]; // p2
        encoded[6] = data[1] ^ data[2] ^ data[3]; // p4
        
        return encoded;
    }
    
    std::vector<int> hammingDecode(const std::vector<int>& encoded) {
        int p1 = encoded[4] ^ encoded[0] ^ encoded[1] ^ encoded[3];
        int p2 = encoded[5] ^ encoded[0] ^ encoded[2] ^ encoded[3];
        int p4 = encoded[6] ^ encoded[1] ^ encoded[2] ^ encoded[3];
        
        int errorPos = p1 * 1 + p2 * 2 + p4 * 4;
        
        std::vector<int> corrected = encoded;
        if (errorPos > 0) {
            corrected[errorPos - 1] ^= 1; // Flip erroneous bit
        }
        
        return {corrected[0], corrected[1], corrected[2], corrected[3]};
    }
    
    // QPSK Modulation (4 symbols per bit pair)
    std::vector<std::complex<double>> qpskModulate(const std::vector<int>& bits) {
        std::vector<std::complex<double>> modulated;
        
        for (int i = 0; i < bits.size(); i += 2) {
            int symbol = (bits[i] << 1) | bits[i+1];
            double phase = (symbol * M_PI / 2);
            modulated.push_back(std::complex<double>(
                std::cos(phase) / std::sqrt(2),
                std::sin(phase) / std::sqrt(2)
            ));
        }
        
        return modulated;
    }
    
    std::vector<int> qpskDemodulate(const std::vector<std::complex<double>>& signal) {
        std::vector<int> bits;
        
        for (const auto& sym : signal) {
            double phase = std::atan2(std::imag(sym), std::real(sym));
            // Normalize to [0, 2π)
            if (phase < 0) phase += 2 * M_PI;
            
            int symbol = (int)(phase * 2 / M_PI);
            bits.push_back((symbol >> 1) & 1);
            bits.push_back(symbol & 1);
        }
        
        return bits;
    }
    
    // Add AWGN (Additive White Gaussian Noise)
    std::vector<std::complex<double>> addNoise(const std::vector<std::complex<double>>& signal,
                                              double snrDb) {
        double snrLinear = calc::expo(10, snrDb / 10.0);
        double signalPower = 0;
        
        for (const auto& s : signal) {
            signalPower += std::abs(s) * std::abs(s);
        }
        signalPower /= signal.size();
        
        double noisePower = signalPower / snrLinear;
        double noiseStdDev = std::sqrt(noisePower / 2);
        
        std::vector<std::complex<double>> noisy = signal;
        for (auto& s : noisy) {
            // Box-Muller transform for Gaussian noise
            double u1 = (double)rand() / RAND_MAX;
            double u2 = (double)rand() / RAND_MAX;
            double z0 = std::sqrt(-2 * std::log(u1)) * std::cos(2 * M_PI * u2);
            double z1 = std::sqrt(-2 * std::log(u1)) * std::sin(2 * M_PI * u2);
            
            s += std::complex<double>(z0 * noiseStdDev, z1 * noiseStdDev);
        }
        
        return noisy;
    }
    
    // Frequency hopping spread spectrum (anti-jamming)
    std::vector<std::complex<double>> frequencyHop(const std::vector<std::complex<double>>& signal,
                                                  const std::vector<int>& hopSequence,
                                                  double baseFreq, double hopRate) {
        std::vector<std::complex<double>> hopped;
        
        for (int i = 0; i < signal.size(); i++) {
            int hopIndex = (i / (int)hopRate) % hopSequence.size();
            double freq = baseFreq + hopSequence[hopIndex];
            double phase = 2 * M_PI * freq * i / hopRate;
            
            std::complex<double> oscillator(std::cos(phase), std::sin(phase));
            hopped.push_back(signal[i] * oscillator);
        }
        
        return hopped;
    }
    
    // Dijkstra's algorithm for optimal mesh routing
    std::vector<int> findOptimalRoute(const std::vector<Node>& nodes, int source, int dest) {
        int n = nodes.size();
        std::vector<double> dist(n, 1e9);
        std::vector<int> parent(n, -1);
        std::vector<bool> visited(n, false);
        
        dist[source] = 0;
        
        for (int i = 0; i < n - 1; i++) {
            int u = -1;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }
            if (dist[u] == 1e9) break;
            visited[u] = true;
            
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    // Calculate distance between nodes
                    double linkDist = geom::dist_2p(nodes[u].x, nodes[u].y, 
                                                   nodes[v].x, nodes[v].y);
                    double linkQuality = calculateLinkQuality(linkDist, 20, 915e6);
                    
                    double cost = linkDist / linkQuality; // Lower quality = higher cost
                    
                    if (dist[u] + cost < dist[v]) {
                        dist[v] = dist[u] + cost;
                        parent[v] = u;
                    }
                }
            }
        }
        
        // Reconstruct path
        std::vector<int> path;
        int curr = dest;
        while (curr != -1) {
            path.insert(path.begin(), curr);
            curr = parent[curr];
        }
        
        return path;
    }
    
    // Friis transmission equation (RF link budget)
    double calculateLinkQuality(double distance, double txPower, double frequency) {
        // Path loss in dB: 20*log10(d) + 20*log10(f) + 20*log10(4π/c)
        double c = 3e8; // Speed of light
        double pathLossDb = 20 * std::log10(distance) + 
                           20 * std::log10(frequency) + 
                           20 * std::log10(4 * M_PI / c);
        
        double rxPower = txPower - pathLossDb;
        
        // Normalize to 0-1 scale (better connection = closer to 1)
        return 1.0 / (1.0 + std::exp(-(rxPower + 80) / 10));
    }
}
