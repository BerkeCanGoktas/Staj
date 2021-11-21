// Abstract Class.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>

using namespace std;

class A {
public:
    int a, b;
    A(int a_, int b_) {
        /*a = a_;
        b = b_;*/
        cout << "Constructing..." << endl;
    }
    virtual void sum() = 0;
};

class B : public A {
public:
    int c;
    B(int i, int j) : A(a, b) {
        this->a = i;
        this -> b = j;
        //a = i;
        //b = j;
        c = a + b;
    }
    void sum() {
        cout << a << " " << b << endl;
        cout << "sum is: " << c << endl;
    }
};

int main()
{
    A *b = new B(1,2);
    //B obj(1, 2);
    b->sum(); //-1717986920 ???

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
