#include <iostream>
using namespace std;

class Test {
public:
    virtual int square(int n) = 0; // Pure virtual function
};

class Arithmetic : public Test {
public:
    int square(int n) override {
        return n * n;
    }
};

int main() {
    Arithmetic obj;
    cout << "Square of 5 = " << obj.square(5);

    return 0;
}
