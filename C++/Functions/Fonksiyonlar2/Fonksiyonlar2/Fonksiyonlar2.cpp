// Fonksiyonlar2.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>

using namespace std;

int sum_(int x, int y) {
    return x + y;
    cout << "a"; //returnden sonrası çalışmaz
};

int mul(int x, int y) {
    return x * y;
};

double division(int x, int y) {
    return x / y; //int döndürüyor (sadece bölüm)
};

int substraction(int x, int y) {
    return x - y;
}

int main()
{
    int x, y;
    cout << "Sayi Giriniz:";
    cin >> x;
    cout << "Sayi Giriniz:";
    cin >> y;

    int sum = sum_(x, y);
    cout << "Toplam: " << sum << endl;
    cout << "Carpim: " << mul(x,y) << endl;
    cout << "Bolum: " << division(x,y) << endl;
    int fark = substraction(x, y);
    cout << "Fark: " << fark << endl;

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
