import 'package:flutter/material.dart';
import 'package:modal_progress_hud_nsn/modal_progress_hud_nsn.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:cbs_turkey/constants.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'welcome_screen.dart';
import 'package:cbs_turkey/data/requests_data.dart';
import 'admin_requests_screen.dart';
import 'package:geocoding/geocoding.dart';
import 'package:provider/provider.dart';

class AdminCitySubmitScreen extends StatefulWidget {
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
                    builder: (context) => AdminCitySubmitScreen(),
                  ),
                );
              },
            ),
          ],
        );
      },
    );
  }

  static String id = 'admin__city_submit_screen';

  @override
  _AdminCitySubmitScreenState createState() => _AdminCitySubmitScreenState();
}

class _AdminCitySubmitScreenState extends State<AdminCitySubmitScreen> {
  bool showSpinner = false;
  final _auth = FirebaseAuth.instance;
  String cityName = '';
  String flora = '';
  String climate = '';
  num altitude = 0;
  int population = 0;
  late List<Location> location;
  final _firestore = FirebaseFirestore.instance;

  @override
  Widget build(BuildContext context) {
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
                Provider.of<RequestData>(context, listen: false).setAdminLogInState(false);
                _auth.signOut();
                Navigator.pushNamed(context, WelcomeScreen.id);
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
                  'Add City',
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
                      child: TextField(
                        onChanged: (value) {
                          cityName = value;
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
                      alignment: Alignment.bottomRight,
                      child: FloatingActionButton.extended(
                        heroTag: 'btn1',
                            onPressed: () async {
                              GeoPoint loc;
                              if(cityName.isNotEmpty){
                              location = await locationFromAddress(cityName);
                              var encoded = location[0].toJson();
                              //print(encoded);
                              double longitude = encoded['longitude'] ;
                              double latitude = encoded['latitude'];
                              loc = GeoPoint(latitude, longitude);
                              }
                              else{
                                loc = GeoPoint(1, 1);
                              }
                              setState(() {
                          showSpinner = true;
                        });
                        try {
                          if(cityName.isNotEmpty){
                                    await _firestore.collection('CityData').add({
                                    'name': cityName,
                                    'climate': climate,
                                    'flora': flora,
                                    'population': population,
                                    'altitude': altitude,
                                    'location': loc,
                                    });
                          }
                          else{
                            String emptyName = 'City name must be provided';
                            throw(emptyName);
                          }
                          setState(() {
                            showSpinner = false;
                          });
                        } on FirebaseException catch (e) {
                          setState(() {
                            showSpinner = false;
                          });
                          widget.showDialog1(context, e.toString());
                        }
                        catch(emptyName){
                          widget.showDialog1(context, emptyName.toString());
                        }
                            },
                            backgroundColor: Colors.lightBlueAccent,
                            foregroundColor: Colors.white,
                            icon: Icon(Icons.save),
                            label: Text('Submit'),
                          ),
                    ),
                        Align(
                          alignment: Alignment.bottomLeft,
                          child: FloatingActionButton.extended(
                            heroTag: 'btn2',
                            onPressed: () async {
                              Provider.of<RequestData>(context, listen: false).setAdminLogInState(true);
                              if(_auth.currentUser!.uid == 'xweXlNwtkVeXuDChHqY2jbzPbFw1'){
                              Provider.of<RequestData>(context, listen: false).getRequests();
                              Navigator.pushNamed(context, AdminRequestsScreen.id); 
                              }
                            },
                            backgroundColor: Colors.lightBlueAccent,
                            foregroundColor: Colors.white,
                            icon: Icon(Icons.support_agent),
                            label: Text('Requests'),
                          ),
                        ),
                  ],),
              ),
            ],),
            ),
    );
  }
}
