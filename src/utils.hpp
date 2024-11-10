#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <cstdint>

// Funcție de hashing: creează un hash simplu dintr-un string, folosit ca seed pentru randomizare
uint32_t generate_hash(const std::string& input);

#endif // UTILS_HPP
