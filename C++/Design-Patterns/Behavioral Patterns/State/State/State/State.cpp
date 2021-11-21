// State.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <typeinfo>

using namespace std;

class Context;

class State {
protected:
    Context* context_; 

public:
    //virtual ~State() {
    //}

    void set_context(Context* context) {
        this->context_ = context; 
    }

    virtual void Handle1() = 0;
    virtual void Handle2() = 0;
};

class Context {
private:
    State* state_; 

public:
    Context(State* state) : state_(nullptr) {
        this->TransitionTo(state);  
    }
    //~Context() {
    //  delete state_;
    //}
    void TransitionTo(State* state) {
        cout << "Context: Transition to " << typeid(*state).name() << ".\n"; 
        if (this->state_ != nullptr) 
            delete this->state_;
        this->state_ = state; 
        this->state_->set_context(this); 
    }
    void Request1() {
        this->state_->Handle1();
    }
    void Request2() {
        this->state_->Handle2();
    }
};

class Durum1 : public State {
public:
    void Handle1() override;

    void Handle2() override {
        cout << "Durum1 handles request2.\n";
    }
};

class Durum2 : public State {
public:
    void Handle1() override {
        cout << "Durum2 handles request1.\n";
    }
    void Handle2() override {
        cout << "Durum2 handles request2.\n";
        cout << "Durum2 wants to change the state of the context.\n";
        this->context_->TransitionTo(new Durum1);
    }
};

void Durum1::Handle1() {
    {
        cout << "Durum1 handles request1.\n";
        cout << "Durum1 wants to change the state of the context.\n";

        this->context_->TransitionTo(new Durum2);
    }
}

void ClientCode() {
    Context* context = new Context(new Durum1);
    context->Request1();
    context->Request2();
    delete context;
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
