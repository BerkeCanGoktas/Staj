import 'package:flutter/material.dart';
import 'request.dart';
import 'package:cloud_firestore/cloud_firestore.dart';

class RequestData extends ChangeNotifier {
  final _firestore = FirebaseFirestore.instance;
  static bool isAdminLoggedIn = false;

  static List<Request> staticRequestsList = [];

  setAdminLogInState(bool state) {
    isAdminLoggedIn = state;
  }

  Future<void> getRequests() async {
    RequestData.staticRequestsList = [];
    if (RequestData.isAdminLoggedIn) {
      await for (var snapshots
          in _firestore.collection('UserRequests').snapshots()) {
        for (var request in snapshots.docs) {
          String cityName = request.get('cityName');
          String requestText = request.get('requestMessage');
          Request req =
              Request(requestCityName: cityName, requestText: requestText);
          RequestData.staticRequestsList.add(req);
          notifyListeners();
        }
      }
    }
    else{
      print('end');
    }
  }

  int requestCount() {
    return staticRequestsList.length;
  }

  Future<String> updateCity(String cityName) async {
    String reference = '';
    var collection = _firestore.collection('CityData');
    var q = await collection.where('name', isEqualTo: cityName);
    var querySnapshot = await q.get();
    for (var doc in querySnapshot.docs) {
      reference = await doc.reference.id;
    }
    print(reference);
    return reference;
  }

  void deleteRequest(Request request) async {
    String? ref = await updateDatabase(request);
    if (ref != null) {
      staticRequestsList.remove(request);
      await _firestore
          .collection('UserRequests')
          .doc(ref)
          .delete()
          .whenComplete(() async {
        await getRequests();
      });
    }
    notifyListeners();
  }

  Future<String?> updateDatabase(Request request) async {
    var collection = _firestore.collection('UserRequests');
    var q = await collection.where('requestMessage',
        isEqualTo: request.requestText);
    var querySnapshot = await q.get();
    for (var doc in querySnapshot.docs) {
      String reference = await doc.reference.id;
      return reference;
    }
  }
}
