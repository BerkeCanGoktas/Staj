#pragma once
#include "Decorator.h"

using namespace std;

class Hata2 : public Decorator
{
public:
    Hata2(Component* component) : Decorator(component) {
    }
    string hataMesaji() const override {
        return Decorator::hataMesaji() + "402 ";
    }
};



