// Non-TypeParameterTemplate.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>

using namespace std;

template <class T, int N>
class Dizi {
    T dizi[N];
public:
    void atama(int x, T value);
    T alma(int x);
};

template <class T, int N>
void Dizi<T, N>::atama(int x, T value) {
    dizi[x] = value;
};

template <class T, int N>
T Dizi<T, N>::alma(int x) {
    return dizi[x];
}

int main()
{
    Dizi<int,2> objint;
    objint.atama(0, 15);
    objint.atama(1, 20);
    //objint.atama(8, 1);
    int x = objint.alma(1);
    cout << x << endl;
    int y = objint.alma(0);
    cout << y << endl;
    Dizi<char, 8> objchar;
    objchar.atama(4, 'a');
    char k = objchar.alma(4);
    cout << k << endl;

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
