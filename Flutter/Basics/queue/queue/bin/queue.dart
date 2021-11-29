import "dart:collection";

void main(List<String> arguments) {
  Queue que = new Queue();
  que.add(10);
que.addAll([20,30,40]);
que.addFirst(50);
Iterator i = que.iterator;
while(i.moveNext()){
  print(i.current);
}
}
