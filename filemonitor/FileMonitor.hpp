#ifndef FILE_MONITOR_HPP
#define FILE_MONITOR_HPP

#include "IFileMonitor.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <thread>
#include <mutex>

namespace fs = std::filesystem;

class FileMonitor final : public IFileMonitor {
    public:
        FileMonitor(const std::string& filePath) : m_filePath(filePath) {}

        void startMonitoring() override {
        // get last modification time
        auto lastModified = fs::last_write_time(m_filePath);

        while (true) {
            // define time to wait
            constexpr auto kTimePeriodMs{500};
            // wait till next modification time check
            std::this_thread::sleep_for(std::chrono::milliseconds(kTimePeriodMs)); 

            // get last modification time
            auto const currentModified = fs::last_write_time(m_filePath);

            // compare two modification time, if different it's mean file was modified
            if (currentModified != lastModified) {
                // lock access to file
                m_fileMutex.lock();
                std::cout << std::endl;
                std::cout << "File was modified!" << std::endl;
                lastModified = currentModified;

                // print file
                std::ifstream fileStream(m_filePath);
                if (fileStream) {
                    std::string line;
                    while (std::getline(fileStream, line)) {
                        std::cout << line << std::endl;
                    }
                    fileStream.close();
                } else {
                    std::cerr << "error!" << std::endl;
                }

                // unlock access to file
                m_fileMutex.unlock();
            }
        }
        }

    private:
        fs::path m_filePath;
        std::mutex m_fileMutex;
};

#endif // FILE_MONITOR_HPP
