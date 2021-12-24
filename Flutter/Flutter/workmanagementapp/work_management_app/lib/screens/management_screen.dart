import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:work_management_app/tasks/task_data.dart';
import 'add_management_screen.dart';
import 'package:work_management_app/components/tasks_list.dart';

class ManagementScreen extends StatefulWidget {
  static String id = 'management_screen';
  static bool isSearching = false;

  @override
  _ManagementScreenState createState() => _ManagementScreenState();
}

class _ManagementScreenState extends State<ManagementScreen> {

  dynamic val = 0;

  @override
  void initState() {
    super.initState();
    AddManagementScreen.getTasksOfUser();
  }

  void closeScreen() async {
    //await TaskData().updateDatabase();
    AddManagementScreen.auth.signOut();
    print(AddManagementScreen.auth.currentUser);
    Navigator.pop(context);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.lightBlueAccent,
      body: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Container(
            padding: EdgeInsets.only(
                top: 60.0, left: 30.0, bottom: 30.0, right: 30.0),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: <Widget>[
                CircleAvatar(
                  child: Icon(
                    Icons.list,
                    size: 30.0,
                    color: Colors.lightBlueAccent,
                  ),
                  backgroundColor: Colors.white,
                  radius: 30.0,
                ),
                SizedBox(
                  height: 10.0,
                ),
                Text(
                  'Work Management',
                  style: TextStyle(
                      color: Colors.white,
                      fontSize: 50.0,
                      fontWeight: FontWeight.w700),
                ),
                Text(
                  '${Provider.of<TaskData>(context).taskCount()} tasks',
                  style: TextStyle(color: Colors.white, fontSize: 18.0),
                ),
              ],
            ),
          ),
          Expanded(
            child: Container(
              decoration: BoxDecoration(
                color: Colors.white,
                borderRadius: BorderRadius.only(
                  topLeft: Radius.circular(20.0),
                  topRight: Radius.circular(20.0),
                ),
              ),
              child: Column(
                children: [
                  Row(children: <Widget>[
                    Padding(
                      padding: const EdgeInsets.only(
                        left: 15.0,
                      ),
                      child: IconButton(
                        onPressed: closeScreen,
                        icon: Icon(
                          Icons.arrow_back,
                          size: 40.0,
                        ),
                        tooltip: 'Logout from your account',
                        color: Colors.lightBlueAccent,
                      ),
                    ),
                    SizedBox(width: 5.0,),
                    Container(
                      child: Flexible(
                        child: Material(
                          elevation: 5.0,
                          color: Colors.white54,
                          borderRadius: BorderRadius.circular(30.0),
                          child: Row(
                            children: <Widget>[
                              Flexible(
                                  child: Padding(
                                      padding: EdgeInsets.symmetric(
                                          horizontal: 20.0, vertical: 5.0),
                                      child: TextField(
                                        decoration: InputDecoration(
                                          border: InputBorder.none,
                                          hintText: 'Search tasks by name',
                                        ),
                                        onChanged: (value){Provider.of<TaskData>(context, listen: false)
                      .searchBarFunction(value);
                      //ManagementScreen.isSearching = false;
                      },
                                      ))),
                              Icon(
                                Icons.search_outlined,
                                size: 40.0,
                                color: Colors.lightBlueAccent,
                              ),
                            ],
                          ),
                        ),
                      ),
                    ),
                    SizedBox(width: 10.0,)
                  ]),
                  Row(
                    children: <Widget>[
                      Flexible(
                        child: ListTile(
                          title: Text("Daily"),
                          leading: Radio(
                            value: 1,
                            groupValue: val,
                            onChanged: (value) {
                              setState(() {
                                val = value;
                                AddManagementScreen.taskType = 'Daily';
                                Provider.of<TaskData>(context, listen: false)
                      .showDailyTasks();
                      ManagementScreen.isSearching = false;
                              });
                            },
                            activeColor: Colors.lightBlueAccent,
                          ),
                        ),
                      ),
                      Flexible(
                        child: ListTile(
                          title: Text("Weekly"),
                          leading: Radio(
                            value: 2,
                            groupValue: val,
                            onChanged: (value) {
                              setState(() {
                                val = value;
                                AddManagementScreen.taskType = 'Weekly';
                                Provider.of<TaskData>(context, listen: false)
                      .showWeeklyTasks();
                      ManagementScreen.isSearching = false;
                              });
                            },
                            activeColor: Colors.lightBlueAccent,
                          ),
                        ),
                      ),
                      Flexible(
                        child: ListTile(
                          title: Text("Monthly"),
                          leading: Radio(
                            value: 3,
                            groupValue: val,
                            onChanged: (value) {
                              setState(() {
                                val = value;
                                AddManagementScreen.taskType = 'Monthly';
                                Provider.of<TaskData>(context, listen: false)
                      .showMonthlyTasks();
                      ManagementScreen.isSearching = false;
                              });
                            },
                            activeColor: Colors.lightBlueAccent,
                          ),
                        ),
                      ),
                    ],
                  ),
                  TasksList(),
                ],
              ),
            ),
          ),
        ],
      ),
      floatingActionButton: FloatingActionButton(
        backgroundColor: Colors.lightBlueAccent,
        child: Icon(Icons.add),
        onPressed: () {
          showModalBottomSheet(
              isScrollControlled: true,
              context: context,
              builder: (context) => SingleChildScrollView(
                      child: Container(
                    padding: EdgeInsets.only(
                        bottom: MediaQuery.of(context).viewInsets.bottom),
                    child: AddManagementScreen(),
                  )));
        },
      ),
    );
  }
}
