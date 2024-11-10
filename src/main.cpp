#include <iostream>
#include <string>
#include <vector>
#include "obfuscation.hpp"
#include "fast_flux.hpp"

// ASCII Art Banner
void printBanner() {
    std::cout << R"(
███████╗ █████╗ ███████╗████████╗███████╗██╗     ██╗   ██╗██╗  ██╗
██╔════╝██╔══██╗██╔════╝╚══██╔══╝██╔════╝██║     ██║   ██║╚██╗██╔╝
█████╗  ███████║███████╗   ██║   █████╗  ██║     ██║   ██║ ╚███╔╝ 
██╔══╝  ██╔══██║╚════██║   ██║   ██╔══╝  ██║     ██║   ██║ ██╔██╗ 
██║     ██║  ██║███████║   ██║   ███████╗███████╗╚██████╔╝██╔╝ ██╗
╚═╝     ╚═╝  ╚═╝╚══════╝   ╚═╝   ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═╝
                                                                  
                   ███████╗██╗   ██╗ █████╗ ██████╗ ███████╗██████╗ 
                   ██╔════╝██║   ██║██╔══██╗██╔══██╗██╔════╝██╔══██╗
                   █████╗  ██║   ██║███████║██████╔╝█████╗  ██████╔╝
                   ██╔══╝  ██║   ██║██╔══██║██╔══██╗██╔══╝  ██╔══██╗
                   ███████╗╚██████╔╝██║  ██║██║  ██║███████╗██║  ██║
                   ╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝
                                                                     
by Xorganique
    )" << std::endl;
}

// Funcție pentru afișarea ajutorului
void printHelp() {
    std::cout << "Utilizare: FastFluxEvader [opțiuni]\n"
              << "Opțiuni:\n"
              << "  -p, --payload    Specifică payload-ul de obfuscat\n"
              << "  -f, --fast-flux  Activează rotația IP Fast-Flux\n"
              << "  -h, --help       Afișează acest mesaj de ajutor\n";
}

// Funcția principală
int main(int argc, char* argv[]) {
    printBanner();  // Afișează banner-ul ASCII la inițiere

    std::string payload;
    bool fastFluxEnabled = false;

    // Parsarea argumentelor
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-p" || arg == "--payload") {
            if (i + 1 < argc) {
                payload = argv[++i];
            } else {
                std::cerr << "Error: The -p flag requires a payload.\n";
                return 1;
            }
        } else if (arg == "--xor-key") {
            if (i + 1 < argc) {
                xor_key = static_cast<uint8_t>(std::stoi(argv[++i])); // conversie la uint8_t
            } else {
                std::cerr << "Error: The --xor-key flag requires a value.\n";
                return 1;
            }
        }
    }


    // Validare dacă payload-ul a fost setat
    if (payload.empty()) {
        std::cerr << "Eroare: Trebuie să specifici un payload cu -p sau --payload.\n";
        return 1;
    }

    // Ofuscare payload
    std::string obfuscated_payload = obfuscate_payload(payload);
    std::cout << "Payload ofuscat: " << obfuscated_payload << std::endl;

    // Generare IP-uri Fast-Flux dacă este activat
    if (fastFluxEnabled) {
        std::vector<uint32_t> rotated_ips = generate_fast_flux_ips(obfuscated_payload);
        std::cout << "IP-urile Fast-Flux obfuscate:\n";
        for (const auto& ip : rotated_ips) {
            std::cout << std::hex << ip << "\n";
        }
    }

    return 0;
}
