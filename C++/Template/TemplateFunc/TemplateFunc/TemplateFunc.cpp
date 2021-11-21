// TemplateFunc.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>

using namespace std;

template <class T>
T sum(T a, T b) {
    return a + b;
}

template <class T, class U>
U sumDiff(T a, U b) {
    return a + b;
}

int main()
{
    int k =  12;
    int l = 17;
    int toplam = sum(k,l);     
    //int toplam = sum <int> (k,l);   //29
    cout << toplam << endl;
    float x = 14.2;
    float y = 16.7;
    float toplam2 = sumDiff(k, y);     
    //float toplam2 = sum <float> (x, y);  //30.9
    cout << toplam2 << endl;
    //float toplamDiff = sumDiff(k, x);    26.2
    //float toplamDiff = sumDiff <int, float> (k, x); //26.2
    //float toplamDiff = sumDiff<int>(k, x);  26.2
    float toplamDiff = sumDiff<float>(k, x); //26.2
    //float toplamDiff = sumDiff <int, int>(k, x); ikinci değişken tipi float olduğu için hata
    cout << toplamDiff << endl;   
    
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
