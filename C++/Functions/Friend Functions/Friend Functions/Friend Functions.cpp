// Friend Functions.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <string>

using namespace std;

class Box {
private:
    int length;
public:
    void setLength(int len) {
        length = len;
    }
    friend class ClassTwo;
    friend void printLength(Box box);
};

class ClassTwo {
public:
    void greeting(Box box) {
        cout << "Hello your box has a length of " << box.length << " cm" << endl; //private verilere de ulaşabiliyor
    }
};

void printLength(Box box) {
    cout << "Uzunluk: " << box.length << " cm" << endl;
}

int main()
{
    Box kutu;
    ClassTwo obj;
    kutu.setLength(8);
    printLength(kutu); //private verilere de ulaşabiliyor
    obj.greeting(kutu);
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
