#include "fast_flux.hpp"
#include <random>
#include <sstream>
#include <iostream>

// Funcția care generează un set de adrese IP obfuscate folosind rotația Fast-Flux
std::vector<uint32_t> generate_fast_flux_ips(const std::string& obfuscated_payload) {
    std::vector<uint32_t> ips;
    std::mt19937 rng(std::random_device{}());  // Generator de numere random pentru IP-uri
    std::uniform_int_distribution<int> dist(1, 254);  // Distribuție pentru intervalul de octeți IP (1-254)

    // Generăm un set de 10 adrese IP rotative
    for (int i = 0; i < 10; ++i) {
        uint32_t ip = (dist(rng) << 24) | (dist(rng) << 16) | (dist(rng) << 8) | dist(rng);
        ips.push_back(ip);
    }

    return ips;
}
