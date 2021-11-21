// SingletonMultiThread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class Singleton {
private:
    static Singleton* singleton_;
    static mutex mutex_;
protected:
    Singleton(const string& value) : value_(value) {

    }
    string value_;
public:
    static Singleton* getInstance(const string& value);
    string value() const {
        return value_;
    }
};

Singleton* Singleton::singleton_ = nullptr ;
mutex Singleton::mutex_;

Singleton* Singleton::getInstance(const string& value) {
    lock_guard<mutex> lock(mutex_);  //kullanılmazsa paralel threadler ayrı objeler oluşturur
    if (singleton_ == nullptr) {
        singleton_ = new Singleton(value);
    }
    return singleton_;
}


void func1() {
    this_thread::sleep_for(chrono::milliseconds(1000));
    Singleton* singleton = Singleton::getInstance("func1");
    cout << singleton->value() << "\n";
}

void func2() {
    this_thread::sleep_for(chrono::milliseconds(1000));
    Singleton* singleton = Singleton::getInstance("func2");
    cout << singleton->value() << "\n";
}
int main()
{
    thread t1(func1);
    thread t2(func2);
    t1.join();
    t2.join();
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
