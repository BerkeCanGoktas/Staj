// TimedCallback2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <future>
#include <ctime>

using namespace std;



void sampleFunc() {
    cout << "Fonksiyon cagrildi" << endl;
}

void sum(int x, int y) {
    int sum_ = x + y;
    cout << sum_ << endl;
}


void timedFunc(int time, void (*ptr)(int x, int y), int x, int y) {
    this_thread::sleep_for(chrono::seconds(time));
    cout << time << " sn beklendi" << endl;
    (*ptr)(x,y);
}

int main()
{
    //future<void> obj = async(timedFunc, 5, sampleFunc);
    cout << "**********" << endl;
    //obj.get();
    //cout << "**********" << endl;
    future<void> obj2 = async(timedFunc, 3, sum, 2,7);
    obj2.get();
    cout << "**********" << endl;
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
