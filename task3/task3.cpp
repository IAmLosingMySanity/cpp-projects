#include <iostream>
#include <fstream>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    ifstream inputFile("f1.txt");
    ofstream outputFile("f2.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Не удалось открыть файлы." << endl;
        return 1;
    }

    string word;
    string shuffledText;

    while (inputFile >> word) {
        int insertPosition = rand() % (shuffledText.length() + 1);
        shuffledText.insert(insertPosition, word + " ");
    }

    outputFile << shuffledText;

    inputFile.close();
    outputFile.close();

    cout << "Слова в файле f1 были случайным образом переупорядочены и записаны в файл f2." << endl;

    return 0;
}