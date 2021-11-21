// Visitor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>

using namespace std;

class ConcreteComponentA;
class ConcreteComponentB;

class Visitor {
public:
    virtual void VisitConcreteComponentA(const ConcreteComponentA* element) const = 0;
    virtual void VisitConcreteComponentB(const ConcreteComponentB* element) const = 0;
};

class Component {
public:
    virtual ~Component() {}
    virtual void Accept(Visitor* visitor) const = 0;
};

class ConcreteComponentA : public Component {
public:
    void Accept(Visitor* visitor) const override {
        visitor->VisitConcreteComponentA(this);
    }
    string ExclusiveMethodOfConcreteComponentA() const {
        return "A";
    }
};

class ConcreteComponentB : public Component {
public:
    void Accept(Visitor* visitor) const override {
        visitor->VisitConcreteComponentB(this);
    }
    string SpecialMethodOfConcreteComponentB() const {
        return "B";
    }
};

class ConcreteVisitor1 : public Visitor {
public:
    void VisitConcreteComponentA(const ConcreteComponentA* element) const override {
        cout << element->ExclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor1" << endl;
    }

    void VisitConcreteComponentB(const ConcreteComponentB* element) const override {
        cout << element->SpecialMethodOfConcreteComponentB() << " + ConcreteVisitor1" << endl;
    }
};

class ConcreteVisitor2 : public Visitor {
public:
    void VisitConcreteComponentA(const ConcreteComponentA* element) const override {
        cout << element->ExclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor2" << endl;
    }
    void VisitConcreteComponentB(const ConcreteComponentB* element) const override {
        cout << element->SpecialMethodOfConcreteComponentB() << " + ConcreteVisitor2" << endl;
    }
};

void ClientCode(array<const Component*, 2> components, Visitor* visitor) {
    for (const Component* comp : components) {
        comp->Accept(visitor);
    }
}

int main() {
    array<const Component*, 2> components = { new ConcreteComponentA, new ConcreteComponentB };
    cout << "The client code works with all visitors via the base Visitor interface:" << endl;
    ConcreteVisitor1* visitor1 = new ConcreteVisitor1;
    ClientCode(components, visitor1);
    cout << endl;
    cout << "It allows the same client code to work with different types of visitors:" << endl;
    ConcreteVisitor2* visitor2 = new ConcreteVisitor2;
    ClientCode(components, visitor2);

    for (const Component* comp : components) {
        delete comp;
    }
    delete visitor1;
    delete visitor2;

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
