class Parent { 
   void func(int a){ print("a: ${a}");} 
   static int x = 10;
}  

class Child extends Parent { 
   @override  //zorunlu değil best practise
   void func(int b) { 
      print("b: ${b}"); 
   } 
   
   void func2(int c){
     print("c: ${c}");
     print("++++++++++++");
     super.func(1);
   }
}

void main() { 
  Parent objParent = new Parent();
  objParent.func(10);
  Child objChild = new Child(); 
  objChild.func(12); 
  print("**************************");
  print(Parent.x);
  Parent.x = 9;
  print(Parent.x);
  print("**************************");
  objChild.func2(25);

} 
