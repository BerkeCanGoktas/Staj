// TempSpecialization.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
using namespace std;

template <class T>
class ArtiBir {
    T eleman;
public:
    ArtiBir(T x) { 
        eleman = x;
    }
    T increase() { 
        return ++eleman; 
    }
};

template <>
class ArtiBir <char> {
    char eleman;
public:
    ArtiBir(char x) { 
        eleman = x; 
    }
    char uppercase()
    {
        if ((eleman >= 'a') && (eleman <= 'z'))
            eleman += 'A' - 'a';
        return eleman;
    }
};

int main() {
    ArtiBir<int> myint(7);
    ArtiBir<char> mychar('j');
    ArtiBir<float> myfloat(4.9);
    cout << myint.increase() << endl;
    cout << myfloat.increase() << endl;
    cout << mychar.uppercase() << endl;
    return 0;
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
