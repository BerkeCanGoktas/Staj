#pragma once

using namespace std;

template <class T, class U>
class TempClass
{
	T a;
	U b;
public:
	TempClass(T first, U second) {
		a = first;
		b = second;
	};
	U sum() {
		U retVal;
		retVal = a + b;
		return retVal;
	};
};

