@echo off
echo Building FastFluxEvader on Windows...

REM Verifică dacă CMake este instalat
cmake --version >nul 2>&1
IF %ERRORLEVEL% NEQ 0 (
    echo CMake nu este instalat. Instalează-l și asigură-te că este în PATH.
    exit /b 1
)

REM Verifică dacă este instalat Visual Studio sau Build Tools pentru a folosi nmake
where nmake >nul 2>&1
IF %ERRORLEVEL% NEQ 0 (
    echo NMake nu este disponibil. Asigură-te că Visual Studio sau Build Tools pentru Windows sunt instalate.
    exit /b 1
)

REM Creează directorul de build dacă nu există
IF NOT EXIST "build" (
    mkdir build
)

REM Intră în directorul de build
cd build

REM Generează fișierele de build folosind CMake
cmake .. -G "NMake Makefiles"
IF %ERRORLEVEL% NEQ 0 (
    echo Eroare la rularea CMake.
    exit /b 1
)

REM Compilează proiectul folosind nmake
nmake
IF %ERRORLEVEL% NEQ 0 (
    echo Eroare la rularea nmake.
    exit /b 1
)

echo Build finalizat cu succes!
cd ..
pause
