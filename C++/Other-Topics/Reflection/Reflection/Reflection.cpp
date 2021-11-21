// Reflection.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <typeinfo>

using namespace std;

class Vehicle {
public:
    Vehicle() {
        hiz = 0;
    }
    virtual void hizlan() {
        cout << "hizlaniyor" << endl;
    }
private:
    int hiz;
};

class Fruit {
public:
    Fruit() {
        tatli = 1;
    }
    virtual void yemek() {
        cout << "meyve yendi" << endl;
    }
private:
    int tatli;
};

class Car : public Vehicle {
public:
    void hizlan() {
        cout << "araba hizlaniyor"<< endl;
    }
};

class Motor : public Vehicle {
public:
    void hizlan() {
        cout << "motor hzilaniyor" << endl;
    }
};

template<class T>
void displayType(T* vehicle) {
    const type_info& tp = typeid(*vehicle);
    cout << "type = " << tp.name() << endl;
}

int main()
{
    /*Vehicle arac;
    displayType(&arac); class Vehicle
    Car araba;
    displayType(&araba);          class Car*/ 
    /*Fruit meyve;
    Vehicle* arac = new Vehicle();
    displayType(arac); // class Vehicle
    int i = 3;
    arac = new Car();
    displayType(arac); // class Car
    //displayType(&arac);  class Vehicle *
    displayType(&meyve);     class Fruit
    displayType(&i);    int*/
    Vehicle* vehicle = 0;
    vehicle = new Car;
    vehicle = new Motor;
    if (typeid(*vehicle) == typeid(Car)){
       ((Car*)vehicle)-> hizlan();
    }
    else {
        cerr << "yanlis tur" << endl;
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
