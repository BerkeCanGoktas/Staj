// TempObjFuncCall.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Class1.h"
#include "Class2.h"

using namespace std;

template<class T>
void funcCaller(T obj) {
	//cout << typeid(obj).name() << endl;
	int x;
	/*string comp = typeid(obj).name();
	if (comp == "class Class2<int>") {
		x = obj.getter2(); // 'getter2': is not a member of 'Class1<int>'
	}
	else if (comp == "class Class1<int>") {
		x = obj.getter(); // 'getter': is not a member of 'Class2<int>'
	}*/
	x = obj.getter2();
	cout << x << endl;
}

int main()
{
    Class1 <int> obj1(1);
	Class2 <int> obj2(16);
	funcCaller(obj2);
	//funcCaller(obj1);

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
