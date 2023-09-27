#include "FileMonitor.hpp"
#include "FileUpdater.hpp"
#include <memory>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string const filePath = argv[1];

    // Create unique_ptrs to manage the lifetime of FileUpdater and FileMonitor objects
    const auto fileUpdater = std::make_unique<FileUpdater>(filePath);
    const auto fileMonitor = std::make_unique<FileMonitor>(filePath);

    // Create threads to run member functions of FileUpdater and FileMonitor
    std::thread updaterThread(&FileUpdater::startUpdating, fileUpdater.get());
    std::thread monitorThread(&FileMonitor::startMonitoring, fileMonitor.get());

    // Wait for threads to finish execution
    updaterThread.join();
    monitorThread.join();

    return 0;
}