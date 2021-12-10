import 'package:geolocator/geolocator.dart';

class Location{
  double latitude = 0;
  double longitude = 0;

  Future<Location> getcurrentLocation() async{
    Location locationObj = Location();
    try {
      Position position = await Geolocator.getCurrentPosition(desiredAccuracy: LocationAccuracy.low);
      latitude = position.latitude;
      longitude = position.longitude;
      return locationObj;
    } catch (e) {
      print(e);
      return locationObj;
    }    
  }
}