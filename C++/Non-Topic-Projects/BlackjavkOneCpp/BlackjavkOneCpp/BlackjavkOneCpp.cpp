// Blackjack2.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

static int kasaEl;
static int oyuncuEl;

class Deck {
public:
	int deste[52];
	int oyuncuDeste[52];
	int kasa[52];
	int cardsOpen = 0;
	int oyuncuCards = 0;
	int kasaCards = 0;
    void shuffle() {
        srand((unsigned)time(NULL));
        for (int i = 0; i < 52; i++) {
            int j = rand() % 52;
            swap(deste[i], deste[j]);
        }
        /*for (int i = 0; i < 52; i++) {
            cout << deste[i] << " ";
        }
        cout << endl;*/
    }
    int* create_deck() {
        for (int i = 0; i < 52; i++) {
            deste[i] = i + 1;
        };
        shuffle();
        return deste;
    };
    string cardSetter(int x) {
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
    }
        void kasaKarar() {
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
        void kasaKartlar() {
            for (int i = 0; i <= kasaCards; i++) {
                string kasaKart = cardSetter(kasa[i]);
                cout << kasaKart << " " << endl;
            }
        }
        void kasaKartCek() {
            cardsOpen++;
            kasa[(kasaCards + 1)] = deste[cardsOpen];
            kasaCards++;
        }

        void kasaHesap(int &kasaEl_) {
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
            kasaEl_ = kasaEl;
        }
        void kartCek() {
            kasaKarar();
            cardsOpen++;
            oyuncuDeste[(oyuncuCards + 1)] = deste[cardsOpen];
            oyuncuCards++;
            for (int i = 0; i <= oyuncuCards; i++) {
                string oyuncuKart = cardSetter(oyuncuDeste[i]);
                cout << oyuncuKart << " ";
            }
        }
        void beginning() {
            for (cardsOpen; cardsOpen < 2; cardsOpen++) {
                oyuncuDeste[cardsOpen] = deste[cardsOpen];
                kasa[(cardsOpen)] = deste[(cardsOpen + 2)];
            }
            /*for (cardsOpen; cardsOpen < 4; cardsOpen++) {
                kasa[cardsOpen] = deste[cardsOpen];
            }*/
            cardsOpen = 3; //+1 =4
            oyuncuCards = 1; //+1 =2
            kasaCards = 1; //+1 =2
            string oyuncuKart1 = cardSetter(oyuncuDeste[0]);
            string OyuncuKart2 = cardSetter(oyuncuDeste[1]);
            string kasaKart = cardSetter(kasa[1]);
            cout << "Kartlariniz: " << oyuncuKart1 << " " << OyuncuKart2 << endl;
            cout << "Kasanin ikinci karti: " << kasaKart << endl;
        }
        void oyunSonu(Deck obj,int &oyuncuEl_) {
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
            kasaHesap(kasaEl);
            cout << "Kasanin Kartlari: " << endl;
            kasaKartlar();
            cout << "Elinizin degeri: " << oyuncuEl << endl;
            oyuncuEl_ = oyuncuEl;
        }
        void sonuc() {
            if (oyuncuEl == 21 && kasaEl != 21) {
                cout << "Tebrikler kazandiniz" << endl;
            }
            else if (oyuncuEl != 21 && kasaEl == 21) {
                cout << "Kaybettiniz" << endl;
            }
            else if(oyuncuEl <21 && kasaEl <21){
                if (oyuncuEl < kasaEl) {
                    cout << "Kaybettiniz" << endl;
                }
                else if (oyuncuEl > kasaEl) {
                    cout << "Tebrikler kazandiniz" << endl;
                }
                else {
                    cout << "Berabere" << endl;
                }
            }
            else if (oyuncuEl > 21 && kasaEl < 21) {
                cout << "Kaybettiniz" << endl;
            }
            else if (oyuncuEl < 21 && kasaEl > 21) {
                cout << "Tebrikler kazandiniz" << endl;
            }
            else {
                cout << "Kazanan yok" << endl;
            }
        }
        void kasaSon(int &kasaEl_) {
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
            kasaEl_ = kasaEl;
            //cout << "kasaEl_:" <<  kasaEl_ << endl;

        }
};

int main()
{
 	string devam = "E";
	Deck objDeste;
	objDeste.create_deck();
	objDeste.beginning();
	while (devam == "E") {
		cout << "Kart Cekmek Istiyor Musunuz?: E/H ";
		cin >> devam;
		if (devam == "E" || devam == "e") {
			objDeste.kartCek();
		}
		else if(devam == "H" || devam == "h"){
            while (kasaEl <= 16) {
                objDeste.kasaSon(kasaEl);
                if (kasaEl > 16) {
                    //cout << kasaEl << endl;
                    break;
                }
                else {
                    //cout << kasaEl << endl;
                    cout << "Kasa kart cekiyor" << endl;
                    objDeste.kasaKartCek();
                   
                }
                
            }
			objDeste.oyunSonu(objDeste, oyuncuEl);
		}
        else {
            cout << "Hatali deger girildi" << endl;
            devam = "E";
        }
        if (devam != "E" && devam != "e") {
            objDeste.sonuc();
            break;
        }
	}
}

// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
