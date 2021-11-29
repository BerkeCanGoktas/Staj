class Class1{
  int x = 0;

  void printx(){
    print(x);
  }
}

void main(List<String> arguments) {
  Class1 obj = new Class1();
  List<Class1> list1 = new List<Class1>.generate(1, (index) => obj);
  list1.first.printx();
  list1[0].printx();

}
