#pragma once
#include "Decorator.h"

using namespace std;

class Hata1 : public Decorator
{
public:
    Hata1(Component* component) : Decorator(component) {
    }
    string hataMesaji() const override {
        return Decorator::hataMesaji() + "401 ";
    }
};

