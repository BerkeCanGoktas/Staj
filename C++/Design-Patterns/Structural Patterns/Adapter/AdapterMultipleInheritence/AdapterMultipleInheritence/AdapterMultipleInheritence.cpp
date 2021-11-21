// AdapterMultipleInheritence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Target {
public:
    virtual ~Target() = default;
    virtual string Request() const {
        return "Target: The default target's behavior.";
    }
};

class Adaptee {
public:
    string SpecificRequest() const {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

class Adapter : public Target, public Adaptee {
public:
    Adapter() {}
    string Request() const override {
        string to_reverse = SpecificRequest();
        reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter: (TRANSLATED) " + to_reverse;
    }
};

void ClientCode(const Target* target) {
    cout << target->Request();
}

int main() {
    cout << "Client: I can work just fine with the Target objects:" << endl;
    Target* target = new Target;
    ClientCode(target);
    cout << endl << endl;
    Adaptee* adaptee = new Adaptee;
    cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:" << endl;
    cout << "Adaptee: " << adaptee->SpecificRequest();
    cout << endl << endl;
    cout << "Client: But I can work with it via the Adapter:" << endl;
    Adapter* adapter = new Adapter;
    ClientCode(adapter);
    cout << endl;

    delete target;
    delete adaptee;
    delete adapter;

    return 0;
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
