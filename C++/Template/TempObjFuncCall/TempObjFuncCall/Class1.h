#pragma once
using namespace std;

template<class T>
class Class1
{
public:
	Class1(T a) {
		x = a;
	}
	T x;
	T getter() {
		return this->x;
	}
};

