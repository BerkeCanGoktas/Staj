import 'package:cbs_turkey/data/city_data.dart';
import 'package:flutter/material.dart';
import 'package:cbs_turkey/data/city.dart';
import 'make_request_screen.dart';
import 'package:flutter/services.dart';
import 'package:flutter_map/flutter_map.dart';
import 'package:latlong2/latlong.dart';

class CityOnClickedScreen extends StatefulWidget {
  static String id = 'city_on_clicked_screen';
  static late City cityData;
  static late String cityName;
  const CityOnClickedScreen({Key? key}) : super(key: key);

  @override
  _CityOnClickedScreenState createState() => _CityOnClickedScreenState();
}

class _CityOnClickedScreenState extends State<CityOnClickedScreen> {
  int altitude = CityOnClickedScreen.cityData.altitude.round();

  @override
  dispose() {
    SystemChrome.setPreferredOrientations([
      DeviceOrientation.landscapeRight,
    ]);
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    bool isLastDigitEqualsToZero =
        CityOnClickedScreen.cityData.altitude - altitude == 0 ? true : false;
    return Scaffold(
      appBar: AppBar(
        title: Center(
            child: Text(
          CityOnClickedScreen.cityData.name.toUpperCase(),
          style: TextStyle(
              fontSize: 24.0,
              fontWeight: FontWeight.w600,
              fontStyle: FontStyle.italic),
        )),
      ),
      body: Padding(
        padding: const EdgeInsets.all(10.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: <Widget>[
            SizedBox(height: 20.0),
            Text(
                'City Altitude: ${isLastDigitEqualsToZero ? altitude : CityOnClickedScreen.cityData.altitude}',
                style: TextStyle(
                  fontSize: 20.0,
                )),
            SizedBox(height: 10.0),
            Text('City Population: ${CityOnClickedScreen.cityData.population}',
                style: TextStyle(
                  fontSize: 20.0,
                )),
            SizedBox(height: 10.0),
            Text('City Climate: ${CityOnClickedScreen.cityData.climate}',
                style: TextStyle(
                  fontSize: 20.0,
                )),
            SizedBox(height: 10.0),
            Text('City Flora: ${CityOnClickedScreen.cityData.flora}',
                style: TextStyle(
                  fontSize: 20.0,
                )),
            SizedBox(height: 10.0),
            Expanded(
                child: Padding(
                  padding: const EdgeInsets.all(8.0),
                  child: FlutterMap(
              options: MapOptions(
                  center: LatLng(CityOnClickedScreen.cityData.location.latitude,
                      CityOnClickedScreen.cityData.location.longitude),
                  zoom: 8,
                  maxZoom: 10,
                  minZoom: 8,
                  swPanBoundary: LatLng(
                      CityOnClickedScreen.cityData.location.latitude,
                      CityOnClickedScreen.cityData.location.longitude),
                  nePanBoundary: LatLng(
                      CityOnClickedScreen.cityData.location.latitude,
                      CityOnClickedScreen.cityData.location.longitude),
              ),
              layers: [
                  TileLayerOptions(
                    urlTemplate:
                        "https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png",
                    subdomains: ['a', 'b', 'c'],
                    attributionBuilder: (_) {
                      return Text(
                        "© OpenStreetMap",
                        style: TextStyle(color: Colors.white38, fontSize: 10.0),
                      );
                    },
                  ),
              ],
            ),
                )),
            Align(
              alignment: Alignment.bottomRight,
              child: FloatingActionButton.extended(
                onPressed: () {
                  Navigator.pushNamed(context, MakeRequestScreen.id);
                },
                backgroundColor: Colors.lightBlueAccent,
                foregroundColor: Colors.white,
                label: Text('Make Request'),
                icon: Icon(Icons.support_agent),
              ),
            ),
            SizedBox(
              height: 20.0,
            ),
          ],
        ),
      ),
    );
  }
}

//ŞEHRİN HARİTASINI GÖSTER (BELKİ?)