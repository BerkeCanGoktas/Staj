import 'package:cbs_turkey/data/city_data.dart';
import 'package:flutter/material.dart';
import 'package:flutter_map/flutter_map.dart';
import 'package:latlong2/latlong.dart'; 
import 'package:provider/provider.dart';
import 'package:flutter/services.dart';

class MapScreen extends StatefulWidget {
  static String id = 'map_sceen';
  const MapScreen({Key? key}) : super(key: key);

  @override
  _MapScreen createState() => _MapScreen();
}

class _MapScreen extends State<MapScreen> {

  @override
  void initState(){
    super.initState();
    SystemChrome.setPreferredOrientations([
        DeviceOrientation.landscapeRight,
    ]);
  }

  @override
  dispose(){
    SystemChrome.setPreferredOrientations([
      DeviceOrientation.portraitUp,
    ]);
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
  return FlutterMap(
    options: MapOptions(
      center: LatLng(39.1667, 35.6667),
      zoom: 6.1,
      maxZoom: 9,
      minZoom: 6.2,
      swPanBoundary: LatLng(36, 26),
      nePanBoundary: LatLng(42, 45),
    ),
    layers: [
      TileLayerOptions(
        urlTemplate: "https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png",
        subdomains: ['a', 'b', 'c'],
        attributionBuilder: (_) {
          return Text("© OpenStreetMap", style: TextStyle(color: Colors.white38, fontSize: 10.0),);
        },
      ),
      MarkerLayerOptions(
        markers: Provider.of<CityData>(context,listen: false).markersList,
      ),
    ],
  );
}
}

// //HARİTAYI KISITLA

// import 'package:city_picker_from_map/city_picker_from_map.dart' as citypicker;
// import 'package:flutter/material.dart';
// import 'package:flutter/services.dart';
// import 'package:cloud_firestore/cloud_firestore.dart';
// import 'city_onclicked_screen.dart';
// import 'package:cbs_turkey/data/city.dart';
// import 'package:cbs_turkey/data/city_data.dart';
// import 'package:provider/provider.dart';

// class MapScreen extends StatefulWidget {
//   static String id = 'map_sceen';
//   const MapScreen({Key? key}) : super(key: key);

//   @override
//   _MapScreen createState() => _MapScreen();
// }

// class _MapScreen extends State<MapScreen> {

//   citypicker.City? selectedCity;
//   final _firestore = FirebaseFirestore.instance;

//   @override
//   void initState(){
//     super.initState();
//     SystemChrome.setPreferredOrientations([
//         DeviceOrientation.landscapeRight,
//     ]);
//   }

//   @override
//   dispose(){
//     SystemChrome.setPreferredOrientations([
//       DeviceOrientation.portraitUp,
//     ]);
//     super.dispose();
//   }

//   @override
//   Widget build(BuildContext context) {
//     return Scaffold(
//       appBar: AppBar(
//         title: Center(
//             child: Text(
//           'Turkey',
//           style: TextStyle(
//               fontSize: 24.0,
//               fontWeight: FontWeight.w600,
//               fontStyle: FontStyle.italic),
//         )),
//       ),
//       body: Center(
//         child: citypicker.CityPickerMap(
//           width: double.infinity,
//           height: double.infinity,
//           map: citypicker.Maps.TURKEY,
//           onChanged: (city) {
//             setState(() {
//             selectedCity = city;
//             });
//           },
//           actAsToggle: true,
//           dotColor: Colors.black,
//           selectedColor: Colors.lightBlueAccent,
//           strokeColor: Colors.green,
//         ),
//       ),
//       floatingActionButton: FloatingActionButton.extended(onPressed: () async{
//         CityOnClickedScreen.cityName = selectedCity!.title;
//         Navigator.pushNamed(context, CityOnClickedScreen.id);
//       }, label: Text('Go To City')),
//     );
//   }
// }