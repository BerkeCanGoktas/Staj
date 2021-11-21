// MultiThreading.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <thread>

using namespace std;

class Sinif {
public:
    void func(int x) {
        //this_thread::yield();
        for (int i = 0; i < x; i++) {
            cout << "Fonksiyon Thread" << i << endl;
        }
    }
};

class ThreadClass {
public: 
    void operator()(int y) {
        this_thread::sleep_for(chrono::seconds(5));
        for (int i = 0; i < y; i++) {
            cout << "Class Thread" << i << endl;
        }
    }

};

int main()
{
    auto lambda = [](int z) {
        
        for (int i = 0; i < z; i++) {
            cout << "Lambda Thread" << i << endl;
        }
    };
    cout << "Threadler calisiyor" << endl;

    Sinif obj;

    thread th1(&Sinif::func, obj, 5);
    th1.join();
    thread th2(ThreadClass(), 3);
    th2.detach();
    cout << "***********";
    thread th3(lambda, 4);
    //join priority 
    cout << "**********";
    th3.detach();
    cout << "son" << endl;
    
    //this_thread::yield;
    this_thread::sleep_for(chrono::seconds(100));

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
