// Decorator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Component {
public:
    virtual string Operation() const = 0;
};

class ConcreteComponent : public Component {
public:
    string Operation() const override {
        return "ConcreteComponent";
    }
};

class ConcreteComponent2 : public Component {
public:
    string Operation() const override {
        return "ConcreteComponent2";
    }
};

class Decorator : public Component {
protected:
    Component* component_;

public:
    Decorator(Component* component) : component_(component) {
    }
    string Operation() const override {
        return this->component_->Operation(); 
    }
};

class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {
    }
    string Operation() const override {
        return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
    }
};

class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* component) : Decorator(component) {
    }

   string Operation() const override {
        return "ConcreteDecoratorB(" + Decorator::Operation() + ")";
    }
};

void ClientCode(Component* component) {
    cout << "RESULT: " << component->Operation() << endl;;
}

int main()
{
    Component* simple = new ConcreteComponent; //ConcreteComponent2 de olur
    cout << "simple component" << endl;
    ClientCode(simple);
    Component* decorator1 = new ConcreteDecoratorA(simple);
    Component* decorator2 = new ConcreteDecoratorB(decorator1);
    cout << "decorated component" << endl;
    ClientCode(decorator1);
    ClientCode(decorator2);
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
