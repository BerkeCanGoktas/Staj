// ThreadAsync.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <future>

using namespace std;

string returnString1(string x) {
    this_thread::sleep_for(chrono::seconds(3));
    string y = "String1: " + x;
    return y;
}

string returnString2(string a) {
    this_thread::sleep_for(chrono::seconds(3));
    string b = "String2: " + a;
    return b;
}

string returnString3(string k) {
    this_thread::sleep_for(chrono::seconds(3));
    string m = "String3: " + k;
    return m;
}


void vreturnString1(string x) {
this_thread::sleep_for(chrono::seconds(3));
string y = "String2: " + x;
}

void vreturnString2(string a) {
    this_thread::sleep_for(chrono::seconds(3));
    string b = "String2: " + a;
}

int main()
{
    chrono::system_clock::time_point start = chrono::system_clock::now();
    future<string> string1Obj = async(launch::async, returnString1, "Ali");
    future<string> string2Obj = async(launch::async, returnString2, "Veli");
    future<string> string3Obj = async(launch::async, returnString3, "Mehmet");
    string string1 = string1Obj.get(); 
    string string2 = string2Obj.get();
    string string3 = string3Obj.get(); //tüm işlemler paralel yürütüldüğü için 3 sn sürer (9 yerine)
    auto end = chrono::system_clock::now();
    auto diff = chrono::duration_cast <chrono::seconds> (end - start).count();
    cout << "Gecen sure: " << diff << endl;
    cout << string1 << " " << string2 << " " << string3 <<  endl;
}

/*int main()
{
    chrono::system_clock::time_point start = chrono::system_clock::now();
    future<string> string1Obj = async(launch::async, returnString1, "Ali");
    //string string1 = string1Obj.get();  Önce objenin get etme işlemi tamamlanır yani main thread objenin değeri gelene kadar devam eder ve 6 sn sürer
    string string2 = returnString2("Veli");
    string string1 = string1Obj.get(); // objeden değer get edilme aşamasından önce main içinde de fonksiyon çalışır ve bekleme olmadığı için işlem 3 sn sürer
    auto end = chrono::system_clock::now();
    auto diff = chrono::duration_cast <chrono::seconds> (end - start).count();
    cout << "Gecen sure: " << diff << endl;
    cout << string1 << " " << string2 << endl;
}*/

/*int main()
{
    chrono::system_clock::time_point start = chrono::system_clock::now();
    future<string> string1Obj = async(launch::async, returnString1, "Ali");
    future<string> string2Obj = async(launch::async, returnString2, "Veli"); //ikisi de paralel olduğu için 3 sn sürer
    string string1 = string1Obj.get();
    //future<string> string2Obj = async(launch::async, returnString2, "Veli"); //önce string1'in get etmesini beklediği için 6 sn sürer
    string string2 = string2Obj.get();
    auto end = chrono::system_clock::now();
    auto diff = chrono::duration_cast <chrono::seconds> (end - start).count();
    cout << "Gecen sure: " << diff << endl;
    cout << string1 << " " << string2 << endl;
}*/

/*int main()
{
    chrono::system_clock::time_point start = chrono::system_clock::now();
    future<void> string1Obj = async(launch::async, vreturnString1, "Ali"); //herhangi bir değer dönmediği için 3 sn sürer
    string string2 = returnString2("Veli");
    future<void> string2Obj = async(launch::async, vreturnString2, "Ali"); //herhangi bir değer dönmediği için 3 sn sürer
    auto end = chrono::system_clock::now();
    auto diff = chrono::duration_cast <chrono::seconds> (end - start).count();
    cout << "Gecen sure: " << diff << endl;
    cout << string2 << endl;
}*/


// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
