import 'package:flutter/material.dart';
import 'package:work_management_app/screens/management_screen.dart';
import 'task_tile.dart';
import 'package:work_management_app/tasks/task_data.dart';
import 'package:provider/provider.dart';
import 'package:work_management_app/tasks/task.dart';

class TasksList extends StatelessWidget {
  const TasksList({ Key? key }) : super(key: key);

  int setDuration(Task task){
    if(task.taskType == 'Daily'){
      //print(DateTime.now().difference(task.taskDate.toDate()).inMinutes.toDouble());
      //return DateTime.now().difference(task.taskDate.toDate()).inMinutes.toDouble();
      return 1;
    }
    else if(task.taskType == 'Weekly'){
      //return DateTime.now().difference(task.taskDate.toDate()).inMinutes/7;
      return 7;
    }
    else if(task.taskType == 'Monthly'){
      //return DateTime.now().difference(task.taskDate.toDate()).inMinutes/30;
      return 30;
    }
    else{
      return 1;
    }
  }
@override
  Widget build(BuildContext context) {
    return Consumer<TaskData>(
      builder: (context, taskData, child) {
        return Flexible(
          child: ListView.builder(
              padding: EdgeInsets.symmetric(
                horizontal: 20.0,
              ),
              itemCount: ManagementScreen.isSearching ? TaskData.temporaryTaskListForSearching.length : TaskData.shownTasks.length,
              itemBuilder: (context, index) {
                return TaskTile(
                  duration: setDuration(TaskData.shownTasks[index]),
                    taskName:
                        ManagementScreen.isSearching ? TaskData.temporaryTaskListForSearching[index].taskName : TaskData.shownTasks[index].taskName,
                    isChecked: ManagementScreen.isSearching ? TaskData.temporaryTaskListForSearching[index].isDone : TaskData.shownTasks[index].isDone,
                    checkboxCallback: (bool checkboxState) {
                       ManagementScreen.isSearching ?  taskData.updateTask(TaskData.shownTasks.singleWhere(
                         (element) => element.taskDate == TaskData.temporaryTaskListForSearching[index].taskDate)): taskData.updateTask(TaskData.shownTasks[index]);
                    },
                    longPressCallback: (){
                        taskData.deleteTask(TaskData.shownTasks[index]);
                    },
                    onTapCallback: () => true,
                    );
              }),
        );
      },
    );
  }
}