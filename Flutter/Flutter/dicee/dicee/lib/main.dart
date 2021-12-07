import 'dart:math';
import 'package:flutter/material.dart';

void main() {
  return runApp(
    MaterialApp(
      home: Scaffold(
        backgroundColor: Colors.red,
        appBar: AppBar(
          title: const Text(
            'Dicee',
            textAlign: TextAlign.center,
          ),
          backgroundColor: Colors.red.shade500,
        ),
        body: DicePage(),
      ),
    ),
  );
}

class DicePage extends StatefulWidget {
  const DicePage({Key? key}) : super(key: key);

  @override
  _DicePageState createState() => _DicePageState();
}

class _DicePageState extends State<DicePage> {
  int _leftDiceNumber = 6;
  int _rightDiceNumber = 6;
  void setDies(){
    _leftDiceNumber = 1 + Random().nextInt(6);
    _rightDiceNumber = 1 + Random().nextInt(6);
  }
  @override
  Widget build(BuildContext context) {
    return Center(
      child: Row(
        children: <Widget>[
          Expanded(
            child: Padding(
              padding: const EdgeInsets.all(8.0),
              child: TextButton(
                onPressed: () {
                  setState(() {
                    setDies();
                  });
                },
                child: Image.asset('images/dice$_leftDiceNumber.png'),
              ),
            ),
          ),
          Expanded(
            child: Padding(
              padding: const EdgeInsets.all(8.0),
              child: TextButton(
                  onPressed: () {
                    setState(() {
                     setDies();
                    });
                  },
                  child: Image.asset('images/dice$_rightDiceNumber.png')),
            ),
          ),
        ],
      ),
    );
  }
}

