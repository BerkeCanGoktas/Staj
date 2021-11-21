#include "Islem.h"
#include "Deck.h"
#include "Kasa.h"

using namespace std;


void kartCek() {
    Kasa obj;
    Deck obj1;
    obj.kasaKarar();
    obj1.cardsOpen++;
    obj1.oyuncuDeste[(obj1.oyuncuCards + 1)] = obj1.deste[obj1.cardsOpen];
    obj1.oyuncuCards++;
    for (int i = 0; i <= obj1.oyuncuCards; i++) {
        string oyuncuKart = obj1.cardSetter(obj1.oyuncuDeste[i]);
        cout << oyuncuKart << " ";
    }
}
void beginning() {
    Deck obj;
    for (obj.cardsOpen; obj.cardsOpen < 2; obj.cardsOpen++) {
        obj.oyuncuDeste[obj.cardsOpen] = obj.deste[obj.cardsOpen];
        obj.kasa[(obj.cardsOpen)] = obj.deste[(obj.cardsOpen + 2)];
    }
    /*for (cardsOpen; cardsOpen < 4; cardsOpen++) {
        kasa[cardsOpen] = deste[cardsOpen];
    }*/
    obj.cardsOpen = 3; //+1 =4
    obj.oyuncuCards = 1; //+1 =2
    obj.kasaCards = 1; //+1 =2
    string oyuncuKart1 = obj.cardSetter(obj.oyuncuDeste[0]);
    string OyuncuKart2 = obj.cardSetter(obj.oyuncuDeste[1]);
    string kasaKart = obj.cardSetter(obj.kasa[1]);
    cout << "Kartlariniz: " << oyuncuKart1 << " " << OyuncuKart2 << endl;
    cout << "Kasanin ikinci karti: " << kasaKart << endl;
}
void oyunSonu(Deck obj) {
    Kasa obj1;
    cout << "Oyun sona erdi" << endl;
    int oyuncuEl = 0;
    int kartDeger = 0;
    for (int i = 0; i <= obj.oyuncuCards; i++) {
        switch (obj.oyuncuDeste[i] % 13) {
        case 1:
            cout << "Asinizin degerini ne yapmak istiyorsunuz?" << endl;
            cin >> kartDeger;
            //cout << kartDeger << " ";
            break;
        case 11:
            kartDeger = 10;
            //cout << kartDeger << " ";
            break;
        case 12:
            kartDeger = 10;
            //cout << kartDeger << " ";
            break;
        case 0:
            kartDeger = 10;
            //cout << kartDeger << " ";
            break;
        default:
            kartDeger = obj.oyuncuDeste[i] % 13;
            //cout << kartDeger << " ";
        }
        oyuncuEl += kartDeger;
    }
    obj1.kasaHesap();
    cout << "Kasanin Kartlari: " << endl;
    obj1.kasaKartlar();
    cout << "Elinizin degeri: " << oyuncuEl << endl;
}