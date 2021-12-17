import 'package:flutter/material.dart';
import 'task_tile.dart';
import 'package:todoey/modals/task_data.dart';
import 'package:provider/provider.dart';

class TasksList extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Consumer<TaskData>(
      builder: (context, taskData, child) {
        return ListView.builder(
            padding: EdgeInsets.symmetric(
              horizontal: 20.0,
            ),
            itemCount: taskData.tasks.length,
            itemBuilder: (context, index) {
              return TaskTile(
                  taskName:
                      taskData.tasks[index].taskName,
                  isChecked: taskData.tasks[index].isDone,
                  checkboxCallback: (bool checkboxState) {
                    taskData.updateTask(taskData.tasks[index]);
                  },
                  longPressCallback: () => taskData.deleteTask(taskData.tasks[index]),
                  );
            });
      },
    );
  }
}
