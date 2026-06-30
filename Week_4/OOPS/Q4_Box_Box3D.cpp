#include <iostream>
using namespace std;

class Box {
protected:
    double length, breadth;

public:
    Box(double l, double b) {
        length = l;
        breadth = b;
    }

    double area() {
        return length * breadth;
    }
};

class Box3D : public Box {
private:
    double height;

public:
    Box3D(double l, double b, double h) : Box(l, b) {
        height = h;
    }

    double volume() {
        return length * breadth * height;
    }
};

int main() {
    Box b(10, 5);
    cout << "Area = " << b.area() << endl;

    Box3D b3(10, 5, 4);
    cout << "Area = " << b3.area() << endl;
    cout << "Volume = " << b3.volume() << endl;

    return 0;
}
