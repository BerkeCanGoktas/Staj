import 'package:flutter/material.dart';
import 'package:modal_progress_hud_nsn/modal_progress_hud_nsn.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:cbs_turkey/data/requests_data.dart';
import 'package:cbs_turkey/screens/admin_city_submit_screen.dart';
import 'package:cbs_turkey/data/request.dart';
import 'package:cbs_turkey/special_widgets/requests_list.dart';

class AdminRequestsScreen extends StatefulWidget {
  static String id = 'admin_requests_screen';
  final _firestore = FirebaseFirestore.instance;

  @override
  _AdminRequestsScreenState createState() => _AdminRequestsScreenState();
}

class _AdminRequestsScreenState extends State<AdminRequestsScreen> {
  bool showSpinner = false;


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
                Navigator.pushNamed(context, AdminCitySubmitScreen.id);
              },
              icon: const Icon(
                Icons.arrow_back,
                size: 40.0,
              ),
              tooltip: 'Go back to city submitting screen',
              color: Colors.lightBlueAccent,
            ),
          ),
          backgroundColor: Colors.white,
          body: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: <Widget>[
              Padding(
                padding: const EdgeInsets.all(10.0),
                child: Text(
                  'Requests',
                  style: TextStyle(
                      color: Colors.lightBlueAccent,
                      fontSize: 35.0,
                      fontWeight: FontWeight.bold),
                ),
              ),
              SizedBox(height: 5.0,),
             Text('Hold on request to make changes.'),
             RequestsList(),
             ],
            ),
    ),);
  }
}