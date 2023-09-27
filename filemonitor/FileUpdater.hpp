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
        FileUpdater(const std::string& filePath) : m_filePath(filePath) {}

        void startUpdating() override {
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

                // lock access to file
                m_fileMutex.lock();
                file << formattedTime;
                file.flush();
                // unlock access to file
                m_fileMutex.unlock();

                // Wait for one second before the next update
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }

    private:
        fs::path m_filePath;
        std::mutex m_fileMutex;
};

#endif // FILE_UPDATER_HPP
