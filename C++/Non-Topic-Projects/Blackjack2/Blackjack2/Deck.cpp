#include "Deck.h"
#include "Kasa.h"
#include "Islem.h"

using namespace std;

    void Deck::shuffle() {
        srand((unsigned)time(NULL));
        for (int i = 0; i < 52; i++) {
            int j = rand() % 52;
            swap(deste[i], deste[j]);
        }
        for (int i = 0; i < 52; i++) {
            cout << deste[i] << " ";
        }
        cout << endl;
    }
    int* Deck::create_deck() {
        for (int i = 0; i < 52; i++) {
            deste[i] = i + 1;
        };
        shuffle();
        return deste;
    };
    string Deck::cardSetter(int x) {
        if (x <= 13) {
            switch (x) {
            case 1:
                return "Maca A";
            case 11:
                return "Maca J";
            case 12:
                return "Maca Q";
            case 13:
                return "Maca K";
            default:
                return "Maca " + to_string(x % 13);
            }

        }
        else if ((13 < x) && (x <= 26)) {
            switch (x) {
            case 14:
                return "Kupa A";
            case 24:
                return "Kupa J";
            case 25:
                return "Kupa Q";
            case 26:
                return "Kupa K";
            default:
                return "Kupa " + to_string(x % 13);
            }

        }
        else if ((26 < x) && (x <= 39)) {
            switch (x) {
            case 27:
                return "Karo A";
            case 37:
                return "Karo J";
            case 38:
                return "Karo Q";
            case 39:
                return "Karo K";
            default:
                return "Karo " + to_string(x % 13);
            }

        }
        else {
            switch (x) {
            case 40:
                return"Sinek A";
            case 50:
                return "Sinek J";
            case 51:
                return "Sinek Q";
            case 52:
                return "Sinek K";
            default:
                return "Sinek " + to_string(x % 13);
            }

        }
};
