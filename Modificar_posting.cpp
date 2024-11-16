#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void updatePostingFile(const std::string& postingFilename, const std::unordered_map<std::string, int>& documentIDs) {
    std::ifstream inputFile(postingFilename);
    std::ofstream outputFile("updated_" + postingFilename);

    if (!inputFile || !outputFile) {
        std::cerr << "Error: Unable to open posting file.\n";
        return;
    }

    std::string token;
    int frequency, documentID;
    double tfidf;

    while (inputFile >> token >> frequency) {
        documentID = documentIDs[token];
        tfidf = calculateTFIDF(frequency, 100, 10, 5); // Valores de ejemplo
        outputFile << token << " | " << documentID << " | " << tfidf << "\n";
    }

    inputFile.close();
    outputFile.close();
    std::cout << "Posting file updated successfully.\n";
}
