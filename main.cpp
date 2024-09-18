//This file will initialize the components, read the configuration, and start generating Ethernet packets.

#include <iostream>
#include "PacketConfig.h"
#include "BurstGenerator.h"
#include "FileWriter.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <configuration file> <output file>\n";
        return 1;
    }

    std::string configFilePath = argv[1];
    std::string outputFilePath = argv[2];

    PacketConfig config;
    if (!config.loadConfig(configFilePath)) {
        std::cerr << "Failed to load configuration file.\n";
        return 1;
    }

    FileWriter fileWriter(outputFilePath);
    BurstGenerator generator(config, fileWriter);

    generator.start();
    
    std::cout << "Packet generation completed.\n";
    return 0;
}
