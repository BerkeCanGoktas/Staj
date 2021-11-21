// TimedCallback3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <future>
#include <ctime>

using namespace std;


void timedFunc(promise<string>* promiseObj, int time, void (*ptr)(promise<string>* promObj)) {
    while (true) {
        this_thread::sleep_for(chrono::seconds(time));
        (*ptr)(promiseObj);
    }
}

void sampleFunc(promise<string>* promObj) {
    promObj->set_value("Fonksiyon cagrildi");
}

int main()
{
    promise<string> promiseObj;
    future<string> futureObj = promiseObj.get_future();
    thread td1(timedFunc, &promiseObj, 3, sampleFunc);
    td1.detach();
    cout << futureObj.get() << endl;
    this_thread::sleep_for(chrono::seconds(5));
    //if (futureObj.valid()) {
      //  cout << futureObj.get() << endl;
    //}
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
