
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

FastFluxEvader is a tool for payloads obfuscation and converts them into a rotating set of IPv4 addresses using Fast-Flux DNS techniques. This tool is designed to help penetration testers and security researchers evade detection systems by masking the C2 server location through a randomized, rotative IP generation scheme.

## Features

- **Payload Obfuscation**: Converts payloads to hexadecimal format for obfuscation.
- **Fast-Flux IP Rotation**: Generates a dynamic set of IPv4 addresses to simulate a Fast-Flux DNS network.
- **Customizable Parameters**: Supports command-line flags for specifying payload and enabling Fast-Flux rotation.
- **Optimized Performance**: Implements key operations in Assembly for efficient IP rotation and obfuscation.

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/YourUsername/FastFluxEvader.git
   cd FastFluxEvader
   ```
 2. **Build the project**:

Ensure you have cmake and nasm installed.
Use the provided build script to compile the project.
```bash
chmod +x build.sh
./build.sh
```
Dependencies:

cmake (for build automation)
nasm (for Assembly compilation)
Usage
Command-Line Flags
-p or --payload: Specifies the payload string to obfuscate. Required.
-f or --fast-flux: Enables Fast-Flux IP rotation. Optional.
-h or --help: Displays help information.
Example Command
To obfuscate a payload and enable Fast-Flux rotation:

```bash
./FastFluxEvader -p "example_payload" -f
```
Example Output
python
Copy code
Payload obfuscated: 6578616d706c655f7061796c6f6164
Fast-Flux IPs generated:
0xaabbccdd
0x11223344
...
Implementation Details
Obfuscation Module (obfuscation.cpp)
Converts the payload to a hexadecimal string using bitwise operations, complicating static analysis and detection.

Fast-Flux Rotation (fast_flux.cpp)
Generates a series of IP addresses by applying Fast-Flux techniques with pseudo-random IP generation. Utilizes a 32-bit hash seed to ensure unique IP sequences per payload.

Assembly Integration (asm_integration.asm)
Implements a bitwise left rotation in Assembly for high-performance IP obfuscation, making detection more difficult.

Testing
Unit tests are included in the tests/ directory, and use GoogleTest for validation.

Run tests:

```bash
cd build
ctest
```
Expected Output:

All tests should pass without errors.
Coverage includes obfuscation validation, Fast-Flux rotation, and utility hashing.
Technical Requirements
C++17: Project is built with C++17 for compatibility and performance.
Assembly: NASM is used for inline Assembly to optimize specific functions.
Randomized IP Generation: Uses std::mt19937 for reliable pseudo-random Fast-Flux IP rotation.
Contributions
Contributions are welcome. Please fork the repository, create a branch, and submit a pull request.

License
This project is licensed under the MIT License.
