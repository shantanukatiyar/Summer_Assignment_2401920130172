#include <iostream>
using namespace std;

// Interface using abstract class
class LibraryUser {

public:
    virtual void registerAccount() = 0;
    virtual void requestBook() = 0;
};

// KidUsers class
class KidUsers : public LibraryUser {

public:
    int age;
    string bookType;

    KidUsers(int a, string bt) {
        age = a;
        bookType = bt;
    }

    void registerAccount() {

        if(age < 12) {
            cout << "You have successfully registered under a Kids Account" << endl;
        }
        else {
            cout << "Sorry, Age must be less than 12 to register as a kid" << endl;
        }
    }

    void requestBook() {

        if(bookType == "Kids") {
            cout << "Book issued successfully, please return the book within 10 days" << endl;
        }
        else {
            cout << "Oops, you are allowed to take only Kids books" << endl;
        }
    }
};

// AdultUser class
class AdultUser : public LibraryUser {

public:
    int age;
    string bookType;

    AdultUser(int a, string bt) {
        age = a;
        bookType = bt;
    }

    void registerAccount() {

        if(age >= 12) {
            cout << "You have successfully registered under an Adult Account" << endl;
        }
        else {
            cout << "Sorry, Age must be greater than 12 to register as an adult" << endl;
        }
    }

    void requestBook() {

        if(bookType == "Fiction") {
            cout << "Book issued successfully, please return the book within 7 days" << endl;
        }
        else {
            cout << "Oops, you are allowed to take only Fiction books" << endl;
        }
    }
};

int main() {

    KidUsers kid1(10, "Kids");

    kid1.registerAccount();
    kid1.requestBook();

    cout << endl;

    AdultUser adult1(23, "Fiction");

    adult1.registerAccount();
    adult1.requestBook();

    return 0;
}


/*

Expected Output:

You have successfully registered under a Kids Account
Book issued successfully, please return the book within 10 days

You have successfully registered under an Adult Account
Book issued successfully, please return the book within 7 days

*/
