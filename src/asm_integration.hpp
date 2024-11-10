#ifndef ASM_INTEGRATION_HPP
#define ASM_INTEGRATION_HPP

#include <cstdint>  // pentru tipul uint32_t

// Funcția Assembly pentru rotația IP-ului la stânga cu un anumit număr de biți
extern "C" uint32_t rotate_left(uint32_t ip, uint8_t bits);

#endif // ASM_INTEGRATION_HPP
