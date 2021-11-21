#pragma once
#include "Decorator.h"

using namespace std;

class Hata4 : public Decorator
{
public:
    Hata4(Component* component) : Decorator(component) {
    }
    string hataMesaji() const override {
        return Decorator::hataMesaji() + "404 ";
    }
};


