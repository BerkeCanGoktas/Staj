// PassByReference.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>

using namespace std;

void numSwap(int x, int y) {
    int z = x;
    x = y;
    y = z;
}

void numSwapWithRef(int &x, int &y) {
    int z = x;
    x = y;
    y = z;
}

int main()
{
    int a, b;
    cout << "Iki Sayi Giriniz: \n";
    cin >> a;
    cin >> b;
    cout << "Once: " << a << " " << b << endl;
    numSwap(a, b); // degisim fonksiyon disina cikmiyor
    cout << "Sonra: " << a << " " << b << endl;
    numSwapWithRef(a, b); // degisim fonksiyon disina cikiyor (a ve b)
    cout << "Sonra (REF): " << a << " " << b << endl;

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
