// TempFuncSpecialization.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Class1.h"
#include "Class2.h"

using namespace std;

template <class T>
void deneme(T x) {
    cout << x << endl;
}

template<>  void deneme<Class1>(Class1 obj) {
    obj.x++;
    cout << obj.x << endl;
}


template<>  void deneme<Class2>(Class2 obj) {
    obj.x++;
    cout << obj.x << endl;
}

int main()
{
    Class1 cls1;
    cls1.x = 6;
    Class2 cls2;
    cls2.x = 16.2;
    string str = "sfjhgksg";
    deneme(str);
    deneme(cls1);
    deneme(cls2);
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
