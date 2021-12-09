import 'package:flutter/material.dart';
import '../constants.dart';

class BottomButton extends StatelessWidget {
  final VoidCallback onPressed;
  final String text;
  BottomButton({required this.onPressed, required this.text});

  @override
  Widget build(BuildContext context) {
    return Expanded(
        child: GestureDetector(
          onTap: onPressed,
          child: Container(
                    child: Center(
          child: Text(
            text,
            style: kButtonTextStyle,
          ),
                    ),
                    color: Color(0xFFEB1555),
                    margin: EdgeInsets.only(top: 10.0),
                    padding: EdgeInsets.only(bottom: 10.0),
                    width: double.infinity,
                  ),
        ));
  }
}