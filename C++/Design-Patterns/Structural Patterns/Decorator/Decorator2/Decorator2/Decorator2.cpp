// Decorator2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Component.h"
#include "Decorator.h"
#include "Hata.h"
#include "Hata1.h"
#include "Hata2.h"
#include "Hata3.h"
#include "Hata4.h"

using namespace std;

int main()
{
    Component* simple = new Hata;
    cout << simple->hataMesaji() << endl;
    Component* hata1 = new Hata1(simple);
    cout << hata1->hataMesaji() << endl;
    Component* hata3 = new Hata3(simple);
    cout << hata3->hataMesaji() << endl;
    hata3 = new Hata3(hata1);
    cout << hata3->hataMesaji() << endl;
    Component* hata2 = new Hata2(hata3);
    cout << hata2->hataMesaji() << endl;
    Component* hata4 = new Hata4(hata2);
    cout << hata4->hataMesaji() << endl;

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
