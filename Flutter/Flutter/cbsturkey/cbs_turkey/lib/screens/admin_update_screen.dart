import 'package:flutter/material.dart';
import 'package:modal_progress_hud_nsn/modal_progress_hud_nsn.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:cbs_turkey/constants.dart';
import 'admin_city_submit_screen.dart';
import 'package:cbs_turkey/data/requests_data.dart';


class AdminCityUpdateScreen extends StatefulWidget {
  String cityName;
  String refID;
  AdminCityUpdateScreen({required this.cityName, required this.refID});
  Future<void> showDialog1(BuildContext context, String errMsg) {
    return showDialog<void>(
      context: context,
      builder: (BuildContext context) {
        return AlertDialog(
          backgroundColor: Colors.white,
          title: const Text('Alert'),
          shape: const RoundedRectangleBorder(
              borderRadius: BorderRadius.all(Radius.circular(15.0))),
          content: Text(errMsg),
          actions: <Widget>[
            TextButton(
              child: const Text('Ok'),
              onPressed: () {
                Navigator.push(
                  context,
                  MaterialPageRoute(
                    builder: (context) => AdminCityUpdateScreen(cityName: cityName, refID: refID,),
                  ),
                );
              },
            ),
          ],
        );
      },
    );
  }

  static String id = 'admin__city_update_screen';

  @override
  _AdminCityUpdateScreenState createState() => _AdminCityUpdateScreenState();
}

class _AdminCityUpdateScreenState extends State<AdminCityUpdateScreen> {
  bool showSpinner = false;
  String flora = '';
  String climate = '';
  num altitude = 0;
  int population = 0;
  GeoPoint? location;
  final _firestore = FirebaseFirestore.instance;

  @override
  Widget build(BuildContext context) {
    print(widget.cityName);
    return ModalProgressHUD(
      inAsyncCall: showSpinner,
      child: Scaffold(
          appBar: AppBar(
            backgroundColor: Colors.white,
            title: Center(
              child: Text(
                'Admin Panel',
                style: TextStyle(
                    fontSize: 35.0,
                    color: Colors.lightBlueAccent,
                    fontWeight: FontWeight.bold),
              ),
            ),
            leading: IconButton(
              onPressed: () {
                Navigator.pushNamed(context, AdminCitySubmitScreen.id);
              },
              icon: const Icon(
                Icons.arrow_back,
                size: 40.0,
              ),
              tooltip: 'Go back to welcome screen',
              color: Colors.lightBlueAccent,
            ),
          ),
          backgroundColor: Colors.white,
          body: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: <Widget>[
              Flexible(
                flex: 1,
                child: Text(
                  'Update City',
                  style: TextStyle(
                      color: Colors.lightBlueAccent,
                      fontSize: 35.0,
                      fontWeight: FontWeight.bold),
                ),
              ),
             Flexible(
               flex: 5,
               child: Column(children: <Widget> [
                  SizedBox(height: 30.0,),
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: <Widget>[
                    SizedBox(
                      width: 5.0,
                    ),
                    Text('City Name:',
                        style: TextStyle(
                            fontSize: 24.0, fontWeight: FontWeight.bold)),
                    SizedBox(
                      width: 10.0,
                    ),
                    Expanded(
                      child: TextFormField(
                        initialValue: widget.cityName,
                        onChanged: (value) {
                          widget.cityName = value;
                        },
                        decoration: textFieldDecoration.copyWith(
                            hintText: 'Enter city name'),
                      ),
                    ),
                    SizedBox(
                      width: 5.0,
                    ),
                  ],
                ),
                 SizedBox(height: 10.0,),
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: <Widget>[
                    SizedBox(
                      width: 5.0,
                    ),
                    Text('City Climate:',
                        style: TextStyle(
                            fontSize: 24.0, fontWeight: FontWeight.bold)),
                    SizedBox(
                      width: 10.0,
                    ),
                    Expanded(
                      child: TextField(
                        onChanged: (value) {
                          climate = value;
                        },
                        decoration: textFieldDecoration.copyWith(
                            hintText: 'Enter city climate'),
                      ),
                    ),
                    SizedBox(
                      width: 5.0,
                    ),
                  ],
                ),
                SizedBox(height: 10.0,),
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: <Widget>[
                    SizedBox(
                      width: 5.0,
                    ),
                    Text('City Flora:',
                        style: TextStyle(
                            fontSize: 24.0, fontWeight: FontWeight.bold)),
                    SizedBox(
                      width: 10.0,
                    ),
                    Expanded(
                      child: TextField(
                        onChanged: (value) {
                          flora = value;
                        },
                        decoration: textFieldDecoration.copyWith(
                            hintText: 'Enter city flora'),
                      ),
                    ),
                    SizedBox(
                      width: 5.0,
                    ),
                  ],
                ),
                SizedBox(height: 10.0,),
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: <Widget>[
                    SizedBox(
                      width: 5.0,
                    ),
                    Text('City Population:',
                        style: TextStyle(
                            fontSize: 24.0, fontWeight: FontWeight.bold)),
                    SizedBox(
                      width: 10.0,
                    ),
                    Expanded(
                      child: TextField(
                        onChanged: (value) {
                          population = int.parse(value);
                        },
                        keyboardType: TextInputType.number,
                        decoration: textFieldDecoration.copyWith(
                            hintText: 'Enter city population'),
                      ),
                    ),
                    SizedBox(
                      width: 5.0,
                    ),
                  ],
                ),
                SizedBox(height: 10.0,),
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: <Widget>[
                    SizedBox(
                      width: 5.0,
                    ),
                    Text('City Altitude:',
                        style: TextStyle(
                            fontSize: 24.0, fontWeight: FontWeight.bold)),
                    SizedBox(
                      width: 10.0,
                    ),
                    Expanded(
                      child: TextField(
                        onChanged: (value) {
                          altitude = num.parse(value);
                        },
                        keyboardType: TextInputType.number,
                        decoration: textFieldDecoration.copyWith(
                            hintText: 'Enter city altitude'),
                      ),
                    ),
                    SizedBox(
                      width: 5.0,
                    ),
                  ],
                ),
               ],),
             ),
              Flexible(
                flex: 2,
                child: Stack(
                  children: <Widget>[                     
                        Align(
                          alignment: Alignment.bottomCenter,
                          child: FloatingActionButton.extended(
                            heroTag: 'btn3',
                            onPressed: () async {
                              //String reference = await RequestData().updateCity(widget.cityName);
                              //print(reference);
                              String requestMessage = '';
                              int? index;
                              await _firestore.collection('CityData').doc(await RequestData().updateCity(widget.cityName)).delete();
                              await _firestore.collection('CityData').add({
                                    'name': widget.cityName,
                                    'climate': climate,
                                    'flora': flora,
                                    'population': population,
                                    'altitude': altitude,
                                    'location': location
                                    });
                              await for(var snapshots in _firestore.collection('UserRequests').snapshots()){
                                for (var request in snapshots.docs) {
                                  if(request.reference.id == widget.refID){
                                  requestMessage = await request.get('requestMessage');
                                  }
                                }
                              await _firestore.collection('UserRequests').doc(widget.refID).delete();     
                              RequestData().getRequests(); 
                              Navigator.pop(context);
                              }
                            },
                            backgroundColor: Colors.lightBlueAccent,
                            foregroundColor: Colors.white,
                            icon: Icon(Icons.update),
                            label: Text('Update'),
                          ),
                        ),
                  ],),
              ),
            ],),
            ),
    );
  }
}
