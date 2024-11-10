#include "utils.hpp"

// Implementarea funcției de hashing simplu pentru un string
uint32_t generate_hash(const std::string& input) {
    uint32_t hash = 0;
    for (char c : input) {
        // Combinația dintre shift și adunare pentru a crea un hash simplu
        hash = (hash << 5) + hash + static_cast<uint32_t>(c);
    }
    return hash;
}
