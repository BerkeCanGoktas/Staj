import 'package:flutter/material.dart';

void main() {
  runApp(
    MaterialApp(
      home: Scaffold(
        //uygulamanın yapısını oluşturan widget,
        appBar: AppBar(
          //tepede bir bar, başlığı ve arkaplan rengi ayarlanmış
          title: const Text("I am Rich"),
          backgroundColor: Colors.blueGrey[900],
        ),
        body: const Center(
          child: Image(
            //resim eklemek için widget
            image: AssetImage('images/diamond.png'),
          ),
        ),
        backgroundColor: Colors.blueGrey, //Scaffoldun arkaplan rengi ayarlanmış
      ),
    ),
  );
}

/*
runApp(const MaterialApp(home: Center(  //runApp fonksiyonu programı çalıştırır, MaterialApp widgetı diğer widgetları kullanmak için temel oluşturur,
    child: Text("Hello World!"),          //Center widgetı ortalar, Text widgetı ekrana metin yazdırır.
  )));
*/

/*
image: NetworkImage(
                'https://cdn.pixabay.com/photo/2015/04/23/22/00/tree-736885__480.jpg'), //urlden eklemek
*/