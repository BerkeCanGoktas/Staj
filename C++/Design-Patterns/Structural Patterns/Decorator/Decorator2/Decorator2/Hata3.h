#pragma once
#include "Decorator.h"

using namespace std;

class Hata3 : public Decorator
{
public:
    Hata3(Component* component) : Decorator(component) {
    }
    string hataMesaji() const override {
        return Decorator::hataMesaji() + "403 ";
    }
};

