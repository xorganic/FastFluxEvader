#include <gtest/gtest.h>
#include "obfuscation.hpp"

TEST(ObfuscationTest, SimplePayload) {
    std::string payload = "test";
    std::string expected_obfuscated = "74657374"; // "test" în hex este 74657374
    EXPECT_EQ(obfuscate_payload(payload), expected_obfuscated);
}

TEST(ObfuscationTest, EmptyPayload) {
    std::string payload = "";
    std::string expected_obfuscated = "";
    EXPECT_EQ(obfuscate_payload(payload), expected_obfuscated);
}
