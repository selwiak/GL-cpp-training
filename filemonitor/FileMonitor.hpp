#ifndef FILE_MONITOR_HPP
#define FILE_MONITOR_HPP

#include "IFileMonitor.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <thread>

namespace fs = std::filesystem;

class FileMonitor : public IFileMonitor {
    public:
        FileMonitor(const std::string& filePath) : filePath(filePath) {}

        void startMonitoring() override {
        // get last modification time
        auto lastModified = fs::last_write_time(filePath);

        while (true) {
            // wait till next modification time check
            std::this_thread::sleep_for(std::chrono::milliseconds(500)); 

            // get last modification time
            auto currentModified = fs::last_write_time(filePath);

            // compare two modification time, if different it's mean file was modified
            if (currentModified != lastModified) {
                std::cout << std::endl;
                std::cout << "File was modified!" << std::endl;
                lastModified = currentModified;

                // print file
                std::ifstream fileStream(filePath);
                if (fileStream) {
                    std::string line;
                    while (std::getline(fileStream, line)) {
                        std::cout << line << std::endl;
                    }
                    fileStream.close();
                } else {
                    std::cerr << "error!" << std::endl;
                }
            }
        }
        }

    private:
        fs::path filePath;
};

#endif // FILE_MONITOR_HPP
