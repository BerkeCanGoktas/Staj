#pragma once
#include "Component.h"
#include <iostream>

using namespace std;

class Hata : public Component
{
	string hataMesaji() const override;
};

