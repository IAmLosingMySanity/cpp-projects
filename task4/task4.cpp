#include <iostream>
#include <fstream>
#include <sstream>

struct incident
{
    int id;
    std::string date;
    std::string type;
    std::string description;
};

void writeToFile(std::ofstream& outputFile, const incident& newIncident)
{
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

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <action>" << std::endl;
        return 1;
    }

    std::string action = argv[1];

    if (action == "w")
    {
        std::ofstream outputFile("incidents.txt", std::ios::app);

        if (!outputFile.is_open())
        {
            std::cerr << "Failed to open file." << std::endl;
            return 1;
        }

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
        
        writeToFile(outputFile, newIncident);

        outputFile.close();
    }
    else if (action == "r")
    {
        std::ifstream inputFile("incidents.txt");

        if (!inputFile.is_open())
        {
            std::cerr << "Failed to open file." << std::endl;
            return 1;
        }

        readFromFile(inputFile);

        inputFile.close();
    }
    else
    {
        std::cerr << "Invalid action. Available actions: w (write), r (read)" << std::endl;
        return 1;
    }

    return 0;
}