#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <thread>

namespace fs = std::filesystem;

int main() {
    // define path to your file
    fs::path filePath = "../test.txt";

    // get last modification time
    auto lastModified = fs::last_write_time(filePath);

    while (true) {
        // wait till next modification time check
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); 

        // get last modification time
        auto currentModified = fs::last_write_time(filePath);

        // compare two modification time, if different it's mean file was modified
        if (currentModified != lastModified) {
            std::cout << "file was modified!" << std::endl;
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

    return 0;
}
