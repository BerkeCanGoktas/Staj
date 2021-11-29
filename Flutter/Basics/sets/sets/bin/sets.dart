void main() { 
   Set numberSet = new  Set(); 
   Set numberSet2 = new Set.from([10,20,20,15]);
   numberSet2.add(50);
   numberSet.add(100); 
   numberSet.add(20); 
   numberSet.add(5); 
   numberSet.add(60); 
   numberSet.add(70);
   print("Default implementation :${numberSet.runtimeType}");  
   
   // all elements are retrieved in the order in which they are inserted 
   for(var no in numberSet) { 
      print(no); 
   } 
   print("*****************");
   for(var a in numberSet2){
     print(a);
   }
}    
