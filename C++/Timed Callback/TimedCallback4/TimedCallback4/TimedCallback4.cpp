// TimedCallback4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma warning(disable : 4996)
#include <iostream>
#include <thread>
#include <future>
#include <ctime>

using namespace std;

int x = 0;

void timedFunc(int time_, int x_, struct tm* startTime_, struct tm* stopTime_) {
    while (true) {
        time_t currentTime;
        struct tm* localTime;

        time(&currentTime);                   // Get the current time
        localTime = localtime(&currentTime);  // Convert the current time to the local time


        if ((localTime->tm_hour == startTime_->tm_hour) && (localTime->tm_min == startTime_->tm_min) && (localTime->tm_sec == startTime_->tm_sec)) {
            this_thread::sleep_for(chrono::seconds(time_));
            x_++;
        }
        else if ((localTime->tm_hour == stopTime_->tm_hour) && (localTime->tm_min == stopTime_->tm_min) && (localTime->tm_sec == stopTime_->tm_sec)) {
            x = x_;
        }
    }
}

int main()
{
    time_t currentTime;
    struct tm* startTime;
    struct tm* stopTime;

    time(&currentTime);

    startTime = localtime(&currentTime);
    startTime->tm_hour = 17;
    startTime->tm_min = 54;
    startTime->tm_sec = 40;
  
    stopTime = localtime(&currentTime);
    stopTime->tm_hour = 17;
    stopTime->tm_min = 55;
    stopTime->tm_sec = 0;

    //cout << Hour << " " << Min << " " << Sec << endl;

    thread td1(timedFunc, 1, x, startTime, stopTime);
    td1.detach();
    this_thread::sleep_for(chrono::seconds(40));
    cout << x << endl;
    while (1) {

    };
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
