// Lambda.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>

using namespace std;

class IsBetweenZeroAndTen {
public:
    bool operator()(int value) {
        return (0 < value) && (value < 10);
    }
};

int main()
{
    /*auto upperBound = 42;
    auto f1 = [upperBound](int value) {
        return 0 < value && value < upperBound; 
    };
    bool isTrue = f1(40);*/
    /*auto f1 = [&upperBound](int value) {
        return 0 < value && value < upperBound; 
    };*/
    /*int m_upperBound = 42;
    auto upperBound = m_upperBound;
    auto f1 = [=](int value) {
        return 0 < value && value < upperBound; 
    };*/
    int m_upperBound = 42;
    auto f1 = [&](int value) {
        return 0 < value && value < m_upperBound; }; //yalnızca statik olmayan bir üye işlevi içerisinde 'this' kullanılabilir??

   
    bool isTrue = f1(40);
    cout << isTrue;
    IsBetweenZeroAndTen obj;
    bool istrue = obj(15);
    cout << istrue << endl;
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
