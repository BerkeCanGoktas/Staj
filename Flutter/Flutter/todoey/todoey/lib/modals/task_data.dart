import 'package:flutter/cupertino.dart';

import 'package:flutter/material.dart';
import 'package:todoey/modals/task.dart';

class TaskData extends ChangeNotifier{
  
  List<Task> tasks = [
    Task(taskName: 'buy milk', isDone: false),
    Task(taskName: 'buy bread', isDone: false),
  ];

  void addTask(String newTask){
    final task = Task(taskName: newTask, isDone: false);
    tasks.add(task);
    notifyListeners();
  }

  void updateTask(Task task){
    task.toggleDone();
    notifyListeners();
  }

  void deleteTask(Task task){
    tasks.remove(task);
    notifyListeners();
  }
}