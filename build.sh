#!/bin/bash

# Script de build pentru FastFluxEvader

# Setează opțiunile de terminare a scriptului dacă există o eroare
set -e

# Culoare pentru output
GREEN='\033[0;32m'
NC='\033[0m' # Fără culoare

echo -e "${GREEN}===== Inițierea build-ului FastFluxEvader =====${NC}"

# Verifică dacă CMake este instalat
if ! command -v cmake &> /dev/null
then
    echo "CMake nu este instalat. Instalare..."
    sudo apt-get update && sudo apt-get install cmake -y
fi

# Verifică dacă assembler-ul NASM este instalat pentru rularea codului ASM
if ! command -v nasm &> /dev/null
then
    echo "NASM nu este instalat. Instalare..."
    sudo apt-get install nasm -y
fi

# Crearea directorului de build dacă nu există
if [ ! -d "build" ]; then
  mkdir build
fi

# Intră în directorul build
cd build

# Rulare CMake pentru generarea fișierelor Make
echo -e "${GREEN}===== Rulare CMake... =====${NC}"
cmake ..

# Compilarea proiectului
echo -e "${GREEN}===== Compilarea proiectului cu Make =====${NC}"
make

# Executarea fișierului dacă compilarea a avut succes
echo -e "${GREEN}===== Rulare FastFluxEvader =====${NC}"
./FastFluxEvader

echo -e "${GREEN}===== Build finalizat! =====${NC}"
