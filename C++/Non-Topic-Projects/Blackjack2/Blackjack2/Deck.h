#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Kasa.h"
#include "Islem.h"

using namespace std;

class Deck {
public:
    int deste[52];
    int oyuncuDeste[52];
    int kasa[52];
    int cardsOpen = 0;
    int oyuncuCards = 0;
    int kasaCards = 0;
    void shuffle();
    int* create_deck();
    string cardSetter(int x);
};