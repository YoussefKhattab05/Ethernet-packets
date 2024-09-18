// This class handles the construction of Ethernet packets, ensuring proper alignment and CRC calculation.

#ifndef ETHERNETPACKET_H
#define ETHERNETPACKET_H

#include <string>
#include "PacketConfig.h"
#include "FileWriter.h"  // Ensure this is included

class EthernetPacket {
public:
    EthernetPacket(const PacketConfig& config, FileWriter& fileWriter);  // Constructor
    void buildPacket();  // Method to build Ethernet packet

private:
    PacketConfig config;
    FileWriter& fileWriter;  // Reference to the FileWriter object

    std::string generatePayload();  // Method to generate the payload
};

#endif
