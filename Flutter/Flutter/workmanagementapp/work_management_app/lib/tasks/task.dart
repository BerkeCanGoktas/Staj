import 'package:cloud_firestore/cloud_firestore.dart';

class Task{
  final String taskName;
  bool isDone;
  final String taskType;
  Timestamp taskDate;
  Task({required this.taskName, required this.isDone, required this.taskType, required this.taskDate});
  void toggleDone(){
    isDone = !isDone;
  }

}