#pragma once
#include "Kasa.h"
#include "Deck.h"

using namespace std;


class �slem : public Kasa
{
public: 
	void oyunSonu(Deck obj);
	void kartCek();
	void beginning();
};

