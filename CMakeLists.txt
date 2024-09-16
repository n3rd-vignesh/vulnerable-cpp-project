cmake_minimum_required(VERSION 3.10)
project(VulnerableCppProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find and include OpenSSL (this will look for OpenSSL on the system or download it via package managers)
find_package(OpenSSL 1.0.2k REQUIRED)

# Add executable
add_executable(vulnerable-cpp-project main.cpp)

# Link OpenSSL libraries
target_link_libraries(vulnerable-cpp-project OpenSSL::SSL OpenSSL::Crypto)
