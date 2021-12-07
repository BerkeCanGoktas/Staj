import 'package:flutter/material.dart';

void main() {
  runApp(
    MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('I am Poor'),
          backgroundColor: Colors.amber[400],
        ),
        body: const Center(
          child: Image(
            image: NetworkImage(
                'https://www.pikpng.com/pngl/m/257-2572612_a-lump-of-coal-for-christmas-piece-of.png'),
          ),
        ),
        backgroundColor: Colors.amberAccent,
      ),
    ),
  );
}
