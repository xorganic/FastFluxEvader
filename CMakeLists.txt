cmake_minimum_required(VERSION 3.10)

# Setează numele proiectului și limbajul
project(FastFluxEvader LANGUAGES C CXX ASM)

# Specificați standardul C++ (de exemplu, C++17 pentru suportul optim)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Opțiuni de optimizare pentru a reduce detectabilitatea
add_compile_options(-O3 -Wall)

# Include directoarele cu fișierele header
include_directories(src)

# Adaugă toate fișierele sursă C++ și Assembly
set(SOURCES
    src/main.cpp
    src/obfuscation.cpp
    src/fast_flux.cpp
    src/utils.cpp
    src/asm_integration.asm
)

# Definește ținta executabilă
add_executable(FastFluxEvader ${SOURCES})

# Setează legătura cu librării specifice dacă este necesar (ex. pthreads pe Linux)
if(UNIX)
    target_link_libraries(FastFluxEvader pthread)
endif()

# Setează flag-urile de compilare pentru optimizarea procesării
target_compile_options(FastFluxEvader PRIVATE -march=native -fomit-frame-pointer)
# Include GoogleTest ca submodul
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Adăugare teste pentru obfuscare și rotație Fast-Flux
add_executable(test_obfuscation tests/test_obfuscation.cpp src/obfuscation.cpp)
add_executable(test_fast_flux tests/test_fast_flux.cpp src/fast_flux.cpp src/asm_integration.asm)

# Link Google Test la proiect
target_link_libraries(test_obfuscation gtest_main)
target_link_libraries(test_fast_flux gtest_main)

# Adăugare teste la CMake
include(GoogleTest)
gtest_discover_tests(test_obfuscation)
gtest_discover_tests(test_fast_flux)
