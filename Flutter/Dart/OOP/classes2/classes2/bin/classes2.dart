class Shape{
  double area = 0;

  void displayArea(){
    print("alan: ${area}");
  }
}

class Circle extends Shape{
  final pi = 3.14;
  double r = 0;

  Circle.noparams(){print("cember olusturuldu");}
  Circle(r){
    if(r>0){
      print("cember olusturuldu");
      this.r = r;
    }
    else {print("yaricap pozitif bir sayi olmalidir");}
  }  

  set areasetter(r){
      area = pi*r*r;
  }

  double get areagetter{
    return area;
  }
}

class MultiLevelInheritenceCircle extends Circle{
  MultiLevelInheritenceCircle() : super(0){}
}



void main(List<String> arguments) {
  Circle obj = new Circle(5.7);
  obj.areasetter = obj.r;
  //print(obj.areagetter);
  obj.displayArea();
  //var obj2 = new MultiLevelInheritenceCircle();
  //obj2.displayArea();
} 

