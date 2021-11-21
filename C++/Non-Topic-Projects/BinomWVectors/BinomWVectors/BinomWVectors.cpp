// BinomWVectors.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int satir;
    cout << "Kac satir gosterilsin:" << endl;
    cin >> satir;
    cout << "****************" << endl << endl;
    vector<int> vect1;
    vector<int> vect2;
    vect1.assign(1, 1);
    vect2.assign(2, 1);
    cout << vect1[0] << endl;
    cout << vect2[0] << " " << vect2[1] << endl;
    int j = 3;
    while (j <= satir) {
    vect1.swap(vect2);
    vect2.clear();
    //cout << vect1[0] << vect1[1] << endl;
    for (int i = 0; i <= vect1.size(); i++) {
        auto itPos = vect2.begin() + i;
        if (i == 0 || i == vect1.size()) {
            vect2.insert(itPos, 1, 1);
        }
        else {
            int x = vect1[i] + vect1[i - 1];
            vect2.insert(itPos, x);
        }
    }
    for (int i = 0; i <= vect2.size() - 1; i++) {
        cout << vect2[i] << " ";
    }
    cout << endl;
    j++;
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
