# FastFluxEvader

FastFluxEvader is a tool designed to obfuscate payloads by converting them into hexadecimal format. It provides a simple method for payload masking, useful in security testing and Red Team engagements, where it’s essential to avoid detection through simple static analysis. This tool is designed for pre-processing payloads that will later be deobfuscated and executed by a loader.

## Features

- **Payload Obfuscation**: Transforms payloads into hexadecimal format to help avoid signature-based detection.
- **Command-line Support**: Offers flags to specify the payload and customization for flexible usage.
- **Cross-Platform Compatibility**: Supports both Linux and Windows installations.

## How to Use FastFluxEvader

After installation, you can use FastFluxEvader to obfuscate a payload directly from the command line. The obfuscated payload can then be passed to a loader or script for deobfuscation and execution.

### Command-Line Flags

- `-p` or `--payload`: Specifies the payload string to obfuscate. **Required.**
- `-h` or `--help`: Displays help information about available flags.

### Example Command

To obfuscate a payload:
```bash
./FastFluxEvader -p "example_payload"
```
Example Output
```yaml
Payload obfuscated: 6578616d706c655f7061796c6f6164
```
The output will be the obfuscated hexadecimal version of the specified payload, which can then be further processed as required.

## Installation
FastFluxEvader can be installed on both Linux and Windows. Below are the installation instructions for each platform.

### Linux Installation
Clone the repository:

```bash
git clone https://github.com/YourUsername/FastFluxEvader.git
cd FastFluxEvader
```
Run the setup script to install dependencies:

Ensure you have sudo permissions to install packages.
The setup script will install cmake, nasm, and GoogleTest.
```bash
chmod +x setup.sh
./setup.sh
```
Build the project:

```bash
./build.sh
```
 Run the tool:
After the build completes, use the tool as described in the usage section.
```bash
./FastFluxEvader -p "example_payload"
```
### Windows Installation
Install Chocolatey (if not already installed):

Open Command Prompt as Administrator and run the following command:

```cmd
@powershell -NoProfile -ExecutionPolicy Bypass -Command "Set-ExecutionPolicy Bypass -Scope Process; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.SecurityProtocolType]::Tls12; Invoke-Expression ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))" && SET "PATH=%PATH%;%ALLUSERSPROFILE%\chocolatey\bin"
```
Clone the repository:
Open a new Command Prompt and run:

```cmd
git clone https://github.com/YourUsername/FastFluxEvader.git
cd FastFluxEvader
```
Run the setup script to install dependencies:

The setup script will use Chocolatey to install cmake and nasm.
```cmd
setup.bat
```
Build the project:

After dependencies are installed, compile the project using cmake and nmake:

```cmd
mkdir build
cd build
cmake ..
nmake
```
Run the tool:

Run the tool from the Command Prompt, providing the required payload flag.

```cmd
FastFluxEvader.exe -p "example_payload"
```
## Testing
FastFluxEvader includes unit tests using GoogleTest. On Linux, tests can be run with ctest after building the project. On Windows, you may need to build GoogleTest manually and configure the test paths in CMake.

### Running Tests on Linux
```bash
cd build
ctest
```
### Running Tests on Windows
Build GoogleTest from source if not already available.
Configure test paths in CMakeLists.txt to point to your GoogleTest libraries.
Run the tests using ctest from the build directory.
## License
FastFluxEvader is licensed under the MIT License. Contributions are welcome!
