#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Incident {
    int id;
    std::string date;
    std::string type;
    std::string description;
};

void cls() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void addIncidentToFile(const Incident& incident, const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << incident.id << " | " << incident.date << " | " << incident.type << " | " << incident.description << "\n";
        file.close();
        std::cout << "Incident added to file successfully." << std::endl;
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

// void deleteIncidentFromFile(int id, const std::string& filename) {
//     std::ifstream inputFile(filename);
//     if (!inputFile.is_open()) {
//         std::cerr << "Unable to open file for reading." << std::endl;
//         return;
//     }

//     std::vector<std::string> lines;
//     std::string line;
//     while (std::getline(inputFile, line)) {
//         size_t pos = line.find("|");
//         int currentId = std::stoi(line.substr(0, pos));
//         if (currentId != id) {
//             lines.push_back(line);
//         }
//     }

//     inputFile.close();

//     std::ofstream outputFile(filename, std::ios::trunc);
//     if (outputFile.is_open()) {
//         for (const auto& l : lines) {
//             outputFile << l << "\n";
//         }
//         outputFile.close();
//         std::cout << "Incident with id " << id << " deleted successfully." << std::endl;
//     } else {
//         std::cerr << "Unable to open file for writing." << std::endl;
//     }
// }

void deleteIncidentFromFile(int id, const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file for reading." << std::endl;
        return;
    }

    std::vector<std::string> matchingLines;
    std::string line;
    while (std::getline(inputFile, line)) {
        size_t pos = line.find("|");
        int currentId = std::stoi(line.substr(0, pos));
        if (currentId == id) {
            matchingLines.push_back(line);
        }
    }

    inputFile.close();

    if (matchingLines.empty()) {
        std::cout << "No incidents found with id " << id << std::endl;
        return;
    }

    if (matchingLines.size() > 1) {
        std::cout << "Multiple incidents found with id " << id << ". Please select one:" << std::endl;
        for (int i = 0; i < matchingLines.size(); ++i) {
            std::cout << i+1 << ". " << matchingLines[i] << std::endl;
        }

        int selection;
        std::cout << "Enter the number of the incident to delete: ";
        std::cin >> selection;

        if (selection < 1 || selection > matchingLines.size()) {
            std::cout << "Invalid selection. No incident deleted." << std::endl;
            return;
        }

        matchingLines.erase(matchingLines.begin() + selection - 1);
    }

    std::ofstream outputFile(filename, std::ios::trunc);
    if (outputFile.is_open()) {
        for (const auto& l : matchingLines) {
            outputFile << l << "\n";
        }
        outputFile.close();
        std::cout << "Incident with id " << id << " deleted successfully." << std::endl;
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

void readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for reading." << std::endl;
    }
}

void searchByDate(const std::string& date, const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        bool found = false;
        while (std::getline(file, line)) {
            size_t pos = line.find(",");
            std::string currentDate = line.substr(pos + 1, line.find(",", pos + 1) - pos - 1);
            if (currentDate == date) {
                std::cout << line << std::endl;
                found = true;
            }
        }
        file.close();

        if (!found) {
            std::cout << "No incidents found for the specified date." << std::endl;
        }
    } else {
        std::cerr << "Unable to open file for reading." << std::endl;
    }
}

int main() {
    std::string filename = "incidents.txt";
    int choice;
    do {
        std::cout << "====================================" << std::endl;
        std::cout << "1. Add incident to file" << std::endl;
        std::cout << "2. Delete incident from file" << std::endl;
        std::cout << "3. Read incidents from file" << std::endl;
        std::cout << "4. Search incidents by date" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        cls();

        switch (choice) {
            case 1: {
                Incident newIncident;
                std::cout << "Enter incident id: ";
                std::cin >> newIncident.id;
                std::cout << "Enter incident date: ";
                std::cin >> newIncident.date;
                std::cin.ignore();
                std::cout << "Enter incident type: ";
                std::getline(std::cin, newIncident.type);
                std::cout << "Enter incident description: ";
                std::getline(std::cin, newIncident.description);
                addIncidentToFile(newIncident, filename);
                break;
            }
            case 2: {
                int id;
                std::cout << "Enter incident id to delete: ";
                std::cin >> id;
                deleteIncidentFromFile(id, filename);
                break;
            }
            case 3: {
                readFromFile(filename);
                break;
            }
            case 4: {
                std::string date;
                std::cout << "Enter date to search incidents: ";
                std::cin >> date;
                searchByDate(date, filename);
                break;
            }
            case 5:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
