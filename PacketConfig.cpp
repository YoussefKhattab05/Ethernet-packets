#include "PacketConfig.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool PacketConfig::loadConfig(const std::string& configFilePath) {
    std::ifstream configFile(configFilePath);
    if (!configFile.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(configFile, line)) {
        if (!parseLine(line)) {
            return false;
        }
    }

    configFile.close();
    return true;
}

bool PacketConfig::parseLine(const std::string& line) {
    std::istringstream iss(line);
    std::string key, value;

    if (std::getline(iss, key, '=') && std::getline(iss, value)) {
        key = key.substr(key.find_first_not_of(' '));  // Trim spaces
        value = value.substr(value.find_first_not_of(' '));

        if (key == "Eth.LineRate") lineRate = std::stoi(value);
        else if (key == "Eth.CaptureSizeMs") captureSizeMs = std::stoi(value);
        else if (key == "Eth.MinNumOfIFGsPerPacket") minNumOfIFGs = std::stoi(value);
        else if (key == "Eth.DestAddress") destAddress = value;
        else if (key == "Eth.SourceAddress") srcAddress = value;
        else if (key == "Eth.MaxPacketSize") maxPacketSize = std::stoi(value);
        else if (key == "Eth.BurstSize") burstSize = std::stoi(value);
        else if (key == "Eth.BurstPeriodicity_us") burstPeriodicityUs = std::stoi(value);
        else return false;

        return true;
    }
    return false;
}
