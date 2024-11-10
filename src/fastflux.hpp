#ifndef FAST_FLUX_HPP
#define FAST_FLUX_HPP

#include <vector>
#include <string>
#include <cstdint>  // pentru tipul uint32_t

// Funcția care generează o listă de adrese IP obfuscate folosind rotația Fast-Flux
std::vector<uint32_t> generate_fast_flux_ips(const std::string& obfuscated_payload);

#endif // FAST_FLUX_HPP
