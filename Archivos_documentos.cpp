#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

void createDocumentFile(const std::string& outputFilename) {
    std::ofstream documentFile(outputFilename);
    if (!documentFile) {
        std::cerr << "Error: Unable to create document file.\n";
        return;
    }

    int documentID = 1;
    std::string directoryPath = "./";

    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.path().extension() == ".txt") {
            documentFile << documentID << " | " << entry.path().string() << "\n";
            documentID++;
        }
    }

    documentFile.close();
    std::cout << "Document file created successfully: " << outputFilename << "\n";
}
