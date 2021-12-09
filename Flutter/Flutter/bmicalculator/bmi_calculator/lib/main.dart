import 'package:flutter/material.dart';
import 'screens/input_page.dart';

const primaryColor =  Color(0xFF0A0E21);
void main() => runApp(BMICalculator());

class BMICalculator extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      theme: ThemeData.dark().copyWith(
        scaffoldBackgroundColor: primaryColor,
        appBarTheme: const AppBarTheme(color: primaryColor),
      ),    
      home: InputPage(),
    );
  }
}
