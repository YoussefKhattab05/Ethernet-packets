
#include "FileWriter.h"
#include <fstream>
#include <iostream>

// Constructor implementation

FileWriter::FileWriter(const std::string& path) : outputPath(path) {}

// Method to write data to the file
void FileWriter::write(const std::string& data) {
    std::ofstream outFile(outputPath, std::ios::app);  // Open file in append mode
    if (outFile.is_open()) {
        outFile << data << std::endl;
    } else {
        std::cerr << "Error: Could not open output file for writing." << std::endl;
    }
}
