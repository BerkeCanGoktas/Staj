import 'package:flutter/material.dart';
import 'questions.dart';

class Helper{
  int counter = 0;
  int shuffled =0;
  int rightAnswerCounter =0;
  int wrongAnswerCounter = 0;
  List<Icon> scoreKeeper = [];
  final List<Questions> _questionList = [
    Questions('Some cats are actually allergic to humans', true),
    Questions('You can lead a cow down stairs but not up stairs.', false),
    Questions('Approximately one quarter of human bones are in the feet.', true),
    Questions('A slug\'s blood is green.', true),
    Questions('Buzz Aldrin\'s mother\'s maiden name was "Moon".', true),
    Questions('It is illegal to pee in the Ocean in Portugal.', true),
    Questions(
        'No piece of square dry paper can be folded in half more than 7 times.',
        false),
    Questions(
        'In London, UK, if you happen to die in the House of Parliament, you are technically entitled to a state funeral, because the building is considered too sacred a place.',
        true),
    Questions(
        'The loudest sound produced by any animal is 188 decibels. That animal is the African Elephant.',
        false),
    Questions(
        'The total surface area of two human lungs is approximately 70 square metres.',
        true),
    Questions('Google was originally called "Backrub".', true),
    Questions(
        'Chocolate affects a dog\'s heart and nervous system; a few ounces are enough to kill a small dog.',
        true),
    Questions(
        'In West Virginia, USA, if you accidentally hit an animal with your car, you are free to take it home to eat.',
        true),

];
void nextQuestion(){
       counter++;
}
  List<Questions> get getQuestionList{
    return _questionList;
  }
  void checkAnswer(bool answer){
    if(answer == _questionList[counter].answer){
      scoreKeeper.add(const Icon(Icons.check, color: Colors.green,));
      rightAnswerCounter++;
    }
    else{
      scoreKeeper.add(const Icon(Icons.close, color: Colors.red,));
      wrongAnswerCounter++;
    }
  }
  
  List<Questions> questionRandomizer(){
    if(shuffled == 0){
      _questionList.shuffle();
    }
    shuffled++;
    return _questionList;
   }

   void reset(){
     counter =0;
     wrongAnswerCounter = 0;
     rightAnswerCounter = 0;
     scoreKeeper.clear();
     shuffled = 0;
     questionRandomizer();
   }
}