import 'package:cbs_turkey/screens/city_onclicked_screen.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter/material.dart';
import 'package:flutter_map/flutter_map.dart';
import 'city.dart';
import 'package:latlong2/latlong.dart';
import 'package:cbs_turkey/screens/city_onclicked_screen.dart';
import 'requests_data.dart';
import 'package:flutter/services.dart';

class CityData extends ChangeNotifier {
  var firestore = FirebaseFirestore.instance;
  static List<City> cityList = [];

  Future<void> getCityData() async {
    await for (var snapshots in firestore.collection('CityData').snapshots()) {
      for (var city in snapshots.docs) {
        double altitude = double.parse(city.get('altitude').toString());
        String climate = city.get('climate');
        String flora = city.get('flora');
        GeoPoint location = city.get('location');
        String name = city.get('name');
        int population = city.get('population');
        City cityObj = City(
            altitude: altitude,
            climate: climate,
            flora: flora,
            location: location,
            name: name,
            population: population);
        cityList.add(cityObj);
        createMarkers();
        notifyListeners();
        print(cityList.length);
      }
    }
  }

  // Future<void> getOneCityData() async{
  //   await for(var snapshots in firestore.collection('CityData').where('name', isEqualTo: CityOnClickedScreen.cityName).snapshots()){
  //     for(var city in  snapshots.docs){
  //       double altitude = double.parse(city.get('altitude').toString());
  //       String climate = city.get('climate');
  //       String flora = city.get('flora');
  //       GeoPoint location = city.get('location');
  //       String name = city.get('name');
  //       int population = city.get('population');
  //       CityOnClickedScreen.cityData = City(altitude: altitude, climate: climate, flora: flora, location: location, name: name, population: population);
  //       notifyListeners();
  //       print(cityList.length);
  //     }
  //   }
  //   print('end');
  // }

  List<Marker> markersList = [];

  void createMarkers() {
    for (var city in CityData.cityList) {
      markersList.add(
        Marker(
            width: 80.0,
            height: 80.0,
            point: LatLng(city.location.latitude, city.location.longitude),
            builder: (ctx) => GestureDetector(
                  child: Icon(Icons.arrow_downward_rounded),
                  onTap: () {
                    SystemChrome.setPreferredOrientations([
                      DeviceOrientation.portraitUp]);
                    CityOnClickedScreen.cityData = City(
                        altitude: city.altitude,
                        climate: city.climate,
                        flora: city.flora,
                        location: city.location,
                        name: city.name,
                        population: city.population);
                    Navigator.pushNamed(ctx, CityOnClickedScreen.id);
                    print('clicked');
                  },
                )),
      );
    }
  }
}
