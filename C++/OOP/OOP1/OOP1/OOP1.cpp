// OOP1.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <string>

using namespace std;

class Car {
public:
    int speed;
    string color;
    string brand;
    Car(string x, string y, int z) { //Constructor function
        cout << "Hello car owner" << endl;
        speed = z;
        color = x;
        brand = y;
    }
    void message() {
        cout << "Have a good trip" << endl;
    }
    void fren(int speed);
};

void Car::fren(int speed) {
    cout << "You stopped at " << speed / 17 << " seconds because you were going with " << speed << " kms per hour" << endl;
}
int main()
{
    Car car1("Grey", "Volvo", 100);
    car1.brand = "Opel";
    cout << "Your Car is " << car1.color << " " << car1.brand << " and is going " << car1.speed << " kms per hour." << endl;
    Car car2("Black", "Mercedes", 85);
    cout << "Your Car is " << car2.color << " " << car2.brand << " and is going " << car2.speed << " kms per hour." << endl;
    car1.message();
    car2.fren(car2.speed);
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
