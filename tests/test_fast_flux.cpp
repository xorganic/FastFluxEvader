#include <gtest/gtest.h>
#include "fast_flux.hpp"
#include <set>

TEST(FastFluxTest, GenerateIPs) {
    std::string obfuscated_payload = "74657374";
    auto ips = generate_fast_flux_ips(obfuscated_payload);

    // Verifică că avem exact 10 IP-uri generate
    EXPECT_EQ(ips.size(), 10);

    // Verifică unicitatea IP-urilor (utilizăm std::set pentru a detecta duplicate)
    std::set<uint32_t> unique_ips(ips.begin(), ips.end());
    EXPECT_EQ(unique_ips.size(), ips.size()); // Ar trebui să fie toate unice
}

TEST(FastFluxTest, DifferentIPPerRun) {
    std::string obfuscated_payload = "74657374";
    auto ips_run1 = generate_fast_flux_ips(obfuscated_payload);
    auto ips_run2 = generate_fast_flux_ips(obfuscated_payload);

    // Verifică că IP-urile generate diferă la fiecare execuție
    EXPECT_NE(ips_run1, ips_run2);
}
