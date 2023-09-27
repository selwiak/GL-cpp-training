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
        FileMonitor(const std::string& filePath, std::mutex& fileMutex) : m_filePath(filePath), m_fileMutex(fileMutex) {}

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

                {
                    // lock access to file
                    std::lock_guard<std::mutex> lock(m_fileMutex);

                    // compare two modification time, if different it's mean file was modified
                    if (currentModified != lastModified) {
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
                    }
                }
            }
        }

    private:
        fs::path m_filePath;
        std::mutex& m_fileMutex;
};

#endif // FILE_MONITOR_HPP
