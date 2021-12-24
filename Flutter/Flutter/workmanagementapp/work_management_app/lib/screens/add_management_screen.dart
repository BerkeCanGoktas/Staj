import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:work_management_app/tasks/task_data.dart';


late User? loggedInUser;

class AddManagementScreen extends StatefulWidget {
  const AddManagementScreen({ Key? key }) : super(key: key);

  static final auth = FirebaseAuth.instance;
  static final firestore = FirebaseFirestore.instance;
  static String taskType = '';

    void getCurrentUser() {
    try {
      final user = AddManagementScreen.auth.currentUser;
      if (user != null) {
        loggedInUser = user;
        print(loggedInUser?.email);
      }
    } catch (e) {
      print(e);
    }
  }

  static void getTasksOfUser() async {
    try {
          final user = auth.currentUser;
          if (user != null) {
            loggedInUser = user;
            print(loggedInUser?.email);
          }
          await for (var snapshots in firestore.collection('tasks').snapshots()) {
          if(TaskData.staticTasksList.isEmpty){
        for (var task in snapshots.docs) {
          if(task.get('user') == loggedInUser?.email){
            print(task.data());
            TaskData().addTask(task.get('taskName'), task.get('taskType'), task.get('taskIsDone'), task.get('taskDate'));
            print(TaskData.staticTasksList.length);
          }
          }
          }
          }
          } catch (e) {
              print(e);
          }
    }

  @override
  _AddManagementScreenState createState() => _AddManagementScreenState();
}

class _AddManagementScreenState extends State<AddManagementScreen> {
    String newTaskTitle = '';

    @override
    void initState() {
      super.initState();
      widget.getCurrentUser();
    }


  @override
  Widget build(BuildContext context) {
    return Container(
        color: Color(0xff757575),
        child: Container(
          padding: EdgeInsets.all(20.0),
          decoration: BoxDecoration(
              color: Colors.white,
              borderRadius: BorderRadius.only(
                  topLeft: Radius.circular(20.0),
                  topRight: Radius.circular(20.0))),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.stretch,
            children: <Widget>[
              Center(
                child: Text(
                  'Add Task',
                  style: TextStyle(
                    color: Colors.lightBlueAccent,
                    fontSize: 30,
                  ),
                ),
              ),
              SizedBox(
                height: 10.0,
              ),
              TextField(
                decoration: InputDecoration(),
                textAlign: TextAlign.center,
                autofocus: true,
                onSubmitted: (newTask) {
                  Timestamp now = new Timestamp.now();
                  newTaskTitle = newTask;
                  Provider.of<TaskData>(context, listen: false)
                      .addTask(newTaskTitle, AddManagementScreen.taskType, false, now);
                      Navigator.pop(context);
                },
                onChanged: (newTask) {
                  newTaskTitle = newTask;
                },
              ),
              SizedBox(
                height: 10.0,
              ),
              TextButton(
                onPressed: () {
                  Timestamp now = new Timestamp.now();
                  Provider.of<TaskData>(context, listen: false)
                      .addTask(newTaskTitle, AddManagementScreen.taskType, false, now);
                  AddManagementScreen.firestore.collection('tasks').add(
                          {'taskName': newTaskTitle, 'user': loggedInUser?.email, 'taskIsDone': false, 'taskType': AddManagementScreen.taskType, 'taskDate': now});
                  Navigator.pop(context);
                },
                child: Text(
                  'Add',
                  style: TextStyle(
                    color: Colors.white,
                    fontSize: 18.0,
                  ),
                ),
                style: TextButton.styleFrom(
                  backgroundColor: Colors.lightBlueAccent,
                ),
              ),
            ],
          ),
        ));
  } 
}

