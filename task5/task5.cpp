#include <iostream>
#include <vector>

class PassengerCarrier;

class Person {
    public:
    Person(std::string p_name)
    {
        name = p_name;
    }
    void drive(const PassengerCarrier&);
 
private:
    std::string name;
};

class PassengerCarrier {
    friend void Person::drive(const PassengerCarrier&);
public:
    virtual void addPassenger(int passengerId) = 0;
    virtual void removePassenger(int passengerId) = 0;
    virtual void printPassengerList() = 0;
    virtual std::string getName() const = 0;
    virtual ~PassengerCarrier() {}
};

class Airplane : public PassengerCarrier {
private:
    std::vector<int> passengerList;
    std::string name;

public:
    Airplane(std::string a_name) {
        name = a_name;
    }
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

    std::string getName() const override {
        return name;
    }
};

class Train : public PassengerCarrier {
private:
    std::vector<int> passengerList;
    std::string name;

public:
    Train(std::string t_name) {
        name = t_name;
    }
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

    std::string getName() const override {
        return name;
    }
};

class Car : public PassengerCarrier {
private:
    std::vector<int> passengerList;
    std::string name;

public:
    Car(std::string c_name) {
        name = c_name;
    }
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

    std::string getName() const override {
        return name;
    }
};

void Person::drive(const PassengerCarrier& carrier) {
    std::cout << name << " is driving a " <<  carrier.getName() << "." << std::endl;
}

int main() {
    PassengerCarrier* airplane = new Airplane("FlexAir");
    airplane->addPassenger(1);
    airplane->addPassenger(2);
    airplane->printPassengerList();
    

    PassengerCarrier* train = new Train("Sapsan");
    train->addPassenger(3);
    train->addPassenger(4);
    train->printPassengerList();
    

    PassengerCarrier* car = new Car("Aurus");
    car->addPassenger(5);
    car->addPassenger(6);
    car->printPassengerList();
    

    Person person("Ryan Gosling"); 
    person.drive(*airplane);
    person.drive(*train);
    person.drive(*car);

    delete airplane;
    delete train;
    delete car;

    return 0;
}