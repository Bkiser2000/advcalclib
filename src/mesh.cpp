#include "mesh.hpp"
#include "geom.hpp"
#include "commun.hpp"
#include <algorithm>
#include <cmath>

namespace mesh {
    
    // Range based on RF link budget (typical LoRa: ~10km)
    const double MAX_RANGE = 10000; // meters
    const double BATTERY_TX_COST = 0.5; // % per transmission
    
    MeshNode initializeNode(int nodeId, double lat, double lon) {
        return {
            nodeId,
            lat, lon,
            100.0,  // 100% battery
            -120,   // worst signal initially
            true,   // online
            {}      // no neighbors yet
        };
    }
    
    // Find neighbors within radio range
    std::vector<int> discoverNeighbors(const MeshNode& node, 
                                      const std::vector<MeshNode>& allNodes) {
        std::vector<int> neighbors;
        
        for (const auto& candidate : allNodes) {
            if (candidate.id == node.id) continue;
            if (!candidate.isOnline) continue;
            
            // Calculate distance
            double dist = geom::dist_2p(node.x, node.y, candidate.x, candidate.y);
            
            if (dist <= MAX_RANGE) {
                // Calculate signal strength using Friis equation
                double signalStrength = comms::calculateLinkQuality(dist, 20, 915e6);
                
                // Only add if signal is strong enough (-100 dBm threshold)
                if (signalStrength > 0.1) {
                    neighbors.push_back(candidate.id);
                }
            }
        }
        
        return neighbors;
    }
    
    // Route message with automatic rerouting
    bool routeMessage(Message& msg, 
                     const std::vector<MeshNode>& nodes,
                     const std::vector<comms::Node>& commNodes) {
        
        // Find route using Dijkstra
        std::vector<int> optimalRoute = comms::findOptimalRoute(
            commNodes, msg.sender, msg.destination
        );
        
        if (optimalRoute.empty()) {
            // No route found - queue for later delivery
            msg.ttl = 24; // Retry for 24 hops
            return false;
        }
        
        msg.route = optimalRoute;
        
        // Simulate routing through mesh
        for (int i = 0; i < optimalRoute.size() - 1; i++) {
            int currentNode = optimalRoute[i];
            int nextNode = optimalRoute[i + 1];
            
            // Check battery on relay node
            auto nodeIt = std::find_if(nodes.begin(), nodes.end(),
                [currentNode](const MeshNode& n) { return n.id == currentNode; });
            
            if (nodeIt != nodes.end() && nodeIt->batteryLevel < 10) {
                // Fall back to lower power route
                return false;
            }
        }
        
        return true;
    }
    
    // Self-healing mesh: auto-discover new paths when nodes fail
    void autoHeal(std::vector<MeshNode>& nodes) {
        for (auto& node : nodes) {
            if (!node.isOnline) continue;
            
            // Periodically rediscover neighbors
            node.neighbors = discoverNeighbors(node, nodes);
            
            // If lost neighbors, broadcast discovery beacon
            if (node.neighbors.empty() && node.batteryLevel > 5) {
                // Broadcast beacon to potentially new neighbors
                for (auto& other : nodes) {
                    if (other.id == node.id || !other.isOnline) continue;
                    
                    double dist = geom::dist_2p(node.x, node.y, other.x, other.y);
                    if (dist <= MAX_RANGE * 1.5) { // Extended range beacon
                        node.neighbors.push_back(other.id);
                    }
                }
            }
        }
    }
    
    // Power optimization: reduce TX power when close neighbors available
    void optimizePower(MeshNode& node, const std::vector<MeshNode>& neighbors) {
        if (node.batteryLevel < 20) {
            // Low battery: use minimum TX power
            node.signalStrength = -100; // Low power mode
        } else if (neighbors.size() > 3) {
            // Multiple neighbors: reduce power
            node.signalStrength = -90;
        } else if (neighbors.empty() && node.batteryLevel > 50) {
            // No neighbors: maximum power to find them
            node.signalStrength = -60;
        } else {
            // Normal operation
            node.signalStrength = -80;
        }
    }
}
