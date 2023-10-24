#include <iostream>
#include <vector>

class PassengerCarrier {
public:
    virtual void addPassenger(int passengerId) = 0;
    virtual void removePassenger(int passengerId) = 0;
    virtual void printPassengerList() = 0;
    virtual ~PassengerCarrier() {}
};

class Airplane : public PassengerCarrier {
private:
    std::vector<int> passengerList;

public:
    void addPassenger(int passengerId) override {
        passengerList.push_back(passengerId);
    }

    void removePassenger(int passengerId) override {
        for (auto it = passengerList.begin(); it != passengerList.end(); ++it) {
            if (*it == passengerId) {
                passengerList.erase(it);
                break;
            }
        }
    }

    void printPassengerList() override {
        std::cout << "Passenger List for Airplane:" << std::endl;
        for (int passengerId : passengerList) {
            std::cout << passengerId << std::endl;
        }
    }
};

class Train : public PassengerCarrier {
private:
    std::vector<int> passengerList;

public:
    void addPassenger(int passengerId) override {
        passengerList.push_back(passengerId);
    }

    void removePassenger(int passengerId) override {
        for (auto it = passengerList.begin(); it != passengerList.end(); ++it) {
            if (*it == passengerId) {
                passengerList.erase(it);
                break;
            }
        }
    }

    void printPassengerList() override {
        std::cout << "Passenger List for Train:" << std::endl;
        for (int passengerId : passengerList) {
            std::cout << passengerId << std::endl;
        }
    }
};

class Car : public PassengerCarrier {
private:
    std::vector<int> passengerList;

public:
    void addPassenger(int passengerId) override {
        passengerList.push_back(passengerId);
    }

    void removePassenger(int passengerId) override {
        for (auto it = passengerList.begin(); it != passengerList.end(); ++it) {
            if (*it == passengerId) {
                passengerList.erase(it);
                break;
            }
        }
    }

    void printPassengerList() override {
        std::cout << "Passenger List for Car:" << std::endl;
        for (int passengerId : passengerList) {
            std::cout << passengerId << std::endl;
        }
    }
};

int main() {
    PassengerCarrier* airplane = new Airplane();
    airplane->addPassenger(1);
    airplane->addPassenger(2);
    airplane->printPassengerList();
    delete airplane;

    PassengerCarrier* train = new Train();
    train->addPassenger(3);
    train->addPassenger(4);
    train->printPassengerList();
    delete train;

    PassengerCarrier* car = new Car();
    car->addPassenger(5);
    car->addPassenger(6);
    car->printPassengerList();
    delete car;

    return 0;
}