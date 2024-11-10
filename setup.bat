@echo off
echo Checking and installing dependencies for FastFluxEvader on Windows...

REM Verify Chocolatey installation
choco -v >nul 2>&1
IF %ERRORLEVEL% NEQ 0 (
    echo Chocolatey is not installed. Please install Chocolatey first.
    exit /b 1
)

REM Function to check and install a package
setlocal
set PACKAGES=cmake nasm

for %%P in (%PACKAGES%) do (
    echo Checking %%P...
    choco list --local-only %%P | find /I "%%P" >nul
    IF %ERRORLEVEL% NEQ 0 (
        echo %%P is not installed. Installing...
        choco install %%P -y
    ) ELSE (
        echo %%P is already installed.
    )
)

REM Check if GoogleTest is installed
REM Note: GoogleTest is usually built from source on Windows, as no official package is available.
REM Optional: Add instructions to manually build and link GoogleTest if required.

echo All dependencies have been checked.
pause
exit /b 0
