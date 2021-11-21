// Mediator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class BaseComponent;
class Mediator {
public:
    virtual void Notify(BaseComponent* sender, string event) const = 0;
};

class BaseComponent {
protected:
    Mediator* mediator_;

public:
    BaseComponent(Mediator* mediator = nullptr) : mediator_(mediator) {
    }
    void set_mediator(Mediator* mediator) {
        this->mediator_ = mediator;
    }
};

class Component1 : public BaseComponent {
public:
    void DoA() {
        cout << "Component 1 does A." << endl;
        this->mediator_->Notify(this, "A");
    }
    void DoB() {
        cout << "Component 1 does B." << endl;
        this->mediator_->Notify(this, "B");
    }
};

class Component2 : public BaseComponent {
public:
    void DoC() {
        cout << "Component 2 does C." << endl;
        this->mediator_->Notify(this, "C");
    }
    void DoD() {
        cout << "Component 2 does D." << endl;
        this->mediator_->Notify(this, "D");
    }
};

class ConcreteMediator : public Mediator {
private:
    Component1* component1_;
    Component2* component2_;

public:
    ConcreteMediator(Component1* c1, Component2* c2) : component1_(c1), component2_(c2) {
        this->component1_->set_mediator(this);
        this->component2_->set_mediator(this);
    }
    void Notify(BaseComponent* sender, string event) const override {
        if (event == "A") {
            cout << "Mediator reacts on A and triggers following operations:" << endl;
            this->component2_->DoC();
        }
        if (event == "D") {
            cout << "Mediator reacts on D and triggers following operations:" << endl;
            this->component1_->DoB();
            this->component2_->DoC();
        }
    }
};

void ClientCode() {
    Component1* c1 = new Component1;
    Component2* c2 = new Component2;
    ConcreteMediator* mediator = new ConcreteMediator(c1, c2);
    cout << "Client triggers operation A." << endl;
    c1->DoA();
    cout << endl;
    cout << "Client triggers operation D." << endl;
    c2->DoD();

    delete c1;
    delete c2;
    delete mediator;
}

int main() {
    ClientCode();
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
