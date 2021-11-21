// Timed Callback.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <future>
#include <ctime>

using namespace std;

bool timeCheck(int startTime) {
    bool zaman = 0;
    while (true) {
        time_t currentTime;
        currentTime = time(NULL);
        int passedTime = currentTime - startTime;
        if (passedTime % 3 == 0) {
            zaman = 1;
            return zaman;
        }
    }
}

bool controlThread(int startTime, bool (*ptr)(int x))
{
   bool x = (*ptr)(startTime);
   return x;
}

void sampleFunc() {
    cout << "Fonksiyon cagrildi" << endl;
}

void sampleFunc2() {
    cout << "Baska fonksiyon cagrildi" << endl;
}

void timedFunc(int startTime, void (*ptr2)()) {
    while (true) {
        this_thread::sleep_for(chrono::seconds(1));
        future<bool> timeObj = async(launch::async, controlThread, startTime, timeCheck);
        bool obj = timeObj.get();
        if (obj == 1) {
            (*ptr2)();
            continue;
        }
        else {
            continue;
        }
    }
}

void mainThread() {
    cout << "main thread" << endl;
    this_thread::sleep_for(chrono::seconds(10));
}

int main()
{
    time_t startTime;
    startTime = time(NULL);
    this_thread::sleep_for(chrono::seconds(2));
    future<void> voidObj = async(launch::async, timedFunc, startTime, sampleFunc2);
    future<void> mainObj = async(launch::async, mainThread);
    mainObj.get();
    voidObj.get(); // burada loopa takılı kalıyor, obj bir şeyler beklediği için
    mainObj.get(); //çağırmadı
   
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
