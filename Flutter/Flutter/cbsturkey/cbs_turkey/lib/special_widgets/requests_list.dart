import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter/material.dart';
import 'package:cbs_turkey/screens/admin_update_screen.dart';
import 'request_tile.dart';
import 'package:cbs_turkey/data/requests_data.dart';
import 'package:provider/provider.dart';


class RequestsList extends StatelessWidget  {
  const RequestsList({ Key? key }) : super(key: key);

@override
  Widget build(BuildContext context) {

    return Consumer<RequestData>(
      builder: (context, requestData, child) {
        return Flexible(
          child: ListView.builder(
              padding: EdgeInsets.symmetric(
                horizontal: 20.0,
              ),
              itemCount: RequestData.staticRequestsList.length,
              itemBuilder: (context, index) {
                return Column(
                  children: [
                    RequestTile(
                        requestCityName:
                           RequestData.staticRequestsList[index].requestCityName,
                        requestText: RequestData.staticRequestsList[index].requestText,
                        longPressCallback: (){
                            requestData.deleteRequest(RequestData.staticRequestsList[index]);
                        },
                        onTapCallback: () async{
                          String reference = '';
                           var collection = FirebaseFirestore.instance.collection('UserRequests');
                            var q = await collection.where('requestMessage', isEqualTo: RequestData.staticRequestsList[index].requestText);
                            var querySnapshot = await q.get();
                            for (var doc in querySnapshot.docs){
                            reference = doc.reference.id;
                            }
                          Navigator.push(context, MaterialPageRoute(builder: (context) => AdminCityUpdateScreen(cityName: RequestData.staticRequestsList[index].requestCityName, refID: reference,)));
                        },
                        ),
                        Divider(color: Colors.lightBlueAccent,)
                  ],
                );
              }),
        );
      },
    );
  }
}