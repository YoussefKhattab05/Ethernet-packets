// This class handles packet bursts based on configuration and controls the timing and periodicity.

#ifndef BURSTGENERATOR_H
#define BURSTGENERATOR_H

#include "PacketConfig.h"
#include "FileWriter.h"
#include "EthernetPacket.h"

class BurstGenerator {
public:
    BurstGenerator(const PacketConfig& config, FileWriter& fileWriter);
    void start();

private:
    const PacketConfig& config;
    FileWriter& fileWriter;
};

#endif // BURSTGENERATOR_H
