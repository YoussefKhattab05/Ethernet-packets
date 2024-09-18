// This class will handle the reading of configuration settings from a file.

#ifndef PACKETCONFIG_H
#define PACKETCONFIG_H

#include <string>

class PacketConfig {
public:
    bool loadConfig(const std::string& configFilePath);

    uint32_t lineRate;
    uint32_t captureSizeMs;
    uint8_t minNumOfIFGs;
    std::string destAddress;
    std::string srcAddress;
    uint32_t maxPacketSize;
    uint32_t burstSize;
    uint32_t burstPeriodicityUs;

private:
    bool parseLine(const std::string& line);
};

#endif // PACKETCONFIG_H
