#ifndef FILE_UPDATER_HPP
#define FILE_UPDATER_HPP

#include "IFileUpdater.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <thread>
#include <mutex>

namespace fs = std::filesystem;

class FileUpdater final : public IFileUpdater {
    public:
        FileUpdater(const fs::path& filePath, std::mutex& fileMutex) : m_filePath(filePath), m_fileMutex(fileMutex) {}

        void startUpdating() override {
            // define time to wait
            constexpr auto kTimePeriodS{1};
            // Open the file
            std::ofstream file(m_filePath, std::ios::app);

            // Check if the file was successfully opened
            if (!file.is_open()) {
                std::cerr << "Can't open file!" << std::endl;
                return;
            }

            // Update the file with formatted time
            while (true) {
                auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
                std::tm currentTime = *std::localtime(&now);

                std::string formattedTime = std::asctime(&currentTime);

                // Wait for one second before the next update
                std::this_thread::sleep_for(std::chrono::seconds(kTimePeriodS));
                    
                // lock access to file
                std::lock_guard<std::mutex> lock(m_fileMutex);
                file << formattedTime;
                file.flush();
            }
        }

    private:
        const fs::path& m_filePath;
        std::mutex& m_fileMutex;
};

#endif // FILE_UPDATER_HPP
