// ThreadValueReturn.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <thread>
#include <future>

using namespace std;


void sum(promise<int>* promObj, int a, int b) {
    int sum = a + b;
    promObj->set_value(sum);
    //this_thread::sleep_for(chrono::seconds(5));
    //cout << "thread1" << endl;
    
}


int main()
{ 
    promise<int> promiseObj;
    future<int> futureObj = promiseObj.get_future();
    thread td1(sum, &promiseObj, 20, 37);
    td1.join();
    cout << "sonuc: " << futureObj.get() << endl;
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
