import 'package:cloud_firestore/cloud_firestore.dart';

class City{
  late double altitude;
  late String climate;
  late String flora;
  late GeoPoint location;
  late String name;
  late int population;
  City({required this.altitude, required this.climate, required this.flora, required this.location, required this.name, required this.population});
}