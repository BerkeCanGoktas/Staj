#pragma once
using namespace std;

template<class T>
class Class2
{
public:
	Class2(T b) {
		y = b;
	}
	T y;
	T getter2() {
		return this->y;
	}
};

