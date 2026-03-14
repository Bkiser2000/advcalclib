#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <string>
#include "commun.hpp"

namespace mesh {
    struct MeshNode {
        int id;
        double x, y;              // GPS coordinates
        double batteryLevel;      // 0-100%
        int signalStrength;       // -120 to 0 dBm
        bool isOnline;
        std::vector<int> neighbors; // Connected node IDs
    };
    
    struct Message {
        int id;
        int sender;
        int destination;
        std::string payload;
        std::vector<int> route;
        int ttl; // Time to live (hops)
    };
    
    // Initialize node with hardware specs
    MeshNode initializeNode(int nodeId, double lat, double lon);
    
    // Broadcast discovery (find neighbors)
    std::vector<int> discoverNeighbors(const MeshNode& node, 
                                      const std::vector<MeshNode>& allNodes);
    
    // Route message through mesh
    bool routeMessage(Message& msg, 
                     const std::vector<MeshNode>& nodes,
                     const std::vector<comms::Node>& commNodes);
    
    // Self-heal: auto-reconnect when nodes rejoin
    void autoHeal(std::vector<MeshNode>& nodes);
    
    // Power optimization: adjust TX power based on need
    void optimizePower(MeshNode& node, const std::vector<MeshNode>& neighbors);
}

#endif
