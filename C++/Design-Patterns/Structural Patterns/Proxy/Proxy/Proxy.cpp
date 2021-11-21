// Proxy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Subject {
public:
    virtual void Request() const = 0;
};

class RealSubject : public Subject {
public:
    void Request() const override {
        cout << "RealSubject: Handling request." << endl;
    }
};

class Proxy : public Subject {     
private:
    RealSubject* real_subject_;

    bool CheckAccess() const {
        cout << "Proxy: Checking access prior to firing a real request." << endl;
        return true;
    }
    void LogAccess() const {
        cout << "Proxy: Logging the time of request." << endl;
    }

public:
    Proxy(RealSubject* real_subject) : real_subject_(new RealSubject(*real_subject)) {
    }

    ~Proxy() {
        delete real_subject_;
    }
   
    void Request() const override {
        if (this->CheckAccess()) {
            this->real_subject_->Request();
            this->LogAccess();
        }
    }
};

void ClientCode(const Subject& subject) {
    subject.Request();
}

int main() {
    cout << "Client: Executing the client code with a real subject:" << endl;
    RealSubject* real_subject = new RealSubject;
    ClientCode(*real_subject);
    cout << endl;
    cout << "Client: Executing the same client code with a proxy:" << endl;
    Proxy* proxy = new Proxy(real_subject);
    ClientCode(*proxy);

    delete real_subject;
    delete proxy;
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
