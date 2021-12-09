import 'package:flutter/material.dart';
import 'package:quizzler/questions.dart';
import 'package:rflutter_alert/rflutter_alert.dart';
import 'helper.dart';
void main() => runApp(Quizzler());

class Quizzler extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        backgroundColor: Colors.blueGrey.shade600,
        body: SafeArea(
          child: Padding(
            padding: const EdgeInsets.symmetric(horizontal: 10.0),
            child: QuizPage(),
          ),
        ),
      ),
    );
  }
}

class QuizPage extends StatefulWidget {
  @override
  _QuizPageState createState() => _QuizPageState();
}

class _QuizPageState extends State<QuizPage> {
  Helper helperObj = Helper();
  @override
  Widget build(BuildContext context) {
    helperObj.questionRandomizer();
    List<Questions> questionList = helperObj.getQuestionList;
    return Column(
      mainAxisAlignment: MainAxisAlignment.spaceBetween,
      crossAxisAlignment: CrossAxisAlignment.stretch,
      children: <Widget>[
        Expanded(
          flex: 5,
          child: Padding(
            padding: const EdgeInsets.all(10.0),
            child: Center(
              child: Text(
                questionList[helperObj.counter].question,
                textAlign: TextAlign.center,
                style: const TextStyle(
                  fontSize: 25.0,
                  color: Colors.white,
                ),
              ),
            ),
          ),
        ),
        Expanded(
          child: Padding(
            padding: const EdgeInsets.all(15.0),
            child: TextButton(
              style: ButtonStyle(
                backgroundColor: MaterialStateProperty.all<Color>(Colors.green),
              ),
              child: const Text(
                'True',
                style: TextStyle(
                  color: Colors.white,
                  fontSize: 20.0,
                ),
              ),
              onPressed: () {
                setState(() {
                  helperObj.checkAnswer(true);
                  if(helperObj.counter < helperObj.getQuestionList.length-1){
                          helperObj.nextQuestion();
                  }
                  else{
                    Alert(context: context, title: "Game Over", desc: "Your Score: ${helperObj.rightAnswerCounter-helperObj.wrongAnswerCounter}").show();
                    helperObj.reset();
                  }
                });
              },
            ),
          ),
        ),
        Expanded(
          child: Padding(
            padding: const EdgeInsets.all(15.0),
            child: TextButton(
              style: ButtonStyle(
                backgroundColor: MaterialStateProperty.all<Color>(Colors.red),
              ),
              child: const Text(
                'False',
                style: TextStyle(
                  fontSize: 20.0,
                  color: Colors.white,
                ),
              ),
              onPressed: () {
                setState(() {
                  helperObj.checkAnswer(false);
                   if(helperObj.counter < helperObj.getQuestionList.length-1){
                          helperObj.nextQuestion();
                  }
                  else{
                    Alert(context: context, title: "Game Over", desc: "Your Score: ${helperObj.rightAnswerCounter-helperObj.wrongAnswerCounter}").show();
                    helperObj.reset();
                  }
                });
              },
            ),
          ),
        ),
        Expanded(
          child: Row(
            children: helperObj.scoreKeeper,
          ),
        )
      ],
    );
  }
}
