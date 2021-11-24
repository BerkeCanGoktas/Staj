void main(List<String> arguments) {
  funcWithDefaultValue(4);
  print("******************");
  //funcWithDefaultValue(4,10); hata
  funcWithOptionalParameter(5);
  print("******************");
  funcWithOptionalParameter(4, b :"abc");
  print("******************");
  funcWithOptionalParameter(6, b: "abc", c: "abcd");
  print("******************");
  funcWithOptionalPositionalParameter("aaa");
  print("******************");
  funcWithOptionalPositionalParameter("aaa", "bbb");
  print("******************");
  print(gonder());
  print("******************");
  printMsg("msg");
}

void funcWithDefaultValue(int x, {int y = 8}){
  print(x);
  print(y);
}

void funcWithOptionalParameter(int a, {b,c}){
  print(a);
  print(b);
  print(c);
}

void funcWithOptionalPositionalParameter(n,[m]){
  print(n);
  print(m);
}

int gonder()=> 123;

void printMsg(msg) => print(msg);

