#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>

int main() {
    std::ifstream inputFile("f1.txt");
    std::ofstream outputFile("f2.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Failed to open files." << std::endl;
        return 1;
    }

    std::vector<std::string> words;
    std::string word;

    while (inputFile >> word) {
        words.emplace_back(std::move(word));
    }

    auto rng = std::default_random_engine{std::random_device{}()};

    std::shuffle(words.begin(), words.end(), rng);

    for (const auto& w : words) {
        outputFile << w << " ";
    }

    std::cout << "The words in file f1 were randomly reordered and written to file f2." << std::endl;

    return 0;
}