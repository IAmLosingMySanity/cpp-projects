#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void menu();
void mainMenu();
int choice = 0;

struct incident
{
    int id;
    std::string date;
    std::string type;
    std::string description;
};

void writeToFile(std::ofstream& outputFile)
{
    incident newIncident;
    std::cout << "Enter incident ID: ";
    std::cin >> newIncident.id;
    std::cout << "Enter incident date: ";
    std::cin.ignore();
    std::getline(std::cin, newIncident.date);
    std::cout << "Enter incident type: ";
    std::getline(std::cin, newIncident.type);
    std::cout << "Enter incident description: ";
    std::getline(std::cin, newIncident.description);

    outputFile << newIncident.id << " | Date: " << newIncident.date << " | Type " << newIncident.type << " | Description: " << newIncident.description << std::endl;
}

void readFromFile(std::ifstream& inputFile)
{
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::cout << line << std::endl;
    }
}

int main(int argc, char** argv) {
    menu();
    return 0;
}

void menu() {
    do {
        mainMenu();
        std::ifstream inputFile;
        std::ofstream outputFile;
        switch (choice) {
            case 1:
                inputFile.open("incidents.txt");
                readFromFile(inputFile);
                inputFile.close();
                break;
            case 2:
                outputFile.open("incidents.txt", std::ios::app);
                writeToFile(outputFile);
                outputFile.close();
                break;
            case 3:
                break;
        }
    } while (choice != 3);
}


void mainMenu() {
    std::cout << "=====================" << std::endl;
    std::cout << "Main Menu\n";
    std::cout << "1 - Read data\n";
    std::cout << "2 - Write data\n";
    std::cout << "3 - Quit\n";
    std::cout << "Please choose: ";
    std::cin >> choice;
}