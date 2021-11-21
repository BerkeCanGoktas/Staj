// TempFuncObj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Class1.h"
#include "Class2.h"
#include "Temp.h"

using namespace std;

int main()
{
	Class1 obj1;
	obj1.x = 7;
	obj1.y = 12;
	Class2 obj2;
	obj2.x = 4.6;
	obj2.y = 16.3;
	Temp<int, Class1> temp;
	temp.setter(obj1);
	temp.sum(temp.a, temp.b);
	//temp.caller(obj1,sum);
	Temp<float, Class2> temp2;
	temp2.setter(obj2);
	temp2.sum(temp2.a, temp2.b);
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
