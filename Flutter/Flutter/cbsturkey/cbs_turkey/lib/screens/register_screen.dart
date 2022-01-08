import 'package:flutter/material.dart';
import 'package:cbs_turkey/constants.dart';
import 'package:cbs_turkey/special_widgets/rounded_button.dart';
import 'map_screen.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:modal_progress_hud_nsn/modal_progress_hud_nsn.dart';
import 'welcome_screen.dart';

class RegisterScreen extends StatefulWidget {
  static String id = 'registration_screen';

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
                    builder: (context) => RegisterScreen(),
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
  _RegisterScreenState createState() => _RegisterScreenState();
}

class _RegisterScreenState extends State<RegisterScreen> {
  final _auth = FirebaseAuth.instance;
  bool showSpinner = false;
  String email = '';
  String password = '';

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
                          onPressed: (){Navigator.pushNamed(context, WelcomeScreen.id);},
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
                            fontSize: 45,
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
                      decoration: textFieldDecoration.copyWith(hintText: 'Enter your email address'),
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
                      decoration: textFieldDecoration.copyWith(hintText: 'Enter your password'),
                    ),
                    const SizedBox(
                      height: 24.0,
                    ),
                    RoundedButton(
                        colour: Colors.blueAccent, title: 'Register', onPressed: () async{
                          setState(() {
                            showSpinner = true;
                          });
                          try{
                         final newUser = await _auth.createUserWithEmailAndPassword(email: email, password: password);
                         if(newUser != null){
                           Navigator.pushNamed(context, MapScreen.id);
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
                        }),
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