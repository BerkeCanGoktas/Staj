import 'dart:core';

void main(List<String> arguments) {
  List logTypes = List.generate(0, (index) => "Warning"); 
  logTypes.add("WARNING"); 
  logTypes.add("ERROR"); 
  logTypes.add("INFO");  
  
  // iterating across list 
  for(String type in logTypes){ 
    print(type); 
  } 
   
  // printing size of the list 
  print(logTypes.length); 
  logTypes.remove("WARNING"); 
   
  print("size after removing."); 
  print(logTypes.length); 
}
