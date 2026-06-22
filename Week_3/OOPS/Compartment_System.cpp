#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Abstract Base Class
class Compartment {
public:
    virtual string notice() = 0; // Pure virtual function
    virtual ~Compartment() {}
};

// Derived Classes
class FirstClass : public Compartment {
public:
    string notice() override {
        return "First Class Compartment: Premium passengers only.";
    }
};

class Ladies : public Compartment {
public:
    string notice() override {
        return "Ladies Compartment: Reserved for women passengers.";
    }
};

class General : public Compartment {
public:
    string notice() override {
        return "General Compartment: Open for all passengers.";
    }
};

class Luggage : public Compartment {
public:
    string notice() override {
        return "Luggage Compartment: For luggage and parcels only.";
    }
};

// Test Class
class TestCompartment {
public:
    static void run() {
        Compartment* compartments[10];

        srand(time(0));

        for (int i = 0; i < 10; i++) {
            int choice = rand() % 4 + 1; // Random number 1-4

            switch (choice) {
                case 1:
                    compartments[i] = new FirstClass();
                    break;
                case 2:
                    compartments[i] = new Ladies();
                    break;
                case 3:
                    compartments[i] = new General();
                    break;
                case 4:
                    compartments[i] = new Luggage();
                    break;
            }
        }

        cout << "Compartment Notices:\n\n";

        for (int i = 0; i < 10; i++) {
            cout << "Compartment " << i + 1 << ": "
                 << compartments[i]->notice() << endl;
        }

        // Free memory
        for (int i = 0; i < 10; i++) {
            delete compartments[i];
        }
    }
};

int main() {
    TestCompartment::run();
    return 0;
}
