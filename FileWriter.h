// This class handles writing the generated packets to an output file.

#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <string>

class FileWriter {
public:
    FileWriter(const std::string& path);
    void write(const std::string& data);
private:
    std::string outputPath;
};

#endif // FILEWRITER_H

