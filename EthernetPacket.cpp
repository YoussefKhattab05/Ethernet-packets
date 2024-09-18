#include "EthernetPacket.h"
#include "Utils.h"
#include <iostream>
#include <sstream>
#include "FileWriter.h"


// Ethernet frame constants
const std::string PREAMBLE = "FB555555555555D5"; // Preamble + Start of Frame Delimiter (SFD)
const uint32_t CRC_WIDTH = 8;  // Width of CRC in hex characters

// Constructor implementation
EthernetPacket::EthernetPacket(const PacketConfig& config, FileWriter& fileWriter)
    : config(config), fileWriter(fileWriter) {}

// Function to build the Ethernet packet
void EthernetPacket::buildPacket() {
    std::stringstream packetStream;

    // Step 1: Add Preamble + SFD
    packetStream << PREAMBLE;

    // Step 2: Add Destination Address (access directly from config)
    std::string destAddress = config.destAddress;
    if (destAddress.substr(0, 2) == "0x") {
    destAddress.erase(0, 2);  // Remove "0x" if present
    }
    packetStream << destAddress;
    

    // Step 3: Add Source Address (access directly from config)
    std::string srcAddress = config.srcAddress;
    if (srcAddress.substr(0, 2) == "0x") {
    srcAddress.erase(0, 2);  // Remove "0x" if present
    }
    packetStream << srcAddress;
    

    // Step 4: Add Ethernet Type (hardcoded for now as 0x0800 for IPv4)
    packetStream << "0800";

    // Step 5: Add Payload (fill with 0x00, size depends on the max packet size minus other fields)
    std::string payload = generatePayload();
    packetStream << payload;

    // Step 6: Calculate and append CRC (after payload)
    std::string packetData = packetStream.str();
    uint32_t crc = calculateCRC32(packetData);
    packetStream << intToHex(crc, CRC_WIDTH);  // Convert CRC to hex and append
    /* */
    for (uint8_t i= 0; i<config.minNumOfIFGs; i++)
    {
        packetStream << "07";
    }
    
    /* */
    // Step 7: Ensure 4-byte alignment using IFGs if needed
    std::string finalPacket = padTo4ByteAlignment(packetStream.str());


    std::string packet = finalPacket;
    if (packet.substr(0, 4) == "0000") {
    packet.erase(0, 4);  
    }
    if (packet.substr(0, 3) == "000") {
    packet.erase(0, 3);  
    }
    if (packet.substr(0, 2) == "00") {
    packet.erase(0, 2);  
    }
    if (packet.substr(0, 1) == "0") {
    packet.erase(0, 1);  
    }

    // Step 8: Write the final packet to the file
    fileWriter.write(packet);
}

// Function to generate the payload of the packet
std::string EthernetPacket::generatePayload() {
    size_t payloadSize = config.maxPacketSize - PREAMBLE.size() / 2
                         - 6 /* Destination Address */
                         - 6 /* Source Address */
                         - 2 /* Ethernet Type */
                         - CRC_WIDTH / 2;  // Size minus header fields and CRC

    std::stringstream payloadStream;
    for (size_t i = 0; i < payloadSize; ++i) {
        payloadStream << "00";  // Fill with 0x00
    }

    return payloadStream.str();
}
