#pragma once
#include <iostream>

using namespace std;

template<class T, class K>
class Temp
{
public:
	T a;
	T b;
	void sum(T a, T b) {
		T sum = a + b;
		cout << sum << endl;
	}
	void caller(K obj, void (*ptr)(T x, T y)){
		cout << "obj func called" << endl;
		(*ptr)(obj.x, obj.y);
	}
	void setter(K obj) {
		this->a = obj.x;
		this->b = obj.y;

	}

};

