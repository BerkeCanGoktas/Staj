// Template Method.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class AbstractClass {
public:
    void TemplateMethod() const {
        this->BaseOperation1();
        this->RequiredOperations1();
        this->BaseOperation2();
        this->Hook1();
        this->RequiredOperation2();
        this->BaseOperation3();
        this->Hook2();
    }
protected:
    void BaseOperation1() const {
        cout << "AbstractClass says: I am doing the bulk of the work" << endl;
    }
    void BaseOperation2() const {
        cout << "AbstractClass says: But I let subclasses override some operations" << endl;
    }
    void BaseOperation3() const {
        cout << "AbstractClass says: But I am doing the bulk of the work anyway" << endl;
    }
    virtual void RequiredOperations1() const = 0;
    virtual void RequiredOperation2() const = 0;
    virtual void Hook1() const {}
    virtual void Hook2() const {}
};
class ConcreteClass1 : public AbstractClass {
protected:
    void RequiredOperations1() const override {
        cout << "ConcreteClass1 says: Implemented Operation1" << endl;
    }
    void RequiredOperation2() const override {
        cout << "ConcreteClass1 says: Implemented Operation2" << endl;
    }
};

class ConcreteClass2 : public AbstractClass {
protected:
    void RequiredOperations1() const override {
        cout << "ConcreteClass2 says: Implemented Operation1" << endl;
    }
    void RequiredOperation2() const override {
        cout << "ConcreteClass2 says: Implemented Operation2" << endl;
    }
    void Hook1() const override {
        cout << "ConcreteClass2 says: Overridden Hook1" << endl;
    }
};

void ClientCode(AbstractClass* class_) {
    class_->TemplateMethod();
}

int main() {
    cout << "Same client code can work with different subclasses:" << endl;
    ConcreteClass1* concreteClass1 = new ConcreteClass1;
    ClientCode(concreteClass1);
    cout << endl;
    cout << "Same client code can work with different subclasses:" << endl;
    ConcreteClass2* concreteClass2 = new ConcreteClass2;
    ClientCode(concreteClass2);
    delete concreteClass1;
    delete concreteClass2;
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
