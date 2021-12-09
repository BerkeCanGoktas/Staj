import 'package:flutter/material.dart';

class RoundIconButton extends StatelessWidget {
  final Widget child;
  final VoidCallback onPressed;

  RoundIconButton({required this.child, required this.onPressed});

  @override
  Widget build(BuildContext context) {
    return RawMaterialButton(
      shape: CircleBorder(),
      child: child,
      elevation: 6.0,
      constraints: BoxConstraints.tightFor(width: 56.0, height: 56.0,),
      onPressed: onPressed,
      fillColor: Color(0xFF4C4F5E),
    );
  }
}