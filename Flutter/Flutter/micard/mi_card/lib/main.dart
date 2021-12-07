import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        backgroundColor: Colors.teal,
        body: SafeArea(
            child: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: <Widget>[
              const CircleAvatar(
                radius: 50.0,
                backgroundColor: Colors.blueGrey,
                foregroundImage: AssetImage('images/person.png'),
              ),
              const Text(
                'Berke Can GÖKTAŞ',
                style: TextStyle(
                  fontFamily: 'Pacifico',
                  fontSize: 40.0,
                  color: Colors.white,
                  fontWeight: FontWeight.bold,
                ),
              ),
              const Text(
                'FLUTTER',
                style: TextStyle(
                  fontFamily: 'Source Sans Pro',
                  fontSize: 30.0,
                  letterSpacing: 2.5,
                  color: Colors.white,
                  fontWeight: FontWeight.bold,
                ),
              ),
              SizedBox(
                height: 20.0,
                width: 350.0,
                child: Divider(
                  color: Colors.teal.shade100,
                ),
              ),
              Card(
                color: Colors.white,
                margin: const EdgeInsets.symmetric(
                  vertical: 10.0,
                  horizontal: 250.0,
                ),
                child: Padding(
                  padding: const EdgeInsets.all(25.0),
                  child: ListTile(
                    leading:
                        // ignore: prefer_const_constructors
                        Icon(
                      Icons.phone,
                      color: Colors.teal,
                    ),
                    title: Text(
                      '+90 530 367 78 30',
                      style: TextStyle(
                        color: Colors.teal.shade900,
                        fontFamily: 'Source Sans Pro',
                        fontSize: 35.0,
                      ),
                    ),
                  ),
                ),
              ),
              Card(
                  color: Colors.white,
                  margin: const EdgeInsets.symmetric(
                    vertical: 10.0,
                    horizontal: 250.0,
                  ),
                  child: Padding(
                      padding: const EdgeInsets.all(25.0),
                      child: ListTile(
                        leading:
                            // ignore: prefer_const_constructors
                            Icon(
                          Icons.email_outlined,
                          color: Colors.teal,
                        ),
                        title: Text(
                          'berke.goktas@boun.edu.tr',
                          style: TextStyle(
                            color: Colors.teal.shade900,
                            fontFamily: 'Source Sans Pro',
                            fontSize: 35.0,
                          ),
                        ),
                      )))
            ],
          ),
        )),
      ),
    );
  }
}
