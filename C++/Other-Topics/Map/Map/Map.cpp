// Map.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <iterator>
#include <map>

using namespace std;

map <int, int> map1;
//map <int, int> map2; 


int main()
{
    map1.insert(pair<int, int>(1, 25));
    map1.insert(pair<int, int>(2, 45));
    map1.insert(pair<int, int>(3, 25)); //aynı valuelar olabilir
    map1.insert(pair<int, char>(4, 'a')); //97 (char number)
    map1.insert(pair<int, int>(1, 20)); //değiştirmiyor hata da vermiyor
    map1.insert(pair<int, float>(5, 7.2)); //7 
    map<int, int>::iterator itr;
    cout << "\tKEY\tELEMENT\n" << endl;
    for (itr = map1.begin(); itr != map1.end(); itr++) {
        cout << '\t' << itr->first << '\t' << itr->second << '\n';
    }
    cout << endl;
    //map <int, int> map2;
    map <int, int> map2(map1.begin(), map1.end()); //() işlemi tanımlamada yapılmak zorunda
    for (itr = map2.begin(); itr != map2.end(); itr++) {
        cout << '\t' << itr->first << '\t' << itr->second << '\n';
    }
    cout << endl;

    map2.erase(map2.begin(), map2.find(3)); //3ü silmedi
    for (itr = map2.begin(); itr != map2.end(); itr++) {
        cout << '\t' << itr->first << '\t' << itr->second << '\n';
    }
    cout << endl;

    int x = map2.erase(5); // başarılı: 1
    cout << "silinme: " << x << endl;
    for (itr = map2.begin(); itr != map2.end(); itr++) {
        cout << '\t' << itr->first << '\t' << itr->second << '\n';
    }
    cout << endl;
    
    cout << "lower bound: " << map1.lower_bound(3) ->first << " " <<  map1.lower_bound(3)->second << endl;
    cout << "upper bound: " << map1.upper_bound(3) -> first << " " << map1.upper_bound(3)->second << endl;

    cout << map1.count(5) << endl;
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
