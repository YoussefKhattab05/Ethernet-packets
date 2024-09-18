// Utility functions like byte manipulation, alignment helpers, etc.

#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

// Utility function declarations
std::string intToHex(uint32_t value, size_t width);
uint32_t calculateCRC32(const std::string& data);
std::string padTo4ByteAlignment(const std::string& packetData);

#endif // UTILS_H
