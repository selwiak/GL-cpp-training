#include "FileMonitor.hpp"
#include <memory>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string const filePath = argv[1];

    const auto monitor = std::make_unique<FileMonitor>(filePath);

    monitor->startMonitoring();

    return 0;
}