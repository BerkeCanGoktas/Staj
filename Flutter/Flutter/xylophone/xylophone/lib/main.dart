import 'package:audioplayers/audio_cache.dart';
import 'package:flutter/material.dart';

void main() => runApp(XylophoneApp());

class XylophoneApp extends StatelessWidget {
  void playSound(int note) async{
      final player = AudioCache();
      await player.play('note$note.wav');
  }
  Expanded buildKey(Color color, String txt, int sound){
    return  Expanded(
                child: Container(
                  color: color,
                  width: double.infinity,
                  child: TextButton(
                    onPressed: () {
                      playSound(sound);
                    },
                    child: Text(
                      txt,
                      style: TextStyle(color: Colors.white, fontSize: 20.0,),
                    ),
                  ),
                ),
              );
  }
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        body: SafeArea(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: <Widget>[
              buildKey(Colors.red, 'A', 1),
              buildKey(Colors.orange, 'B', 2),
              buildKey(Colors.yellow, 'C', 3),
              buildKey(Colors.lime, 'D', 4),
              buildKey(Colors.green, 'E', 5),
              buildKey(Colors.blue, 'F', 6),
              buildKey(Colors.purple, 'G', 7),
            ],
          ),
        ),
      ),
    );
  }
}

