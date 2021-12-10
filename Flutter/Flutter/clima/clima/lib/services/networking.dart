import 'package:http/http.dart' as http;
import 'package:clima/utilities/constants.dart';
import 'dart:convert';
import 'location.dart';

class NetworkHelper{

  Future<dynamic> getDataFromCityName(String cityName) async{
     http.Response response = await http.get(Uri.parse('https://api.openweathermap.org/data/2.5/weather?q=${cityName}&appid=${myAPIKey}&units=metric'));
     if(response.statusCode == 200){
      String data = response.body;
      return jsonDecode(data);
    }
    else{
      print(response.statusCode);
    }
  }

  Future<dynamic> getDataFromLocation() async{
    Location locationObj = Location();
    await locationObj.getcurrentLocation();
    http.Response response = await http.get(Uri.parse('https://api.openweathermap.org/data/2.5/weather?lat=${locationObj.latitude}&lon=${locationObj.longitude}&appid=${myAPIKey}&units=metric'));
    if(response.statusCode == 200){
      String data = response.body;
      return jsonDecode(data);
    }
    else{
      print(response.statusCode);
    }
  }

}