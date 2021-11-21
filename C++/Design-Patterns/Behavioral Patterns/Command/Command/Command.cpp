// Command.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Command {
public:
    virtual ~Command() {
    }
    virtual void Execute() const = 0;
};

class SimpleCommand : public Command {
private:
    string pay_load_;

public:
    explicit SimpleCommand(string pay_load) : pay_load_(pay_load) {
    }
    void Execute() const override {
        cout << "SimpleCommand: See, I can do simple things like printing (" << this->pay_load_ << ")" << endl;
    }
};

class Receiver {
public:
    void DoSomething(const string& a) {
        cout << "Receiver: Working on (" << a << ".)" << endl;
    }
    void DoSomethingElse(const string& b) {
        cout << "Receiver: Also working on (" << b << ".)" << endl;
    }
};

class ComplexCommand : public Command {
    Receiver* receiver_;
    string a_;
    string b_;
public:
    ComplexCommand(Receiver* receiver, string a, string b) : receiver_(receiver), a_(a), b_(b) {
    }
    void Execute() const override {
        cout << "ComplexCommand: Complex stuff should be done by a receiver object." << endl;
        this->receiver_->DoSomething(this->a_);
        this->receiver_->DoSomethingElse(this->b_);
    }
};

class Invoker {
private:
    Command* on_start_;
    Command* on_finish_;

public:
    ~Invoker() {
        delete on_start_;
        delete on_finish_;
    }

    void SetOnStart(Command* command) {
        this->on_start_ = command;
    }
    void SetOnFinish(Command* command) {
        this->on_finish_ = command;
    }

    void DoSomethingImportant() {
        cout << "Invoker: Does anybody want something done before I begin?" << endl;
        if (this->on_start_) {
            this->on_start_->Execute();
        }
        cout << "Invoker: ...doing something really important..." << endl;
        cout << "Invoker: Does anybody want something done after I finish?" << endl;
        if (this->on_finish_) {
            this->on_finish_->Execute();
        }
    }
};

int main() {
    Invoker* invoker = new Invoker;
    invoker->SetOnStart(new SimpleCommand("Say Hi!"));
    Receiver* receiver = new Receiver;
    invoker->SetOnFinish(new ComplexCommand(receiver, "Send email", "Save report"));
    invoker->DoSomethingImportant();

    delete invoker;
    delete receiver;

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
