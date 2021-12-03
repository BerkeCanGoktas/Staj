class Car{
  String engine = "E1001";
  String name = " ";
  Car(){
    print("araba olusturuldu");
  }
  Car.constructorwparam(engine){
    this.engine = engine;
  }

  set carname(name){
    if(name!= ""){
      this.name = name;
      print("isim degistirildi yeni isim: ${name}");
    }
    else {print("hata lutfen isim giriniz!");}
  }

  String get carname{
    return this.name;
  }


  void displayEngine(){
    print(engine);
  }

}

void main(List<String> arguments) {
  Car car = new Car();
  Car car2 = new Car.constructorwparam("E1002");

  car.displayEngine();
  car2.displayEngine();
  print(car.engine);

  print("***********************************");

  car.carname = "Volvo";
  car2.carname = "Mercedes";
  String x = car.carname;
  print(x);
  print(car2.carname);
}
