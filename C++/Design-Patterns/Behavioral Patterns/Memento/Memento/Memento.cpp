// Memento.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class Memento {
public:
    virtual string GetName() const = 0;
    virtual string date() const = 0;
    virtual string state() const = 0;
};

class ConcreteMemento : public Memento {
private:
    string state_;
    string date_;

public:
    ConcreteMemento(string state) : state_(state) {
        this->state_ = state;
        auto start = chrono::system_clock::now();
        time_t savedTime = chrono::system_clock::to_time_t(start);
        char tmBuff[27];
        ctime_s(tmBuff, sizeof(tmBuff), &savedTime);
        this->date_ = tmBuff;
    }
    string state() const override {
        return this->state_;
    }
    string GetName() const override {
        return this->date_ + "(" + this->state_.substr(0, 9) + "...)";
    }
    string date() const override {
        return this->date_;
    }
};

class Originator {
private:
    string state_;

    string GenerateRandomString(int length = 10) {
        const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        int stringLength = sizeof(alphanum) - 1;

        string random_string;
        for (int i = 0; i < length; i++) {
            random_string += alphanum[rand() % stringLength];
        }
        return random_string;
    }

public:
    Originator(string state) : state_(state) {
        cout << "Originator: My initial state is: " << this->state_ << endl;
    }
    void DoSomething() {
        cout << "Originator: I'm doing something important." << endl;
        this->state_ = this->GenerateRandomString(30);
        cout << "Originator: and my state has changed to: " << this->state_ << endl;
    }

    Memento* Save() {
        return new ConcreteMemento(this->state_);
    }
    void Restore(Memento* memento) {
        this->state_ = memento->state();
        cout << "Originator: My state has changed to: " << this->state_ << endl;
    }
};

class Caretaker {
private:
    vector<Memento*> mementos_;
    Originator* originator_;

public:
    Caretaker(Originator* originator) : originator_(originator) {
        this->originator_ = originator;
    }

    void Backup() {
        cout << endl << "Caretaker: Saving Originator's state..." << endl;
        this->mementos_.push_back(this->originator_->Save());
    }
    void Undo() {
        if (!this->mementos_.size()) {
            return;
        }
        Memento* memento = this->mementos_.back();
        this->mementos_.pop_back();
        cout << "Caretaker: Restoring state to: " << memento->GetName() << endl;
        try {
            this->originator_->Restore(memento);
        }
        catch (...) {
            this->Undo();
        }
    }
    void ShowHistory() const {
        cout << "Caretaker: Here's the list of mementos:" << endl;
        for (Memento* memento : this->mementos_) {
            cout << memento->GetName() << endl;
        }
    }
};

void ClientCode() {
    Originator* originator = new Originator("Super-duper-super-puper-super.");
    Caretaker* caretaker = new Caretaker(originator);
    caretaker->Backup();
    originator->DoSomething();
    caretaker->Backup();
    originator->DoSomething();
    caretaker->Backup();
    originator->DoSomething();
    cout << endl;
    caretaker->ShowHistory();
    cout << endl << "Client: Now, let's rollback!" << endl << endl;
    caretaker->Undo();
    cout << endl << "Client: Once more!" << endl << endl;
    caretaker->Undo();

    delete originator;
    delete caretaker;
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
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
