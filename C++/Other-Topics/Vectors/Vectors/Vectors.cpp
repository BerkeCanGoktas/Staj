// Vectors.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

class Vehicle {
public: 
	const char* name;
	string brand;
	int speed;
	string color;
	string objectName;
};

class Car : public Vehicle {
public:
	//int speed;
	//string objectName;
	//const char* name;
	//string color;
	Car(int speed_, string color_, string brand_, string name_) {
		speed = speed_;
		color = color_;
		brand = brand_;
		objectName = name_;
	}
};

class Motor : public Vehicle {
public:
	//int speed;
	//string objectName;
	//const char* name;
	//string color;
	Motor(int speed_, string color_, string brand_, string name_) {
		speed = speed_;
		color = color_;
		brand = brand_;
		objectName = name_;
	}
};

int main()
{
	Motor motor1(145, "black", "Suzuki", "Motor");
	Car car1(100,"red","Fiat","Car");
	Car car2(60,"blue", "Renault", "Car");
	vector <class Car> cars;
	vector <class Vehicle> vehicles;
	vehicles.push_back(motor1);
	vehicles.push_back(car1);
	vehicles.push_back(car2);
	cars.push_back(car1);
	cars.push_back(car2);
	for (int i = 0; i < cars.size(); i++) {
		//cout << "Your " << cars[i].name << " is a " << cars[i].color << " " << cars[i].brand << " and is going " << cars[i].speed << " kms per hour" << endl;
	}
	for (int i = 0; i < vehicles.size(); i++) {
		cout << "Your " << vehicles[i].objectName << "  is a " << vehicles[i].color << " " << vehicles[i].brand << " and is going " << vehicles[i].speed << " kms per hour" << endl;
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
