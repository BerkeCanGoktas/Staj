import 'package:cbs_turkey/data/city.dart';
import 'package:cbs_turkey/data/requests_data.dart';
import 'package:flutter/material.dart';
import 'package:cbs_turkey/screens/admin_city_submit_screen.dart';
import 'package:cbs_turkey/special_widgets/rounded_button.dart';
import 'package:cbs_turkey/constants.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'map_screen.dart';
import 'package:provider/provider.dart';
import 'package:modal_progress_hud_nsn/modal_progress_hud_nsn.dart';
import 'welcome_screen.dart';
import 'package:cbs_turkey/data/city_data.dart';

class LoginScreen extends StatefulWidget {
  static String id = 'login_screen';

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
                    builder: (context) => LoginScreen(),
                  ),
                );
              },
            ),
          ],
        );
      },
    );
  }

  @override
  _LoginScreenState createState() => _LoginScreenState();
}

class _LoginScreenState extends State<LoginScreen> {
  String email = '';
  String password = '';
  final _auth = FirebaseAuth.instance;
  bool showSpinner = false;
  bool isAdmin = false;
  String id = MapScreen.id;

  bool checkIfAdmin(UserCredential loggedUser) {
    if (loggedUser.user!.uid == 'xweXlNwtkVeXuDChHqY2jbzPbFw1') {
      id = AdminCitySubmitScreen.id;
      return true;
    }
    return false;
  }

  @override
  Widget build(BuildContext context) {
    return ModalProgressHUD(
      inAsyncCall: showSpinner,
      child: Scaffold(
        backgroundColor: Colors.white,
        body: Padding(
          padding: const EdgeInsets.symmetric(horizontal: 24.0),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              Flexible(
                flex: 1,
                child: Padding(
                  padding: const EdgeInsets.only(
                    left: 15.0,
                  ),
                  child: IconButton(
                    onPressed: () {
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
              ),
              Flexible(
                flex: 5,
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  crossAxisAlignment: CrossAxisAlignment.stretch,
                  children: <Widget>[
                    const Center(
                      child: Text(
                        'Turkey',
                        style: TextStyle(
                          fontSize: 60,
                          fontWeight: FontWeight.w900,
                          color: Colors.black54,
                        ),
                      ),
                    ),
                    const SizedBox(
                      height: 48.0,
                    ),
                    TextField(
                      keyboardType: TextInputType.emailAddress,
                      textAlign: TextAlign.center,
                      onChanged: (value) {
                        email = value;
                      },
                      decoration: textFieldDecoration.copyWith(
                          hintText: 'Enter your email address'),
                    ),
                    const SizedBox(
                      height: 8.0,
                    ),
                    TextField(
                      textAlign: TextAlign.center,
                      obscureText: true,
                      onChanged: (value) {
                        password = value;
                      },
                      decoration: textFieldDecoration.copyWith(
                          hintText: 'Enter your password'),
                    ),
                    const SizedBox(
                      height: 24.0,
                    ),
                    RoundedButton(
                      colour: Colors.lightBlueAccent,
                      title: 'Login',
                      onPressed: () async {
                        setState(() {
                          showSpinner = true;
                        });
                        try {
                          Provider.of<CityData>(context, listen: false)
                              .getCityData();
                          final loggedUser =
                              await _auth.signInWithEmailAndPassword(
                                  email: email, password: password);
                          if (loggedUser != null) {
                            bool isAdmin = checkIfAdmin(loggedUser);
                            if(isAdmin){
                              Provider.of<RequestData>(context, listen: false).setAdminLogInState(true);
                            }
                            Navigator.pushNamed(context, id);
                          }
                          setState(() {
                            showSpinner = false;
                          });
                        } on FirebaseAuthException catch (e) {
                          setState(() {
                            showSpinner = false;
                          });
                          widget.showDialog1(context, e.toString());
                        }
                      },
                    ),
                  ],
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
