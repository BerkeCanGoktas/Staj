import 'package:work_management_app/screens/add_management_screen.dart';
import 'package:flutter/material.dart';
import 'package:work_management_app/screens/management_screen.dart';
import 'task.dart';
import 'package:cloud_firestore/cloud_firestore.dart';

class TaskData extends ChangeNotifier{

  static List<Task> staticTasksList = [];
  static List<Task> shownTasks =[];
  static List<Task> temporaryTaskListForSearching = [];
  
  void addTask(String newTask, String taskType, bool isDone, Timestamp taskDate) async{
    final task = Task(taskName: newTask, isDone: isDone, taskType: taskType, taskDate: taskDate);
    staticTasksList.add(task);
    shownTasks.add(task);
    AddManagementScreen.firestore.collection('tasks').add({'taskName': task.taskName, 'user': loggedInUser?.email,
     'taskIsDone': task.isDone, 'taskType': task.taskType, 'taskDate': task.taskDate});
    notifyListeners();
  }

  void searchBarFunction(String value){
    temporaryTaskListForSearching = [];
    ManagementScreen.isSearching = true;
    int searchLength = value.length;
    for(var task in TaskData.shownTasks){
        if(task.taskName.toLowerCase().contains(value.toLowerCase())){
          TaskData.temporaryTaskListForSearching.add(task);
          print(temporaryTaskListForSearching.length);
        }
    }
    notifyListeners();
  }

  void showDailyTasks(){
    shownTasks = [];
    for(Task task in staticTasksList){
      if(task.taskType == 'Daily'){
        shownTasks.add(task);
        print(shownTasks[0].taskName);
      }
    }
    notifyListeners();
  }
  void showWeeklyTasks(){
    shownTasks = [];
    for(Task task in staticTasksList){
      if(task.taskType == 'Weekly'){
        shownTasks.add(task);
        print(shownTasks[0].taskName);
      }
    }
    notifyListeners();
  }
  void showMonthlyTasks(){
    shownTasks = [];
    for(Task task in staticTasksList){
      if(task.taskType == 'Monthly'){
        shownTasks.add(task);
        print(shownTasks[0].taskName);
      }
    }
    notifyListeners();
  }

  int taskCount(){
    return shownTasks.length;
  }

  void updateTask(Task task) async{
    task.toggleDone();
    String? ref = await updateDatabase(task);
    if(ref!.isNotEmpty){
      AddManagementScreen.firestore.collection('tasks').doc(ref).update({'taskIsDone': task.isDone});
    }
    notifyListeners();
  }

  void deleteTask(Task task) async{
    String? ref = await updateDatabase(task);
    if(ref!.isNotEmpty){
      AddManagementScreen.firestore.collection('tasks').doc(ref).delete();
    }
    shownTasks.remove(task);
    staticTasksList.remove(task);
    notifyListeners();
  }
  Future<String?> updateDatabase(Task task) async{
    var collection = AddManagementScreen.firestore.collection('tasks');
    var q = await collection.where('taskDate', isEqualTo: task.taskDate);
    var querySnapshot = await q.get();
    for (var doc in querySnapshot.docs){
      String reference = await doc.reference.id;
      return reference;
    }
  }
}