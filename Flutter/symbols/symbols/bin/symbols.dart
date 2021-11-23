import 'dart:core'; 
import 'dart:mirrors'; 
import 'foo.dart';  

main() { 
   Symbol lib = new Symbol("foo_lib");   
   //library name stored as Symbol 
   
   Symbol clsToSearch = new Symbol("Foo");  
   // class name stored as Symbol   
  String name_of_lib = MirrorSystem.getName(lib); 
   
   print(lib); 
   print(name_of_lib); 

   if(checkIf_classAvailableInlibrary(lib, clsToSearch))  
   // searches Foo class in foo_lib library 
      print("class found.."); 

    reflect_InstanceMethods(lib, clsToSearch); 
}  
   
bool checkIf_classAvailableInlibrary(Symbol libraryName, Symbol className) { 
   MirrorSystem mirrorSystem = currentMirrorSystem(); 
   LibraryMirror libMirror = mirrorSystem.findLibrary(libraryName); 
   try{
     if (libMirror != null) { 
      print("Found Library"); 
      print("checkng...class details.."); 
      print("No of classes found is : ${libMirror.declarations.length}"); 
      libMirror.declarations.forEach((s, d) => print(s));  
         
      if (libMirror.declarations.containsKey(className)) return true; 
      return false; 
   }
   else{
     String err = "hata";
     throw err;
   }
   }
   catch(err) {
      print(err);
      return false;
   }   
}

void reflect_InstanceMethods(Symbol libraryName, Symbol className) { 
   MirrorSystem mirrorSystem = currentMirrorSystem(); 
   LibraryMirror libMirror = mirrorSystem.findLibrary(libraryName); 
   
   if (libMirror != null) { 
      print("Found Library"); 
      print("checkng...class details.."); 
      print("No of classes found is : ${libMirror.declarations.length}"); 
      libMirror.declarations.forEach((s, d) => print(s));  
      
      if (libMirror.declarations.containsKey(className)) print("found class");
      ClassMirror? classMirror = libMirror.declarations[className] as ClassMirror?; 
      
      print("No of instance methods found is ${classMirror!.instanceMembers.length}");
      classMirror.instanceMembers.forEach((s, v) => print(s)); 
   } 
}    
