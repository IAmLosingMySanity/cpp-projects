/*Дан текстовый файл f1. Случайным образом переупорядочить слова исходного текста и результат записать в файл f2.*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

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
        words.push_back(word);
    }

    auto rng = std::default_random_engine{std::time(0)};

    std::shuffle(words.begin(), words.end(), rng);

    for (const std::string& w : words) {
        outputFile << w << " ";
    }

    inputFile.close();
    outputFile.close();

    std::cout << "The words in file f1 were randomly reordered and written to file f2." << std::endl;
    
    return 0;
}