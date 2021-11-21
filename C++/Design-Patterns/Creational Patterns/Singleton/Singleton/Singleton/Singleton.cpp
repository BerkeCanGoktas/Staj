// Singleton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Singleton {
protected:
    Singleton(const string value) : value_(value) {

    }
    static Singleton* singleton_;
    string value_;
public:
    Singleton(Singleton& other) = delete;  
    void operator=(const Singleton&) = delete;
    static Singleton* getInstance(const string& value);
    string value() const /*?*/ {
        return value_;
    }
};

Singleton* Singleton::singleton_ = nullptr;

Singleton* Singleton::getInstance(const string& value) {
    if (singleton_ == nullptr) {
        singleton_ = new Singleton(value);
    }
    return singleton_;
}

int main()
{
    Singleton* singletonObj = Singleton::getInstance("Singleton");
    cout << singletonObj->value() << endl; //Singleton
    Singleton* singletonObj2 = Singleton::getInstance("Singleton degil");
    cout << singletonObj2->value() << endl; //Singleton
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
