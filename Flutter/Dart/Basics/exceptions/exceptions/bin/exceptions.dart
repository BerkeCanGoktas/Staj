void division(int x, int y)
{
  try{
    if(y!=0){
      print(x/y);
    }
    else{
      String err = "bolen 0 olamaz";
      throw err ;
    }
  } 
  catch(err){
    print(err);
  }
  finally{
    print("son");
  }
}

void main(List<String> arguments) {
  division(15, 3);
  division(100, 0);
}
