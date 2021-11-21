// Map2.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main()
{
    map <int, char> map1;
    map1[1] = 'a';
    map1[2] = 'b';
    map1[3] = 'c';
    map1[4] = 'd';
    //map1[3] = 'x'; 3 = x

    for (int i = 1; i <= map1.size(); i++) {
        cout << i<< "- " <<  map1.at(i) << endl;
    }

    map <int, char> map2;
    map2[4] = 'k';
    map2[5] = 'l';
    map2[6] = 'm';
    map1.swap(map2);

    cout << endl; 
    for (int i = 4; i <= 3+map1.size(); i++) {
        cout << i << "- " << map1.at(i) << endl;
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
