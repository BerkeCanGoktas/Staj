#pragma once
#include "Component.h"

using namespace std;

class Decorator : public Component {
protected:
    Component* component_;

public:
    Decorator(Component* component) : component_(component) {
    }
    string hataMesaji() const override {
        return this->component_->hataMesaji();
    }
};
