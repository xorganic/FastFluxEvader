#include "obfuscation.hpp"
#include <sstream>
#include <iomanip>

// Funcția care convertește un șir de caractere într-un șir hex pentru ofuscare
std::string obfuscate_payload(const std::string& payload) {
    std::stringstream obfuscated;
    for (unsigned char ch : payload) {
        // Convertește fiecare caracter în hex și adaugă la fluxul de ieșire
        obfuscated << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(ch);
    }
    return obfuscated.str();
}
