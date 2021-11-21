// List.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main()
{
    list <int> list1, list2;
    for (int i = 1; i <= 10; i++) {
        list1.push_front(i);
        list2.push_back(i * i);
    }
    list <int> ::iterator itr;
    //list1.assign(3, 500);

    for (itr = list1.begin(); itr != list1.end(); itr++) {
        cout << *itr << endl;  //10-9-8-...-1
    }
    cout << endl;
    list <int> ::iterator itr2;
    list2.pop_back();
    list2.pop_front();
    for (itr2 = list2.begin(); itr2 != list2.end(); itr2++) {
        cout << *itr2 << endl; //4-9-...-81
    }
    cout << endl;
    list1.sort();
    list2.sort();
    list1.merge(list2); //sort etmeden listelemiyor
    for (itr = list1.begin(); itr != list1.end(); itr++) {
        cout << *itr << endl;  
    }
    cout << endl;
    
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
