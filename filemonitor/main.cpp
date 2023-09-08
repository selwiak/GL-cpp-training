#include "FileMonitor.hpp"
#include <memory>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filePath = argv[1];

    // creating object
    std::unique_ptr<IFileMonitor> monitor = std::make_unique<FileMonitor>(filePath);

    monitor->startMonitoring();

    return 0;
}