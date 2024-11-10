#include "obfuscation.hpp"
#include <sstream>
#include <iomanip>

// Funcția care obfuschează payload-ul și aplică XOR dacă este specificat un key
std::string obfuscate_payload(const std::string& payload, uint8_t xor_key = 0) {
    std::stringstream obfuscated;
    for (unsigned char ch : payload) {
        // Aplică XOR doar dacă xor_key este diferit de 0
        ch = xor_key ? (ch ^ xor_key) : ch;
        obfuscated << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(ch);
    }
    return obfuscated.str();
}
