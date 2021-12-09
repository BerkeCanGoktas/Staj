import 'dart:math';

class CalculatorBrain{

  final int height;
  final int weight;

  CalculatorBrain({required this.height, required this.weight});

  num calculateBMI(){
    double bmi = weight/(pow(height/100, 2));
    return num.parse(bmi.toStringAsFixed(1));
  }

  String? getResult(){
    num bmi = calculateBMI();
    if(bmi >= 25){
        return 'Overweight';
    }
    else if(bmi <= 25 && bmi >= 18){
      return 'Normal';
    }
    else if(bmi < 18){
      return 'Underweight';
    }
  }

  String? getInterperation(){
    num bmi = calculateBMI();
    if(bmi >= 25){
        return 'You have a higher than normal body weight. Try to exercise more!';
    }
    else if(bmi <= 25 && bmi >= 18){
      return 'You have normal body weight. Good job!';
    }
    else if(bmi < 18){
      return 'You have a lower than normal body weight. Try to eat a bit more!';
    }
  }

}