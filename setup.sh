#!/bin/bash

# Script de setup pentru FastFluxEvader
# Asigură instalarea cmake, nasm și GoogleTest

# Culoare pentru mesaje
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # Fără culoare

echo -e "${GREEN}===== Verificarea și instalarea dependențelor =====${NC}"

# Funcție pentru a verifica și instala un pachet
check_and_install() {
    PACKAGE=$1
    if ! dpkg -s $PACKAGE &> /dev/null; then
        echo -e "${RED}$PACKAGE nu este instalat. Instalare...${NC}"
        sudo apt-get update && sudo apt-get install -y $PACKAGE
    else
        echo -e "${GREEN}$PACKAGE este deja instalat.${NC}"
    fi
}

# Verificare și instalare cmake
check_and_install "cmake"

# Verificare și instalare nasm (assembler pentru codul Assembly)
check_and_install "nasm"

# Verificare și instalare GoogleTest
if [ ! -d "/usr/src/googletest" ]; then
    echo -e "${RED}GoogleTest nu este instalat. Instalare...${NC}"
    sudo apt-get install -y git
    cd /usr/src
    sudo git clone https://github.com/google/googletest.git
    cd googletest
    sudo cmake .
    sudo make
    sudo cp -r googletest/include/gtest /usr/include
    sudo cp googlemock/libgmock.a googlemock/libgmock_main.a googlemock/libgtest.a googlemock/libgtest_main.a /usr/lib/
    echo -e "${GREEN}GoogleTest a fost instalat cu succes.${NC}"
else
    echo -e "${GREEN}GoogleTest este deja instalat.${NC}"
fi

echo -e "${GREEN}===== Toate dependențele sunt instalate =====${NC}"
