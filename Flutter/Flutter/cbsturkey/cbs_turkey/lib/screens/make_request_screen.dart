import 'package:flutter/material.dart';
import 'city_onclicked_screen.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter/services.dart';

class MakeRequestScreen extends StatefulWidget {
  static String id = 'make_request_screen';
  const MakeRequestScreen({ Key? key }) : super(key: key);

  @override
  _MakeRequestScreenState createState() => _MakeRequestScreenState();
}

class _MakeRequestScreenState extends State<MakeRequestScreen> {
  final _firestore = FirebaseFirestore.instance;
  String? newRequestMsg;
  String requestCityName = CityOnClickedScreen.cityData.name;

  @override
  void initState(){
    super.initState();
    SystemChrome.setPreferredOrientations([
        DeviceOrientation.portraitUp,
    ]);
  }

  @override
  dispose(){
    SystemChrome.setPreferredOrientations([
      DeviceOrientation.landscapeRight,
    ]);
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.lightBlueAccent,
      body: SafeArea(
        child: Container(
            color: Color(0xff757575),
            child: Container(
              padding: EdgeInsets.all(20.0),
              decoration: BoxDecoration(
                  color: Colors.white,
                  borderRadius: BorderRadius.only(
                      topLeft: Radius.circular(20.0),
                      topRight: Radius.circular(20.0))),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.stretch,
                children: <Widget>[
                  Center(
                    child: Text(
                      'Add Request',
                      style: TextStyle(
                        color: Colors.lightBlueAccent,
                        fontSize: 30,
                      ),
                    ),
                  ),
                  SizedBox(
                    height: 300.0,
                  ),
                  TextField(
                    decoration: InputDecoration(),
                    textAlign: TextAlign.center,
                    autofocus: true,
                    onSubmitted: (newRequest) {
                      newRequestMsg = newRequest;
                          Navigator.pop(context);
                    },
                    onChanged: (newRequest) {
                      newRequestMsg = newRequest;
                    },
                  ),
                  SizedBox(
                    height: 100.0,
                  ),
                  TextButton(
                    onPressed: () async {
                      await _firestore.collection('UserRequests').add({'cityName': requestCityName, 'requestMessage': newRequestMsg});
                      Navigator.pop(context);
                    },
                    child: Text(
                      'Add',
                      style: TextStyle(
                        color: Colors.white,
                        fontSize: 18.0,
                      ),
                    ),
                    style: TextButton.styleFrom(
                      backgroundColor: Colors.lightBlueAccent,
                    ),
                  ),
                   SizedBox(
                    height: 10.0,
                  ),
                  TextButton(
                    onPressed: () async {
                      Navigator.pop(context);
                    },
                    child: Text(
                      'Go Back',
                      style: TextStyle(
                        color: Colors.white,
                        fontSize: 18.0,
                      ),
                    ),
                    style: TextButton.styleFrom(
                      backgroundColor: Colors.lightBlueAccent,
                    ),
                  ),
                ],
              ),
            )),
      ),
    );
  } 
}