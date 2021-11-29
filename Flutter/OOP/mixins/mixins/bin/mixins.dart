abstract class Shape{
  void area();
}

class Square extends Shape with Color, Perimeter{
  int? a;
  int? b;

  @override
  void area(){
    print(a!*b!);
  }

  @override 
  void perimeter(){
    print(2*(a!+b!));
  }

  void coloring(){
      print(color);
    }
}

class Cloth with Color /*, Perimeter hata çünkü Perimeter Shape subclasslarına eklenebiliyor*/{
    void coloring(){
      print(color);
    }
}


mixin Color{
  String? color;
}

mixin Perimeter on Shape{
  void perimeter();
}

void main(List<String> arguments) {
  var kare = new Square();
  kare.a =5;
  kare.b=10;
  kare.color = "mavi";
  kare.area();
  kare.coloring();
  kare.perimeter();

  print("********************");

  var pantolon = new Cloth();
  pantolon.color = "siyah";
  pantolon.coloring();
}
