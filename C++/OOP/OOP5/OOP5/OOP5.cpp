// OBB5.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>

using namespace std;

//Inherited Class'tan oluşturulmuş objeler aynı isimli fonksiyonlarda child class'ı çağırıyor. (Polymorphism)

class Animal {
public:
    void voice() {
        cout << "Voice" << endl;
    }
};

class Dog : Animal {
public:
    void voice() {
        cout << "Hav Hav" << endl;
    }
};

class Bird : Animal {
public:
    void voice() {
        cout << "Cik Cik" << endl;
    }
};

class Kedi : Animal {
public:
    void voice() {
        cout << "Miyav" << endl;
    }
};

int main()
{
    Bird boncuk;
    boncuk.voice();
    Kedi azman;
    azman.voice();
    Dog karabas;
    karabas.voice();
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
