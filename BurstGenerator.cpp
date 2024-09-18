#include "BurstGenerator.h"
#include "EthernetPacket.h"
#include "FileWriter.h"
#include <thread> // For std::this_thread
#include <chrono> // For std::chrono::microseconds
#include <iostream>

BurstGenerator::BurstGenerator(const PacketConfig& config, FileWriter& fileWriter)
    : config(config), fileWriter(fileWriter) {}

void BurstGenerator::start() {
    // Calculate the total time in microseconds
    long long totalTimeUs = config.captureSizeMs * 1000;

    // Calculate the number of bursts
    long long numBursts = totalTimeUs / config.burstPeriodicityUs;

    for (long long i = 0; i < numBursts; ++i) {
        for (int j = 0; j < config.burstSize; ++j) {
            EthernetPacket packet(config, fileWriter);
            packet.buildPacket();
        }

        // Sleep for the burst periodicity
   //     std::this_thread::sleep_for(std::chrono::microseconds(config.burstPeriodicityUs));
    }
}