#include "Kasa.h"
#include "Deck.h"
#include "Islem.h"

using namespace std;


    void Kasa::kasaKarar() {
        int kasaEl = 0;
        int kasaDeger = 0;
        int kasaDurum = 1;
        for (int i = 0; i <= kasaCards; i++) {
            switch (kasa[i] % 13) {
            case 11:
                kasaDeger = 10;
                break;
            case 12:
                kasaDeger = 10;
                break;
            case 0:
                kasaDeger = 10;
                break;
            default:
                kasaDeger = kasa[i] % 13;
            }
            kasaEl += kasaDeger;
        }
        while (kasaDurum) {
            if (kasaEl <= 16) {
                cout << "Kasa kart cekiyor" << endl;
                kasaKartCek();
                kasaDurum = 0;
            }
            else {
                cout << "Kasa Oyundan Cekildi" << endl;
                kasaDurum = 0;
            }
        }
    }
    void Kasa::kasaKartlar() {
        for (int i = 0; i <= kasaCards; i++) {
            string kasaKart = cardSetter(kasa[i]);
            cout << kasaKart << " " << endl;
        }
    }
    void Kasa::kasaKartCek() {
        cardsOpen++;
        kasa[(kasaCards + 1)] = deste[cardsOpen];
        kasaCards++;
    }

    void Kasa::kasaHesap() {
        int kasaEl = 0;
        int kasaDeger = 0;
        for (int i = 0; i <= kasaCards; i++) {
            switch (kasa[i] % 13) {
            case 11:
                kasaDeger = 10;
                break;
            case 12:
                kasaDeger = 10;
                break;
            case 0:
                kasaDeger = 10;
                break;
            default:
                kasaDeger = kasa[i] % 13;
            }
            kasaEl += kasaDeger;
        }
        cout << "Kasanin Elinin toplami: " << kasaEl << endl;
    }